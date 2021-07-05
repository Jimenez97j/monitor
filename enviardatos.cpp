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

void enviardatos::closeEvent(QCloseEvent*){
    emit bandera_perilla_9();
    //this->close();
    contpos_9 = 0;
    //delete this;
}

void enviardatos::boton_handle_9(QString x){

    if (x == "derecha"){
    contpos_9 = contpos_9 + 1;
    if(contpos_9 > 4){
        contpos_9 = 4;
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


    else if(x == "click"){
        on_okay_clicked();

    }

}

void enviardatos:: on_okay_clicked(){

    switch(contpos_9)
    {
    case 0:
       on_bpm_envio_clicked();
        break;
    case 1:
        on_spo2_envio_clicked();
        break;
    case 2:
        on_pani_envio_clicked();
        break;
    case 3:
        on_temp_envio_clicked();
        break;
    case 4:
        on_toolButton_5_clicked();
        break;
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
    emit bandera_perilla_9();
    emit send_data(1);
    this->close();
    contpos_9 = 0;
    delete this;
}

void enviardatos::on_spo2_envio_clicked()
{
    emit bandera_perilla_9();
    emit send_data(2);
    this->close();
    contpos_9 = 0;
    delete this;
}

void enviardatos::on_pani_envio_clicked()
{
    emit bandera_perilla_9();
    emit send_data(3);
    this->close();
    contpos_9 = 0;
    delete this;
}

void enviardatos::on_temp_envio_clicked()
{
    emit bandera_perilla_9();
    emit send_data(4);
    this->close();
    contpos_9 = 0;
    delete this;
}

void enviardatos::on_toolButton_5_clicked()
{
    emit bandera_perilla_9();
    emit send_data(5);
    this->close();
    contpos_9 = 0;
    delete this;
}
