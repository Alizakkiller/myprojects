#include "Client.h"

Client::Client(QTcpSocket *tcpsocket)
    : m_tcpsocket(tcpsocket)
{
    QObject::connect(m_tcpsocket, &QTcpSocket::connected, this, &Client::handleConnected);
}

void Client::connect()
{
    m_tcpsocket->connectToHost("127.0.0.1", 2000);
    setCurrentStatus("yellow");
}

void Client::handleConnected()
{
    setCurrentStatus("green");
    setConnected(true);

}

QString Client::currentStatus() const
{
    return m_currentStatus;
}

void Client::setCurrentStatus(const QString &newCurrentStatus)
{
    if (m_currentStatus == newCurrentStatus)

        return;
    m_currentStatus = newCurrentStatus;
    emit currentStatusChanged();
}

bool Client::connected() const
{
    return m_connected;
}



void Client::setConnected(bool newConnected)
{
    if (m_connected == newConnected)
        return;
    m_connected = newConnected;
    emit connectedChanged();
}

void Client::setname(QString n)   //sending name
{
    m_data0.append("!");
    m_data0.append(n.toLocal8Bit());
    m_tcpsocket->write(m_data0);
    m_data0.clear();
    m_data0.append("\n");
}

void Client::setfamili(QString f) // sending famili
{
   m_data0.append(f.toLocal8Bit());
   m_tcpsocket->write(m_data0);
   m_data0.clear();
   m_data0.append("\n");
}
void Client::setdif(QString dif) //sending dificality
{
    m_data0.append(dif.toLocal8Bit());
    m_tcpsocket->write(m_data0);
    m_data0.clear();
}

void Client::setdistance(int dis) // sending distance
{
    m_data0.append("@");
    m_data0.append(QString::number(dis).toStdString());
    m_tcpsocket->write(m_data0);
    m_data0.clear();
}

void Client::settime(double t) //sending time
{
    m_data0.append("$");
    m_data0.append(QString::number(t).toStdString());
    m_tcpsocket->write(m_data0);

    m_data0.append("*");
    m_data0.clear();

}






