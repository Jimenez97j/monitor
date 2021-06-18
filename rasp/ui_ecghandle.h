/********************************************************************************
** Form generated from reading UI file 'ecghandle.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ECGHANDLE_H
#define UI_ECGHANDLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_ecghandle
{
public:
    QCustomPlot *plot_ecg;
    QWidget *borrargraph_ecg;

    void setupUi(QWidget *ecghandle)
    {
        if (ecghandle->objectName().isEmpty())
            ecghandle->setObjectName(QString::fromUtf8("ecghandle"));
        ecghandle->resize(1104, 310);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(252, 243, 243, 0));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        ecghandle->setPalette(palette);
        ecghandle->setAutoFillBackground(false);
        plot_ecg = new QCustomPlot(ecghandle);
        plot_ecg->setObjectName(QString::fromUtf8("plot_ecg"));
        plot_ecg->setGeometry(QRect(0, 0, 1101, 311));
        plot_ecg->setCursor(QCursor(Qt::BlankCursor));
        plot_ecg->setAutoFillBackground(true);
        borrargraph_ecg = new QWidget(plot_ecg);
        borrargraph_ecg->setObjectName(QString::fromUtf8("borrargraph_ecg"));
        borrargraph_ecg->setGeometry(QRect(0, 0, 21, 311));
        borrargraph_ecg->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        retranslateUi(ecghandle);

        QMetaObject::connectSlotsByName(ecghandle);
    } // setupUi

    void retranslateUi(QWidget *ecghandle)
    {
        ecghandle->setWindowTitle(QCoreApplication::translate("ecghandle", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ecghandle: public Ui_ecghandle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ECGHANDLE_H
