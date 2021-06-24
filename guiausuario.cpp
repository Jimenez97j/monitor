#include "guiausuario.h"
#include "ui_guiausuario.h"
#include "qdebug.h"
bool bandera_deshabilitar_barra_MOD2= true;
int contpos_guiusuario = 0;




GuiaUsuario::GuiaUsuario(QWidget *parent, SerialSpo2 *serialspo2_enviar_datos) :
    QDialog(parent),
    ui(new Ui::GuiaUsuario)
{
    spo2serial_guiusuario = serialspo2_enviar_datos;
    ui->setupUi(this);
    connect(spo2serial_guiusuario, SIGNAL(boton_ajustes(QString )), this, SLOT(boton_handle_guiusuario(QString )), Qt::QueuedConnection);
    ui->tabWidget->setCurrentIndex(0);

}

GuiaUsuario::~GuiaUsuario()
{
    delete ui;
}

void GuiaUsuario::boton_handle_guiusuario(QString x){

    if (x == "derecha"){
    contpos_guiusuario = contpos_guiusuario + 1;
    if(contpos_guiusuario > 2){
        contpos_guiusuario = 2;
    }
    opciones_guiusuario();
    }

    else if(x == "izquierda"){
        contpos_guiusuario = contpos_guiusuario - 1;
        if(contpos_guiusuario < 0){
            contpos_guiusuario = 0;
        }
        opciones_guiusuario();
    }

    else if(x == "click"){
        on_okay_clicked();
    }

}

void GuiaUsuario:: on_okay_clicked(){
    switch(contpos_guiusuario)
    {
    case 0:
        on_toolButton_pressed();
        break;
    case 1:
        on_toolButton_3_pressed();
        break;
    case 2:
        on_toolButton_2_pressed();
        break;

    }
}


void GuiaUsuario:: opciones_guiusuario(){
    switch(contpos_guiusuario)
    {
    case 0:
        ui->toolButton->setStyleSheet("background-color:red;");
        ui->toolButton_3->setStyleSheet("");
        break;
    case 1:
        ui->toolButton_3->setStyleSheet("background-color:red;");
        ui->toolButton->setStyleSheet("");
        ui->toolButton_2->setStyleSheet("");
        break;
    case 2:
        ui->toolButton_2->setStyleSheet("background-color:red;");
        ui->toolButton_3->setStyleSheet("");
        break;

    }
}

void GuiaUsuario::on_toolButton_pressed()
{
    emit habilitar_barra_ajustes();
    this->close();
    contpos_guiusuario = 0;
    delete this;
}

void GuiaUsuario::on_toolButton_2_pressed()
{
    int index = ui->tabWidget->currentIndex();
    ui->tabWidget->setCurrentIndex(index + 1);
    qDebug()<<ui->tabWidget->currentIndex();
}


void GuiaUsuario::on_toolButton_3_pressed()
{
    int index = ui->tabWidget->currentIndex();
    ui->tabWidget->setCurrentIndex(index - 1);
    qDebug()<<ui->tabWidget->currentIndex();
}
