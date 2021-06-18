/********************************************************************************
** Form generated from reading UI file 'galeria.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GALERIA_H
#define UI_GALERIA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_galeria
{
public:
    QComboBox *comboBox;
    QLabel *imagen;
    QLabel *min1;
    QLabel *min2;
    QLabel *min3;
    QToolButton *min1_boton;
    QToolButton *min2_boton;
    QToolButton *min3_boton;
    QLabel *label;
    QToolButton *toolButton;
    QToolButton *trash;
    QLabel *label_2;

    void setupUi(QDialog *galeria)
    {
        if (galeria->objectName().isEmpty())
            galeria->setObjectName(QString::fromUtf8("galeria"));
        galeria->resize(1290, 800);
        galeria->setCursor(QCursor(Qt::BlankCursor));
        comboBox = new QComboBox(galeria);
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(680, 33, 571, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        comboBox->setFont(font);
        comboBox->setCursor(QCursor(Qt::BlankCursor));
        comboBox->setStyleSheet(QString::fromUtf8("Visibility=\"Collapsed\">-- Seleccionar item --"));
        comboBox->setEditable(false);
        imagen = new QLabel(galeria);
        imagen->setObjectName(QString::fromUtf8("imagen"));
        imagen->setGeometry(QRect(40, 130, 901, 641));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        imagen->setFont(font1);
        imagen->setCursor(QCursor(Qt::BlankCursor));
        imagen->setScaledContents(true);
        min1 = new QLabel(galeria);
        min1->setObjectName(QString::fromUtf8("min1"));
        min1->setGeometry(QRect(1080, 125, 101, 81));
        min1->setCursor(QCursor(Qt::BlankCursor));
        min1->setScaledContents(true);
        min2 = new QLabel(galeria);
        min2->setObjectName(QString::fromUtf8("min2"));
        min2->setGeometry(QRect(1080, 230, 101, 81));
        min2->setCursor(QCursor(Qt::BlankCursor));
        min2->setScaledContents(true);
        min3 = new QLabel(galeria);
        min3->setObjectName(QString::fromUtf8("min3"));
        min3->setGeometry(QRect(1080, 335, 101, 81));
        min3->setCursor(QCursor(Qt::BlankCursor));
        min3->setScaledContents(true);
        min1_boton = new QToolButton(galeria);
        min1_boton->setObjectName(QString::fromUtf8("min1_boton"));
        min1_boton->setGeometry(QRect(1080, 125, 101, 81));
        min1_boton->setCursor(QCursor(Qt::BlankCursor));
        min1_boton->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"background-repeat:none;\n"
"border:none;\n"
"\n"
""));
        min2_boton = new QToolButton(galeria);
        min2_boton->setObjectName(QString::fromUtf8("min2_boton"));
        min2_boton->setGeometry(QRect(1080, 230, 101, 81));
        min2_boton->setCursor(QCursor(Qt::BlankCursor));
        min2_boton->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"background-repeat:none;\n"
"border:none;\n"
"\n"
""));
        min3_boton = new QToolButton(galeria);
        min3_boton->setObjectName(QString::fromUtf8("min3_boton"));
        min3_boton->setGeometry(QRect(1080, 335, 101, 81));
        min3_boton->setCursor(QCursor(Qt::BlankCursor));
        min3_boton->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"background-repeat:none;\n"
"border:none;\n"
"\n"
""));
        label = new QLabel(galeria);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1291, 801));
        label->setCursor(QCursor(Qt::BlankCursor));
        label->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/fondo_Alarmas.png")));
        label->setScaledContents(true);
        toolButton = new QToolButton(galeria);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(1180, 700, 90, 90));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font2.setBold(true);
        font2.setWeight(75);
        toolButton->setFont(font2);
        toolButton->setCursor(QCursor(Qt::BlankCursor));
        toolButton->setStyleSheet(QString::fromUtf8("border: 0px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagenes/btn_Cerrar.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(90, 90));
        trash = new QToolButton(galeria);
        trash->setObjectName(QString::fromUtf8("trash"));
        trash->setGeometry(QRect(1080, 700, 90, 90));
        trash->setCursor(QCursor(Qt::BlankCursor));
        trash->setStyleSheet(QString::fromUtf8("border: 0px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imagenes/btn_Eliminar.png"), QSize(), QIcon::Normal, QIcon::Off);
        trash->setIcon(icon1);
        trash->setIconSize(QSize(90, 90));
        label_2 = new QLabel(galeria);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1070, 560, 121, 17));
        label_2->setFont(font1);
        label->raise();
        comboBox->raise();
        imagen->raise();
        min1->raise();
        min2->raise();
        min3->raise();
        min1_boton->raise();
        min2_boton->raise();
        min3_boton->raise();
        toolButton->raise();
        trash->raise();
        label_2->raise();

        retranslateUi(galeria);

        QMetaObject::connectSlotsByName(galeria);
    } // setupUi

    void retranslateUi(QDialog *galeria)
    {
        galeria->setWindowTitle(QCoreApplication::translate("galeria", "Dialog", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("galeria", "Seleccionar imagen...", nullptr));

        imagen->setText(QCoreApplication::translate("galeria", "                                                      Seleccione una imagen para mostrar", nullptr));
        min1->setText(QString());
        min2->setText(QString());
        min3->setText(QString());
        min1_boton->setText(QString());
        min2_boton->setText(QString());
        min3_boton->setText(QString());
        label->setText(QString());
        trash->setText(QString());
        label_2->setText(QCoreApplication::translate("galeria", "Ultimas Capturas", nullptr));
    } // retranslateUi

};

namespace Ui {
    class galeria: public Ui_galeria {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GALERIA_H
