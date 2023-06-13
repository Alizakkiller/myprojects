#ifndef CPPGENERATOR_H
#define CPPGENERATOR_H
#include <string>
#include <vector>
#include <memory>
#include <QString>

class Client;
class CppGenerator
{
    Client *m_client;
    QString m_dificality;
    double m_distance;

public:
    CppGenerator();

    void setDistance(double x, double y);  // x and y came from ui for generate distance
    QString dificality() const;
    double distance() const;
    void setDificality(const QString &newDificality);



    //////////////////////sending data

};

#endif // CPPGENERATOR_H
