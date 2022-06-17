#include "interpolationcalc.h"

InterpolationCalc::InterpolationCalc()
{

}

std::pair<QVector<double>, QVector<double> > InterpolationCalc::SolveLagrangeMethod(const ControlBlock &data)
{
    size_t last_index = data.getXvector().size() - 1, counter = 0;
    QVector<double> x,y;
    double xBegin = data.getXvector()[0] - step, xEnd = data.getXvector()[last_index] + step;
    while(xBegin < xEnd)
    {
        double yL = 0;

        while (counter != last_index + 1)
        {
            double chislitel = 1, znamenatel = 1;
            for (size_t i = 0; i < last_index + 1; ++i)
            {
                if (counter == i)
                    continue;

                chislitel*=(xBegin-data.AtX(i));
                znamenatel*=(data.AtX(counter)-data.AtX(i));
            }

            yL+=data.AtY(counter)*(chislitel/znamenatel);
            ++counter;
        }

        x.append(xBegin);
        y.append(yL);

        counter = 0;
        xBegin+=step;
    }


    return std::make_pair(x,y);
}

std::pair<QVector<double>,QVector<double>> InterpolationCalc::SolveRationalFuncBerrut(const ControlBlock &data)
{
    size_t last_index = data.getXvector().size() - 1, counter = 0;
    QVector<double> x,y;
    double xBegin = data.getXvector()[0] - step, xEnd = data.getXvector()[last_index] + step;

    while (xBegin < xEnd) {
        double chislitel = 0, znamenatel = 0;

        while(counter != last_index + 1)
        {
            double temp = 1;
            for (size_t i = 0; i < last_index + 1; ++i)
            {
                if (counter == i)
                    continue;

                temp*=(xBegin-data.AtX(i));
            }

            znamenatel += temp*qPow(-1,counter);
            chislitel += temp*data.AtY(counter)*qPow(-1,counter);
            ++counter;
        }

        x.append(xBegin);
        y.append(chislitel/znamenatel);

        counter = 0;
        xBegin+=step;
    }

    return std::make_pair(x,y);
}

void InterpolationCalc::setStep(double minProection)
{
    step = minProection;
}
