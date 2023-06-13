#ifndef VIEOMODEL_H
#define VIEOMODEL_H

#include <QObject>
#include "Server.h"
#include "File.h"
#include <memory>

class VieoModel : public QObject
{
    Q_OBJECT
    Server *m_server;
    std::shared_ptr<File> m_file;
    Q_PROPERTY(QString currentStatus READ currentStatus WRITE setCurrentStatus NOTIFY currentStatusChanged)
    Q_PROPERTY(QString receivedData READ receivedData  NOTIFY receivedDataChanged) //send name famili dificality to  ui
    Q_PROPERTY(QString receivedData1 READ receivedData1  NOTIFY receivedData1Changed)
    Q_PROPERTY(QVector<double> points READ points WRITE setpoints NOTIFY pointsChanged)// sending distance and time to ui

public:
    explicit VieoModel(Server *server,std::shared_ptr<File> file);
    Q_INVOKABLE void listen();
    Q_INVOKABLE void close();
    Q_INVOKABLE void savefile(); // for save file ...


    QString currentStatus() const;
    void setCurrentStatus(const QString &newCurrentStatus);


    QString receivedData() const;

    Server *server() const;

    QString receivedData1() const;

    QVector<double> points();

    void setpoints(const QVector<double> &newPoints);

    Q_INVOKABLE void numgen(); //parsing time and distance




signals:

    void currentStatusChanged();

    void receivedDataChanged();

    void receivedData1Changed();

    void pointsChanged();


private:
    QString m_currentStatus;
    QString m_receivedData;
    QString m_receivedData1;
    QVector<double> m_points;
};

#endif // VIEOMODEL_H
