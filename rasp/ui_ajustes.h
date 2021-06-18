/********************************************************************************
** Form generated from reading UI file 'ajustes.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJUSTES_H
#define UI_AJUSTES_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ajustes
{
public:
    QComboBox *comboBox;
    QLabel *SelDis;
    QWidget *widget_2;
    QLabel *label_2;
    QWidget *widget;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_7;
    QToolButton *toolButton;
    QToolButton *cleanAll;
    QLabel *Guia;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *DetArr;
    QToolButton *Guia_Usu;
    QLabel *Contra_2;
    QLabel *label_11;
    QToolButton *toolButton_2;
    QLabel *Titulo;
    QLabel *FH;
    QCheckBox *checkBox;
    QComboBox *time_save;
    QLabel *ARRIT;
    QDateEdit *dateEdit;
    QTimeEdit *timeEdit;

    void setupUi(QDialog *ajustes)
    {
        if (ajustes->objectName().isEmpty())
            ajustes->setObjectName(QString::fromUtf8("ajustes"));
        ajustes->resize(1290, 800);
        ajustes->setCursor(QCursor(Qt::BlankCursor));
        comboBox = new QComboBox(ajustes);
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(730, 160, 281, 41));
        QFont font;
        font.setPointSize(15);
        comboBox->setFont(font);
        comboBox->setCursor(QCursor(Qt::BlankCursor));
        SelDis = new QLabel(ajustes);
        SelDis->setObjectName(QString::fromUtf8("SelDis"));
        SelDis->setGeometry(QRect(330, 150, 281, 41));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush1(QColor(255, 255, 255, 128));
        brush1.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QBrush brush2(QColor(255, 255, 255, 128));
        brush2.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QBrush brush3(QColor(255, 255, 255, 128));
        brush3.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        SelDis->setPalette(palette);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font1.setPointSize(30);
        font1.setBold(true);
        font1.setWeight(75);
        SelDis->setFont(font1);
        SelDis->setCursor(QCursor(Qt::BlankCursor));
        SelDis->setStyleSheet(QString::fromUtf8("color:white;"));
        widget_2 = new QWidget(ajustes);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 1291, 801));
        widget_2->setCursor(QCursor(Qt::BlankCursor));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: #3297db;"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(6, 10, 70, 70));
        label_2->setCursor(QCursor(Qt::BlankCursor));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/img_Config.png")));
        label_2->setScaledContents(true);
        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 0, 1131, 801));
        widget->setCursor(QCursor(Qt::BlankCursor));
        widget->setStyleSheet(QString::fromUtf8("background-color: #0c4469;"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 140, 60, 60));
        label->setCursor(QCursor(Qt::BlankCursor));
        label->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/img_Dise\303\261o.png")));
        label->setScaledContents(true);
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(170, 280, 60, 60));
        label_6->setCursor(QCursor(Qt::BlankCursor));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/img_Reloj.png")));
        label_6->setScaledContents(true);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(170, 560, 60, 60));
        label_4->setCursor(QCursor(Qt::BlankCursor));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/img_Busqueda.png")));
        label_4->setScaledContents(true);
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 360, 41, 41));
        label_7->setCursor(QCursor(Qt::BlankCursor));
        toolButton = new QToolButton(widget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(925, 700, 90, 90));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font2.setBold(true);
        font2.setWeight(75);
        toolButton->setFont(font2);
        toolButton->setCursor(QCursor(Qt::BlankCursor));
        toolButton->setStyleSheet(QString::fromUtf8("border: none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagenes/btn_Cerrar.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(90, 90));
        cleanAll = new QToolButton(widget);
        cleanAll->setObjectName(QString::fromUtf8("cleanAll"));
        cleanAll->setGeometry(QRect(1030, 700, 90, 90));
        cleanAll->setFont(font2);
        cleanAll->setCursor(QCursor(Qt::BlankCursor));
        cleanAll->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imagenes/btn_Restaurar.png"), QSize(), QIcon::Normal, QIcon::Off);
        cleanAll->setIcon(icon1);
        cleanAll->setIconSize(QSize(90, 90));
        Guia = new QLabel(widget);
        Guia->setObjectName(QString::fromUtf8("Guia"));
        Guia->setGeometry(QRect(710, 580, 241, 41));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush4(QColor(12, 68, 105, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush4);
        QBrush brush5(QColor(255, 255, 255, 128));
        brush5.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        QBrush brush6(QColor(255, 255, 255, 128));
        brush6.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        QBrush brush7(QColor(255, 255, 255, 128));
        brush7.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        Guia->setPalette(palette1);
        Guia->setFont(font1);
        Guia->setCursor(QCursor(Qt::BlankCursor));
        Guia->setStyleSheet(QString::fromUtf8("Color:white;"));
        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(800, 266, 61, 21));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush4);
        QBrush brush8(QColor(255, 255, 255, 128));
        brush8.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        QBrush brush9(QColor(255, 255, 255, 128));
        brush9.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        QBrush brush10(QColor(255, 255, 255, 128));
        brush10.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        label_8->setPalette(palette2);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setWeight(75);
        label_8->setFont(font3);
        label_8->setCursor(QCursor(Qt::BlankCursor));
        label_8->setStyleSheet(QString::fromUtf8("color:white;"));
        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(660, 266, 71, 21));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush4);
        QBrush brush11(QColor(255, 255, 255, 128));
        brush11.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        QBrush brush12(QColor(255, 255, 255, 128));
        brush12.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        QBrush brush13(QColor(255, 255, 255, 128));
        brush13.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush13);
#endif
        label_9->setPalette(palette3);
        label_9->setFont(font3);
        label_9->setCursor(QCursor(Qt::BlankCursor));
        label_9->setStyleSheet(QString::fromUtf8("color:white;"));
        label_10 = new QLabel(widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(650, 570, 60, 60));
        label_10->setCursor(QCursor(Qt::BlankCursor));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/img_Guia.png")));
        label_10->setScaledContents(true);
        DetArr = new QLabel(widget);
        DetArr->setObjectName(QString::fromUtf8("DetArr"));
        DetArr->setGeometry(QRect(250, 570, 341, 41));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush4);
        QBrush brush14(QColor(255, 255, 255, 128));
        brush14.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush14);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        QBrush brush15(QColor(255, 255, 255, 128));
        brush15.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush15);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        QBrush brush16(QColor(255, 255, 255, 128));
        brush16.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush16);
#endif
        DetArr->setPalette(palette4);
        DetArr->setFont(font1);
        DetArr->setCursor(QCursor(Qt::BlankCursor));
        DetArr->setStyleSheet(QString::fromUtf8("color:white;"));
        Guia_Usu = new QToolButton(widget);
        Guia_Usu->setObjectName(QString::fromUtf8("Guia_Usu"));
        Guia_Usu->setGeometry(QRect(950, 585, 40, 40));
        Guia_Usu->setFont(font2);
        Guia_Usu->setCursor(QCursor(Qt::BlankCursor));
        Guia_Usu->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imagenes/btn_Visualizar.png"), QSize(), QIcon::Normal, QIcon::Off);
        Guia_Usu->setIcon(icon2);
        Guia_Usu->setIconSize(QSize(40, 40));
        Contra_2 = new QLabel(widget);
        Contra_2->setObjectName(QString::fromUtf8("Contra_2"));
        Contra_2->setGeometry(QRect(250, 425, 241, 41));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush4);
        QBrush brush17(QColor(255, 255, 255, 128));
        brush17.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush17);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        QBrush brush18(QColor(255, 255, 255, 128));
        brush18.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush18);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        QBrush brush19(QColor(255, 255, 255, 128));
        brush19.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush19);
#endif
        Contra_2->setPalette(palette5);
        Contra_2->setFont(font1);
        Contra_2->setCursor(QCursor(Qt::BlankCursor));
        Contra_2->setStyleSheet(QString::fromUtf8("color:white;"));
        label_11 = new QLabel(widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(170, 415, 60, 60));
        label_11->setCursor(QCursor(Qt::BlankCursor));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/img_Guardar.png")));
        label_11->setScaledContents(true);
        toolButton_2 = new QToolButton(widget);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(950, 290, 40, 40));
        toolButton_2->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imagenes/btn_Guardar.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon3);
        toolButton_2->setIconSize(QSize(40, 40));
        toolButton_2->setAutoRaise(false);
        Titulo = new QLabel(ajustes);
        Titulo->setObjectName(QString::fromUtf8("Titulo"));
        Titulo->setGeometry(QRect(90, 30, 261, 41));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush20(QColor(255, 255, 255, 128));
        brush20.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush20);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QBrush brush21(QColor(255, 255, 255, 128));
        brush21.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush21);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QBrush brush22(QColor(255, 255, 255, 128));
        brush22.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush22);
#endif
        Titulo->setPalette(palette6);
        Titulo->setFont(font1);
        Titulo->setCursor(QCursor(Qt::BlankCursor));
        Titulo->setStyleSheet(QString::fromUtf8("color: white;"));
        FH = new QLabel(ajustes);
        FH->setObjectName(QString::fromUtf8("FH"));
        FH->setGeometry(QRect(330, 290, 321, 41));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush23(QColor(85, 87, 83, 255));
        brush23.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush23);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush23);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush23);
        QBrush brush24(QColor(255, 255, 255, 128));
        brush24.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush24);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush23);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush23);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush23);
        QBrush brush25(QColor(255, 255, 255, 128));
        brush25.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush25);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush23);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush23);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush23);
        QBrush brush26(QColor(255, 255, 255, 128));
        brush26.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush26);
#endif
        FH->setPalette(palette7);
        FH->setFont(font1);
        FH->setCursor(QCursor(Qt::BlankCursor));
        FH->setStyleSheet(QString::fromUtf8("color:white;"));
        checkBox = new QCheckBox(ajustes);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(340, 616, 111, 41));
        QPalette palette8;
        QBrush brush27(QColor(239, 41, 41, 255));
        brush27.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush27);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush27);
        QBrush brush28(QColor(190, 190, 190, 255));
        brush28.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush28);
        checkBox->setPalette(palette8);
        QFont font4;
        font4.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font4.setPointSize(15);
        font4.setBold(true);
        font4.setWeight(75);
        checkBox->setFont(font4);
        checkBox->setCursor(QCursor(Qt::BlankCursor));
        checkBox->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"}"));
        time_save = new QComboBox(ajustes);
        time_save->addItem(QString());
        time_save->setObjectName(QString::fromUtf8("time_save"));
        time_save->setGeometry(QRect(730, 430, 281, 41));
        time_save->setFont(font);
        time_save->setCursor(QCursor(Qt::BlankCursor));
        ARRIT = new QLabel(ajustes);
        ARRIT->setObjectName(QString::fromUtf8("ARRIT"));
        ARRIT->setGeometry(QRect(380, 620, 141, 31));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush29(QColor(255, 255, 255, 128));
        brush29.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Active, QPalette::PlaceholderText, brush29);
#endif
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QBrush brush30(QColor(255, 255, 255, 128));
        brush30.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush30);
#endif
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QBrush brush31(QColor(255, 255, 255, 128));
        brush31.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush31);
#endif
        ARRIT->setPalette(palette9);
        QFont font5;
        font5.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font5.setPointSize(20);
        font5.setBold(true);
        font5.setWeight(75);
        ARRIT->setFont(font5);
        ARRIT->setStyleSheet(QString::fromUtf8("color:white;"));
        dateEdit = new QDateEdit(ajustes);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(730, 290, 141, 51));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::Button, brush);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush);
        palette10.setBrush(QPalette::Active, QPalette::Highlight, brush);
        QBrush brush32(QColor(0, 0, 0, 255));
        brush32.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Active, QPalette::HighlightedText, brush32);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush32);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush);
        QBrush brush33(QColor(145, 145, 145, 255));
        brush33.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Disabled, QPalette::Highlight, brush33);
        palette10.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush32);
        dateEdit->setPalette(palette10);
        dateEdit->setFont(font);
        dateEdit->setStyleSheet(QString::fromUtf8("QDateEdit { border: 3px solid white; border-radius: 5px; background-color: white; }\n"
"\n"
"QTimeEdit::down-button{\n"
"   width: 25;\n"
"   height: 20px;\n"
"\n"
"\n"
"}\n"
"QDateEdit::up-button { \n"
"   width: 25px;  \n"
"   height: 20px;\n"
"\n"
"}"));
        dateEdit->setReadOnly(false);
        dateEdit->setCalendarPopup(true);
        timeEdit = new QTimeEdit(ajustes);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(880, 290, 131, 51));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::Button, brush);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush);
        palette11.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette11.setBrush(QPalette::Active, QPalette::HighlightedText, brush32);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush32);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::Highlight, brush33);
        palette11.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush32);
        timeEdit->setPalette(palette11);
        timeEdit->setFont(font);
        timeEdit->setStyleSheet(QString::fromUtf8("QTimeEdit { border: 3px solid white; border-radius: 5px; background-color: white; }\n"
"\n"
"QTimeEdit::down-button{\n"
"   width: 25;\n"
"   height: 20px;\n"
"\n"
"\n"
"}\n"
"QTimeEdit::up-button { \n"
"   width: 25px;  \n"
"   height: 20px;\n"
"\n"
"}\n"
""));
        timeEdit->setCalendarPopup(true);
        widget_2->raise();
        comboBox->raise();
        SelDis->raise();
        Titulo->raise();
        FH->raise();
        checkBox->raise();
        time_save->raise();
        ARRIT->raise();
        dateEdit->raise();
        timeEdit->raise();

        retranslateUi(ajustes);

        QMetaObject::connectSlotsByName(ajustes);
    } // setupUi

    void retranslateUi(QDialog *ajustes)
    {
        ajustes->setWindowTitle(QCoreApplication::translate("ajustes", "Dialog", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("ajustes", "Seleccionar dise\303\261o...", nullptr));

        SelDis->setText(QCoreApplication::translate("ajustes", "Seleccionar dise\303\261o", nullptr));
        label_2->setText(QString());
        label->setText(QString());
        label_6->setText(QString());
        label_4->setText(QString());
        label_7->setText(QString());
        toolButton->setText(QString());
        cleanAll->setText(QString());
        Guia->setText(QCoreApplication::translate("ajustes", "Guia de Usuario", nullptr));
        label_8->setText(QCoreApplication::translate("ajustes", "Hora", nullptr));
        label_9->setText(QCoreApplication::translate("ajustes", "Fecha", nullptr));
        label_10->setText(QString());
        DetArr->setText(QCoreApplication::translate("ajustes", "Deteccion de Arritmias", nullptr));
        Guia_Usu->setText(QString());
        Contra_2->setText(QCoreApplication::translate("ajustes", "Auto-Guardado", nullptr));
        label_11->setText(QString());
        toolButton_2->setText(QString());
        Titulo->setText(QCoreApplication::translate("ajustes", "CONFIGURACI\303\223N", nullptr));
        FH->setText(QCoreApplication::translate("ajustes", "Modificar Fecha/Hora", nullptr));
        checkBox->setText(QString());
        time_save->setItemText(0, QCoreApplication::translate("ajustes", "Seleccionar tiempo...", nullptr));

        ARRIT->setText(QCoreApplication::translate("ajustes", "Desactivado", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("ajustes", "dd/MM/yyyy", nullptr));
        timeEdit->setDisplayFormat(QCoreApplication::translate("ajustes", "HH:mm:ss", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ajustes: public Ui_ajustes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJUSTES_H
