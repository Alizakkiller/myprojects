#ifndef FILE_H
#define FILE_H


#include <fstream>
#include <sstream>
#include <QVector>

class File
{
    QString m_filename;
public:
    File();
    void savevec(const QVector<double> &v,const QString &filename);


signals:

};

#endif // FILE_H
