#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QVector>

class Server : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentStatus READ currentStatus WRITE setCurrentStatus NOTIFY currentStatusChanged) //status
    Q_PROPERTY(QString receivedString READ receivedString WRITE setreceivedString NOTIFY receivedStringChanged) // recive name famili and dificality
    Q_PROPERTY(QString receivedString1 READ receivedString1 WRITE setreceivedString1 NOTIFY receivedString1Changed) // recive distance and time


public:
    explicit Server(QTcpServer *server);

    QString currentStatus() const; //Q_PROPERTY
    void setCurrentStatus(const QString &newStatus); //Q_PROPERTY

    QString receivedString() const; //Q_PROPERTY

    void setreceivedString(const QString &newReceivedString); //Q_PROPERTY

    QString receivedString1() const; //Q_PROPERTY
    void setreceivedString1(const QString &newReceivedString1); //Q_PROPERTY

signals:
    void currentStatusChanged(); //Q_PROPERTY

    void receivedStringChanged(); //Q_PROPERTY

    void receivedString1Changed(); //Q_PROPERTY

public slots:
    void start();
    void Quit();
    void newConnection();

    void readyRead();





private:
    QString m_Status;
    QByteArray m_data;
    QTcpServer *m_server;
    QTcpSocket *m_socket;
    QString m_receivedString;
    char * m_buffer = new char[1000];
    int m_ab{};


    QString m_receivedString1;
};

#endif // SERVER_H
