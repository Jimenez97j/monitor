/********************************************************************************
** Form generated from reading UI file 'pantallacarga.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANTALLACARGA_H
#define UI_PANTALLACARGA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_PantallaCarga
{
public:
    QProgressBar *barradecarga;
    QLabel *label;

    void setupUi(QDialog *PantallaCarga)
    {
        if (PantallaCarga->objectName().isEmpty())
            PantallaCarga->setObjectName(QString::fromUtf8("PantallaCarga"));
        PantallaCarga->resize(800, 480);
        barradecarga = new QProgressBar(PantallaCarga);
        barradecarga->setObjectName(QString::fromUtf8("barradecarga"));
        barradecarga->setGeometry(QRect(0, 440, 801, 41));
        QPalette palette;
        QBrush brush(QColor(211, 215, 207, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(69, 81, 151, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush2(QColor(69, 81, 151, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush3(QColor(190, 190, 190, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        QBrush brush4(QColor(0, 0, 0, 128));
        brush4.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        barradecarga->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        barradecarga->setFont(font);
        barradecarga->setAutoFillBackground(false);
        barradecarga->setStyleSheet(QString::fromUtf8("QProgressBar::chunk  {background: #000080; }\n"
""));
        barradecarga->setValue(60);
        barradecarga->setAlignment(Qt::AlignCenter);
        barradecarga->setTextVisible(true);
        barradecarga->setOrientation(Qt::Horizontal);
        label = new QLabel(PantallaCarga);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 801, 441));
        label->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/pantalladecarga.png")));

        retranslateUi(PantallaCarga);

        QMetaObject::connectSlotsByName(PantallaCarga);
    } // setupUi

    void retranslateUi(QDialog *PantallaCarga)
    {
        PantallaCarga->setWindowTitle(QCoreApplication::translate("PantallaCarga", "Dialog", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PantallaCarga: public Ui_PantallaCarga {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANTALLACARGA_H
