/********************************************************************************
** Form generated from reading UI file 'enviardatos.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENVIARDATOS_H
#define UI_ENVIARDATOS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_enviardatos
{
public:
    QToolButton *bpm_envio;
    QToolButton *spo2_envio;
    QToolButton *pani_envio;
    QToolButton *temp_envio;
    QToolButton *toolButton_5;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *enviardatos)
    {
        if (enviardatos->objectName().isEmpty())
            enviardatos->setObjectName(QString::fromUtf8("enviardatos"));
        enviardatos->resize(602, 110);
        enviardatos->setStyleSheet(QString::fromUtf8("background-color: #3297db"));
        bpm_envio = new QToolButton(enviardatos);
        bpm_envio->setObjectName(QString::fromUtf8("bpm_envio"));
        bpm_envio->setGeometry(QRect(25, 30, 65, 65));
        bpm_envio->setStyleSheet(QString::fromUtf8("border:none;\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagenes/btn_Corazon.png"), QSize(), QIcon::Normal, QIcon::Off);
        bpm_envio->setIcon(icon);
        bpm_envio->setIconSize(QSize(65, 65));
        spo2_envio = new QToolButton(enviardatos);
        spo2_envio->setObjectName(QString::fromUtf8("spo2_envio"));
        spo2_envio->setGeometry(QRect(147, 30, 65, 65));
        spo2_envio->setStyleSheet(QString::fromUtf8("border:none;\n"
"\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imagenes/btn_CaraSonriente.png"), QSize(), QIcon::Normal, QIcon::Off);
        spo2_envio->setIcon(icon1);
        spo2_envio->setIconSize(QSize(65, 65));
        pani_envio = new QToolButton(enviardatos);
        pani_envio->setObjectName(QString::fromUtf8("pani_envio"));
        pani_envio->setGeometry(QRect(268, 30, 65, 65));
        pani_envio->setStyleSheet(QString::fromUtf8("border:none;\n"
"\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imagenes/btn_EnviarPANI.png"), QSize(), QIcon::Normal, QIcon::Off);
        pani_envio->setIcon(icon2);
        pani_envio->setIconSize(QSize(65, 65));
        temp_envio = new QToolButton(enviardatos);
        temp_envio->setObjectName(QString::fromUtf8("temp_envio"));
        temp_envio->setGeometry(QRect(387, 30, 65, 65));
        temp_envio->setStyleSheet(QString::fromUtf8("border:none;\n"
"\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imagenes/btn_EnviarTemp.png"), QSize(), QIcon::Normal, QIcon::Off);
        temp_envio->setIcon(icon3);
        temp_envio->setIconSize(QSize(65, 65));
        toolButton_5 = new QToolButton(enviardatos);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        toolButton_5->setGeometry(QRect(507, 30, 65, 65));
        toolButton_5->setStyleSheet(QString::fromUtf8("border:none;\n"
"\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/imagenes/btn_EnviarTodo.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon4);
        toolButton_5->setIconSize(QSize(65, 65));
        label = new QLabel(enviardatos);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 101, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(enviardatos);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 2, 101, 17));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(enviardatos);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(250, 0, 101, 20));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4 = new QLabel(enviardatos);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(370, 2, 111, 17));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_5 = new QLabel(enviardatos);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(490, 2, 121, 16));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        retranslateUi(enviardatos);

        QMetaObject::connectSlotsByName(enviardatos);
    } // setupUi

    void retranslateUi(QDialog *enviardatos)
    {
        enviardatos->setWindowTitle(QCoreApplication::translate("enviardatos", "Dialog", nullptr));
        bpm_envio->setText(QString());
        spo2_envio->setText(QString());
        pani_envio->setText(QString());
        temp_envio->setText(QString());
        toolButton_5->setText(QString());
        label->setText(QCoreApplication::translate("enviardatos", "ENVIAR BPM", nullptr));
        label_2->setText(QCoreApplication::translate("enviardatos", "ENVIAR SPO2", nullptr));
        label_3->setText(QCoreApplication::translate("enviardatos", "ENVIAR PANI", nullptr));
        label_4->setText(QCoreApplication::translate("enviardatos", "ENVIAR TEMP", nullptr));
        label_5->setText(QCoreApplication::translate("enviardatos", "ENVIAR TODO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class enviardatos: public Ui_enviardatos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENVIARDATOS_H
