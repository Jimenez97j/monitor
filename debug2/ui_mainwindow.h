/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "ecghandle.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QCustomPlot *plot;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *bpmsp2_5;
    QLabel *bpmsp2_6;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_7;
    QWidget *color;
    QLabel *analisis;
    QWidget *ECGBLOCK;
    QLabel *bpm_ecg;
    QLabel *bpmsp2_3;
    QLabel *bpm_label_spo2_2;
    QLabel *bpmsp2;
    QLabel *bpm_label_spo2;
    QWidget *OXBLOCK;
    QLabel *SPO2;
    QLabel *bpmsp2_4;
    QLabel *bpmsp2_2;
    QWidget *TEMP;
    QWidget *PANI;
    QLabel *rpm;
    QLabel *rpm_label_2;
    QLabel *rpm_label;
    QWidget *DIAS;
    QLabel *pres_sis_label_2;
    QLabel *pres_sis_label_4;
    QLabel *pres_sis_2;
    QWidget *SYS;
    QLabel *pres_sis;
    QLabel *pres_sis_label;
    QLabel *pres_sis_label_3;
    QLabel *temp;
    QLabel *temp_label_2;
    QLabel *temp_label;
    QWidget *Barra;
    QToolButton *open_records;
    QToolButton *screenshot;
    QToolButton *galeria_open;
    QToolButton *alarmas;
    QToolButton *iniciarpani;
    QToolButton *derivaciones;
    QToolButton *registro_usuario;
    QToolButton *Paciente;
    QToolButton *modelo2;
    QToolButton *ajustes;
    QLabel *fh;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QWidget *borrargraph;
    ecghandle *ecg;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(1290, 800);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        MainWindow->setPalette(palette);
        MainWindow->setCursor(QCursor(Qt::BlankCursor));
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setCursor(QCursor(Qt::BlankCursor));
        plot = new QCustomPlot(centralwidget);
        plot->setObjectName(QString::fromUtf8("plot"));
        plot->setGeometry(QRect(30, 390, 1071, 281));
        plot->setCursor(QCursor(Qt::BlankCursor));
        plot->setAcceptDrops(false);
        plot->setAutoFillBackground(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 40, 16, 291));
        label_2->setCursor(QCursor(Qt::BlankCursor));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/Corchete Rojo.png")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 390, 16, 281));
        label_3->setCursor(QCursor(Qt::BlankCursor));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/Corchete Verde.png")));
        label_3->setScaledContents(true);
        bpmsp2_5 = new QLabel(centralwidget);
        bpmsp2_5->setObjectName(QString::fromUtf8("bpmsp2_5"));
        bpmsp2_5->setGeometry(QRect(20, 10, 91, 20));
        QPalette palette1;
        QBrush brush1(QColor(239, 41, 41, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush2(QColor(204, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        QBrush brush3(QColor(204, 0, 0, 128));
        brush3.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        QBrush brush4(QColor(204, 0, 0, 128));
        brush4.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        QBrush brush5(QColor(190, 190, 190, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        QBrush brush6(QColor(204, 0, 0, 128));
        brush6.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        bpmsp2_5->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        bpmsp2_5->setFont(font);
        bpmsp2_5->setCursor(QCursor(Qt::BlankCursor));
        bpmsp2_6 = new QLabel(centralwidget);
        bpmsp2_6->setObjectName(QString::fromUtf8("bpmsp2_6"));
        bpmsp2_6->setGeometry(QRect(20, 350, 91, 20));
        QPalette palette2;
        QBrush brush7(QColor(11, 149, 33, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush2);
        QBrush brush8(QColor(204, 0, 0, 128));
        brush8.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        QBrush brush9(QColor(204, 0, 0, 128));
        brush9.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        QBrush brush10(QColor(204, 0, 0, 128));
        brush10.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        bpmsp2_6->setPalette(palette2);
        bpmsp2_6->setFont(font);
        bpmsp2_6->setCursor(QCursor(Qt::BlankCursor));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(320, 10, 211, 17));
        QPalette palette3;
        QBrush brush11(QColor(32, 74, 135, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush11);
        QBrush brush12(QColor(32, 74, 135, 128));
        brush12.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush12);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush11);
        QBrush brush13(QColor(32, 74, 135, 128));
        brush13.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush13);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        QBrush brush14(QColor(32, 74, 135, 128));
        brush14.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush14);
#endif
        label_6->setPalette(palette3);
        QFont font1;
        font1.setPointSize(8);
        label_6->setFont(font1);
        label_6->setCursor(QCursor(Qt::BlankCursor));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(200, 10, 381, 20));
        label_5->setCursor(QCursor(Qt::BlankCursor));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(200, -1, 381, 31));
        label_7->setCursor(QCursor(Qt::BlankCursor));
        color = new QWidget(centralwidget);
        color->setObjectName(QString::fromUtf8("color"));
        color->setGeometry(QRect(0, 0, 1291, 691));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Base, brush);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush);
        color->setPalette(palette4);
        color->setCursor(QCursor(Qt::ArrowCursor));
        analisis = new QLabel(color);
        analisis->setObjectName(QString::fromUtf8("analisis"));
        analisis->setGeometry(QRect(50, 413, 181, 21));
        QPalette palette5;
        QBrush brush15(QColor(61, 222, 199, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush15);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush15);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        analisis->setPalette(palette5);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        analisis->setFont(font2);
        analisis->setCursor(QCursor(Qt::BlankCursor));
        ECGBLOCK = new QWidget(color);
        ECGBLOCK->setObjectName(QString::fromUtf8("ECGBLOCK"));
        ECGBLOCK->setGeometry(QRect(1120, 20, 151, 91));
        ECGBLOCK->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"border-style: outset;\n"
