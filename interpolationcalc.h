#ifndef INTERPOLATIONCALC_H
#define INTERPOLATIONCALC_H
#include "controlblock.h"
#include <QtCore/qmath.h>
class InterpolationCalc
{
public:
    InterpolationCalc();

    std::pair<QVector<double>,QVector<double>> SolveLagrangeMethod(const ControlBlock& data);
    std::pair<QVector<double>,QVector<double>> SolveRationalFuncBerrut(const ControlBlock& data);
    void setStep(double minProection);

private:
    double step;
};

#endif // INTERPOLATIONCALC_H
