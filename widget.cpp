#include "widget.h"
#include "ui_widget.h"

enum idPlot
{
    PointLayer = 0,
    LagrangePlot = 1,
    BerrutPlot = 2
};

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    StartSetting();
    connect(ui->widget, SIGNAL(mousePress(QMouseEvent *)), this, SLOT(NewPoint(QMouseEvent *)));
    connect(ui->widget, SIGNAL(mouseMove(QMouseEvent*)), this,SLOT(showPointToolTip(QMouseEvent*)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::AddPoint(double x, double y)
{
    data.addSomePoint(x,y);
    calc.setStep(data.getProection()/10);
    CheckData();
}
void Widget::ClearData()
{
    ui->widget->graph(idPlot::LagrangePlot)->setData({},{});
    ui->widget->graph(idPlot::BerrutPlot)->setData({},{});
    ui->Import->setVisible(true);
    data.Clear();
    CheckData();
}

void Widget::plot()
{
    ui->widget->graph(idPlot::PointLayer)->setData(data.getXvector(),data.getYvector());
    ui->widget->replot();
    ui->widget->update();
}

void Widget::NewPoint(QMouseEvent *event)
{
    if (isWrite)
    {
        QPoint point = event->pos();
        AddPoint(ui->widget->xAxis->pixelToCoord(point.x()),ui->widget->yAxis->pixelToCoord(point.y()));
        qDebug() << ui->widget->xAxis->pixelToCoord(point.x())<<":"<<ui->widget->yAxis->pixelToCoord(point.y());
        this->plot();
    }
}

void Widget::showPointToolTip(QMouseEvent *event)
{

    double x = ui->widget->xAxis->pixelToCoord(event->pos().x());
    double y = ui->widget->yAxis->pixelToCoord(event->pos().y());
    ui->Coord->setText(QString("x: %1 , y: %2").arg(x,0,'d',3).arg(y,0,'d',3));
}


void Widget::SettingPlotForPen()
{
    ui->widget->setInteraction(QCP::iRangeZoom, false);
    ui->widget->setInteraction(QCP::iRangeDrag, false);
}
void Widget::SettingPlotForHand()
{
    ui->widget->setInteraction(QCP::iRangeZoom, true);
    ui->widget->setInteraction(QCP::iRangeDrag, true);
}

void Widget::StartSetting()
{
    ui->widget->addGraph(); //PointLayer
    ui->widget->addGraph(); //LagrangePlot
    ui->widget->addGraph(); //BerrutPlot
    ui->widget->graph(idPlot::PointLayer)->setPen(QPen(Qt::blue));
    ui->widget->graph(idPlot::LagrangePlot)->setPen(QPen(Qt::red));
    ui->widget->graph(idPlot::BerrutPlot)->setPen(QPen(Qt::black));
    ui->widget->graph(idPlot::PointLayer)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(idPlot::PointLayer)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->Solver->setVisible(false);
}

void Widget::CheckData()
{
    if (data.EnumPoints() >= 2)
    {
        ui->Solver->setVisible(true);
    }
    else
    {
        ui->Solver->setVisible(false);
    }

}

void Widget::on_pen_clicked()
{
    isWrite = true;
    this->SettingPlotForPen();
}


void Widget::on_hand_clicked()
{
    isWrite = false;
    this->SettingPlotForHand();
}


void Widget::on_Import_clicked()
{
    QString data;
    data = QFileDialog::getOpenFileName(this,"Choose file","test","Text files (*.txt);");
    std::ifstream file(data.toStdString());

    while (file.is_open())
    {
        std::string strForX, strForY;

        std::getline(file, strForX);
        std::getline(file, strForY);
        std::stringstream ssX,ssY;
        ssX << strForX;
        ssY << strForY;
        while(!ssX.eof())
        {
            double tempX,tempY;
            ssX>>tempX;
            ssY>>tempY;
            AddPoint(tempX,tempY);
        }
        CheckData();
        file.close();
    }
    plot();
}


void Widget::on_Clear_clicked()
{
    ClearData();
    plot();
}


void Widget::on_Solver_clicked()
{
    ui->Solver->setVisible(false);
    ui->Import->setVisible(false);

    std::pair<QVector<double>,QVector<double>> tempB = calc.SolveRationalFuncBerrut(data);
    ui->widget->graph(idPlot::BerrutPlot)->setData(tempB.first,tempB.second);

    std::pair<QVector<double>,QVector<double>> tempL = calc.SolveLagrangeMethod(data);
    ui->widget->graph(idPlot::LagrangePlot)->setData(tempL.first,tempL.second);

    if (isWarning) // need realize
    {
        QMessageBox::warning(this, "Be careful", "Hight risk of oscillation(Lagrange");
        isWarning = false;
    }

    ui->widget->replot();
    ui->widget->update();
}