"\n"
"border-width: 2px;\n"
"\n"
"border-color: white;\n"
""));
        bpm_ecg = new QLabel(ECGBLOCK);
        bpm_ecg->setObjectName(QString::fromUtf8("bpm_ecg"));
        bpm_ecg->setGeometry(QRect(10, 7, 101, 61));
        QPalette palette6;
        QBrush brush16(QColor(255, 0, 0, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush16);
        QBrush brush17(QColor(191, 64, 64, 0));
        brush17.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush17);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush17);
        QBrush brush18(QColor(204, 0, 0, 128));
        brush18.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush18);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush16);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush17);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        QBrush brush19(QColor(204, 0, 0, 128));
        brush19.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush19);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        QBrush brush20(QColor(204, 0, 0, 128));
        brush20.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush20);
#endif
        bpm_ecg->setPalette(palette6);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font3.setPointSize(59);
        font3.setBold(true);
        font3.setWeight(75);
        bpm_ecg->setFont(font3);
        bpm_ecg->setCursor(QCursor(Qt::BlankCursor));
        bpm_ecg->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        bpmsp2_3 = new QLabel(ECGBLOCK);
        bpmsp2_3->setObjectName(QString::fromUtf8("bpmsp2_3"));
        bpmsp2_3->setGeometry(QRect(110, 10, 31, 16));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush16);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush17);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush17);
        QBrush brush21(QColor(204, 0, 0, 128));
        brush21.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush21);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush16);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush17);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        QBrush brush22(QColor(204, 0, 0, 128));
        brush22.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush22);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        QBrush brush23(QColor(204, 0, 0, 128));
        brush23.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush23);
#endif
        bpmsp2_3->setPalette(palette7);
        bpmsp2_3->setFont(font2);
        bpmsp2_3->setCursor(QCursor(Qt::BlankCursor));
        bpmsp2_3->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        bpm_label_spo2_2 = new QLabel(ECGBLOCK);
        bpm_label_spo2_2->setObjectName(QString::fromUtf8("bpm_label_spo2_2"));
        bpm_label_spo2_2->setGeometry(QRect(110, 67, 31, 16));
        QPalette palette8;
        QBrush brush24(QColor(89, 255, 242, 255));
        brush24.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush24);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush17);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush17);
        QBrush brush25(QColor(204, 0, 0, 128));
        brush25.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush25);
#endif
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush24);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush17);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        QBrush brush26(QColor(204, 0, 0, 128));
        brush26.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush26);
#endif
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        QBrush brush27(QColor(204, 0, 0, 128));
        brush27.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush27);
#endif
        bpm_label_spo2_2->setPalette(palette8);
        bpm_label_spo2_2->setFont(font2);
        bpm_label_spo2_2->setCursor(QCursor(Qt::BlankCursor));
        bpm_label_spo2_2->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        bpmsp2 = new QLabel(ECGBLOCK);
        bpmsp2->setObjectName(QString::fromUtf8("bpmsp2"));
        bpmsp2->setGeometry(QRect(70, 60, 41, 21));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush24);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush17);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush17);
        QBrush brush28(QColor(204, 0, 0, 128));
        brush28.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Active, QPalette::PlaceholderText, brush28);
#endif
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush24);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush17);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        QBrush brush29(QColor(204, 0, 0, 128));
        brush29.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush29);
#endif
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        QBrush brush30(QColor(204, 0, 0, 128));
        brush30.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush30);
