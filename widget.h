#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>
#include <QDebug>
#include <QFileDialog>
#include <QString>
#include <fstream>
#include <sstream>
#include <QMessageBox>
#include <QtAlgorithms>
#include "controlblock.h"
#include "interpolationcalc.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void AddPoint(double x, double y);
    void ClearData();
    void plot();

private slots:
    void NewPoint(QMouseEvent * event);
    void showPointToolTip(QMouseEvent *event);
    void on_pen_clicked();

    void on_hand_clicked();

    void on_Import_clicked();

    void on_Clear_clicked();

    void on_Solver_clicked();

private:
    Ui::Widget *ui;

    ControlBlock data;
    InterpolationCalc calc;

    void SettingPlotForPen();
    void SettingPlotForHand();
    void StartSetting();
    void CheckData();
    bool isWarning = false;
    bool isWrite = false;
};
#endif // WIDGET_H
