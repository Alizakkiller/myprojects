#ifndef CLIENT_H
#define CLIENT_H


#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT
    QByteArray m_data0= "";
    QTcpSocket *m_tcpsocket;

    Q_PROPERTY(QString currentStatus READ currentStatus WRITE setCurrentStatus NOTIFY currentStatusChanged) //status for connect
    Q_PROPERTY(bool connected READ connected WRITE setConnected NOTIFY connectedChanged)
public:
    explicit Client(QTcpSocket *tcpsocket);

    QString currentStatus() const;  //Q_PROPERTY
    void setCurrentStatus(const QString &newCurrentStatus); //Q_PROPERTY

    bool connected() const; //Q_PROPERTY

    void setConnected(bool newConnected); //Q_PROPERTY




signals:
    void currentStatusChanged(); //Q_PROPERTY
    void connectedChanged(); //Q_PROPERTY

public slots:
    void connect();
    void setname(QString n);
    void setfamili(QString f);
    void setdif(QString dif);
    void setdistance(int dis);
    void settime(double t);



    void handleConnected();



private:
    QString m_currentStatus; //Q_PROPERTY
    bool m_connected; //Q_PROPERTY

};

#endif // CLIENT_H