#endif
        bpmsp2->setPalette(palette9);
        QFont font4;
        font4.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font4.setPointSize(19);
        font4.setBold(true);
        font4.setWeight(75);
        bpmsp2->setFont(font4);
        bpmsp2->setCursor(QCursor(Qt::BlankCursor));
        bpmsp2->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        bpm_label_spo2 = new QLabel(ECGBLOCK);
        bpm_label_spo2->setObjectName(QString::fromUtf8("bpm_label_spo2"));
        bpm_label_spo2->setGeometry(QRect(110, 55, 41, 16));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush24);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush17);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush17);
        QBrush brush31(QColor(204, 0, 0, 128));
        brush31.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Active, QPalette::PlaceholderText, brush31);
#endif
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush24);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush17);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        QBrush brush32(QColor(204, 0, 0, 128));
        brush32.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush32);
#endif
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        QBrush brush33(QColor(204, 0, 0, 128));
        brush33.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush33);
#endif
        bpm_label_spo2->setPalette(palette10);
        QFont font5;
        font5.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font5.setPointSize(10);
        font5.setBold(true);
        font5.setWeight(75);
        bpm_label_spo2->setFont(font5);
        bpm_label_spo2->setCursor(QCursor(Qt::BlankCursor));
        bpm_label_spo2->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        OXBLOCK = new QWidget(color);
        OXBLOCK->setObjectName(QString::fromUtf8("OXBLOCK"));
        OXBLOCK->setGeometry(QRect(1120, 150, 151, 71));
        OXBLOCK->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"border-style: outset;\n"
"\n"
"border-width: 2px;\n"
"\n"
"border-color: white;"));
        SPO2 = new QLabel(OXBLOCK);
        SPO2->setObjectName(QString::fromUtf8("SPO2"));
        SPO2->setGeometry(QRect(10, 10, 111, 51));
        QPalette palette11;
        QBrush brush34(QColor(22, 255, 23, 255));
        brush34.setStyle(Qt::SolidPattern);
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush34);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush17);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush17);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush34);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush17);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        SPO2->setPalette(palette11);
        QFont font6;
        font6.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font6.setPointSize(46);
        font6.setBold(true);
        font6.setWeight(75);
        SPO2->setFont(font6);
        SPO2->setCursor(QCursor(Qt::BlankCursor));
        SPO2->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        bpmsp2_4 = new QLabel(OXBLOCK);
        bpmsp2_4->setObjectName(QString::fromUtf8("bpmsp2_4"));
        bpmsp2_4->setGeometry(QRect(110, 20, 51, 20));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush34);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush17);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush17);
        QBrush brush35(QColor(204, 0, 0, 128));
        brush35.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Active, QPalette::PlaceholderText, brush35);
#endif
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush34);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush17);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        QBrush brush36(QColor(204, 0, 0, 128));
        brush36.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush36);
#endif
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        QBrush brush37(QColor(204, 0, 0, 128));
        brush37.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush37);
#endif
        bpmsp2_4->setPalette(palette12);
        bpmsp2_4->setFont(font2);
        bpmsp2_4->setCursor(QCursor(Qt::BlankCursor));
        bpmsp2_4->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        bpmsp2_2 = new QLabel(OXBLOCK);
        bpmsp2_2->setObjectName(QString::fromUtf8("bpmsp2_2"));
        bpmsp2_2->setGeometry(QRect(120, 30, 31, 31));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush34);
        palette13.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush17);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush17);
        QBrush brush38(QColor(204, 0, 0, 128));
        brush38.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Active, QPalette::PlaceholderText, brush38);
#endif
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush34);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush17);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        QBrush brush39(QColor(204, 0, 0, 128));
        brush39.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush39);
#endif
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        QBrush brush40(QColor(204, 0, 0, 128));
        brush40.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush40);
#endif
        bpmsp2_2->setPalette(palette13);
        QFont font7;
        font7.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font7.setPointSize(14);
        font7.setBold(true);
        font7.setWeight(75);
        bpmsp2_2->setFont(font7);
        bpmsp2_2->setCursor(QCursor(Qt::BlankCursor));
        bpmsp2_2->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        TEMP = new QWidget(color);
        TEMP->setObjectName(QString::fromUtf8("TEMP"));
        TEMP->setGeometry(QRect(1120, 260, 151, 71));
        TEMP->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"border-style: outset;\n"
"\n"
"border-width: 2px;\n"
"\n"
"border-color: white;"));
        PANI = new QWidget(color);
        PANI->setObjectName(QString::fromUtf8("PANI"));
        PANI->setGeometry(QRect(1120, 370, 151, 71));
        PANI->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"border-style: outset;\n"
