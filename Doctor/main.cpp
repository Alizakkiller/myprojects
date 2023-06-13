#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTcpServer>
#include <QThread>
#include <memory>
#include "Server.h"
#include "VieoModel.h"
#include "File.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/Doctor1/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    QTcpServer *server = new QTcpServer();
    Server *recieved = new Server(server);


    QThread thread;
    recieved->moveToThread(&thread);
    server->moveToThread(&thread);
    thread.start();


    File file;


    VieoModel *view = new VieoModel(recieved,std::make_shared<File>(file));

    engine.rootContext()->setContextProperty("model", view);
    qmlRegisterType<VieoModel>("Viewmodels", 1 , 0 , "Viewmodel");

    engine.load(url);



    return app.exec();

}
