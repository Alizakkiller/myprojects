#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <memory>
#include <QThread>
#include "Client.h"
#include "cppgenerator.h"
#include "Viewmodel.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);


    QTcpSocket *socket = new QTcpSocket();
    Client *sender = new Client(socket);
    QThread thread;
    sender->moveToThread(&thread);
    socket->moveToThread(&thread);
    thread.start();

    CppGenerator gn;

    ViewModel view1(std::make_shared<CppGenerator>(gn),sender);

    QMetaObject::invokeMethod(sender,"connect");

    engine.rootContext()->setContextProperty("cpp" , &view1);
    qmlRegisterType<ViewModel>("ViewModels" , 1 , 0 , "ViewModel" );

    engine.load(url);

    return app.exec();
}
