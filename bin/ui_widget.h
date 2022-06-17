/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QCustomPlot *widget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *Coord;
    QGroupBox *Write_Watch_RBbox;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QRadioButton *pen;
    QRadioButton *hand;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QPushButton *Solver;
    QPushButton *Import;
    QPushButton *Clear;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(874, 624);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/bin/cos.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        widget = new QCustomPlot(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 20, 671, 591));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(500, 500));
        widget->setMaximumSize(QSize(1000, 1000));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(690, 20, 171, 591));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        Coord = new QLabel(layoutWidget);
        Coord->setObjectName(QString::fromUtf8("Coord"));

        verticalLayout_2->addWidget(Coord);

        Write_Watch_RBbox = new QGroupBox(layoutWidget);
        Write_Watch_RBbox->setObjectName(QString::fromUtf8("Write_Watch_RBbox"));
        horizontalLayout = new QHBoxLayout(Write_Watch_RBbox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pen = new QRadioButton(Write_Watch_RBbox);
        pen->setObjectName(QString::fromUtf8("pen"));

        verticalLayout->addWidget(pen);

        hand = new QRadioButton(Write_Watch_RBbox);
        hand->setObjectName(QString::fromUtf8("hand"));

        verticalLayout->addWidget(hand);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addWidget(Write_Watch_RBbox);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        Solver = new QPushButton(layoutWidget);
        Solver->setObjectName(QString::fromUtf8("Solver"));

        verticalLayout_2->addWidget(Solver);

        Import = new QPushButton(layoutWidget);
        Import->setObjectName(QString::fromUtf8("Import"));

        verticalLayout_2->addWidget(Import);

        Clear = new QPushButton(layoutWidget);
        Clear->setObjectName(QString::fromUtf8("Clear"));

        verticalLayout_2->addWidget(Clear);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        Coord->setText(QString());
        Write_Watch_RBbox->setTitle(QString());
        pen->setText(QCoreApplication::translate("Widget", "Pen", nullptr));
        hand->setText(QCoreApplication::translate("Widget", "Hand", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Lagrange(red)", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Berrut(black)", nullptr));
        Solver->setText(QCoreApplication::translate("Widget", "Solve", nullptr));
        Import->setText(QCoreApplication::translate("Widget", "Import(txt)", nullptr));
        Clear->setText(QCoreApplication::translate("Widget", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
