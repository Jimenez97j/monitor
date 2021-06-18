/********************************************************************************
** Form generated from reading UI file 'config_alarmas.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_ALARMAS_H
#define UI_CONFIG_ALARMAS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_config_alarmas
{
public:
    QLabel *label;
    QLabel *label_4;
    QLabel *ecg_alarm_min;
    QLabel *ecg_alarm_max;
    QLabel *spo2_alarm_min;
    QLabel *spo2_alarm_max;
    QLabel *rpm_alarm_min;
    QLabel *rpm_alarm_max;
    QToolButton *menos_min_ecg;
    QToolButton *mas_min_ecg;
    QToolButton *menos_max_ecg;
    QToolButton *menos_min_spo2;
    QToolButton *mas_min_spo2;
    QToolButton *menos_max_spo2;
    QToolButton *mas_max_spo2;
    QToolButton *menos_min_rpm;
    QToolButton *mas_min_rpm;
    QToolButton *mas_max_rpm;
    QToolButton *menos_max_rpm;
    QWidget *widget_2;
    QWidget *widget;
    QLabel *Regis;
    QToolButton *mas_max_ecg;
    QPushButton *OK;
    QPushButton *CERRAR;
    QLabel *label_5;
    QLabel *label_10;
    QLabel *label_3;
    QLabel *label_8;

    void setupUi(QDialog *config_alarmas)
    {
        if (config_alarmas->objectName().isEmpty())
            config_alarmas->setObjectName(QString::fromUtf8("config_alarmas"));
        config_alarmas->resize(1290, 800);
        QPalette palette;
        QBrush brush(QColor(186, 189, 182, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(52, 101, 164, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush2);
        QBrush brush3(QColor(83, 165, 236, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        QBrush brush4(QColor(255, 255, 255, 128));
        brush4.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush5(QColor(255, 255, 255, 128));
        brush5.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush);
        QBrush brush6(QColor(190, 190, 190, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        QBrush brush7(QColor(255, 255, 255, 128));
        brush7.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        config_alarmas->setPalette(palette);
        config_alarmas->setCursor(QCursor(Qt::ArrowCursor));
        config_alarmas->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(config_alarmas);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 350, 111, 61));
        QPalette palette1;
        QBrush brush8(QColor(115, 210, 22, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        label->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(44);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setCursor(QCursor(Qt::BlankCursor));
        label_4 = new QLabel(config_alarmas);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(260, 170, 101, 61));
        QPalette palette2;
        QBrush brush9(QColor(239, 41, 41, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        QBrush brush10(QColor(0, 0, 0, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush10);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        QBrush brush11(QColor(0, 0, 0, 128));
        brush11.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        QBrush brush12(QColor(0, 0, 0, 128));
        brush12.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        QBrush brush13(QColor(0, 0, 0, 128));
        brush13.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush13);
#endif
        label_4->setPalette(palette2);
        label_4->setFont(font);
        label_4->setCursor(QCursor(Qt::BlankCursor));
        ecg_alarm_min = new QLabel(config_alarmas);
        ecg_alarm_min->setObjectName(QString::fromUtf8("ecg_alarm_min"));
        ecg_alarm_min->setGeometry(QRect(480, 170, 91, 61));
        QPalette palette3;
        QBrush brush14(QColor(204, 0, 0, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush14);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush14);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        ecg_alarm_min->setPalette(palette3);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font1.setPointSize(50);
        font1.setBold(true);
        font1.setWeight(75);
        ecg_alarm_min->setFont(font1);
        ecg_alarm_min->setCursor(QCursor(Qt::BlankCursor));
        ecg_alarm_max = new QLabel(config_alarmas);
        ecg_alarm_max->setObjectName(QString::fromUtf8("ecg_alarm_max"));
        ecg_alarm_max->setGeometry(QRect(840, 170, 101, 61));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush14);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        ecg_alarm_max->setPalette(palette4);
        ecg_alarm_max->setFont(font1);
        ecg_alarm_max->setCursor(QCursor(Qt::BlankCursor));
        spo2_alarm_min = new QLabel(config_alarmas);
        spo2_alarm_min->setObjectName(QString::fromUtf8("spo2_alarm_min"));
        spo2_alarm_min->setGeometry(QRect(480, 350, 91, 61));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        spo2_alarm_min->setPalette(palette5);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font2.setPointSize(50);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setWeight(75);
        font2.setStrikeOut(false);
        spo2_alarm_min->setFont(font2);
        spo2_alarm_min->setCursor(QCursor(Qt::BlankCursor));
        spo2_alarm_max = new QLabel(config_alarmas);
        spo2_alarm_max->setObjectName(QString::fromUtf8("spo2_alarm_max"));
        spo2_alarm_max->setGeometry(QRect(840, 350, 101, 61));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        spo2_alarm_max->setPalette(palette6);
        spo2_alarm_max->setFont(font1);
        spo2_alarm_max->setCursor(QCursor(Qt::BlankCursor));
        rpm_alarm_min = new QLabel(config_alarmas);
        rpm_alarm_min->setObjectName(QString::fromUtf8("rpm_alarm_min"));
        rpm_alarm_min->setGeometry(QRect(480, 530, 91, 61));
        QPalette palette7;
        QBrush brush15(QColor(0, 150, 210, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush15);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush15);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush15);
        QBrush brush16(QColor(0, 150, 210, 128));
        brush16.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush16);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush15);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush15);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush15);
        QBrush brush17(QColor(0, 150, 210, 128));
        brush17.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush17);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush15);
        QBrush brush18(QColor(0, 150, 210, 128));
        brush18.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush18);
#endif
        rpm_alarm_min->setPalette(palette7);
        rpm_alarm_min->setFont(font1);
        rpm_alarm_min->setCursor(QCursor(Qt::BlankCursor));
        rpm_alarm_min->setStyleSheet(QString::fromUtf8("color:#0096d2"));
        rpm_alarm_max = new QLabel(config_alarmas);
        rpm_alarm_max->setObjectName(QString::fromUtf8("rpm_alarm_max"));
        rpm_alarm_max->setGeometry(QRect(840, 530, 101, 61));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush15);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush15);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush15);
        QBrush brush19(QColor(0, 150, 210, 128));
        brush19.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush19);
#endif
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush15);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush15);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush15);
        QBrush brush20(QColor(0, 150, 210, 128));
        brush20.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush20);
#endif
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush15);
        QBrush brush21(QColor(0, 150, 210, 128));
        brush21.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush21);
#endif
        rpm_alarm_max->setPalette(palette8);
        rpm_alarm_max->setFont(font1);
        rpm_alarm_max->setCursor(QCursor(Qt::BlankCursor));
        rpm_alarm_max->setStyleSheet(QString::fromUtf8("color:#0096d2"));
        menos_min_ecg = new QToolButton(config_alarmas);
        menos_min_ecg->setObjectName(QString::fromUtf8("menos_min_ecg"));
        menos_min_ecg->setGeometry(QRect(410, 180, 40, 40));
        menos_min_ecg->setCursor(QCursor(Qt::BlankCursor));
        menos_min_ecg->setStyleSheet(QString::fromUtf8("background-repeat:none;\n"
"border:none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagenes/btn_signo_Menos.png"), QSize(), QIcon::Normal, QIcon::Off);
        menos_min_ecg->setIcon(icon);
        menos_min_ecg->setIconSize(QSize(40, 40));
        mas_min_ecg = new QToolButton(config_alarmas);
        mas_min_ecg->setObjectName(QString::fromUtf8("mas_min_ecg"));
        mas_min_ecg->setGeometry(QRect(580, 180, 40, 40));
        mas_min_ecg->setCursor(QCursor(Qt::BlankCursor));
        mas_min_ecg->setStyleSheet(QString::fromUtf8("background-repeat:none;\n"
"border:none;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imagenes/btn_signo_,Mas.png"), QSize(), QIcon::Normal, QIcon::Off);
        mas_min_ecg->setIcon(icon1);
        mas_min_ecg->setIconSize(QSize(40, 40));
        menos_max_ecg = new QToolButton(config_alarmas);
        menos_max_ecg->setObjectName(QString::fromUtf8("menos_max_ecg"));
        menos_max_ecg->setGeometry(QRect(770, 180, 40, 40));
        menos_max_ecg->setCursor(QCursor(Qt::BlankCursor));
        menos_max_ecg->setStyleSheet(QString::fromUtf8("background-repeat:none;\n"
"border:none;"));
        menos_max_ecg->setIcon(icon);
        menos_max_ecg->setIconSize(QSize(40, 40));
        menos_min_spo2 = new QToolButton(config_alarmas);
        menos_min_spo2->setObjectName(QString::fromUtf8("menos_min_spo2"));
        menos_min_spo2->setGeometry(QRect(410, 360, 40, 40));
        menos_min_spo2->setCursor(QCursor(Qt::BlankCursor));
        menos_min_spo2->setStyleSheet(QString::fromUtf8("background-repeat:none;\n"
"border:none;"));
        menos_min_spo2->setIcon(icon);
        menos_min_spo2->setIconSize(QSize(40, 40));
        mas_min_spo2 = new QToolButton(config_alarmas);
        mas_min_spo2->setObjectName(QString::fromUtf8("mas_min_spo2"));
        mas_min_spo2->setGeometry(QRect(580, 360, 40, 40));
        mas_min_spo2->setCursor(QCursor(Qt::BlankCursor));
        mas_min_spo2->setStyleSheet(QString::fromUtf8("background-repeat:none;\n"
"border:none;"));
        mas_min_spo2->setIcon(icon1);
        mas_min_spo2->setIconSize(QSize(40, 40));
        menos_max_spo2 = new QToolButton(config_alarmas);
        menos_max_spo2->setObjectName(QString::fromUtf8("menos_max_spo2"));
        menos_max_spo2->setGeometry(QRect(770, 360, 40, 40));
        menos_max_spo2->setCursor(QCursor(Qt::BlankCursor));
        menos_max_spo2->setStyleSheet(QString::fromUtf8("background-repeat:none;\n"
"border:none;"));
        menos_max_spo2->setIcon(icon);
        menos_max_spo2->setIconSize(QSize(40, 40));
        mas_max_spo2 = new QToolButton(config_alarmas);
        mas_max_spo2->setObjectName(QString::fromUtf8("mas_max_spo2"));
        mas_max_spo2->setGeometry(QRect(950, 360, 40, 40));
        mas_max_spo2->setCursor(QCursor(Qt::BlankCursor));
        mas_max_spo2->setStyleSheet(QString::fromUtf8("background-repeat:none;\n"
"border:none;"));
        mas_max_spo2->setIcon(icon1);
        mas_max_spo2->setIconSize(QSize(40, 40));
        menos_min_rpm = new QToolButton(config_alarmas);
        menos_min_rpm->setObjectName(QString::fromUtf8("menos_min_rpm"));
        menos_min_rpm->setGeometry(QRect(410, 540, 40, 40));
        menos_min_rpm->setCursor(QCursor(Qt::BlankCursor));
        menos_min_rpm->setStyleSheet(QString::fromUtf8("background-repeat:none;\n"
"border:none;"));
        menos_min_rpm->setIcon(icon);
        menos_min_rpm->setIconSize(QSize(40, 40));
        mas_min_rpm = new QToolButton(config_alarmas);
        mas_min_rpm->setObjectName(QString::fromUtf8("mas_min_rpm"));
        mas_min_rpm->setGeometry(QRect(580, 540, 40, 40));
        mas_min_rpm->setCursor(QCursor(Qt::BlankCursor));
        mas_min_rpm->setStyleSheet(QString::fromUtf8("background-repeat:none;\n"
"border:none;"));
        mas_min_rpm->setIcon(icon1);
        mas_min_rpm->setIconSize(QSize(40, 40));
        mas_max_rpm = new QToolButton(config_alarmas);
        mas_max_rpm->setObjectName(QString::fromUtf8("mas_max_rpm"));
        mas_max_rpm->setGeometry(QRect(950, 540, 40, 40));
        mas_max_rpm->setCursor(QCursor(Qt::BlankCursor));
        mas_max_rpm->setStyleSheet(QString::fromUtf8("background-repeat:none;\n"
"border:none;"));
        mas_max_rpm->setIcon(icon1);
        mas_max_rpm->setIconSize(QSize(40, 40));
        menos_max_rpm = new QToolButton(config_alarmas);
        menos_max_rpm->setObjectName(QString::fromUtf8("menos_max_rpm"));
        menos_max_rpm->setGeometry(QRect(770, 540, 40, 40));
        menos_max_rpm->setCursor(QCursor(Qt::BlankCursor));
        menos_max_rpm->setStyleSheet(QString::fromUtf8("background-repeat:none;\n"
"border:none;"));
        menos_max_rpm->setIcon(icon);
        menos_max_rpm->setIconSize(QSize(40, 40));
        widget_2 = new QWidget(config_alarmas);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 1301, 801));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush10);
        QBrush brush22(QColor(50, 151, 219, 255));
        brush22.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush22);
        palette9.setBrush(QPalette::Active, QPalette::Light, brush15);
        palette9.setBrush(QPalette::Active, QPalette::Midlight, brush15);
        palette9.setBrush(QPalette::Active, QPalette::Dark, brush15);
        palette9.setBrush(QPalette::Active, QPalette::Mid, brush15);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush10);
        palette9.setBrush(QPalette::Active, QPalette::BrightText, brush15);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush10);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush22);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush22);
        palette9.setBrush(QPalette::Active, QPalette::Shadow, brush15);
        palette9.setBrush(QPalette::Active, QPalette::HighlightedText, brush15);
        palette9.setBrush(QPalette::Active, QPalette::AlternateBase, brush15);
        QBrush brush23(QColor(104, 255, 237, 255));
        brush23.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::NoRole, brush23);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipBase, brush23);
        QBrush brush24(QColor(0, 0, 0, 128));
        brush24.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Active, QPalette::PlaceholderText, brush24);
#endif
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush10);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush22);
        palette9.setBrush(QPalette::Inactive, QPalette::Light, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::Midlight, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::Dark, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::Mid, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush10);
        palette9.setBrush(QPalette::Inactive, QPalette::BrightText, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush10);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush22);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush22);
        palette9.setBrush(QPalette::Inactive, QPalette::Shadow, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::NoRole, brush23);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush23);
        QBrush brush25(QColor(0, 0, 0, 128));
        brush25.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush25);
#endif
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush22);
        palette9.setBrush(QPalette::Disabled, QPalette::Light, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::Midlight, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::Dark, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::Mid, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::BrightText, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush22);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush22);
        palette9.setBrush(QPalette::Disabled, QPalette::Shadow, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::NoRole, brush23);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush23);
        QBrush brush26(QColor(0, 0, 0, 128));
        brush26.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush26);
#endif
        widget_2->setPalette(palette9);
        widget_2->setCursor(QCursor(Qt::BlankCursor));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: #3297db;"));
        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 0, 1131, 811));
        QPalette palette10;
        QBrush brush27(QColor(12, 68, 105, 255));
        brush27.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush27);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush27);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush27);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush27);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush27);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush27);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush27);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush27);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush27);
        widget->setPalette(palette10);
        widget->setCursor(QCursor(Qt::ArrowCursor));
        widget->setStyleSheet(QString::fromUtf8("background-color: #0c4469;"));
        Regis = new QLabel(widget);
        Regis->setObjectName(QString::fromUtf8("Regis"));
        Regis->setGeometry(QRect(10, 30, 181, 41));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush27);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush27);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush27);
        QBrush brush28(QColor(255, 255, 255, 128));
        brush28.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Active, QPalette::PlaceholderText, brush28);
#endif
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush27);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush27);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush27);
        QBrush brush29(QColor(255, 255, 255, 128));
        brush29.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush29);
#endif
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush27);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush27);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush27);
        QBrush brush30(QColor(255, 255, 255, 128));
        brush30.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush30);
#endif
        Regis->setPalette(palette11);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font3.setPointSize(40);
        font3.setBold(true);
        font3.setWeight(75);
        Regis->setFont(font3);
        Regis->setCursor(QCursor(Qt::BlankCursor));
        Regis->setStyleSheet(QString::fromUtf8("color:white;"));
        mas_max_ecg = new QToolButton(widget);
        mas_max_ecg->setObjectName(QString::fromUtf8("mas_max_ecg"));
        mas_max_ecg->setGeometry(QRect(870, 180, 40, 40));
        mas_max_ecg->setCursor(QCursor(Qt::BlankCursor));
        mas_max_ecg->setStyleSheet(QString::fromUtf8("background-repeat:none;\n"
"border:none;"));
        mas_max_ecg->setIcon(icon1);
        mas_max_ecg->setIconSize(QSize(40, 40));
        OK = new QPushButton(widget);
        OK->setObjectName(QString::fromUtf8("OK"));
        OK->setGeometry(QRect(1030, 700, 90, 90));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font4.setBold(true);
        font4.setWeight(75);
        OK->setFont(font4);
        OK->setCursor(QCursor(Qt::BlankCursor));
        OK->setStyleSheet(QString::fromUtf8("border: 0px;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imagenes/btn_Ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        OK->setIcon(icon2);
        OK->setIconSize(QSize(90, 90));
        CERRAR = new QPushButton(widget);
        CERRAR->setObjectName(QString::fromUtf8("CERRAR"));
        CERRAR->setGeometry(QRect(930, 700, 90, 90));
        CERRAR->setFont(font4);
        CERRAR->setCursor(QCursor(Qt::BlankCursor));
        CERRAR->setStyleSheet(QString::fromUtf8("border: 0px;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imagenes/btn_Cerrar.png"), QSize(), QIcon::Normal, QIcon::Off);
        CERRAR->setIcon(icon3);
        CERRAR->setIconSize(QSize(90, 90));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(340, 80, 211, 31));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush27);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush27);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush27);
        QBrush brush31(QColor(255, 255, 255, 128));
        brush31.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Active, QPalette::PlaceholderText, brush31);
#endif
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush27);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush27);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush27);
        QBrush brush32(QColor(255, 255, 255, 128));
        brush32.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush32);
#endif
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush27);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush27);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush27);
        QBrush brush33(QColor(255, 255, 255, 128));
        brush33.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush33);
#endif
        label_5->setPalette(palette12);
        QFont font5;
        font5.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font5.setPointSize(25);
        font5.setBold(true);
        font5.setWeight(75);
        label_5->setFont(font5);
        label_5->setCursor(QCursor(Qt::BlankCursor));
        label_10 = new QLabel(widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(700, 80, 221, 31));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette13.setBrush(QPalette::Active, QPalette::Button, brush27);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush27);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush27);
        QBrush brush34(QColor(255, 255, 255, 128));
        brush34.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Active, QPalette::PlaceholderText, brush34);
#endif
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush27);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush27);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush27);
        QBrush brush35(QColor(255, 255, 255, 128));
        brush35.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush35);
#endif
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush27);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush27);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush27);
        QBrush brush36(QColor(255, 255, 255, 128));
        brush36.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush36);
#endif
        label_10->setPalette(palette13);
        label_10->setFont(font5);
        label_10->setCursor(QCursor(Qt::BlankCursor));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(5, 10, 70, 70));
        label_3->setCursor(QCursor(Qt::BlankCursor));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/img_Alarma.png")));
        label_3->setScaledContents(true);
        label_8 = new QLabel(config_alarmas);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(260, 520, 131, 81));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush15);
        QBrush brush37(QColor(85, 87, 83, 255));
        brush37.setStyle(Qt::SolidPattern);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush37);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush15);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush15);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush37);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush37);
        QBrush brush38(QColor(0, 150, 210, 128));
        brush38.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Active, QPalette::PlaceholderText, brush38);
#endif
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush15);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush37);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush15);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush15);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush37);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush37);
        QBrush brush39(QColor(0, 150, 210, 128));
        brush39.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush39);
#endif
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush37);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush15);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush37);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush37);
        QBrush brush40(QColor(0, 150, 210, 128));
        brush40.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush40);
#endif
        label_8->setPalette(palette14);
        label_8->setFont(font);
        label_8->setCursor(QCursor(Qt::BlankCursor));
        label_8->setStyleSheet(QString::fromUtf8("color:#0096d2"));
        widget_2->raise();
        label->raise();
        label_4->raise();
        ecg_alarm_min->raise();
        ecg_alarm_max->raise();
        spo2_alarm_min->raise();
        spo2_alarm_max->raise();
        rpm_alarm_min->raise();
        rpm_alarm_max->raise();
        menos_min_ecg->raise();
        mas_min_ecg->raise();
        menos_max_ecg->raise();
        menos_min_spo2->raise();
        mas_min_spo2->raise();
        menos_max_spo2->raise();
        mas_max_spo2->raise();
        menos_min_rpm->raise();
        mas_min_rpm->raise();
        mas_max_rpm->raise();
        menos_max_rpm->raise();
        label_8->raise();

        retranslateUi(config_alarmas);

        QMetaObject::connectSlotsByName(config_alarmas);
    } // setupUi

    void retranslateUi(QDialog *config_alarmas)
    {
        config_alarmas->setWindowTitle(QCoreApplication::translate("config_alarmas", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("config_alarmas", "SpO2", nullptr));
        label_4->setText(QCoreApplication::translate("config_alarmas", "ECG", nullptr));
        ecg_alarm_min->setText(QCoreApplication::translate("config_alarmas", "00", nullptr));
        ecg_alarm_max->setText(QCoreApplication::translate("config_alarmas", "00", nullptr));
        spo2_alarm_min->setText(QCoreApplication::translate("config_alarmas", "00", nullptr));
        spo2_alarm_max->setText(QCoreApplication::translate("config_alarmas", "00", nullptr));
        rpm_alarm_min->setText(QCoreApplication::translate("config_alarmas", "00", nullptr));
        rpm_alarm_max->setText(QCoreApplication::translate("config_alarmas", "00", nullptr));
        menos_min_ecg->setText(QString());
        mas_min_ecg->setText(QString());
        menos_max_ecg->setText(QString());
        menos_min_spo2->setText(QString());
        mas_min_spo2->setText(QString());
        menos_max_spo2->setText(QString());
        mas_max_spo2->setText(QString());
        menos_min_rpm->setText(QString());
        mas_min_rpm->setText(QString());
        mas_max_rpm->setText(QString());
        menos_max_rpm->setText(QString());
        Regis->setText(QCoreApplication::translate("config_alarmas", "Alarmas", nullptr));
        mas_max_ecg->setText(QString());
        OK->setText(QString());
        CERRAR->setText(QString());
        label_5->setText(QCoreApplication::translate("config_alarmas", "RANGO M\303\215NIMO", nullptr));
        label_10->setText(QCoreApplication::translate("config_alarmas", "RANGO MAXIMO", nullptr));
        label_3->setText(QString());
        label_8->setText(QCoreApplication::translate("config_alarmas", "TEMP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class config_alarmas: public Ui_config_alarmas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_ALARMAS_H
