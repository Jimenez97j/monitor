/********************************************************************************
** Form generated from reading UI file 'paciente.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PACIENTE_H
#define UI_PACIENTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Paciente
{
public:
    QWidget *widget;
    QLabel *edad;
    QLabel *sexo;
    QLabel *Escsex;
    QLabel *nombe;
    QLabel *nota;
    QLabel *Escdad;
    QPlainTextEdit *notas;
    QLabel *Apellido;
    QLabel *Escnombre;
    QPushButton *paciente1;
    QPushButton *paciente2;
    QPushButton *paciente3;
    QLabel *sangre;
    QLabel *Escsangre;

    void setupUi(QDialog *Paciente)
    {
        if (Paciente->objectName().isEmpty())
            Paciente->setObjectName(QString::fromUtf8("Paciente"));
        Paciente->resize(340, 588);
        Paciente->setCursor(QCursor(Qt::BlankCursor));
        Paciente->setStyleSheet(QString::fromUtf8("background-color: #3297db;"));
        widget = new QWidget(Paciente);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(18, 20, 302, 542));
        widget->setCursor(QCursor(Qt::BlankCursor));
        widget->setStyleSheet(QString::fromUtf8("background-color: #0c4469;"));
        edad = new QLabel(widget);
        edad->setObjectName(QString::fromUtf8("edad"));
        edad->setGeometry(QRect(0, 80, 61, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        edad->setFont(font);
        edad->setCursor(QCursor(Qt::BlankCursor));
        edad->setStyleSheet(QString::fromUtf8("color:white;"));
        sexo = new QLabel(widget);
        sexo->setObjectName(QString::fromUtf8("sexo"));
        sexo->setGeometry(QRect(0, 119, 61, 31));
        sexo->setFont(font);
        sexo->setCursor(QCursor(Qt::BlankCursor));
        sexo->setStyleSheet(QString::fromUtf8("color:white;"));
        Escsex = new QLabel(widget);
        Escsex->setObjectName(QString::fromUtf8("Escsex"));
        Escsex->setGeometry(QRect(70, 120, 71, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        Escsex->setFont(font1);
        Escsex->setCursor(QCursor(Qt::BlankCursor));
        nombe = new QLabel(widget);
        nombe->setObjectName(QString::fromUtf8("nombe"));
        nombe->setGeometry(QRect(0, 0, 91, 31));
        nombe->setFont(font);
        nombe->setCursor(QCursor(Qt::BlankCursor));
        nombe->setStyleSheet(QString::fromUtf8("color:white;"));
        nota = new QLabel(widget);
        nota->setObjectName(QString::fromUtf8("nota"));
        nota->setGeometry(QRect(1, 210, 71, 31));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(12, 68, 105, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(255, 255, 255, 128));
        brush2.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush3(QColor(255, 255, 255, 128));
        brush3.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush4(QColor(255, 255, 255, 128));
        brush4.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        nota->setPalette(palette);
        nota->setFont(font);
        nota->setCursor(QCursor(Qt::BlankCursor));
        nota->setStyleSheet(QString::fromUtf8("color:white;"));
        Escdad = new QLabel(widget);
        Escdad->setObjectName(QString::fromUtf8("Escdad"));
        Escdad->setGeometry(QRect(70, 80, 61, 31));
        Escdad->setFont(font1);
        Escdad->setCursor(QCursor(Qt::BlankCursor));
        notas = new QPlainTextEdit(widget);
        notas->setObjectName(QString::fromUtf8("notas"));
        notas->setGeometry(QRect(70, 210, 222, 222));
        notas->setFont(font1);
        notas->viewport()->setProperty("cursor", QVariant(QCursor(Qt::BlankCursor)));
        notas->setCenterOnScroll(true);
        Apellido = new QLabel(widget);
        Apellido->setObjectName(QString::fromUtf8("Apellido"));
        Apellido->setGeometry(QRect(0, 40, 201, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font2.setBold(false);
        font2.setWeight(50);
        Apellido->setFont(font2);
        Apellido->setCursor(QCursor(Qt::BlankCursor));
        Escnombre = new QLabel(widget);
        Escnombre->setObjectName(QString::fromUtf8("Escnombre"));
        Escnombre->setGeometry(QRect(95, 0, 201, 31));
        Escnombre->setFont(font1);
        Escnombre->setCursor(QCursor(Qt::BlankCursor));
        paciente1 = new QPushButton(widget);
        paciente1->setObjectName(QString::fromUtf8("paciente1"));
        paciente1->setGeometry(QRect(30, 460, 60, 60));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font3.setBold(true);
        font3.setWeight(75);
        paciente1->setFont(font3);
        paciente1->setCursor(QCursor(Qt::BlankCursor));
        paciente1->setStyleSheet(QString::fromUtf8(""));
        paciente2 = new QPushButton(widget);
        paciente2->setObjectName(QString::fromUtf8("paciente2"));
        paciente2->setGeometry(QRect(120, 460, 60, 60));
        paciente2->setFont(font3);
        paciente2->setCursor(QCursor(Qt::BlankCursor));
        paciente2->setStyleSheet(QString::fromUtf8(""));
        paciente3 = new QPushButton(widget);
        paciente3->setObjectName(QString::fromUtf8("paciente3"));
        paciente3->setGeometry(QRect(210, 460, 60, 60));
        paciente3->setFont(font3);
        paciente3->setCursor(QCursor(Qt::BlankCursor));
        paciente3->setStyleSheet(QString::fromUtf8(""));
        sangre = new QLabel(widget);
        sangre->setObjectName(QString::fromUtf8("sangre"));
        sangre->setGeometry(QRect(0, 160, 161, 31));
        sangre->setFont(font);
        sangre->setCursor(QCursor(Qt::BlankCursor));
        sangre->setStyleSheet(QString::fromUtf8("color:white;"));
        Escsangre = new QLabel(widget);
        Escsangre->setObjectName(QString::fromUtf8("Escsangre"));
        Escsangre->setGeometry(QRect(170, 161, 91, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font4.setPointSize(20);
        Escsangre->setFont(font4);
        Escsangre->setCursor(QCursor(Qt::BlankCursor));

        retranslateUi(Paciente);

        QMetaObject::connectSlotsByName(Paciente);
    } // setupUi

    void retranslateUi(QDialog *Paciente)
    {
        Paciente->setWindowTitle(QCoreApplication::translate("Paciente", "Dialog", nullptr));
        edad->setText(QCoreApplication::translate("Paciente", "Edad:", nullptr));
        sexo->setText(QCoreApplication::translate("Paciente", "Sexo:", nullptr));
        Escsex->setText(QString());
        nombe->setText(QCoreApplication::translate("Paciente", "Nombre:", nullptr));
        nota->setText(QCoreApplication::translate("Paciente", "Nota:", nullptr));
        Escdad->setText(QString());
        notas->setPlainText(QString());
        Apellido->setText(QString());
        Escnombre->setText(QString());
        paciente1->setText(QCoreApplication::translate("Paciente", "1", nullptr));
        paciente2->setText(QCoreApplication::translate("Paciente", "2", nullptr));
        paciente3->setText(QCoreApplication::translate("Paciente", "3", nullptr));
        sangre->setText(QCoreApplication::translate("Paciente", "Tipo de Sangre:", nullptr));
        Escsangre->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Paciente: public Ui_Paciente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACIENTE_H