"\n"
"border-width: 2px;\n"
"\n"
"border-color: white;"));
        rpm = new QLabel(PANI);
        rpm->setObjectName(QString::fromUtf8("rpm"));
        rpm->setGeometry(QRect(10, 10, 91, 51));
        QPalette palette14;
        QBrush brush41(QColor(237, 212, 0, 255));
        brush41.setStyle(Qt::SolidPattern);
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush41);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush17);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush17);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush41);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush17);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        rpm->setPalette(palette14);
        QFont font8;
        font8.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font8.setPointSize(36);
        font8.setBold(true);
        font8.setWeight(75);
        rpm->setFont(font8);
        rpm->setCursor(QCursor(Qt::BlankCursor));
        rpm->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        rpm_label_2 = new QLabel(PANI);
        rpm_label_2->setObjectName(QString::fromUtf8("rpm_label_2"));
        rpm_label_2->setGeometry(QRect(100, 20, 31, 20));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush41);
        palette15.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette15.setBrush(QPalette::Active, QPalette::Base, brush17);
        palette15.setBrush(QPalette::Active, QPalette::Window, brush17);
        QBrush brush42(QColor(204, 0, 0, 128));
        brush42.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Active, QPalette::PlaceholderText, brush42);
#endif
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush41);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette15.setBrush(QPalette::Inactive, QPalette::Base, brush17);
        palette15.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        QBrush brush43(QColor(204, 0, 0, 128));
        brush43.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush43);
#endif
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette15.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        QBrush brush44(QColor(204, 0, 0, 128));
        brush44.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush44);
#endif
        rpm_label_2->setPalette(palette15);
        rpm_label_2->setFont(font2);
        rpm_label_2->setCursor(QCursor(Qt::BlankCursor));
        rpm_label_2->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        rpm_label = new QLabel(PANI);
        rpm_label->setObjectName(QString::fromUtf8("rpm_label"));
        rpm_label->setGeometry(QRect(100, 40, 41, 16));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush41);
        palette16.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette16.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette16.setBrush(QPalette::Active, QPalette::Base, brush17);
        palette16.setBrush(QPalette::Active, QPalette::Window, brush17);
        QBrush brush45(QColor(204, 0, 0, 128));
        brush45.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Active, QPalette::PlaceholderText, brush45);
#endif
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush41);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette16.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette16.setBrush(QPalette::Inactive, QPalette::Base, brush17);
        palette16.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        QBrush brush46(QColor(204, 0, 0, 128));
        brush46.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush46);
#endif
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette16.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette16.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette16.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        QBrush brush47(QColor(204, 0, 0, 128));
        brush47.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush47);
#endif
        rpm_label->setPalette(palette16);
        rpm_label->setFont(font2);
        rpm_label->setCursor(QCursor(Qt::BlankCursor));
        rpm_label->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        DIAS = new QWidget(color);
        DIAS->setObjectName(QString::fromUtf8("DIAS"));
        DIAS->setGeometry(QRect(1120, 580, 151, 71));
        DIAS->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"border-style: outset;\n"
"\n"
"border-width: 2px;\n"
"\n"
"border-color: white;"));
        pres_sis_label_2 = new QLabel(DIAS);
        pres_sis_label_2->setObjectName(QString::fromUtf8("pres_sis_label_2"));
        pres_sis_label_2->setGeometry(QRect(100, 20, 31, 16));
        QPalette palette17;
        QBrush brush48(QColor(255, 29, 225, 255));
        brush48.setStyle(Qt::SolidPattern);
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush48);
        palette17.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette17.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette17.setBrush(QPalette::Active, QPalette::Base, brush17);
        palette17.setBrush(QPalette::Active, QPalette::Window, brush17);
        QBrush brush49(QColor(204, 0, 0, 128));
        brush49.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Active, QPalette::PlaceholderText, brush49);
#endif
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush48);
        palette17.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette17.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette17.setBrush(QPalette::Inactive, QPalette::Base, brush17);
        palette17.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        QBrush brush50(QColor(204, 0, 0, 128));
        brush50.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush50);
#endif
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette17.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette17.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette17.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette17.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        QBrush brush51(QColor(204, 0, 0, 128));
        brush51.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush51);
#endif
        pres_sis_label_2->setPalette(palette17);
        pres_sis_label_2->setFont(font2);
        pres_sis_label_2->setCursor(QCursor(Qt::BlankCursor));
        pres_sis_label_2->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        pres_sis_label_4 = new QLabel(DIAS);
        pres_sis_label_4->setObjectName(QString::fromUtf8("pres_sis_label_4"));
        pres_sis_label_4->setGeometry(QRect(100, 40, 41, 16));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::WindowText, brush48);
        palette18.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette18.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette18.setBrush(QPalette::Active, QPalette::Base, brush17);
        palette18.setBrush(QPalette::Active, QPalette::Window, brush17);
        QBrush brush52(QColor(204, 0, 0, 128));
        brush52.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette18.setBrush(QPalette::Active, QPalette::PlaceholderText, brush52);
