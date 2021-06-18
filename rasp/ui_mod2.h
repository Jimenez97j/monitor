/********************************************************************************
** Form generated from reading UI file 'mod2.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOD2_H
#define UI_MOD2_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MOD2
{
public:
    QWidget *color;
    QWidget *SPO2BLOCK;
    QLabel *tex2;
    QLabel *SPO2;
    QLabel *tex3;
    QWidget *widget;
    QToolButton *registros;
    QToolButton *captura;
    QToolButton *galeria;
    QToolButton *alarmas;
    QToolButton *pani;
    QToolButton *registro;
    QToolButton *paciente;
    QToolButton *close;
    QToolButton *ajustes;
    QToolButton *sound;
    QLabel *label_10;
    QToolButton *derivaciones;
    QToolButton *internet;
    QFrame *frame;
    QWidget *BPMBLOCK;
    QLabel *bpm_ecg;
    QLabel *tex;
    QWidget *SYSBLOCK;
    QLabel *sisto;
    QLabel *tex5;
    QLabel *tex4;
    QWidget *DIABLOCK;
    QLabel *tex7;
    QLabel *tex6;
    QLabel *dias;
    QWidget *PANIBLOCK;
    QLabel *media;
    QLabel *tex10;
    QLabel *tex11;
    QWidget *TEMPBLOCK;
    QLabel *temp;
    QLabel *tex8;
    QLabel *tex9;
    QLabel *notificacion;
    QLabel *notificacion2;
    QLabel *notificacion3;
    QLabel *notificacion4;
    QLabel *notificacion7;
    QLabel *notificacion11;
    QLabel *notificacion6;
    QLabel *notificacion8;
    QLabel *notificacion13;
    QLabel *notificacion5;
    QLabel *notificacion12;
    QLabel *notificacion10;
    QLabel *notificacion9;

    void setupUi(QDialog *MOD2)
    {
        if (MOD2->objectName().isEmpty())
            MOD2->setObjectName(QString::fromUtf8("MOD2"));
        MOD2->resize(1290, 800);
        MOD2->setStyleSheet(QString::fromUtf8(""));
        color = new QWidget(MOD2);
        color->setObjectName(QString::fromUtf8("color"));
        color->setGeometry(QRect(0, 0, 1291, 801));
        color->setCursor(QCursor(Qt::BlankCursor));
        SPO2BLOCK = new QWidget(color);
        SPO2BLOCK->setObjectName(QString::fromUtf8("SPO2BLOCK"));
        SPO2BLOCK->setGeometry(QRect(90, 0, 550, 220));
        SPO2BLOCK->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"border-style: outset;\n"
"border-width: 7px;\n"
"border-color: white;"));
        tex2 = new QLabel(SPO2BLOCK);
        tex2->setObjectName(QString::fromUtf8("tex2"));
        tex2->setGeometry(QRect(350, 40, 121, 61));
        QPalette palette;
        QBrush brush(QColor(107, 255, 25, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(191, 64, 64, 0));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(190, 190, 190, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        tex2->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(43);
        font.setBold(true);
        font.setWeight(75);
        tex2->setFont(font);
        tex2->setCursor(QCursor(Qt::BlankCursor));
        tex2->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"border:none;"));
        SPO2 = new QLabel(SPO2BLOCK);
        SPO2->setObjectName(QString::fromUtf8("SPO2"));
        SPO2->setGeometry(QRect(0, 0, 311, 211));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        SPO2->setPalette(palette1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font1.setPointSize(135);
        font1.setBold(true);
        font1.setWeight(75);
        SPO2->setFont(font1);
        SPO2->setCursor(QCursor(Qt::BlankCursor));
        SPO2->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        tex3 = new QLabel(SPO2BLOCK);
        tex3->setObjectName(QString::fromUtf8("tex3"));
        tex3->setGeometry(QRect(380, 130, 81, 51));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        tex3->setPalette(palette2);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font2.setPointSize(48);
        font2.setBold(true);
        font2.setWeight(75);
        tex3->setFont(font2);
        tex3->setCursor(QCursor(Qt::BlankCursor));
        tex3->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        widget = new QWidget(color);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 690, 1291, 131));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        registros = new QToolButton(widget);
        registros->setObjectName(QString::fromUtf8("registros"));
        registros->setGeometry(QRect(3, 10, 90, 90));
        registros->setCursor(QCursor(Qt::BlankCursor));
        registros->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagenes/btn_Credencial.png"), QSize(), QIcon::Normal, QIcon::Off);
        registros->setIcon(icon);
        registros->setIconSize(QSize(90, 90));
        captura = new QToolButton(widget);
        captura->setObjectName(QString::fromUtf8("captura"));
        captura->setGeometry(QRect(103, 10, 90, 90));
        captura->setCursor(QCursor(Qt::BlankCursor));
        captura->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imagenes/btn_Foto.png"), QSize(), QIcon::Normal, QIcon::Off);
        captura->setIcon(icon1);
        captura->setIconSize(QSize(90, 90));
        galeria = new QToolButton(widget);
        galeria->setObjectName(QString::fromUtf8("galeria"));
        galeria->setGeometry(QRect(203, 10, 90, 90));
        galeria->setCursor(QCursor(Qt::BlankCursor));
        galeria->setStyleSheet(QString::fromUtf8("border-image: url(:/imagenes/Galeria.png) 0 0 0 0 strech strech;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imagenes/btn_Galeria.png"), QSize(), QIcon::Normal, QIcon::Off);
        galeria->setIcon(icon2);
        galeria->setIconSize(QSize(90, 90));
        alarmas = new QToolButton(widget);
        alarmas->setObjectName(QString::fromUtf8("alarmas"));
        alarmas->setGeometry(QRect(303, 10, 90, 90));
        alarmas->setCursor(QCursor(Qt::BlankCursor));
        alarmas->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imagenes/btn_Alarma.png"), QSize(), QIcon::Normal, QIcon::Off);
        alarmas->setIcon(icon3);
        alarmas->setIconSize(QSize(90, 90));
        pani = new QToolButton(widget);
        pani->setObjectName(QString::fromUtf8("pani"));
        pani->setGeometry(QRect(403, 10, 90, 90));
        pani->setCursor(QCursor(Qt::BlankCursor));
        pani->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/imagenes/btn_IniciarPresion.png"), QSize(), QIcon::Normal, QIcon::Off);
        pani->setIcon(icon4);
        pani->setIconSize(QSize(90, 90));
        registro = new QToolButton(widget);
        registro->setObjectName(QString::fromUtf8("registro"));
        registro->setGeometry(QRect(603, 10, 90, 90));
        registro->setCursor(QCursor(Qt::BlankCursor));
        registro->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/imagenes/btn_Registro.png"), QSize(), QIcon::Normal, QIcon::Off);
        registro->setIcon(icon5);
        registro->setIconSize(QSize(90, 90));
        paciente = new QToolButton(widget);
        paciente->setObjectName(QString::fromUtf8("paciente"));
        paciente->setGeometry(QRect(703, 10, 90, 90));
        paciente->setCursor(QCursor(Qt::BlankCursor));
        paciente->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/imagenes/btn_Paciente.png"), QSize(), QIcon::Normal, QIcon::Off);
        paciente->setIcon(icon6);
        paciente->setIconSize(QSize(90, 90));
        close = new QToolButton(widget);
        close->setObjectName(QString::fromUtf8("close"));
        close->setGeometry(QRect(803, 10, 90, 90));
        close->setCursor(QCursor(Qt::BlankCursor));
        close->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/imagenes/btn_GraficaSI.png"), QSize(), QIcon::Normal, QIcon::Off);
        close->setIcon(icon7);
        close->setIconSize(QSize(90, 90));
        ajustes = new QToolButton(widget);
        ajustes->setObjectName(QString::fromUtf8("ajustes"));
        ajustes->setGeometry(QRect(1003, 10, 90, 90));
        ajustes->setCursor(QCursor(Qt::BlankCursor));
        ajustes->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/imagenes/btn_Config.png"), QSize(), QIcon::Normal, QIcon::Off);
        ajustes->setIcon(icon8);
        ajustes->setIconSize(QSize(90, 90));
        sound = new QToolButton(widget);
        sound->setObjectName(QString::fromUtf8("sound"));
        sound->setGeometry(QRect(903, 10, 90, 90));
        sound->setCursor(QCursor(Qt::BlankCursor));
        sound->setStyleSheet(QString::fromUtf8(""));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/imagenes/btn_Sonido.png"), QSize(), QIcon::Normal, QIcon::Off);
        sound->setIcon(icon9);
        sound->setIconSize(QSize(90, 90));
        label_10 = new QLabel(widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(1200, 40, 81, 41));
        QPalette palette3;
        QBrush brush3(QColor(255, 255, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        label_10->setPalette(palette3);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font3.setPointSize(13);
        font3.setBold(true);
        font3.setWeight(75);
        label_10->setFont(font3);
        label_10->setCursor(QCursor(Qt::BlankCursor));
        label_10->setStyleSheet(QString::fromUtf8(" qproperty-alignment: AlignCenter;"));
        derivaciones = new QToolButton(widget);
        derivaciones->setObjectName(QString::fromUtf8("derivaciones"));
        derivaciones->setEnabled(false);
        derivaciones->setGeometry(QRect(503, 10, 90, 90));
        derivaciones->setCursor(QCursor(Qt::BlankCursor));
        derivaciones->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/imagenes/btn_Pulso.png"), QSize(), QIcon::Normal, QIcon::Off);
        derivaciones->setIcon(icon10);
        derivaciones->setIconSize(QSize(90, 90));
        internet = new QToolButton(widget);
        internet->setObjectName(QString::fromUtf8("internet"));
        internet->setGeometry(QRect(1103, 10, 90, 90));
        internet->setCursor(QCursor(Qt::BlankCursor));
        internet->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/imagenes/btn_Internet.png"), QSize(), QIcon::Normal, QIcon::Off);
        internet->setIcon(icon11);
        internet->setIconSize(QSize(90, 90));
        frame = new QFrame(color);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(-20, -10, 1311, 701));
        frame->setCursor(QCursor(Qt::BlankCursor));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        BPMBLOCK = new QWidget(frame);
        BPMBLOCK->setObjectName(QString::fromUtf8("BPMBLOCK"));
        BPMBLOCK->setGeometry(QRect(670, 10, 550, 220));
        BPMBLOCK->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"border-style: outset;\n"
"border-width: 7px;\n"
"border-color: white;"));
        bpm_ecg = new QLabel(BPMBLOCK);
        bpm_ecg->setObjectName(QString::fromUtf8("bpm_ecg"));
        bpm_ecg->setGeometry(QRect(10, 0, 311, 211));
        QPalette palette4;
        QBrush brush5(QColor(204, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        bpm_ecg->setPalette(palette4);
        bpm_ecg->setFont(font1);
        bpm_ecg->setCursor(QCursor(Qt::BlankCursor));
        bpm_ecg->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        tex = new QLabel(BPMBLOCK);
        tex->setObjectName(QString::fromUtf8("tex"));
        tex->setGeometry(QRect(370, 0, 111, 91));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        tex->setPalette(palette5);
        tex->setFont(font);
        tex->setCursor(QCursor(Qt::BlankCursor));
        tex->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        SYSBLOCK = new QWidget(frame);
        SYSBLOCK->setObjectName(QString::fromUtf8("SYSBLOCK"));
        SYSBLOCK->setGeometry(QRect(110, 240, 550, 220));
        SYSBLOCK->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"border-style: outset;\n"
"border-width: 7px;\n"
"border-color: white;"));
        sisto = new QLabel(SYSBLOCK);
        sisto->setObjectName(QString::fromUtf8("sisto"));
        sisto->setGeometry(QRect(10, 10, 301, 201));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        sisto->setPalette(palette6);
        sisto->setFont(font1);
        sisto->setCursor(QCursor(Qt::BlankCursor));
        sisto->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        tex5 = new QLabel(SYSBLOCK);
        tex5->setObjectName(QString::fromUtf8("tex5"));
        tex5->setGeometry(QRect(370, 60, 91, 51));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        tex5->setPalette(palette7);
        tex5->setFont(font);
        tex5->setCursor(QCursor(Qt::BlankCursor));
        tex5->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        tex4 = new QLabel(SYSBLOCK);
        tex4->setObjectName(QString::fromUtf8("tex4"));
        tex4->setGeometry(QRect(330, 120, 161, 71));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        tex4->setPalette(palette8);
        tex4->setFont(font2);
        tex4->setCursor(QCursor(Qt::BlankCursor));
        tex4->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        DIABLOCK = new QWidget(frame);
        DIABLOCK->setObjectName(QString::fromUtf8("DIABLOCK"));
        DIABLOCK->setGeometry(QRect(670, 240, 550, 220));
        DIABLOCK->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"border-style: outset;\n"
"border-width: 7px;\n"
"border-color: white;"));
        tex7 = new QLabel(DIABLOCK);
        tex7->setObjectName(QString::fromUtf8("tex7"));
        tex7->setGeometry(QRect(340, 110, 171, 71));
        QPalette palette9;
        QBrush brush6(QColor(255, 29, 225, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        tex7->setPalette(palette9);
        tex7->setFont(font2);
        tex7->setCursor(QCursor(Qt::BlankCursor));
        tex7->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        tex6 = new QLabel(DIABLOCK);
        tex6->setObjectName(QString::fromUtf8("tex6"));
        tex6->setGeometry(QRect(370, 60, 101, 51));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        tex6->setPalette(palette10);
        tex6->setFont(font);
        tex6->setCursor(QCursor(Qt::BlankCursor));
        tex6->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        dias = new QLabel(DIABLOCK);
        dias->setObjectName(QString::fromUtf8("dias"));
        dias->setGeometry(QRect(10, 10, 311, 201));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        dias->setPalette(palette11);
        dias->setFont(font1);
        dias->setCursor(QCursor(Qt::BlankCursor));
        dias->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        PANIBLOCK = new QWidget(frame);
        PANIBLOCK->setObjectName(QString::fromUtf8("PANIBLOCK"));
        PANIBLOCK->setGeometry(QRect(110, 470, 550, 220));
        PANIBLOCK->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"border-style: outset;\n"
"border-width: 7px;\n"
"border-color: white;"));
        media = new QLabel(PANIBLOCK);
        media->setObjectName(QString::fromUtf8("media"));
        media->setGeometry(QRect(10, 10, 301, 201));
        QPalette palette12;
        QBrush brush7(QColor(237, 212, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        media->setPalette(palette12);
        media->setFont(font1);
        media->setCursor(QCursor(Qt::BlankCursor));
        media->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        tex10 = new QLabel(PANIBLOCK);
        tex10->setObjectName(QString::fromUtf8("tex10"));
        tex10->setGeometry(QRect(360, 70, 121, 41));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette13.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        tex10->setPalette(palette13);
        tex10->setFont(font);
        tex10->setCursor(QCursor(Qt::BlankCursor));
        tex10->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;\n"
""));
        tex11 = new QLabel(PANIBLOCK);
        tex11->setObjectName(QString::fromUtf8("tex11"));
        tex11->setGeometry(QRect(360, 120, 151, 51));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        tex11->setPalette(palette14);
        tex11->setFont(font);
        tex11->setCursor(QCursor(Qt::BlankCursor));
        tex11->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        TEMPBLOCK = new QWidget(frame);
        TEMPBLOCK->setObjectName(QString::fromUtf8("TEMPBLOCK"));
        TEMPBLOCK->setGeometry(QRect(670, 470, 550, 220));
        TEMPBLOCK->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"border-style: outset;\n"
"border-width: 7px;\n"
"border-color: white;"));
        temp = new QLabel(TEMPBLOCK);
        temp->setObjectName(QString::fromUtf8("temp"));
        temp->setGeometry(QRect(10, 10, 311, 201));
        QPalette palette15;
        QBrush brush8(QColor(27, 80, 255, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette15.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        temp->setPalette(palette15);
        temp->setFont(font1);
        temp->setCursor(QCursor(Qt::BlankCursor));
        temp->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        tex8 = new QLabel(TEMPBLOCK);
        tex8->setObjectName(QString::fromUtf8("tex8"));
        tex8->setGeometry(QRect(360, 50, 121, 61));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette16.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        tex8->setPalette(palette16);
        tex8->setFont(font);
        tex8->setCursor(QCursor(Qt::BlankCursor));
        tex8->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        tex9 = new QLabel(TEMPBLOCK);
        tex9->setObjectName(QString::fromUtf8("tex9"));
        tex9->setGeometry(QRect(390, 120, 67, 61));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette17.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette17.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette17.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette17.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette17.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette17.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette17.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette17.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette17.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        tex9->setPalette(palette17);
        tex9->setFont(font2);
        tex9->setCursor(QCursor(Qt::BlankCursor));
        tex9->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"    border:none;"));
        frame->raise();
        SPO2BLOCK->raise();
        widget->raise();
        notificacion = new QLabel(MOD2);
        notificacion->setObjectName(QString::fromUtf8("notificacion"));
        notificacion->setGeometry(QRect(770, 80, 21, 21));
        notificacion->setCursor(QCursor(Qt::BlankCursor));
        notificacion->setAlignment(Qt::AlignJustify|Qt::AlignTop);
        notificacion2 = new QLabel(MOD2);
        notificacion2->setObjectName(QString::fromUtf8("notificacion2"));
        notificacion2->setGeometry(QRect(770, 100, 21, 21));
        notificacion2->setCursor(QCursor(Qt::BlankCursor));
        notificacion2->setAlignment(Qt::AlignJustify|Qt::AlignTop);
        notificacion3 = new QLabel(MOD2);
        notificacion3->setObjectName(QString::fromUtf8("notificacion3"));
        notificacion3->setGeometry(QRect(770, 120, 21, 21));
        notificacion3->setCursor(QCursor(Qt::BlankCursor));
        notificacion3->setAlignment(Qt::AlignJustify|Qt::AlignTop);
        notificacion4 = new QLabel(MOD2);
        notificacion4->setObjectName(QString::fromUtf8("notificacion4"));
        notificacion4->setGeometry(QRect(770, 140, 21, 21));
        notificacion4->setCursor(QCursor(Qt::BlankCursor));
        notificacion4->setAlignment(Qt::AlignJustify|Qt::AlignTop);
        notificacion7 = new QLabel(MOD2);
        notificacion7->setObjectName(QString::fromUtf8("notificacion7"));
        notificacion7->setGeometry(QRect(770, 200, 21, 21));
        notificacion7->setCursor(QCursor(Qt::BlankCursor));
        notificacion7->setAlignment(Qt::AlignJustify|Qt::AlignTop);
        notificacion11 = new QLabel(MOD2);
        notificacion11->setObjectName(QString::fromUtf8("notificacion11"));
        notificacion11->setGeometry(QRect(770, 290, 21, 21));
        notificacion11->setCursor(QCursor(Qt::BlankCursor));
        notificacion11->setAlignment(Qt::AlignJustify|Qt::AlignTop);
        notificacion6 = new QLabel(MOD2);
        notificacion6->setObjectName(QString::fromUtf8("notificacion6"));
        notificacion6->setGeometry(QRect(770, 180, 21, 21));
        notificacion6->setCursor(QCursor(Qt::BlankCursor));
        notificacion6->setAlignment(Qt::AlignJustify|Qt::AlignTop);
        notificacion8 = new QLabel(MOD2);
        notificacion8->setObjectName(QString::fromUtf8("notificacion8"));
        notificacion8->setGeometry(QRect(770, 230, 21, 21));
        notificacion8->setCursor(QCursor(Qt::BlankCursor));
        notificacion8->setAlignment(Qt::AlignJustify|Qt::AlignTop);
        notificacion13 = new QLabel(MOD2);
        notificacion13->setObjectName(QString::fromUtf8("notificacion13"));
        notificacion13->setGeometry(QRect(770, 330, 21, 21));
        notificacion13->setCursor(QCursor(Qt::BlankCursor));
        notificacion13->setAlignment(Qt::AlignJustify|Qt::AlignTop);
        notificacion5 = new QLabel(MOD2);
        notificacion5->setObjectName(QString::fromUtf8("notificacion5"));
        notificacion5->setGeometry(QRect(770, 160, 21, 21));
        notificacion5->setCursor(QCursor(Qt::BlankCursor));
        notificacion5->setAlignment(Qt::AlignJustify|Qt::AlignTop);
        notificacion12 = new QLabel(MOD2);
        notificacion12->setObjectName(QString::fromUtf8("notificacion12"));
        notificacion12->setGeometry(QRect(770, 310, 21, 21));
        notificacion12->setCursor(QCursor(Qt::BlankCursor));
        notificacion12->setAlignment(Qt::AlignJustify|Qt::AlignTop);
        notificacion10 = new QLabel(MOD2);
        notificacion10->setObjectName(QString::fromUtf8("notificacion10"));
        notificacion10->setGeometry(QRect(770, 270, 21, 21));
        notificacion10->setCursor(QCursor(Qt::BlankCursor));
        notificacion10->setAlignment(Qt::AlignJustify|Qt::AlignTop);
        notificacion9 = new QLabel(MOD2);
        notificacion9->setObjectName(QString::fromUtf8("notificacion9"));
        notificacion9->setGeometry(QRect(770, 250, 21, 21));
        notificacion9->setCursor(QCursor(Qt::BlankCursor));
        notificacion9->setAlignment(Qt::AlignJustify|Qt::AlignTop);

        retranslateUi(MOD2);

        QMetaObject::connectSlotsByName(MOD2);
    } // setupUi

    void retranslateUi(QDialog *MOD2)
    {
        MOD2->setWindowTitle(QCoreApplication::translate("MOD2", "Dialog", nullptr));
        tex2->setText(QCoreApplication::translate("MOD2", "SpO2", nullptr));
        SPO2->setText(QCoreApplication::translate("MOD2", "97", nullptr));
        tex3->setText(QCoreApplication::translate("MOD2", "%", nullptr));
        registros->setText(QString());
        captura->setText(QString());
        galeria->setText(QString());
        alarmas->setText(QString());
        pani->setText(QString());
        registro->setText(QString());
        paciente->setText(QString());
        close->setText(QString());
        ajustes->setText(QString());
        sound->setText(QString());
        label_10->setText(QCoreApplication::translate("MOD2", "rggfdgd", nullptr));
        derivaciones->setText(QString());
        internet->setText(QString());
        bpm_ecg->setText(QCoreApplication::translate("MOD2", "100", nullptr));
        tex->setText(QCoreApplication::translate("MOD2", "BPM", nullptr));
        sisto->setText(QCoreApplication::translate("MOD2", "120 ", nullptr));
        tex5->setText(QCoreApplication::translate("MOD2", "SYS.", nullptr));
        tex4->setText(QCoreApplication::translate("MOD2", "mmHg", nullptr));
        tex7->setText(QCoreApplication::translate("MOD2", "mmHg", nullptr));
        tex6->setText(QCoreApplication::translate("MOD2", "DIA.", nullptr));
        dias->setText(QCoreApplication::translate("MOD2", "80", nullptr));
        media->setText(QCoreApplication::translate("MOD2", "100", nullptr));
        tex10->setText(QCoreApplication::translate("MOD2", "PANI", nullptr));
        tex11->setText(QCoreApplication::translate("MOD2", "media", nullptr));
        temp->setText(QCoreApplication::translate("MOD2", "36.3", nullptr));
        tex8->setText(QCoreApplication::translate("MOD2", "TEMP", nullptr));
        tex9->setText(QCoreApplication::translate("MOD2", "C\302\260", nullptr));
        notificacion->setText(QString());
        notificacion2->setText(QString());
        notificacion3->setText(QString());
        notificacion4->setText(QString());
        notificacion7->setText(QString());
        notificacion11->setText(QString());
        notificacion6->setText(QString());
        notificacion8->setText(QString());
        notificacion13->setText(QString());
        notificacion5->setText(QString());
        notificacion12->setText(QString());
        notificacion10->setText(QString());
        notificacion9->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MOD2: public Ui_MOD2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOD2_H
