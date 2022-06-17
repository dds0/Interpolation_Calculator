#include "controlblock.h"

ControlBlock::ControlBlock()
{

}

void ControlBlock::addSomePoint(double x, double y)
{
    dataX.append(x);
    dataY.append(y);
    this->SortXY();
}

QVector<double> ControlBlock::getYvector() const
{
    return dataY;
}

QVector<double> ControlBlock::getXvector() const
{
    return dataX;
}

size_t ControlBlock::EnumPoints() const
{
    return dataX.size();
}

void ControlBlock::Clear()
{
    dataX.clear();
    dataY.clear();
}

double ControlBlock::AtX(size_t index) const
{
    return dataX[index];
}

double ControlBlock::AtY(size_t index) const
{
    return dataY[index];
}

double ControlBlock::getProection() const
{
    return minProection;
}

void ControlBlock::SortXY()
{
    std::map<double,double> map;
    size_t i;
    minProection = 0;
    double temp;
    for (i = 0; i < static_cast<size_t>(dataX.size()); ++i)
    {
        map.insert(std::make_pair(dataX[i],dataY[i]));
        temp = abs(abs(minProection) - abs(dataX[i]));
        if (minProection > temp)
            minProection = temp;
    }

    minProection = temp/dataX.size();
    qDebug()<<"MinProection"<<minProection;
    i = 0;

    for (const auto& s: map)
    {
        dataX[i] = s.first;
        dataY[i] = s.second;
        qDebug()<<"Point at coordinate "<<dataX[i]<<":"<<dataY[i];
        ++i;
    }
}