#endif
        palette18.setBrush(QPalette::Inactive, QPalette::WindowText, brush48);
        palette18.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette18.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette18.setBrush(QPalette::Inactive, QPalette::Base, brush17);
        palette18.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        QBrush brush53(QColor(204, 0, 0, 128));
        brush53.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette18.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush53);
#endif
        palette18.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette18.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette18.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette18.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette18.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        QBrush brush54(QColor(204, 0, 0, 128));
        brush54.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette18.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush54);
#endif
        pres_sis_label_4->setPalette(palette18);
        pres_sis_label_4->setFont(font2);
        pres_sis_label_4->setCursor(QCursor(Qt::BlankCursor));
        pres_sis_label_4->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        pres_sis_2 = new QLabel(DIAS);
        pres_sis_2->setObjectName(QString::fromUtf8("pres_sis_2"));
        pres_sis_2->setGeometry(QRect(10, 10, 91, 51));
        QPalette palette19;
        palette19.setBrush(QPalette::Active, QPalette::WindowText, brush48);
        palette19.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette19.setBrush(QPalette::Active, QPalette::Base, brush17);
        palette19.setBrush(QPalette::Active, QPalette::Window, brush17);
        palette19.setBrush(QPalette::Inactive, QPalette::WindowText, brush48);
        palette19.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette19.setBrush(QPalette::Inactive, QPalette::Base, brush17);
        palette19.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        palette19.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette19.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette19.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette19.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        pres_sis_2->setPalette(palette19);
        pres_sis_2->setFont(font8);
        pres_sis_2->setCursor(QCursor(Qt::BlankCursor));
        pres_sis_2->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        SYS = new QWidget(color);
        SYS->setObjectName(QString::fromUtf8("SYS"));
        SYS->setGeometry(QRect(1120, 480, 151, 63));
        QPalette palette20;
        QBrush brush55(QColor(0, 0, 0, 255));
        brush55.setStyle(Qt::SolidPattern);
        palette20.setBrush(QPalette::Active, QPalette::Button, brush55);
        palette20.setBrush(QPalette::Active, QPalette::Base, brush55);
        palette20.setBrush(QPalette::Active, QPalette::Window, brush55);
        palette20.setBrush(QPalette::Inactive, QPalette::Button, brush55);
        palette20.setBrush(QPalette::Inactive, QPalette::Base, brush55);
        palette20.setBrush(QPalette::Inactive, QPalette::Window, brush55);
        palette20.setBrush(QPalette::Disabled, QPalette::Button, brush55);
        palette20.setBrush(QPalette::Disabled, QPalette::Base, brush55);
        palette20.setBrush(QPalette::Disabled, QPalette::Window, brush55);
        SYS->setPalette(palette20);
        SYS->setStyleSheet(QString::fromUtf8("background-color: black;\n"
"border-style: outset;\n"
"\n"
"border-width: 2px;\n"
"\n"
"border-color: white;"));
        pres_sis = new QLabel(SYS);
        pres_sis->setObjectName(QString::fromUtf8("pres_sis"));
        pres_sis->setGeometry(QRect(10, 10, 91, 51));
        QPalette palette21;
        palette21.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette21.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette21.setBrush(QPalette::Active, QPalette::Base, brush17);
        palette21.setBrush(QPalette::Active, QPalette::Window, brush17);
        palette21.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette21.setBrush(QPalette::Inactive, QPalette::Base, brush17);
        palette21.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        palette21.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette21.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette21.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette21.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        pres_sis->setPalette(palette21);
        pres_sis->setFont(font8);
        pres_sis->setCursor(QCursor(Qt::BlankCursor));
        pres_sis->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        pres_sis_label = new QLabel(SYS);
        pres_sis_label->setObjectName(QString::fromUtf8("pres_sis_label"));
        pres_sis_label->setGeometry(QRect(100, 30, 41, 20));
        QPalette palette22;
        palette22.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette22.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette22.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette22.setBrush(QPalette::Active, QPalette::Base, brush17);
        palette22.setBrush(QPalette::Active, QPalette::Window, brush17);
        QBrush brush56(QColor(204, 0, 0, 128));
        brush56.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette22.setBrush(QPalette::Active, QPalette::PlaceholderText, brush56);
#endif
        palette22.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette22.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette22.setBrush(QPalette::Inactive, QPalette::Base, brush17);
        palette22.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        QBrush brush57(QColor(204, 0, 0, 128));
        brush57.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette22.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush57);
#endif
        palette22.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette22.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette22.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette22.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette22.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        QBrush brush58(QColor(204, 0, 0, 128));
        brush58.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette22.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush58);
