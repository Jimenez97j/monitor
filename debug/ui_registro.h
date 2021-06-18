/********************************************************************************
** Form generated from reading UI file 'registro.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRO_H
#define UI_REGISTRO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Registro
{
public:
    QWidget *widget_2;
    QWidget *widget;
    QLabel *Leyenda;
    QLabel *Sexo;
    QLabel *Edad;
    QLabel *Sangre;
    QLabel *Regis;
    QLabel *Nombre;
    QLabel *Paterno;
    QLabel *Notas;
    QLabel *Materno;
    QLabel *Sangre_2;
    QPushButton *CERRAR;
    QPushButton *OK;
    QSpinBox *age_c;
    QLabel *Nombre_2;
    QLabel *imagen;
    QTextEdit *notes;
    QTextEdit *last_name;
    QTextEdit *names;
    QTextEdit *mother_last_name;
    QComboBox *blood_type;
    QComboBox *gender;
    QComboBox *num_paciente;
    QTextEdit *names_2;

    void setupUi(QDialog *Registro)
    {
        if (Registro->objectName().isEmpty())
            Registro->setObjectName(QString::fromUtf8("Registro"));
        Registro->resize(1290, 800);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(0, 150, 210, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(104, 255, 237, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush3);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        QBrush brush4(QColor(114, 159, 207, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::NoRole, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush);
        QBrush brush5(QColor(0, 0, 0, 128));
        brush5.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::NoRole, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush);
        QBrush brush6(QColor(0, 0, 0, 128));
        brush6.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::NoRole, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush);
        QBrush brush7(QColor(0, 0, 0, 128));
        brush7.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        Registro->setPalette(palette);
        Registro->setCursor(QCursor(Qt::BlankCursor));
        widget_2 = new QWidget(Registro);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 1291, 801));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush8(QColor(50, 151, 219, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush8);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush8);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Active, QPalette::NoRole, brush3);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush3);
        QBrush brush9(QColor(0, 0, 0, 128));
        brush9.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::NoRole, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush3);
        QBrush brush10(QColor(0, 0, 0, 128));
        brush10.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::NoRole, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush3);
        QBrush brush11(QColor(0, 0, 0, 128));
        brush11.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        widget_2->setPalette(palette1);
        widget_2->setCursor(QCursor(Qt::BlankCursor));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: #3297db;"));
        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 0, 1121, 801));
        QPalette palette2;
        QBrush brush12(QColor(12, 68, 105, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush12);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush12);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        widget->setPalette(palette2);
        widget->setCursor(QCursor(Qt::BlankCursor));
        widget->setStyleSheet(QString::fromUtf8("background-color: #0c4469;"));
        Leyenda = new QLabel(widget);
        Leyenda->setObjectName(QString::fromUtf8("Leyenda"));
        Leyenda->setGeometry(QRect(140, 100, 841, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        Leyenda->setFont(font);
        Leyenda->setCursor(QCursor(Qt::BlankCursor));
        Leyenda->setStyleSheet(QString::fromUtf8("color:white;"));
        Sexo = new QLabel(widget);
        Sexo->setObjectName(QString::fromUtf8("Sexo"));
        Sexo->setGeometry(QRect(576, 361, 61, 31));
        Sexo->setFont(font);
        Sexo->setCursor(QCursor(Qt::BlankCursor));
        Sexo->setStyleSheet(QString::fromUtf8("color:white;"));
        Edad = new QLabel(widget);
        Edad->setObjectName(QString::fromUtf8("Edad"));
        Edad->setGeometry(QRect(900, 371, 61, 20));
        Edad->setFont(font);
        Edad->setCursor(QCursor(Qt::BlankCursor));
        Edad->setStyleSheet(QString::fromUtf8("color:white;"));
        Sangre = new QLabel(widget);
        Sangre->setObjectName(QString::fromUtf8("Sangre"));
        Sangre->setGeometry(QRect(70, 361, 161, 31));
        Sangre->setFont(font);
        Sangre->setCursor(QCursor(Qt::BlankCursor));
        Sangre->setStyleSheet(QString::fromUtf8("color:white"));
        Regis = new QLabel(widget);
        Regis->setObjectName(QString::fromUtf8("Regis"));
        Regis->setGeometry(QRect(10, 30, 491, 51));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush12);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush12);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush12);
        QBrush brush13(QColor(255, 255, 255, 128));
        brush13.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush13);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        QBrush brush14(QColor(255, 255, 255, 128));
        brush14.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush14);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        QBrush brush15(QColor(255, 255, 255, 128));
        brush15.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush15);
#endif
        Regis->setPalette(palette3);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font1.setPointSize(40);
        font1.setBold(true);
        font1.setWeight(75);
        Regis->setFont(font1);
        Regis->setCursor(QCursor(Qt::BlankCursor));
        Regis->setStyleSheet(QString::fromUtf8("color:white;"));
        Nombre = new QLabel(widget);
        Nombre->setObjectName(QString::fromUtf8("Nombre"));
        Nombre->setGeometry(QRect(100, 176, 121, 31));
        Nombre->setFont(font);
        Nombre->setCursor(QCursor(Qt::BlankCursor));
        Nombre->setStyleSheet(QString::fromUtf8("color:white;"));
        Paterno = new QLabel(widget);
        Paterno->setObjectName(QString::fromUtf8("Paterno"));
        Paterno->setGeometry(QRect(50, 271, 181, 31));
        Paterno->setFont(font);
        Paterno->setCursor(QCursor(Qt::BlankCursor));
        Paterno->setStyleSheet(QString::fromUtf8("color:white;"));
        Notas = new QLabel(widget);
        Notas->setObjectName(QString::fromUtf8("Notas"));
        Notas->setGeometry(QRect(80, 551, 141, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush12);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush12);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush12);
        QBrush brush16(QColor(255, 255, 255, 128));
        brush16.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush16);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush12);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        QBrush brush17(QColor(255, 255, 255, 128));
        brush17.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush17);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        QBrush brush18(QColor(255, 255, 255, 128));
        brush18.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush18);
#endif
        Notas->setPalette(palette4);
        Notas->setFont(font);
        Notas->setCursor(QCursor(Qt::BlankCursor));
        Notas->setStyleSheet(QString::fromUtf8("color:white;"));
        Materno = new QLabel(widget);
        Materno->setObjectName(QString::fromUtf8("Materno"));
        Materno->setGeometry(QRect(550, 270, 191, 31));
        Materno->setFont(font);
        Materno->setCursor(QCursor(Qt::BlankCursor));
        Materno->setStyleSheet(QString::fromUtf8("color:white;"));
        Sangre_2 = new QLabel(widget);
        Sangre_2->setObjectName(QString::fromUtf8("Sangre_2"));
        Sangre_2->setGeometry(QRect(58, 461, 171, 31));
        Sangre_2->setFont(font);
        Sangre_2->setCursor(QCursor(Qt::BlankCursor));
        Sangre_2->setStyleSheet(QString::fromUtf8("color:white;"));
        CERRAR = new QPushButton(widget);
        CERRAR->setObjectName(QString::fromUtf8("CERRAR"));
        CERRAR->setGeometry(QRect(920, 701, 90, 90));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font2.setBold(true);
        font2.setWeight(75);
        CERRAR->setFont(font2);
        CERRAR->setCursor(QCursor(Qt::BlankCursor));
        CERRAR->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagenes/btn_Cerrar.png"), QSize(), QIcon::Normal, QIcon::Off);
        CERRAR->setIcon(icon);
        CERRAR->setIconSize(QSize(90, 90));
        CERRAR->setFlat(false);
        OK = new QPushButton(widget);
        OK->setObjectName(QString::fromUtf8("OK"));
        OK->setGeometry(QRect(1020, 700, 90, 90));
        OK->setFont(font2);
        OK->setCursor(QCursor(Qt::BlankCursor));
        OK->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imagenes/btn_Ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        OK->setIcon(icon1);
        OK->setIconSize(QSize(90, 90));
        age_c = new QSpinBox(widget);
        age_c->setObjectName(QString::fromUtf8("age_c"));
        age_c->setGeometry(QRect(960, 351, 71, 51));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Highlight, brush1);
        palette5.setBrush(QPalette::Active, QPalette::HighlightedText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Highlight, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush19(QColor(145, 145, 145, 255));
        brush19.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Disabled, QPalette::Highlight, brush19);
        palette5.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush);
        age_c->setPalette(palette5);
        QFont font3;
        font3.setPointSize(20);
        age_c->setFont(font3);
        age_c->setCursor(QCursor(Qt::BlankCursor));
        age_c->setStyleSheet(QString::fromUtf8("QSpinBox { border: 3px solid white; border-radius: 5px; background-color: white; }\n"
"\n"
"QSpinBox::down-button{\n"
"   width: 25;\n"
"   height: 20px;\n"
"\n"
"\n"
"}\n"
"QSpinBox::up-button { \n"
"   width: 25px;  \n"
"   height: 20px;\n"
"\n"
"}"));
        age_c->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        age_c->setAccelerated(false);
        Nombre_2 = new QLabel(widget);
        Nombre_2->setObjectName(QString::fromUtf8("Nombre_2"));
        Nombre_2->setGeometry(QRect(690, 181, 51, 31));
        Nombre_2->setFont(font);
        Nombre_2->setCursor(QCursor(Qt::BlankCursor));
        Nombre_2->setStyleSheet(QString::fromUtf8("color:white;"));
        Sangre->raise();
        Materno->raise();
        Leyenda->raise();
        Sexo->raise();
        Edad->raise();
        Regis->raise();
        Nombre->raise();
        Paterno->raise();
        Notas->raise();
        Sangre_2->raise();
        CERRAR->raise();
        OK->raise();
        age_c->raise();
        Nombre_2->raise();
        imagen = new QLabel(widget_2);
        imagen->setObjectName(QString::fromUtf8("imagen"));
        imagen->setGeometry(QRect(5, 10, 70, 70));
        imagen->setCursor(QCursor(Qt::BlankCursor));
        imagen->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/img_Registro.png")));
        imagen->setScaledContents(true);
        notes = new QTextEdit(Registro);
        notes->setObjectName(QString::fromUtf8("notes"));
        notes->setGeometry(QRect(310, 551, 601, 151));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush20(QColor(0, 0, 0, 128));
        brush20.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush20);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        QBrush brush21(QColor(0, 0, 0, 128));
        brush21.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush21);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        QBrush brush22(QColor(0, 0, 0, 128));
        brush22.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush22);
#endif
        notes->setPalette(palette6);
        notes->setFont(font3);
        notes->viewport()->setProperty("cursor", QVariant(QCursor(Qt::BlankCursor)));
        last_name = new QTextEdit(Registro);
        last_name->setObjectName(QString::fromUtf8("last_name"));
        last_name->setGeometry(QRect(310, 261, 291, 51));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush23(QColor(136, 138, 133, 255));
        brush23.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush23);
        palette7.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        QBrush brush24(QColor(0, 0, 0, 128));
        brush24.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush24);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush23);
        palette7.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        QBrush brush25(QColor(0, 0, 0, 128));
        brush25.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush25);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush23);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush23);
        palette7.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        QBrush brush26(QColor(0, 0, 0, 128));
        brush26.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush26);
#endif
        last_name->setPalette(palette7);
        last_name->setFont(font3);
        last_name->viewport()->setProperty("cursor", QVariant(QCursor(Qt::BlankCursor)));
        last_name->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        names = new QTextEdit(Registro);
        names->setObjectName(QString::fromUtf8("names"));
        names->setGeometry(QRect(310, 171, 341, 51));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        QBrush brush27(QColor(0, 0, 0, 128));
        brush27.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush27);
#endif
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        QBrush brush28(QColor(0, 0, 0, 128));
        brush28.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush28);
#endif
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        QBrush brush29(QColor(0, 0, 0, 128));
        brush29.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush29);
#endif
        names->setPalette(palette8);
        names->setFont(font3);
        names->viewport()->setProperty("cursor", QVariant(QCursor(Qt::BlankCursor)));
        mother_last_name = new QTextEdit(Registro);
        mother_last_name->setObjectName(QString::fromUtf8("mother_last_name"));
        mother_last_name->setGeometry(QRect(820, 261, 291, 51));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush23);
        palette9.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush23);
        palette9.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        QBrush brush30(QColor(0, 0, 0, 128));
        brush30.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Active, QPalette::PlaceholderText, brush30);
#endif
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush23);
        palette9.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush23);
        palette9.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        QBrush brush31(QColor(0, 0, 0, 128));
        brush31.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush31);
#endif
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush23);
        palette9.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush23);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush23);
        palette9.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        QBrush brush32(QColor(0, 0, 0, 128));
        brush32.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush32);
#endif
        mother_last_name->setPalette(palette9);
        mother_last_name->setFont(font3);
        mother_last_name->viewport()->setProperty("cursor", QVariant(QCursor(Qt::BlankCursor)));
        blood_type = new QComboBox(Registro);
        blood_type->addItem(QString());
        blood_type->setObjectName(QString::fromUtf8("blood_type"));
        blood_type->setGeometry(QRect(310, 351, 191, 51));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush);
        palette10.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
        blood_type->setPalette(palette10);
        blood_type->setFont(font3);
        blood_type->setCursor(QCursor(Qt::BlankCursor));
        blood_type->setStyleSheet(QString::fromUtf8(""));
        gender = new QComboBox(Registro);
        gender->addItem(QString());
        gender->setObjectName(QString::fromUtf8("gender"));
        gender->setGeometry(QRect(720, 351, 191, 51));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::Base, brush);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush);
        gender->setPalette(palette11);
        gender->setFont(font3);
        gender->setCursor(QCursor(Qt::BlankCursor));
        num_paciente = new QComboBox(Registro);
        num_paciente->setObjectName(QString::fromUtf8("num_paciente"));
        num_paciente->setGeometry(QRect(310, 451, 601, 51));
        num_paciente->setFont(font3);
        num_paciente->setCursor(QCursor(Qt::BlankCursor));
        names_2 = new QTextEdit(Registro);
        names_2->setObjectName(QString::fromUtf8("names_2"));
        names_2->setGeometry(QRect(820, 168, 291, 51));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        QBrush brush33(QColor(0, 0, 0, 128));
        brush33.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Active, QPalette::PlaceholderText, brush33);
#endif
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        QBrush brush34(QColor(0, 0, 0, 128));
        brush34.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush34);
#endif
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        QBrush brush35(QColor(0, 0, 0, 128));
        brush35.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush35);
#endif
        names_2->setPalette(palette12);
        names_2->setFont(font3);
        names_2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::BlankCursor)));

        retranslateUi(Registro);

        CERRAR->setDefault(false);


        QMetaObject::connectSlotsByName(Registro);
    } // setupUi

    void retranslateUi(QDialog *Registro)
    {
        Registro->setWindowTitle(QCoreApplication::translate("Registro", "Dialog", nullptr));
        Leyenda->setText(QCoreApplication::translate("Registro", "*M\303\241ximo de registro de 3 pacientes simultaneos, puede eliminar pacientes inactivos", nullptr));
        Sexo->setText(QCoreApplication::translate("Registro", "Sexo:", nullptr));
        Edad->setText(QCoreApplication::translate("Registro", "Edad:", nullptr));
        Sangre->setText(QCoreApplication::translate("Registro", "Tipo de Sangre:", nullptr));
        Regis->setText(QCoreApplication::translate("Registro", "REGISTRO DE PACIENTE", nullptr));
        Nombre->setText(QCoreApplication::translate("Registro", "Nombres(s):", nullptr));
        Paterno->setText(QCoreApplication::translate("Registro", "Apellido Paterno:", nullptr));
        Notas->setText(QCoreApplication::translate("Registro", "Notas/Alertas:", nullptr));
        Materno->setText(QCoreApplication::translate("Registro", "Apellido Materno:", nullptr));
        Sangre_2->setText(QCoreApplication::translate("Registro", "Reescribir datos:", nullptr));
        Nombre_2->setText(QCoreApplication::translate("Registro", "UID:", nullptr));
        imagen->setText(QString());
        blood_type->setItemText(0, QCoreApplication::translate("Registro", "Seleccionar...", nullptr));

        gender->setItemText(0, QCoreApplication::translate("Registro", "Seleccionar...", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Registro: public Ui_Registro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRO_H
