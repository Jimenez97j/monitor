/********************************************************************************
** Form generated from reading UI file 'error.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERROR_H
#define UI_ERROR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Error
{
public:
    QWidget *widget;
    QLabel *ErrorTi;
    QLabel *PC;
    QLabel *CON;
    QLabel *EB;
    QLabel *BD;
    QPushButton *Reiniciar;
    QPushButton *OK;
    QLabel *PC_ver;
    QLabel *BD_Ver;
    QLabel *EB_ver;
    QLabel *COn_ver;
    QLabel *Estado;

    void setupUi(QDialog *Error)
    {
        if (Error->objectName().isEmpty())
            Error->setObjectName(QString::fromUtf8("Error"));
        Error->resize(500, 350);
        Error->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));
        widget = new QWidget(Error);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 0, 421, 361));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));
        ErrorTi = new QLabel(widget);
        ErrorTi->setObjectName(QString::fromUtf8("ErrorTi"));
        ErrorTi->setGeometry(QRect(10, 10, 81, 31));
        QPalette palette;
        QBrush brush(QColor(211, 215, 207, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(85, 87, 83, 255));
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
        ErrorTi->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(21);
        font.setBold(true);
        font.setWeight(75);
        ErrorTi->setFont(font);
        ErrorTi->setCursor(QCursor(Qt::BlankCursor));
        PC = new QLabel(widget);
        PC->setObjectName(QString::fromUtf8("PC"));
        PC->setGeometry(QRect(30, 80, 201, 17));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        PC->setFont(font1);
        CON = new QLabel(widget);
        CON->setObjectName(QString::fromUtf8("CON"));
        CON->setGeometry(QRect(30, 130, 91, 20));
        CON->setFont(font1);
        EB = new QLabel(widget);
        EB->setObjectName(QString::fromUtf8("EB"));
        EB->setGeometry(QRect(30, 180, 141, 17));
        EB->setFont(font1);
        BD = new QLabel(widget);
        BD->setObjectName(QString::fromUtf8("BD"));
        BD->setGeometry(QRect(30, 230, 111, 20));
        BD->setFont(font1);
        Reiniciar = new QPushButton(widget);
        Reiniciar->setObjectName(QString::fromUtf8("Reiniciar"));
        Reiniciar->setGeometry(QRect(240, 300, 81, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font2.setBold(true);
        font2.setWeight(75);
        Reiniciar->setFont(font2);
        Reiniciar->setCursor(QCursor(Qt::BlankCursor));
        Reiniciar->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 41, 41);"));
        Reiniciar->setFlat(false);
        OK = new QPushButton(widget);
        OK->setObjectName(QString::fromUtf8("OK"));
        OK->setGeometry(QRect(330, 299, 81, 31));
        OK->setFont(font2);
        OK->setCursor(QCursor(Qt::BlankCursor));
        OK->setStyleSheet(QString::fromUtf8("background-color: rgb(138, 226, 52);"));
        PC_ver = new QLabel(widget);
        PC_ver->setObjectName(QString::fromUtf8("PC_ver"));
        PC_ver->setGeometry(QRect(270, 80, 91, 17));
        QPalette palette1;
        QBrush brush3(QColor(238, 238, 236, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        PC_ver->setPalette(palette1);
        PC_ver->setFont(font2);
        BD_Ver = new QLabel(widget);
        BD_Ver->setObjectName(QString::fromUtf8("BD_Ver"));
        BD_Ver->setGeometry(QRect(270, 230, 101, 20));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        BD_Ver->setPalette(palette2);
        BD_Ver->setFont(font2);
        EB_ver = new QLabel(widget);
        EB_ver->setObjectName(QString::fromUtf8("EB_ver"));
        EB_ver->setGeometry(QRect(270, 180, 91, 17));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        EB_ver->setPalette(palette3);
        EB_ver->setFont(font2);
        COn_ver = new QLabel(widget);
        COn_ver->setObjectName(QString::fromUtf8("COn_ver"));
        COn_ver->setGeometry(QRect(270, 130, 91, 17));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        COn_ver->setPalette(palette4);
        COn_ver->setFont(font2);
        Estado = new QLabel(widget);
        Estado->setObjectName(QString::fromUtf8("Estado"));
        Estado->setGeometry(QRect(270, 40, 67, 17));
        QPalette palette5;
        QBrush brush4(QColor(78, 154, 6, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        Estado->setPalette(palette5);
        Estado->setFont(font2);

        retranslateUi(Error);

        Reiniciar->setDefault(false);


        QMetaObject::connectSlotsByName(Error);
    } // setupUi

    void retranslateUi(QDialog *Error)
    {
        Error->setWindowTitle(QCoreApplication::translate("Error", "Dialog", nullptr));
        ErrorTi->setText(QCoreApplication::translate("Error", "ERROR", nullptr));
        PC->setText(QCoreApplication::translate("Error", "Puertos de Comunicaci\303\263n", nullptr));
        CON->setText(QCoreApplication::translate("Error", "Conexiones", nullptr));
        EB->setText(QCoreApplication::translate("Error", "Estado de Bater\303\255a", nullptr));
        BD->setText(QCoreApplication::translate("Error", "Base de datos", nullptr));
        Reiniciar->setText(QCoreApplication::translate("Error", "Reiniciar", nullptr));
        OK->setText(QCoreApplication::translate("Error", "OK", nullptr));
        PC_ver->setText(QCoreApplication::translate("Error", "Verificando...", nullptr));
        BD_Ver->setText(QCoreApplication::translate("Error", "Verificando...", nullptr));
        EB_ver->setText(QCoreApplication::translate("Error", "Verificando...", nullptr));
        COn_ver->setText(QCoreApplication::translate("Error", "Verificando...", nullptr));
        Estado->setText(QCoreApplication::translate("Error", "ESTADO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Error: public Ui_Error {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERROR_H
