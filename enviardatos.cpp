#include "enviardatos.h"
#include "ui_enviardatos.h"
#include <QMessageBox>

enviardatos::enviardatos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enviardatos)
{
    ui->setupUi(this);
}

enviardatos::~enviardatos()
{
    delete ui;
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
