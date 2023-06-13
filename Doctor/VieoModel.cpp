#include "VieoModel.h"


VieoModel::VieoModel(Server *server, std::shared_ptr<File> file)
    :m_server(server),
      m_file(file)
{
    connect(m_server, &Server::currentStatusChanged, this, &VieoModel::currentStatusChanged);
    connect(m_server, &Server::receivedStringChanged, this, &VieoModel::receivedDataChanged);
    connect(m_server, &Server::receivedString1Changed, this, &VieoModel::receivedData1Changed);
    connect(m_server, &Server::receivedString1Changed , this ,&VieoModel::pointsChanged);

}

void VieoModel::listen()
{
    QMetaObject::invokeMethod(m_server, "start");

}

void VieoModel::close()
{
    QMetaObject::invokeMethod(m_server, "Quit");
}

void VieoModel::savefile()
{
    m_file->savevec(m_points,"file.text");  //save file
}



QString VieoModel::currentStatus() const
{
    return m_server->currentStatus();
}

void VieoModel::setCurrentStatus(const QString &newCurrentStatus)
{
    if (m_currentStatus == newCurrentStatus)
        return;
    m_currentStatus = newCurrentStatus;
    emit currentStatusChanged();
}

Server *VieoModel::server() const
{
    return m_server;
}
QString VieoModel::receivedData() const
{
    return m_server->receivedString();
}

QString VieoModel::receivedData1() const
{
    return m_receivedData1;
}

QVector<double> VieoModel::points()
{
    return m_points;
}


void VieoModel::setpoints(const QVector<double> &newPoints)
{
    if (m_points == newPoints)
        return;
    m_points = newPoints;
    emit pointsChanged();
}

void VieoModel::numgen()
{
    QByteArray byteArray = m_server->receivedString1().toUtf8();
    double distance{};
            double time{};
            int startIndex;
            int endIndex;



                startIndex = byteArray.indexOf("$") + 1; // first character after "$" its time
                endIndex = byteArray.indexOf("@", startIndex);
                time = QString(byteArray.mid(startIndex, endIndex - startIndex)).toDouble();

                startIndex = endIndex + 1; // first character after "@" its distance
                endIndex = byteArray.indexOf("@", startIndex);
                distance = QString(byteArray.mid(startIndex, endIndex - startIndex)).toDouble();

                    m_points.append(distance);
                    m_points.append(time);
}