#endif
        pres_sis_label->setPalette(palette22);
        pres_sis_label->setFont(font2);
        pres_sis_label->setCursor(QCursor(Qt::BlankCursor));
        pres_sis_label->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        pres_sis_label_3 = new QLabel(SYS);
        pres_sis_label_3->setObjectName(QString::fromUtf8("pres_sis_label_3"));
        pres_sis_label_3->setGeometry(QRect(100, 10, 21, 16));
        QPalette palette23;
        palette23.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette23.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette23.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette23.setBrush(QPalette::Active, QPalette::Base, brush17);
        palette23.setBrush(QPalette::Active, QPalette::Window, brush17);
        QBrush brush59(QColor(204, 0, 0, 128));
        brush59.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette23.setBrush(QPalette::Active, QPalette::PlaceholderText, brush59);
#endif
        palette23.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette23.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette23.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette23.setBrush(QPalette::Inactive, QPalette::Base, brush17);
        palette23.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        QBrush brush60(QColor(204, 0, 0, 128));
        brush60.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette23.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush60);
#endif
        palette23.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette23.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette23.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette23.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette23.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        QBrush brush61(QColor(204, 0, 0, 128));
        brush61.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette23.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush61);
#endif
        pres_sis_label_3->setPalette(palette23);
        pres_sis_label_3->setFont(font2);
        pres_sis_label_3->setCursor(QCursor(Qt::BlankCursor));
        pres_sis_label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        temp = new QLabel(color);
        temp->setObjectName(QString::fromUtf8("temp"));
        temp->setGeometry(QRect(1122, 273, 101, 51));
        QPalette palette24;
        QBrush brush62(QColor(0, 150, 210, 255));
        brush62.setStyle(Qt::SolidPattern);
        palette24.setBrush(QPalette::Active, QPalette::WindowText, brush62);
        palette24.setBrush(QPalette::Inactive, QPalette::WindowText, brush62);
        palette24.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        temp->setPalette(palette24);
        temp->setFont(font8);
        temp->setCursor(QCursor(Qt::BlankCursor));
        temp_label_2 = new QLabel(color);
        temp_label_2->setObjectName(QString::fromUtf8("temp_label_2"));
        temp_label_2->setGeometry(QRect(1222, 280, 41, 16));
        QPalette palette25;
        palette25.setBrush(QPalette::Active, QPalette::WindowText, brush62);
        palette25.setBrush(QPalette::Active, QPalette::Text, brush2);
        QBrush brush63(QColor(204, 0, 0, 128));
        brush63.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette25.setBrush(QPalette::Active, QPalette::PlaceholderText, brush63);
#endif
        palette25.setBrush(QPalette::Inactive, QPalette::WindowText, brush62);
        palette25.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        QBrush brush64(QColor(204, 0, 0, 128));
        brush64.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette25.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush64);
#endif
        palette25.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette25.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        QBrush brush65(QColor(204, 0, 0, 128));
        brush65.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette25.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush65);
#endif
        temp_label_2->setPalette(palette25);
        temp_label_2->setFont(font2);
        temp_label_2->setCursor(QCursor(Qt::BlankCursor));
        temp_label = new QLabel(color);
        temp_label->setObjectName(QString::fromUtf8("temp_label"));
        temp_label->setGeometry(QRect(1222, 300, 20, 16));
        QPalette palette26;
        palette26.setBrush(QPalette::Active, QPalette::WindowText, brush62);
        palette26.setBrush(QPalette::Active, QPalette::Text, brush2);
        QBrush brush66(QColor(204, 0, 0, 128));
        brush66.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette26.setBrush(QPalette::Active, QPalette::PlaceholderText, brush66);
#endif
        palette26.setBrush(QPalette::Inactive, QPalette::WindowText, brush62);
        palette26.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        QBrush brush67(QColor(204, 0, 0, 128));
        brush67.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette26.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush67);
#endif
        palette26.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette26.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        QBrush brush68(QColor(204, 0, 0, 128));
        brush68.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette26.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush68);
#endif
        temp_label->setPalette(palette26);
        temp_label->setFont(font2);
        temp_label->setCursor(QCursor(Qt::BlankCursor));
        Barra = new QWidget(centralwidget);
        Barra->setObjectName(QString::fromUtf8("Barra"));
        Barra->setGeometry(QRect(0, 690, 1291, 131));
        Barra->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"  border:none\n"
