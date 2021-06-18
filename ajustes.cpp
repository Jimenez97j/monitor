#include "ajustes.h"
#include "ui_ajustes.h"
#include <QMessageBox>
#include <QDebug>
#include <QDir>
#include <guiausuario.h>

ajustes::ajustes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajustes)
{
    ui->setupUi(this);
    QString maincolor = getajustes();

    ui->comboBox->addItem(maincolor);
    if(maincolor != "Verde Aqua"){
        ui->comboBox->addItem("Verde Aqua");
    }
    if(maincolor != "Blanco Luminoso"){
        ui->comboBox->addItem("Blanco Luminoso");
    }
    if(maincolor != "Negro Espacial"){
        ui->comboBox->addItem("Negro Espacial");
    }
    if(maincolor != "Morado renaciente"){
        ui->comboBox->addItem("Morado renaciente");
    }
    if(maincolor != "Azul Opaco"){
        ui->comboBox->addItem("Azul Opaco");
    }
    QString detection_mode = detection_status();
    if(detection_mode == "true"){
        ui->ARRIT->setText("<font color='green'>Activada</font>");
        ui->checkBox->setChecked(1);
    }else{
        ui->ARRIT->setText("<font color=#ef2929>Desactivada</font>");
        ui->checkBox->setChecked(0);
    }

    //for select the time of saving data into database
    ui->time_save->addItem("1 minuto");
    ui->time_save->addItem("5 minutos");
    ui->time_save->addItem("15 minutos");
    ui->time_save->addItem("30 minutos");
    ui->time_save->addItem("1 hora");

    QString actual_time_save = gettime();

    if(actual_time_save == "1"){
        ui->time_save->setCurrentIndex(0);
    }
    if(actual_time_save == "2"){
        ui->time_save->setCurrentIndex(1);
    }
    if(actual_time_save == "3"){
        ui->time_save->setCurrentIndex(2);
    }
    if(actual_time_save == "4"){
        ui->time_save->setCurrentIndex(3);
    }
    if(actual_time_save == "5"){
        ui->time_save->setCurrentIndex(4);
    }

    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
    ui->timeEdit->setTime(QTime::currentTime());
}

ajustes::~ajustes(){
    delete ui;
}

void ajustes::on_cleanAll_pressed(){
    emit sonido_click();

    QMessageBox msgBox;
    msgBox.setWindowTitle("Restaurar sistema");
    msgBox.setText("Esta a punto de restaurar el sistema. Los registros y capturas de pantalla serán borrados, así como todas las configuraciones serán devueltas a su estado de fabrica.");
    msgBox.setInformativeText("Esta acción no se puede deshacer, ¿Desea continuar?");
    msgBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    int ret = msgBox.exec();

    switch (ret) {
      case QMessageBox::Cancel:
          // Cancel was clicked and it should do nothing
          break;
      case QMessageBox::Ok:
          // Ok was clicked and it should erase everything
          int i = 0;
          QStringList lista = QDir("./imagenes/").entryList();
          while (lista.length() > i) {
              QDir("./imagenes/").remove(lista[i]);
              i++;
          }
          cleanAll();
          break;
    }
}

void ajustes::on_comboBox_currentIndexChanged(int index){

      QString data = ui->comboBox->currentText();
      if(data == "Verde Aqua"){
          data = "#326d72";
      }
      if(data == "Morado renaciente"){
          data = "#20214f";
      }
      if(data == "Blanco Luminoso"){
          data = "#ffffff";
      }
      if(data == "Negro Espacial"){
          data = "#000000";
      }
      if(data == "Azul Opaco"){
          data = "#003e6c";
      }
      changebackground(data);
      emit change_color_click();
      emit sonido_click();


}

void ajustes::on_toolButton_pressed(){
    emit sonido_click();
    this->close();
}

void ajustes::on_checkBox_toggled(bool checked){
    emit sonido_click();
    QString ia_command;
    if(checked){

        ui->ARRIT->setText("<font color='green'>Activada</font>");
        ui->checkBox->setChecked(1);
        ia_command = "python3 /home/RED/diagnostico6.py";

    }else{
        ui->ARRIT->setText("<font color=#ef2929>Desactivada</font>");
        ui->checkBox->setChecked(0);

    }

    system(ia_command.toStdString().c_str());
    detection_mode(checked);
    emit detection_change();
}

void ajustes::on_Guia_Usu_pressed()
{
    emit sonido_click();
    GuiaUsuario ventana1;
    ventana1.setWindowFlags(Qt::FramelessWindowHint);
    ventana1.exec();
    show();
}

void ajustes::on_time_save_currentIndexChanged(int index)
{
    emit time_save_change(index);
    emit sonido_click();
}

void ajustes::on_toolButton_2_clicked()
{

    QString fecha = ui->dateEdit->date().toString("yyyyMMdd");
    QString comandoCambio = "date +%Y%m%d -s ";
    comandoCambio.append(fecha);
    int estado = system(comandoCambio.toStdString().c_str());
    if(estado == -1)
    {
        qDebug()<<"Error al cambiar la fecha";
    }
    else
    {
        qDebug()<<"Fecha actualizada";
    }

    QString hora = ui->timeEdit->time().toString("HH:mm:ss");
    comandoCambio = "date +%T -s ";
    comandoCambio.append(hora);
    estado = system(comandoCambio.toStdString().c_str());
    if(estado == -1)
    {
        qDebug()<<"Error al cambiar la hora";
    }
    else
    {
        qDebug()<<"Hora actualizada";
    }

    estado = system("/sbin/hwclock -w");
    if(estado == -1)
    {
        qDebug()<<"Error al actualizar el hardware";
    }
    else
    {
        qDebug()<<"Hardware clock actualizado";
    }
}
