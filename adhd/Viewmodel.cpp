#include "Viewmodel.h"
#include "Client.h"

ViewModel::ViewModel(std::shared_ptr<CppGenerator> cpp, Client *client)
    :m_cpp(cpp)
    ,m_client(client)
{
   QObject::connect(m_client, &Client::currentStatusChanged, this, &ViewModel::currentStatusChanged);
}


void ViewModel::send()  // send name famili and dificality
{
    QMetaObject::invokeMethod(m_client, "setname", Q_ARG(QString, m_nname));
    QMetaObject::invokeMethod(m_client, "setfamili", Q_ARG(QString, m_famili));
    QMetaObject::invokeMethod(m_client, "setdif", Q_ARG(QString, m_cpp->dificality()));

}

void ViewModel::send1() //send time and distance to client class
{
    QMetaObject::invokeMethod(m_client, "settime", Q_ARG(double, m_time));
    QMetaObject::invokeMethod(m_client, "setdistance", Q_ARG(int, m_cpp->distance()));
}



void ViewModel::connect()
{
    QMetaObject::invokeMethod(m_client, "connect");
}
void ViewModel::setdistance(long long x, long long y) //giving x and y from ui
{
    m_cpp->setDistance(x,y);
}


QString ViewModel::currentStatus() const
{
    return m_client->currentStatus();

}

QString ViewModel::nname() const
{
    return m_nname;
}

void ViewModel::setNname(const QString &newNname)
{
    if (m_nname == newNname)
        return;
    m_nname = newNname;
    //////////////////////////////////
    m_client->setname(m_nname);
    //////////////////////////////////
    emit nnameChanged();
}

QString ViewModel::famili() const
{
    return m_famili;
}

void ViewModel::setFamili(const QString &newFamili)
{

    if (m_famili == newFamili)
        return;
    m_famili = newFamili;
    //////////////////////////////
    m_client->setfamili(m_famili);
    //////////////////////////////
    emit familiChanged();
}

int ViewModel::dif() const
{
    return m_dif;
}

void ViewModel::setDif(int newDif)//dificality i give number and convert to string
{
    if(newDif==0)
    {
        m_cpp->setDificality("easy");
    }
    else if(newDif==1)
    {
        m_cpp->setDificality("normal");
    }
    else
    {
        m_cpp->setDificality("hard");
    }
    if (m_dif == newDif)
        return;
    m_dif = newDif;
    //////////////////////////////////////////
     m_client->setdif(m_cpp->dificality());
     ////////////////////////////////////////
    emit difChanged();

}




double ViewModel::time() const
{
    return m_time;
}

void ViewModel::setTime(const double &newTime)
{
    if (m_time == newTime)
        return;
    m_time = newTime;
    emit timeChanged();
}
