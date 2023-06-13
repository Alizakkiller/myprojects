#include "File.h"
#include "qdebug.h"

File::File()
{

}

void File::savevec(const QVector<double> &v, const QString &filename)// saving time and distance
{
    m_filename = filename;
    std::ofstream file(m_filename.toStdString());
    if(file.is_open()){
        for(const auto&item :v){
            file << item << ",";
        }
        file.close();
    }
}