""));
        open_records = new QToolButton(Barra);
        open_records->setObjectName(QString::fromUtf8("open_records"));
        open_records->setGeometry(QRect(3, 10, 90, 90));
        open_records->setCursor(QCursor(Qt::BlankCursor));
        open_records->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagenes/btn_Credencial.png"), QSize(), QIcon::Normal, QIcon::Off);
        open_records->setIcon(icon);
        open_records->setIconSize(QSize(90, 90));
        screenshot = new QToolButton(Barra);
        screenshot->setObjectName(QString::fromUtf8("screenshot"));
        screenshot->setGeometry(QRect(103, 10, 90, 90));
        screenshot->setCursor(QCursor(Qt::BlankCursor));
        screenshot->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imagenes/btn_Foto.png"), QSize(), QIcon::Normal, QIcon::Off);
        screenshot->setIcon(icon1);
        screenshot->setIconSize(QSize(90, 90));
        galeria_open = new QToolButton(Barra);
        galeria_open->setObjectName(QString::fromUtf8("galeria_open"));
        galeria_open->setGeometry(QRect(203, 10, 90, 90));
        galeria_open->setCursor(QCursor(Qt::BlankCursor));
        galeria_open->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imagenes/btn_Galeria.png"), QSize(), QIcon::Normal, QIcon::Off);
        galeria_open->setIcon(icon2);
        galeria_open->setIconSize(QSize(90, 90));
        galeria_open->setAutoRaise(false);
        alarmas = new QToolButton(Barra);
        alarmas->setObjectName(QString::fromUtf8("alarmas"));
        alarmas->setGeometry(QRect(303, 10, 90, 90));
        alarmas->setCursor(QCursor(Qt::BlankCursor));
        alarmas->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imagenes/btn_Alarma.png"), QSize(), QIcon::Normal, QIcon::Off);
        alarmas->setIcon(icon3);
        alarmas->setIconSize(QSize(90, 90));
        iniciarpani = new QToolButton(Barra);
        iniciarpani->setObjectName(QString::fromUtf8("iniciarpani"));
        iniciarpani->setGeometry(QRect(403, 10, 90, 90));
        iniciarpani->setCursor(QCursor(Qt::BlankCursor));
        iniciarpani->setStyleSheet(QString::fromUtf8(""));
        iniciarpani->setIconSize(QSize(90, 90));
        derivaciones = new QToolButton(Barra);
        derivaciones->setObjectName(QString::fromUtf8("derivaciones"));
        derivaciones->setGeometry(QRect(503, 10, 90, 90));
        derivaciones->setCursor(QCursor(Qt::BlankCursor));
        derivaciones->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/imagenes/btn_Pulso.png"), QSize(), QIcon::Normal, QIcon::Off);
        derivaciones->setIcon(icon4);
        derivaciones->setIconSize(QSize(90, 90));
        registro_usuario = new QToolButton(Barra);
        registro_usuario->setObjectName(QString::fromUtf8("registro_usuario"));
        registro_usuario->setGeometry(QRect(603, 10, 90, 90));
        registro_usuario->setCursor(QCursor(Qt::BlankCursor));
        registro_usuario->setStyleSheet(QString::fromUtf8(""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/imagenes/btn_Registro.png"), QSize(), QIcon::Normal, QIcon::Off);
        registro_usuario->setIcon(icon5);
        registro_usuario->setIconSize(QSize(90, 90));
        Paciente = new QToolButton(Barra);
        Paciente->setObjectName(QString::fromUtf8("Paciente"));
        Paciente->setGeometry(QRect(703, 10, 90, 90));
        Paciente->setCursor(QCursor(Qt::BlankCursor));
        Paciente->setStyleSheet(QString::fromUtf8(""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/imagenes/btn_Paciente.png"), QSize(), QIcon::Normal, QIcon::Off);
        Paciente->setIcon(icon6);
        Paciente->setIconSize(QSize(90, 90));
        modelo2 = new QToolButton(Barra);
        modelo2->setObjectName(QString::fromUtf8("modelo2"));
        modelo2->setGeometry(QRect(803, 10, 90, 90));
        modelo2->setCursor(QCursor(Qt::BlankCursor));
        modelo2->setStyleSheet(QString::fromUtf8(""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/imagenes/btn_GraficaNO.png"), QSize(), QIcon::Normal, QIcon::Off);
        modelo2->setIcon(icon7);
        modelo2->setIconSize(QSize(90, 90));
        ajustes = new QToolButton(Barra);
        ajustes->setObjectName(QString::fromUtf8("ajustes"));
        ajustes->setGeometry(QRect(1003, 10, 90, 90));
        ajustes->setCursor(QCursor(Qt::BlankCursor));
        ajustes->setStyleSheet(QString::fromUtf8(""));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/imagenes/btn_Config.png"), QSize(), QIcon::Normal, QIcon::Off);
        ajustes->setIcon(icon8);
        ajustes->setIconSize(QSize(90, 90));
        fh = new QLabel(Barra);
        fh->setObjectName(QString::fromUtf8("fh"));
        fh->setGeometry(QRect(1200, 40, 81, 41));
        QPalette palette27;
        palette27.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette27.setBrush(QPalette::Active, QPalette::Button, brush55);
        palette27.setBrush(QPalette::Active, QPalette::Base, brush55);
        palette27.setBrush(QPalette::Active, QPalette::Window, brush55);
        palette27.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::Button, brush55);
        palette27.setBrush(QPalette::Inactive, QPalette::Base, brush55);
        palette27.setBrush(QPalette::Inactive, QPalette::Window, brush55);
        palette27.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette27.setBrush(QPalette::Disabled, QPalette::Button, brush55);
        palette27.setBrush(QPalette::Disabled, QPalette::Base, brush55);
        palette27.setBrush(QPalette::Disabled, QPalette::Window, brush55);
        fh->setPalette(palette27);
        QFont font9;
        font9.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font9.setPointSize(13);
        font9.setBold(true);
        font9.setWeight(75);
        fh->setFont(font9);
        fh->setCursor(QCursor(Qt::BlankCursor));
        fh->setLayoutDirection(Qt::LeftToRight);
        fh->setStyleSheet(QString::fromUtf8(" qproperty-alignment: AlignCenter;"));
        toolButton = new QToolButton(Barra);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(903, 10, 90, 90));
        toolButton->setCursor(QCursor(Qt::BlankCursor));
        toolButton->setIconSize(QSize(90, 90));
        toolButton->setCheckable(false);
        toolButton_2 = new QToolButton(Barra);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(1103, 10, 90, 90));
        toolButton_2->setStyleSheet(QString::fromUtf8(""));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/imagenes/btn_Internet.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon9);
        toolButton_2->setIconSize(QSize(90, 90));
        borrargraph = new QWidget(centralwidget);
        borrargraph->setObjectName(QString::fromUtf8("borrargraph"));
        borrargraph->setGeometry(QRect(30, 390, 21, 281));
        borrargraph->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        ecg = new ecghandle(centralwidget);
        ecg->setObjectName(QString::fromUtf8("ecg"));
        ecg->setGeometry(QRect(30, 30, 1071, 301));
        ecg->setAutoFillBackground(false);
        MainWindow->setCentralWidget(centralwidget);
        color->raise();
        plot->raise();
        label_2->raise();
        label_3->raise();
        bpmsp2_5->raise();
        bpmsp2_6->raise();
        label_6->raise();
        label_5->raise();
        label_7->raise();
        Barra->raise();
        borrargraph->raise();
        ecg->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        bpmsp2_5->setText(QCoreApplication::translate("MainWindow", "ECG", nullptr));
        bpmsp2_6->setText(QCoreApplication::translate("MainWindow", "PLETH", nullptr));
        label_6->setText(QString());
        label_5->setText(QString());
        label_7->setText(QString());
        analisis->setText(QString());
        bpm_ecg->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        bpmsp2_3->setText(QCoreApplication::translate("MainWindow", "BPM", nullptr));
        bpm_label_spo2_2->setText(QCoreApplication::translate("MainWindow", "SpO2", nullptr));
        bpmsp2->setText(QCoreApplication::translate("MainWindow", " --", nullptr));
        bpm_label_spo2->setText(QCoreApplication::translate("MainWindow", "Fuente", nullptr));
        SPO2->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        bpmsp2_4->setText(QCoreApplication::translate("MainWindow", "SpO2", nullptr));
        bpmsp2_2->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        rpm->setText(QCoreApplication::translate("MainWindow", " --", nullptr));
        rpm_label_2->setText(QCoreApplication::translate("MainWindow", "PANI", nullptr));
        rpm_label->setText(QCoreApplication::translate("MainWindow", "Media", nullptr));
        pres_sis_label_2->setText(QCoreApplication::translate("MainWindow", "Dia.", nullptr));
        pres_sis_label_4->setText(QCoreApplication::translate("MainWindow", "mmHg", nullptr));
        pres_sis_2->setText(QCoreApplication::translate("MainWindow", " --", nullptr));
        pres_sis->setText(QCoreApplication::translate("MainWindow", " --", nullptr));
        pres_sis_label->setText(QCoreApplication::translate("MainWindow", "mmHg", nullptr));
        pres_sis_label_3->setText(QCoreApplication::translate("MainWindow", "Sys.", nullptr));
        temp->setText(QCoreApplication::translate("MainWindow", "  --", nullptr));
        temp_label_2->setText(QCoreApplication::translate("MainWindow", "Temp", nullptr));
        temp_label->setText(QCoreApplication::translate("MainWindow", "C\302\260", nullptr));
        open_records->setText(QString());
        screenshot->setText(QString());
        galeria_open->setText(QString());
        alarmas->setText(QString());
        iniciarpani->setText(QString());
        derivaciones->setText(QString());
        registro_usuario->setText(QString());
        Paciente->setText(QString());
        modelo2->setText(QString());
        ajustes->setText(QString());
        fh->setText(QCoreApplication::translate("MainWindow", "03-12-2020 14:14:32", nullptr));
        toolButton->setText(QString());
        toolButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
