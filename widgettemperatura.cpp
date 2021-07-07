#include "widgettemperatura.h"
#include <QLabel>

WidgetTemperatura::WidgetTemperatura(QWidget *parent, int largo, int alto) : QWidget(parent)
{
    //setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::Popup);
    resize(largo, alto);
    setObjectName("widgetTemperatura");

    //setStyleSheet("QWidget#widgetTemperatura {border: 5Px solid rgb(9, 150, 219); border-radius: 5Px;}"); //#widgetTemperatura
    lblFondo = new QLabel(this);
    lblFondo->setStyleSheet("QLabel{background-color: black; color: rgb(9, 150, 219); border: 5Px solid rgb(9, 150, 219); border-radius: 15Px;}");
    lblFondo->setGeometry(QRect(0, 0, largo, alto));

    lblValor = new QLabel(this);
    QFont *fuente = new QFont;
    fuente->setPointSize(44);
    fuente->setBold(true);
    fuente->setWeight(75);
    lblValor->setFont(*fuente);
    lblValor->setStyleSheet("QLabel{color: rgb(9, 150, 219);}");
    lblValor->setGeometry(QRect(10, 0, 150, 100));

    lblNombre = new QLabel(this);
    fuente->setPointSize(20);
    fuente->setBold(true);
    fuente->setWeight(75);
    lblNombre->setFont(*fuente);
    lblNombre->setStyleSheet("QLabel{color: rgb(9, 150, 219);}");
    lblNombre->setGeometry(QRect(160, 0, 90, 50));
    lblNombre->setText("Temp");

    lblUnidad = new QLabel(this);
    fuente->setPointSize(22);
    fuente->setBold(true);
    fuente->setWeight(75);
    lblUnidad->setFont(*fuente);
    lblUnidad->setStyleSheet("QLabel{color: rgb(9, 150, 219);}");
    lblUnidad->setGeometry(QRect(160, 50, 90, 50));
    lblUnidad->setText("°C");

}

void WidgetTemperatura::set_valor(QString valor){
    lblValor->setText(valor);
}
