#include "alarmas.h"
#include "ui_alarmas.h"
#include <QScrollBar>
#include <QDebug>


alarmas::alarmas(QWidget *parent) :
    QDialog(parent)
   , ui(new Ui::alarmas)
{
    ui->setupUi(this);
        QString nombre;
        nombre.append("/opt/monitor_selespo2/bin/prueba.sqlite");
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(nombre);
        if(db.open()){
            crearTabla();
            qDebug()<<"conexion establecida";
        }
        ui->tableWidget->verticalScrollBar()->setStyleSheet("QScrollBar:vertical { width: 50px; background-color: #90c6fd;}");
}


alarmas::~alarmas(){
    delete ui;
}


void alarmas::crearTabla(){
    QString consulta;
    consulta.append("SELECT * FROM registros WHERE 1 ORDER BY id DESC");
    QSqlQuery crear;
    crear.prepare(consulta);
    crear.exec();
    int fila = 0;
    while(crear.next()){
        ui->tableWidget->insertRow(fila);
        ui->tableWidget->setItem(fila, 0, new QTableWidgetItem(crear.value(1).toByteArray().constData()));
        ui->tableWidget->setItem(fila, 1, new QTableWidgetItem(crear.value(2).toByteArray().constData()));
        ui->tableWidget->setItem(fila, 2, new QTableWidgetItem(crear.value(3).toByteArray().constData()));
        ui->tableWidget->setItem(fila, 3, new QTableWidgetItem(crear.value(4).toByteArray().constData()));
        ui->tableWidget->setItem(fila, 4, new QTableWidgetItem(crear.value(5).toByteArray().constData()));
        ui->tableWidget->setItem(fila, 5, new QTableWidgetItem(crear.value(6).toByteArray().constData()));
        ui->tableWidget->setItem(fila, 6, new QTableWidgetItem(crear.value(7).toByteArray().constData()));
        ui->tableWidget->setItem(fila, 7, new QTableWidgetItem(crear.value(8).toByteArray().constData()));
        fila ++;
    }

}





void alarmas::on_pushButton_pressed()
{
    emit sonido_click();
    this->close();
}
