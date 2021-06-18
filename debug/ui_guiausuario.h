/********************************************************************************
** Form generated from reading UI file 'guiausuario.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIAUSUARIO_H
#define UI_GUIAUSUARIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiaUsuario
{
public:
    QTabWidget *tabWidget;
    QWidget *Guia;
    QLabel *label;
    QWidget *Menu;
    QLabel *label_2;
    QWidget *Bienvenida;
    QLabel *label_3;
    QWidget *VistaGeneral;
    QLabel *label_4;
    QWidget *Tendencias;
    QLabel *label_5;
    QWidget *T2;
    QLabel *label_6;
    QWidget *CapPantalla;
    QLabel *label_7;
    QWidget *Galeria;
    QLabel *label_8;
    QWidget *G2;
    QLabel *label_9;
    QWidget *Alarmas;
    QLabel *label_10;
    QWidget *A2;
    QLabel *label_11;
    QWidget *PANI;
    QLabel *label_12;
    QWidget *Derivaciones;
    QLabel *label_13;
    QWidget *Registro;
    QLabel *label_14;
    QWidget *R2;
    QLabel *label_15;
    QWidget *Informacion;
    QLabel *label_16;
    QWidget *I2;
    QLabel *label_17;
    QWidget *Numerico;
    QLabel *label_18;
    QWidget *N2;
    QLabel *label_19;
    QWidget *Configuracion;
    QLabel *label_20;
    QWidget *C2;
    QLabel *label_21;
    QWidget *Sonido;
    QLabel *label_22;
    QWidget *Parametros;
    QLabel *label_23;
    QWidget *Contacto;
    QLabel *label_24;
    QWidget *tab_24;
    QLabel *label_25;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;

    void setupUi(QDialog *GuiaUsuario)
    {
        if (GuiaUsuario->objectName().isEmpty())
            GuiaUsuario->setObjectName(QString::fromUtf8("GuiaUsuario"));
        GuiaUsuario->resize(800, 480);
        GuiaUsuario->setCursor(QCursor(Qt::BlankCursor));
        tabWidget = new QTabWidget(GuiaUsuario);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 801, 481));
        tabWidget->setCursor(QCursor(Qt::BlankCursor));
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 70, 88);\n"
"font: 11pt \"Ubuntu Condensed\" ;\n"
"color:#a3fcd7;\n"
"\n"
"                               "));
        tabWidget->setTabPosition(QTabWidget::South);
        Guia = new QWidget();
        Guia->setObjectName(QString::fromUtf8("Guia"));
        Guia->setCursor(QCursor(Qt::BlankCursor));
        label = new QLabel(Guia);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 799, 451));
        label->setCursor(QCursor(Qt::BlankCursor));
        label->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/1")));
        label->setScaledContents(true);
        tabWidget->addTab(Guia, QString());
        Menu = new QWidget();
        Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->setCursor(QCursor(Qt::BlankCursor));
        label_2 = new QLabel(Menu);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 800, 451));
        label_2->setCursor(QCursor(Qt::BlankCursor));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/2.png")));
        label_2->setScaledContents(true);
        tabWidget->addTab(Menu, QString());
        Bienvenida = new QWidget();
        Bienvenida->setObjectName(QString::fromUtf8("Bienvenida"));
        Bienvenida->setCursor(QCursor(Qt::BlankCursor));
        label_3 = new QLabel(Bienvenida);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 0, 800, 480));
        label_3->setCursor(QCursor(Qt::BlankCursor));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/3.png")));
        label_3->setScaledContents(true);
        tabWidget->addTab(Bienvenida, QString());
        VistaGeneral = new QWidget();
        VistaGeneral->setObjectName(QString::fromUtf8("VistaGeneral"));
        VistaGeneral->setCursor(QCursor(Qt::BlankCursor));
        label_4 = new QLabel(VistaGeneral);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 0, 800, 451));
        label_4->setCursor(QCursor(Qt::BlankCursor));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/4.png")));
        label_4->setScaledContents(true);
        tabWidget->addTab(VistaGeneral, QString());
        Tendencias = new QWidget();
        Tendencias->setObjectName(QString::fromUtf8("Tendencias"));
        Tendencias->setCursor(QCursor(Qt::BlankCursor));
        label_5 = new QLabel(Tendencias);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 0, 800, 451));
        label_5->setCursor(QCursor(Qt::BlankCursor));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/5.png")));
        label_5->setScaledContents(true);
        tabWidget->addTab(Tendencias, QString());
        T2 = new QWidget();
        T2->setObjectName(QString::fromUtf8("T2"));
        T2->setCursor(QCursor(Qt::BlankCursor));
        label_6 = new QLabel(T2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 0, 800, 451));
        label_6->setCursor(QCursor(Qt::BlankCursor));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/6.png")));
        label_6->setScaledContents(true);
        tabWidget->addTab(T2, QString());
        CapPantalla = new QWidget();
        CapPantalla->setObjectName(QString::fromUtf8("CapPantalla"));
        CapPantalla->setCursor(QCursor(Qt::BlankCursor));
        label_7 = new QLabel(CapPantalla);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(0, 0, 800, 451));
        label_7->setCursor(QCursor(Qt::BlankCursor));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/7.png")));
        label_7->setScaledContents(true);
        tabWidget->addTab(CapPantalla, QString());
        Galeria = new QWidget();
        Galeria->setObjectName(QString::fromUtf8("Galeria"));
        Galeria->setCursor(QCursor(Qt::BlankCursor));
        label_8 = new QLabel(Galeria);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(0, 0, 800, 451));
        label_8->setCursor(QCursor(Qt::BlankCursor));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/8.png")));
        label_8->setScaledContents(true);
        tabWidget->addTab(Galeria, QString());
        G2 = new QWidget();
        G2->setObjectName(QString::fromUtf8("G2"));
        G2->setCursor(QCursor(Qt::BlankCursor));
        label_9 = new QLabel(G2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(0, 0, 800, 451));
        label_9->setCursor(QCursor(Qt::BlankCursor));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/9.png")));
        label_9->setScaledContents(true);
        tabWidget->addTab(G2, QString());
        Alarmas = new QWidget();
        Alarmas->setObjectName(QString::fromUtf8("Alarmas"));
        Alarmas->setCursor(QCursor(Qt::BlankCursor));
        label_10 = new QLabel(Alarmas);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(0, 0, 800, 451));
        label_10->setCursor(QCursor(Qt::BlankCursor));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/10.png")));
        label_10->setScaledContents(true);
        tabWidget->addTab(Alarmas, QString());
        A2 = new QWidget();
        A2->setObjectName(QString::fromUtf8("A2"));
        A2->setCursor(QCursor(Qt::BlankCursor));
        label_11 = new QLabel(A2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(0, 0, 800, 451));
        label_11->setCursor(QCursor(Qt::BlankCursor));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/11.png")));
        label_11->setScaledContents(true);
        tabWidget->addTab(A2, QString());
        PANI = new QWidget();
        PANI->setObjectName(QString::fromUtf8("PANI"));
        PANI->setCursor(QCursor(Qt::BlankCursor));
        label_12 = new QLabel(PANI);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(0, 0, 800, 451));
        label_12->setCursor(QCursor(Qt::BlankCursor));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/12.png")));
        label_12->setScaledContents(true);
        tabWidget->addTab(PANI, QString());
        Derivaciones = new QWidget();
        Derivaciones->setObjectName(QString::fromUtf8("Derivaciones"));
        Derivaciones->setCursor(QCursor(Qt::BlankCursor));
        label_13 = new QLabel(Derivaciones);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(0, 0, 800, 451));
        label_13->setCursor(QCursor(Qt::BlankCursor));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/13.png")));
        label_13->setScaledContents(true);
        tabWidget->addTab(Derivaciones, QString());
        Registro = new QWidget();
        Registro->setObjectName(QString::fromUtf8("Registro"));
        Registro->setCursor(QCursor(Qt::BlankCursor));
        label_14 = new QLabel(Registro);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(0, 0, 800, 451));
        label_14->setCursor(QCursor(Qt::BlankCursor));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/14.png")));
        label_14->setScaledContents(true);
        tabWidget->addTab(Registro, QString());
        R2 = new QWidget();
        R2->setObjectName(QString::fromUtf8("R2"));
        R2->setCursor(QCursor(Qt::BlankCursor));
        label_15 = new QLabel(R2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(0, 0, 800, 451));
        label_15->setCursor(QCursor(Qt::BlankCursor));
        label_15->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/15.png")));
        label_15->setScaledContents(true);
        tabWidget->addTab(R2, QString());
        Informacion = new QWidget();
        Informacion->setObjectName(QString::fromUtf8("Informacion"));
        Informacion->setCursor(QCursor(Qt::BlankCursor));
        label_16 = new QLabel(Informacion);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(0, 0, 800, 451));
        label_16->setCursor(QCursor(Qt::BlankCursor));
        label_16->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/16.png")));
        label_16->setScaledContents(true);
        tabWidget->addTab(Informacion, QString());
        I2 = new QWidget();
        I2->setObjectName(QString::fromUtf8("I2"));
        I2->setCursor(QCursor(Qt::BlankCursor));
        label_17 = new QLabel(I2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(0, 0, 800, 451));
        label_17->setCursor(QCursor(Qt::BlankCursor));
        label_17->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/17.png")));
        label_17->setScaledContents(true);
        tabWidget->addTab(I2, QString());
        Numerico = new QWidget();
        Numerico->setObjectName(QString::fromUtf8("Numerico"));
        Numerico->setCursor(QCursor(Qt::BlankCursor));
        label_18 = new QLabel(Numerico);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(0, 0, 800, 451));
        label_18->setCursor(QCursor(Qt::BlankCursor));
        label_18->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/18.png")));
        label_18->setScaledContents(true);
        tabWidget->addTab(Numerico, QString());
        N2 = new QWidget();
        N2->setObjectName(QString::fromUtf8("N2"));
        N2->setCursor(QCursor(Qt::BlankCursor));
        label_19 = new QLabel(N2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(0, 0, 800, 451));
        label_19->setCursor(QCursor(Qt::BlankCursor));
        label_19->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/19.png")));
        label_19->setScaledContents(true);
        tabWidget->addTab(N2, QString());
        Configuracion = new QWidget();
        Configuracion->setObjectName(QString::fromUtf8("Configuracion"));
        Configuracion->setCursor(QCursor(Qt::BlankCursor));
        label_20 = new QLabel(Configuracion);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(0, 0, 800, 451));
        label_20->setCursor(QCursor(Qt::BlankCursor));
        label_20->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/20.png")));
        label_20->setScaledContents(true);
        tabWidget->addTab(Configuracion, QString());
        C2 = new QWidget();
        C2->setObjectName(QString::fromUtf8("C2"));
        C2->setCursor(QCursor(Qt::BlankCursor));
        label_21 = new QLabel(C2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(0, 0, 800, 451));
        label_21->setCursor(QCursor(Qt::BlankCursor));
        label_21->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/21.png")));
        label_21->setScaledContents(true);
        tabWidget->addTab(C2, QString());
        Sonido = new QWidget();
        Sonido->setObjectName(QString::fromUtf8("Sonido"));
        Sonido->setCursor(QCursor(Qt::BlankCursor));
        label_22 = new QLabel(Sonido);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(0, 0, 800, 451));
        label_22->setCursor(QCursor(Qt::BlankCursor));
        label_22->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/22.png")));
        label_22->setScaledContents(true);
        tabWidget->addTab(Sonido, QString());
        Parametros = new QWidget();
        Parametros->setObjectName(QString::fromUtf8("Parametros"));
        Parametros->setCursor(QCursor(Qt::BlankCursor));
        label_23 = new QLabel(Parametros);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(0, 0, 800, 451));
        label_23->setCursor(QCursor(Qt::BlankCursor));
        label_23->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/23.png")));
        label_23->setScaledContents(true);
        tabWidget->addTab(Parametros, QString());
        Contacto = new QWidget();
        Contacto->setObjectName(QString::fromUtf8("Contacto"));
        Contacto->setCursor(QCursor(Qt::BlankCursor));
        label_24 = new QLabel(Contacto);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(0, 0, 800, 451));
        label_24->setCursor(QCursor(Qt::BlankCursor));
        label_24->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/24.png")));
        label_24->setScaledContents(true);
        tabWidget->addTab(Contacto, QString());
        tab_24 = new QWidget();
        tab_24->setObjectName(QString::fromUtf8("tab_24"));
        tab_24->setCursor(QCursor(Qt::BlankCursor));
        label_25 = new QLabel(tab_24);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(0, 0, 800, 451));
        label_25->setCursor(QCursor(Qt::BlankCursor));
        label_25->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/25.png")));
        label_25->setScaledContents(true);
        tabWidget->addTab(tab_24, QString());
        toolButton = new QToolButton(GuiaUsuario);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(714, 14, 71, 23));
        toolButton->setCursor(QCursor(Qt::BlankCursor));
        toolButton->setStyleSheet(QString::fromUtf8("background-image: url(:/imagenes/SalirGuia.png);\n"
"background-repeat:none;\n"
"border:none"));
        toolButton_2 = new QToolButton(GuiaUsuario);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(700, 413, 81, 31));
        toolButton_2->setCursor(QCursor(Qt::BlankCursor));
        toolButton_2->setStyleSheet(QString::fromUtf8("background-color: #a3fcd7;\n"
"font: 11pt \"Ubuntu Condensed\" ;\n"
"color:rgb(0, 70, 88);\n"
""));
        toolButton_3 = new QToolButton(GuiaUsuario);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setGeometry(QRect(10, 413, 81, 31));
        toolButton_3->setCursor(QCursor(Qt::BlankCursor));
        toolButton_3->setStyleSheet(QString::fromUtf8("background-color: #a3fcd7;\n"
"font: 11pt \"Ubuntu Condensed\" ;\n"
"color:rgb(0, 70, 88);\n"
""));

        retranslateUi(GuiaUsuario);

        tabWidget->setCurrentIndex(22);


        QMetaObject::connectSlotsByName(GuiaUsuario);
    } // setupUi

    void retranslateUi(QDialog *GuiaUsuario)
    {
        GuiaUsuario->setWindowTitle(QCoreApplication::translate("GuiaUsuario", "Dialog", nullptr));
        label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Guia), QCoreApplication::translate("GuiaUsuario", "Guia", nullptr));
        label_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Menu), QCoreApplication::translate("GuiaUsuario", "Menu", nullptr));
        label_3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Bienvenida), QCoreApplication::translate("GuiaUsuario", "Bienvenida", nullptr));
        label_4->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(VistaGeneral), QCoreApplication::translate("GuiaUsuario", "Vista General", nullptr));
        label_5->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Tendencias), QCoreApplication::translate("GuiaUsuario", "Tendencias", nullptr));
        label_6->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(T2), QCoreApplication::translate("GuiaUsuario", "T2", nullptr));
        label_7->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(CapPantalla), QCoreApplication::translate("GuiaUsuario", "Cap.Pantalla", nullptr));
        label_8->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Galeria), QCoreApplication::translate("GuiaUsuario", "Galeria", nullptr));
        label_9->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(G2), QCoreApplication::translate("GuiaUsuario", "G2", nullptr));
        label_10->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Alarmas), QCoreApplication::translate("GuiaUsuario", "Alarmas", nullptr));
        label_11->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(A2), QCoreApplication::translate("GuiaUsuario", "A2", nullptr));
        label_12->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(PANI), QCoreApplication::translate("GuiaUsuario", "PANI", nullptr));
        label_13->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Derivaciones), QCoreApplication::translate("GuiaUsuario", "Derivaciones", nullptr));
        label_14->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Registro), QCoreApplication::translate("GuiaUsuario", "Registro", nullptr));
        label_15->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(R2), QCoreApplication::translate("GuiaUsuario", "R2", nullptr));
        label_16->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Informacion), QCoreApplication::translate("GuiaUsuario", "Informaci\303\263n", nullptr));
        label_17->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(I2), QCoreApplication::translate("GuiaUsuario", "I2", nullptr));
        label_18->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Numerico), QCoreApplication::translate("GuiaUsuario", "Numerico", nullptr));
        label_19->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(N2), QCoreApplication::translate("GuiaUsuario", "N2", nullptr));
        label_20->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Configuracion), QCoreApplication::translate("GuiaUsuario", "Configuraci\303\263n", nullptr));
        label_21->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(C2), QCoreApplication::translate("GuiaUsuario", "C2", nullptr));
        label_22->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Sonido), QCoreApplication::translate("GuiaUsuario", "Sonido", nullptr));
        label_23->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Parametros), QCoreApplication::translate("GuiaUsuario", "Parametros", nullptr));
        label_24->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Contacto), QCoreApplication::translate("GuiaUsuario", "Contacto", nullptr));
        label_25->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_24), QCoreApplication::translate("GuiaUsuario", "Page", nullptr));
        toolButton->setText(QString());
        toolButton_2->setText(QCoreApplication::translate("GuiaUsuario", "Siguiente", nullptr));
        toolButton_3->setText(QCoreApplication::translate("GuiaUsuario", "Anterior", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GuiaUsuario: public Ui_GuiaUsuario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIAUSUARIO_H
