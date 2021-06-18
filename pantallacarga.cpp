#include "pantallacarga.h"
#include "ui_pantallacarga.h"
#include <QDebug>
#include <QTimer>
#include <QPalette>
#include <QMessageBox>

int contador_barra=0;
bool* status_usb = new bool[3];
int carga = 0;

PantallaCarga::PantallaCarga(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PantallaCarga)
{
    ui->setupUi(this);
    QTimer *cronometro=new QTimer(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer()));
    cronometro->start(1);
    ui->barradecarga->setValue(0);
    ui->barradecarga->setMinimum(0);
    ui->barradecarga->setMaximum(100);
   // ui->barradecarga->setStyleSheet(ui->barradecarga->property("defaultStyleSheet").toString() + " QProgressBar::chunk { background: #000080; }");
}

PantallaCarga::~PantallaCarga()
{
    delete ui;
}

void PantallaCarga::funcionActivacionTimer(){
status_usb = usb();
contador_barra=contador_barra+1;

if(contador_barra==1500){
    emit leds_t();
    emit check_inicio();
    ui->barradecarga->setValue(0);
    if(!status_usb[0]){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error en el sistema, posible problema de Hardware");
        msgBox.setText("El acoplamiento de Spo2, temperatura, PANI y alarmas no responde. Si continua con el encendido estás mediciones no estarán disponibles");
        msgBox.setInformativeText("¿Desea continuar?");
        msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        int ret = msgBox.exec();
        QString system_out = "sudo shutdown now";

        switch (ret) {
          case QMessageBox::No:
                system(system_out.toStdString().c_str());
                exit(EXIT_FAILURE);
             break;
          case QMessageBox::Yes:
                carga = carga + 15;
                ui->barradecarga->setValue(carga);
              break;
        }

    }else{carga = carga + 15; ui->barradecarga->setValue(carga);}
    if(!status_usb[1]){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error en el sistema, posible problema de Hardware");
        msgBox.setText("El acoplamiento de ECG no responde. Si continua con el encendido estás mediciones no estarán disponibles");
        msgBox.setInformativeText("¿Desea continuar?");
        msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        int ret = msgBox.exec();
        QString system_out = "sudo shutdown now";

        switch (ret) {
          case QMessageBox::No:
                system(system_out.toStdString().c_str());
                exit(EXIT_FAILURE);
             break;
        case QMessageBox::Yes:
              carga = carga + 5;
              ui->barradecarga->setValue(carga);
              break;
        }

    }else{carga = carga + 5; ui->barradecarga->setValue(carga);}
    if(!status_usb[2]){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error en el sistema, posible problema de Hardware");
        msgBox.setText("El acoplamiento de datos ECG (latidos por minuto, derivaciones, rpm) no responde. Si continua con el encendido estás mediciones no estarán disponibles");
        msgBox.setInformativeText("¿Desea continuar?");
        msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        int ret = msgBox.exec();
        QString system_out = "sudo shutdown now";

        switch (ret) {
          case QMessageBox::No:
                system(system_out.toStdString().c_str());
                exit(EXIT_FAILURE);
             break;
          case QMessageBox::Yes:
              carga = carga + 5;
              ui->barradecarga->setValue(carga);
              break;
        }
    }else{carga = carga + 5; ui->barradecarga->setValue(carga);}

}

if(contador_barra==3000) {
    if(!status_usb[3]){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error en el sistema, base de datos no encontrada.");
        msgBox.setText("No se encontró una base de datos valida. Si continua con el encendido datos, alarmas, configuraciones no estarán disponibles.");
        msgBox.setInformativeText("¿Desea continuar?");
        msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        int ret = msgBox.exec();
        QString system_out = "sudo shutdown now";

        switch (ret) {
          case QMessageBox::No:
                system(system_out.toStdString().c_str());
                exit(EXIT_FAILURE);
             break;
        case QMessageBox::Yes:
              carga = carga + 15;
              ui->barradecarga->setValue(carga);
              break;
        }

    }else{carga = carga + 15; ui->barradecarga->setValue(carga);}
}

if(contador_barra==4500) {
    if(!status_usb[3]){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error en el sistema, directorio de imagenes no encontrado.");
        msgBox.setText("No se encontró un directorio y falló la creación del mismo, no será posible tomar capturas de pantalla.");
        msgBox.setInformativeText("¿Desea continuar?");
        msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        int ret = msgBox.exec();
        QString system_out = "sudo shutdown now";

        switch (ret) {
          case QMessageBox::No:
                system(system_out.toStdString().c_str());
                exit(EXIT_FAILURE);
             break;
        case QMessageBox::Yes:
              carga = carga = 100;
              ui->barradecarga->setValue(carga);
              break;
        }

    }else{carga = 100; ui->barradecarga->setValue(carga);}
}

if(contador_barra>6000) {
    if(carga==100) {
        emit leds_l();
        carga = 105;
    }
    if(carga==105) {
        this->close();
    }
 }

}

