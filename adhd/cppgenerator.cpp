#include "cppgenerator.h"
#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>


void CppGenerator:: setDistance (double x, double y) //geting x and y from ui and give distance
{
    double reqAns = 0;
    std::vector<double> div;
    std::vector<std::pair<int , int >> m{{0,150},{120,100},{200,10},
                                       {250,46},{80,150},{200,109},
                                       {280,117},{302,90},{300,210},
                                       {150,205},{225,250},{246,229},
                                       {479,201},{459,93},{580,150}};;
    for (int i = 0; i < m.size() - 1; i++)
        {


    double ABF = m[i+1].first - m[i].first;
    double ABS = m[i+1].second - m[i].second;



    double BEF = x - m[i+1].first;
    double BES = y - m[i+1].second;



    double AEF = x - m[i].first;
    double AES = y - m[i].second;


    double AB_BE, AB_AE;


    AB_BE = (ABF * BEF + ABS * BES);
    AB_AE = (ABF * AEF + ABS * AES);


    if (AB_BE > 0) {


        double m_y = y - m[i+1].second;
        double m_x = x - m[i+1].first;
        reqAns = sqrt(m_x * m_x + m_y * m_y);
    }


    else if (AB_AE < 0) {
        double m_y = y - m[i].second;
        double m_x = x - m[i].first;
        reqAns = sqrt(m_x * m_x + m_y * m_y);
    }


    else {


        double m_x1 = ABF;
        double m_y1 = ABS;
        double m_x2 = AEF;
        double m_y2 = AES;
        double mod = sqrt(m_x1 * m_x1 + m_y1 * m_y1);
        reqAns = std::abs(m_x1 * m_y2 - m_y1 * m_x2) / mod;
    }
    div.emplace_back(reqAns);
   }
    auto min = std::min_element(div.begin(),div.end()); //min distance of all distaces in vector

    if (m_dificality=="easy"){   //enabel dificlity to algorithm
        m_distance = *min-6;
        if(m_distance<0)
            m_distance=0;
    }
    else if (m_dificality=="normal") {
        m_distance = *min-3;
        if(m_distance<0)
            m_distance=0;
    }
    else{
        m_distance = *min;
    }

}

QString CppGenerator::dificality() const
{
    return m_dificality;
}

double CppGenerator::distance() const
{
    return m_distance;
}

void CppGenerator::setDificality(const QString &newDificality)
{
    m_dificality = newDificality;
}

CppGenerator::CppGenerator()
{

}


