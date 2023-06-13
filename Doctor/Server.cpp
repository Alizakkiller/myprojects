#include "Server.h"
#include <cmath>
#include <QVector>

QString Server::receivedString() const
{
    return m_receivedString;
}

Server::Server(QTcpServer *server)
    :m_server(server)
{
   QObject::connect(m_server,&QTcpServer::newConnection,this,&Server::newConnection);

}

void Server::start()
{
    if(m_server->isListening())
        return;
    setCurrentStatus("yellow");
    m_server->listen(QHostAddress::Any, 2000);
}

void Server::Quit()
{

    setCurrentStatus("black");
}

void Server::newConnection()
{
    if(m_server->hasPendingConnections())
    {
        m_socket = m_server->nextPendingConnection();
        connect(m_socket, &QTcpSocket::readyRead, this, &Server::readyRead);
        connect(m_socket, &QTcpSocket::disconnected, this, &Server::start);
        setCurrentStatus("green");


    }
}


void Server::readyRead()
{
    QByteArray byteArray ;
    while (m_socket->bytesAvailable() > 0)
    {
        auto readsize = m_socket->read(m_buffer, 1000);
        for (int i = 0; i < readsize; ++i) {
            byteArray.append(m_buffer[i]);
        }

    }
        QString myString;
        int startIndex;
        int endIndex;


        if(m_ab==0){
            m_ab++;
            startIndex = byteArray.indexOf("!") + 1; // first character after "!" its name and famili and dificality
            endIndex = byteArray.indexOf("$", startIndex);
            myString = QString::fromUtf8(byteArray.mid(startIndex, endIndex - startIndex));
            setreceivedString(myString);

        }
        else{
            setreceivedString1(QString::fromUtf8(byteArray)); //sending an other data to viow model
        }

}



QString Server::currentStatus() const
{
    return m_Status;
}

void Server::setCurrentStatus(const QString &newStatus)
{
    if (m_Status == newStatus)
        return;
    m_Status = newStatus;
    emit currentStatusChanged();
}

void Server::setreceivedString(const QString &newReceivedString)
{
    if (m_receivedString == newReceivedString)
        return;
    m_receivedString = newReceivedString;
    emit receivedStringChanged();
}

QString Server::receivedString1() const
{
    return m_receivedString1;
}

void Server::setreceivedString1(const QString &newReceivedString1)
{
    if (m_receivedString1 == newReceivedString1)
        return;
    m_receivedString1 = newReceivedString1;
    emit receivedString1Changed();
}
