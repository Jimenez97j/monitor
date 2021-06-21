#include "enviardatos.h"
#include "ui_enviardatos.h"
#include <QMessageBox>

int contpos_9 = 0;

    enviardatos::enviardatos(QWidget *parent, SerialSpo2 *serialspo2_enviar_datos) :
    QDialog(parent),
    ui(new Ui::enviardatos)
{
    spo2serial_9 = serialspo2_enviar_datos;
    ui->setupUi(this);
    connect(spo2serial_9, SIGNAL(boton_ajustes(QString )), this, SLOT(boton_handle_9(QString )), Qt::QueuedConnection);
}

enviardatos::~enviardatos()
{
    delete ui;
}

void enviardatos::boton_handle_9(QString x){

    if (x == "derecha"){
    contpos_9 = contpos_9 + 1;
    if(contpos_9 > 8){
        contpos_9 = 8;
    }
    opciones_enviardatos();
    }

    else if(x == "izquierda"){
        contpos_9 = contpos_9 - 1;
        if(contpos_9 < 0){
            contpos_9 = 0;
        }
        opciones_enviardatos();
    }

}

void enviardatos:: opciones_enviardatos(){
    switch(contpos_9)
    {
    case 0:
        ui->bpm_envio->setStyleSheet("background-color:red;");
        ui->spo2_envio->setStyleSheet("");
        break;
    case 1:
        ui->spo2_envio->setStyleSheet("background-color:red;");
        ui->bpm_envio->setStyleSheet("");
        ui->pani_envio->setStyleSheet("");
        break;
    case 2:
        ui->pani_envio->setStyleSheet("background-color:red;");
        ui->spo2_envio->setStyleSheet("");
        ui->temp_envio->setStyleSheet("");
        break;
    case 3:
        ui->temp_envio->setStyleSheet("background-color:red;");
        ui->pani_envio->setStyleSheet("");
        ui->toolButton_5->setStyleSheet("");
        break;
    case 4:
        ui->toolButton_5->setStyleSheet("background-color:red;");
        ui->temp_envio->setStyleSheet("");
        break;

    }
}


void enviardatos::on_bpm_envio_clicked()
{
    emit send_data(1);
}

void enviardatos::on_spo2_envio_clicked()
{
     emit send_data(2);
}

void enviardatos::on_pani_envio_clicked()
{
     emit send_data(3);
}

void enviardatos::on_temp_envio_clicked()
{
     emit send_data(4);
}

void enviardatos::on_toolButton_5_clicked()
{
     emit send_data(5);
}
