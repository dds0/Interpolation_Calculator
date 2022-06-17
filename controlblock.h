#ifndef CONTROLBLOCK_H
#define CONTROLBLOCK_H
#include <QVector>
#include <map>
#include <QDebug>

class ControlBlock
{
public:
    explicit ControlBlock();

    void addSomePoint(double x, double y);
    QVector<double> getYvector() const;
    QVector<double> getXvector() const;
    size_t EnumPoints() const;
    void Clear();

    double AtX(size_t index) const;
    double AtY(size_t index) const;
    double getProection() const;

private:
    QVector<double> dataX,dataY;
    void SortXY();
    double minProection;
};

#endif // CONTROLBLOCK_H
