#include "alarmas.h"
#include "ui_alarmas.h"
#include <QScrollBar>
#include <QDebug>


alarmas::alarmas(QWidget *parent, SerialSpo2 *serialspo2_registro) :
    QDialog(parent)
   , ui(new Ui::alarmas)
{
    numero_eventos = 0;
    numero_scrolls = 0;
    contador_scrolls = 0;
    numero_eventos_mostrados = 22;
    numero_mas_eventos = 7;

    ui->setupUi(this);
    spo2serial_7 = serialspo2_registro;
    connect(spo2serial_7, SIGNAL(boton_ajustes(QString )), this, SLOT(boton_handle_7(QString )), Qt::QueuedConnection);
    QString nombre;
    nombre.append("/opt/monitor_selespo/bin/prueba.sqlite"); //"/opt/monitor_selespo2/bin/prueba.sqlite"
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

void alarmas::boton_handle_7(QString x){
    if (x == "derecha"){
        //bajar
        bajar();
    }
    else if(x == "izquierda"){
        //subir
        subir();
    }
    else if(x == "click"){
        //tecla ok
    }
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

    qDebug() << "[ALARMAS]  numeor de eventos cargados: " << fila;
    numero_eventos = fila;
    obtener_numero_scrolls();

}

void alarmas::on_pushButton_pressed()
{
    emit sonido_click();
    this->close();
}

void alarmas::bajar(){
    try {
        qDebug() << "bajar";
        if(contador_scrolls < numero_scrolls){
            contador_scrolls += 1;
            //qDebug() << "bajar if : " + QString::number(contador_scrolls);
            int temp = numero_eventos_mostrados + (numero_mas_eventos * contador_scrolls) - 1;
            if(temp > numero_eventos - 1){
                temp = numero_eventos - 1;
                //qDebug() << "bajar if if: " + QString::number(temp);
            }
            //qDebug() << "bajar if if final : " + QString::number(temp);
            ui->tableWidget->scrollToItem(ui->tableWidget->item(temp,0), QAbstractItemView::PositionAtBottom);
        }
    }  catch (std::exception &e) {
        qWarning("Error %s desde la funcion %s", e.what(), Q_FUNC_INFO );

    }
}

void alarmas::subir(){
    try {
        if(contador_scrolls > 0){
            contador_scrolls -= 1;
            int temp = numero_eventos_mostrados + (numero_mas_eventos * contador_scrolls) - 1;

            ui->tableWidget->scrollToItem(ui->tableWidget->item(temp,0), QAbstractItemView::PositionAtBottom);
        }
    }  catch (std::exception &e) {
        qWarning("Error %s desde la funcion %s", e.what(), Q_FUNC_INFO );

    }
}

void alarmas::obtener_numero_scrolls(){
    try {
        int temp = numero_eventos - numero_eventos_mostrados;
        if(temp > 0){
            int temp2 = temp/2;
            if(temp %numero_mas_eventos > 0){
                temp2++;
            }
            numero_scrolls = temp2;
        }
        else{
            numero_scrolls = 0;
        }
        qDebug() << "obtener_numero_scrolls: " + QString::number(numero_scrolls);
    }  catch (std::exception &e) {
        qWarning("Error %s desde la funcion %s", e.what(), Q_FUNC_INFO );

    }
}
