#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "cppgenerator.h"
#include <memory>
#include <QObject>
#include <QString>
#include "Client.h"

class ViewModel : public QObject
{
    Q_OBJECT
    std::shared_ptr<CppGenerator> m_cpp;
    Client *m_client;
    Q_PROPERTY(QString currentStatus READ currentStatus NOTIFY currentStatusChanged)


    Q_PROPERTY(QString nname READ nname WRITE setNname NOTIFY nnameChanged)
    Q_PROPERTY(QString famili READ famili WRITE setFamili NOTIFY familiChanged)
    Q_PROPERTY(int dif READ dif WRITE setDif NOTIFY difChanged)
    Q_PROPERTY(double time READ time WRITE setTime NOTIFY timeChanged)


public:
    ViewModel(std::shared_ptr<CppGenerator> cpp, Client *client);

    Q_INVOKABLE void setdistance(long long int x , long long int y);
    Q_INVOKABLE void connect();
    Q_INVOKABLE void send();
    Q_INVOKABLE void send1();

    QString currentStatus() const;//Q_PROPERTY
    QString nname() const;//Q_PROPERTY
    void setNname(const QString &newNname);//Q_PROPERTY

    QString famili() const;//Q_PROPERTY
    void setFamili(const QString &newFamili);//Q_PROPERTY

    int dif() const;//Q_PROPERTY
    void setDif(int newDif);//Q_PROPERTY

    double time() const;//Q_PROPERTY
    void setTime(const double &newTime);//Q_PROPERTY

signals:
    void currentStatusChanged(); //Q_PROPERTY
    void nnameChanged(); //Q_PROPERTY

    void familiChanged(); //Q_PROPERTY

    void difChanged(); //Q_PROPERTY

    void timeChanged();//Q_PROPERTY

private:
    QString m_currentStatus;
    QString m_nname;
    QString m_famili;
    int m_dif;

    double m_time;
};

#endif // VIEWMODEL_H
