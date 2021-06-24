#include "config_alarmas.h"
#include "ui_config_alarmas.h"
#include <QDebug>

int contpos_4 = 0;
config_alarmas::config_alarmas(QWidget *parent, SerialSpo2 *serialspo2_alarmas) :
    QDialog(parent),
    ui(new Ui::config_alarmas)
{
    spo2serial_4 = serialspo2_alarmas;
    ui->setupUi(this);
    opciones_alarmas();
    connect(spo2serial_4, SIGNAL(boton_ajustes(QString )), this, SLOT(boton_handle_4(QString )), Qt::QueuedConnection);
    QString nombre;
    nombre.append("/opt/monitor_selespo/bin/prueba.sqlite");
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(nombre);

    if(db.open()){
        QString consulta;
        consulta.append("SELECT * FROM alarmas WHERE 1");
        QSqlQuery crear;
        crear.prepare(consulta);
        crear.exec();
        crear.next();
        ui->ecg_alarm_min->setText(crear.value(0).toByteArray().constData());
        ui->ecg_alarm_max->setText(crear.value(1).toByteArray().constData());
        ui->spo2_alarm_min->setText(crear.value(2).toByteArray().constData());
        ui->spo2_alarm_max->setText(crear.value(3).toByteArray().constData());
        ui->rpm_alarm_min->setText(crear.value(4).toByteArray().constData());
        ui->rpm_alarm_max->setText(crear.value(5).toByteArray().constData());
    }
}

config_alarmas::~config_alarmas(){
    delete ui;
}

void config_alarmas::boton_handle_4(QString y){


    qDebug()<<"hola";
    if (y == "derecha"){
    contpos_4 = contpos_4 + 1;
    if(contpos_4 > 13){
        contpos_4 = 13;
    }
    opciones_alarmas();
    }

    else if(y == "izquierda"){
        contpos_4 = contpos_4 - 1;
        if(contpos_4 < 0){
            contpos_4 = 0;
        }
        opciones_alarmas();
    }

    else if(y == "click"){
        on_oka_clicked();

    }




}


void config_alarmas:: on_oka_clicked(){

    switch(contpos_4)
    {
    case 0:
       on_menos_min_ecg_pressed();
        break;
    case 1:
        on_mas_min_ecg_pressed();
        break;
    case 2:
        on_menos_max_ecg_pressed();
        break;
    case 3:
        on_mas_max_ecg_pressed();
        break;
    case 4:
        on_menos_min_spo2_pressed();
        break;
    case 5:
        on_mas_min_spo2_pressed();
        break;
    case 6:
        on_menos_max_spo2_pressed();
        break;
    case 7:
        on_mas_max_spo2_pressed();
        break;
    case 8:
        on_menos_min_rpm_pressed();
        break;
    case 9:
        on_mas_min_rpm_pressed();
        break;
    case 10:
        on_menos_max_rpm_pressed();
        break;
    case 11:
        on_mas_max_rpm_pressed();
        break;
    case 12:
        on_CERRAR_pressed();
        break;
    case 13:
        on_OK_pressed();
        break;
    }

}

void config_alarmas:: opciones_alarmas(){
    switch(contpos_4)
    {
    case 0:
    ui->menos_min_ecg->setIcon(QIcon(":/imagenes/btn_signo_MenosV.png"));
    ui->mas_min_ecg->setIcon(QIcon(":/imagenes/btn_signo_,Mas.png"));

    break;
case 1:
    ui->mas_min_ecg->setIcon(QIcon(":/imagenes/btn_signo_,MasV.png"));
    ui->menos_min_ecg->setIcon(QIcon(":/imagenes/btn_signo_Menos.png"));
    ui->menos_max_ecg->setIcon(QIcon(":/imagenes/btn_signo_Menos.png"));

    break;
case 2:

    ui->menos_max_ecg->setIcon(QIcon(":/imagenes/btn_signo_MenosV.png"));
    ui->mas_min_ecg->setIcon(QIcon(":/imagenes/btn_signo_,Mas.png"));
    ui->mas_max_ecg->setIcon(QIcon(":/imagenes/btn_signo_,Mas.png"));
    break;
case 3:
    ui->mas_max_ecg->setIcon(QIcon(":/imagenes/btn_signo_,MasV.png"));
    ui->menos_max_ecg->setIcon(QIcon(":/imagenes/btn_signo_Menos.png"));
    ui->menos_min_spo2->setIcon(QIcon(":/imagenes/btn_signo_Menos.png"));
    break;
case 4:
    ui->menos_min_spo2->setIcon(QIcon(":/imagenes/btn_signo_MenosV.png"));
    ui->mas_max_ecg->setIcon(QIcon(":/imagenes/btn_signo_,Mas.png"));
    ui->mas_min_spo2->setIcon(QIcon(":/imagenes/btn_signo_,Mas.png"));
    break;
case 5:
    ui->mas_min_spo2->setIcon(QIcon(":/imagenes/btn_signo_,MasV.png"));
    ui->menos_min_spo2->setIcon(QIcon(":/imagenes/btn_signo_Menos.png"));
    ui->menos_max_spo2->setIcon(QIcon(":/imagenes/btn_signo_Menos.png"));
    break;
case 6:
    ui->menos_max_spo2->setIcon(QIcon(":/imagenes/btn_signo_MenosV.png"));
    ui->mas_min_spo2->setIcon(QIcon(":/imagenes/btn_signo_,Mas.png"));
    ui->mas_max_spo2->setIcon(QIcon(":/imagenes/btn_signo_,Mas.png"));
    break;
case 7:
    ui->mas_max_spo2->setIcon(QIcon(":/imagenes/btn_signo_,MasV.png"));
    ui->menos_max_spo2->setIcon(QIcon(":/imagenes/btn_signo_Menos.png"));
    ui->menos_min_rpm->setIcon(QIcon(":/imagenes/btn_signo_Menos.png"));
    break;
    case 8:    ui->menos_min_rpm->setIcon(QIcon(":/imagenes/btn_signo_MenosV.png"));

    ui->mas_max_spo2->setIcon(QIcon(":/imagenes/btn_signo_,Mas.png"));
    ui->mas_min_rpm->setIcon(QIcon(":/imagenes/btn_signo_,Mas.png"));
    break;
case 9:
    ui->mas_min_rpm->setIcon(QIcon(":/imagenes/btn_signo_,MasV.png"));
    ui->menos_min_rpm->setIcon(QIcon(":/imagenes/btn_signo_Menos.png"));
    ui->menos_max_rpm->setIcon(QIcon(":/imagenes/btn_signo_Menos.png"));
    break;
case 10:
    ui->menos_max_rpm->setIcon(QIcon(":/imagenes/btn_signo_MenosV.png"));
    ui->mas_min_rpm->setIcon(QIcon(":/imagenes/btn_signo_,Mas.png"));
    ui->mas_max_rpm->setIcon(QIcon(":/imagenes/btn_signo_,Mas.png"));
    break;
case 11:
    ui->mas_max_rpm->setIcon(QIcon(":/imagenes/btn_signo_,MasV.png"));
    ui->menos_max_rpm->setIcon(QIcon(":/imagenes/btn_signo_Menos.png"));
    ui->CERRAR->setIcon(QIcon(":/imagenes/btn_Cerrar.png"));
    break;
case 12:
    ui->CERRAR->setIcon(QIcon(":/imagenes/btn_CerrarV.png"));
    ui->mas_max_rpm->setIcon(QIcon(":/imagenes/btn_signo_,Mas.png"));
   ui->OK->setIcon(QIcon(":/imagenes/btn_Ok.png"));
    break;
case 13:
    ui->OK->setIcon(QIcon(":/imagenes/btn_OkV.png"));
    ui->CERRAR->setIcon(QIcon(":/imagenes/btn_Cerrar.png"));
    break;
    }
}


void config_alarmas::on_CERRAR_pressed()
{
    emit sonido_click();
    emit habilitar_barra_desde_alarmas();
    this->close();
    contpos_4 = 0;
    delete this;

}

void config_alarmas::on_OK_pressed()
{
    emit sonido_click();
    QString consulta, ecg_min, ecg_max, spo2_min, spo2_max, rpm_min, rpm_max;
    QSqlQuery crear;
    ecg_min = ui->ecg_alarm_min->text();
    ecg_max = ui->ecg_alarm_max->text();
    spo2_min = ui->spo2_alarm_min->text();
    spo2_max = ui->spo2_alarm_max->text();
    rpm_min = ui->rpm_alarm_min->text();
    rpm_max = ui->rpm_alarm_max->text();

    consulta.append("UPDATE alarmas SET ecg_min = " + ecg_min
                    +", ecg_max =" + ecg_max
                    +", spo2_min= " + spo2_min
                    +",spo2_max= " + spo2_max
                    +", rpm_min= " + rpm_min
                    +", rpm_max= " + rpm_max +" WHERE ID = '1'");
    crear.prepare(consulta);
    crear.exec();
    emit alarms_change();
    emit habilitar_barra_desde_alarmas();
    this->close();
    contpos_4 = 0;
    delete this;
}



void config_alarmas::on_menos_min_ecg_pressed()
{
    emit sonido_click();

    int less, compare;
    QString text, prevent;

    text = ui->ecg_alarm_min->text();
    less = text.toInt();
    less = less - 1;
    text = QString::number(less);
    if(text == "0"){text="1";}
    ui->ecg_alarm_min->setText(text);
}

void config_alarmas::on_mas_min_ecg_pressed()
{

    emit sonido_click();
    int less, compare;
    QString text, prevent;

    text = ui->ecg_alarm_min->text();
    prevent = ui->ecg_alarm_max->text();
    less = text.toInt();
    compare = prevent.toInt();
    if(less == compare-1){}else{less = less + 1;}
    text = QString::number(less);
    ui->ecg_alarm_min->setText(text);

}

void config_alarmas::on_menos_max_ecg_pressed()
{
    emit sonido_click();
    int less, compare;
    QString text, prevent;
    text = ui->ecg_alarm_max->text();
    prevent = ui->ecg_alarm_min->text();
    compare = prevent.toInt();
    less = text.toInt();
    if(less == compare+1){}else{less = less - 1;}
    text = QString::number(less);
    ui->ecg_alarm_max->setText(text);
}

void config_alarmas::on_mas_max_ecg_pressed()
{
    emit sonido_click();
    int less, compare;
    QString text, prevent;
    text = ui->ecg_alarm_max->text();
    less = text.toInt();
    less = less + 1;
    text = QString::number(less);
    ui->ecg_alarm_max->setText(text);
}


void config_alarmas::on_menos_min_spo2_pressed()
{
    emit sonido_click();

    int less, compare;
    QString text, prevent;

    text = ui->spo2_alarm_min->text();
    less = text.toInt();
    less = less - 1;
    text = QString::number(less);
    if(text == "0"){text="1";}
    ui->spo2_alarm_min->setText(text);

}

void config_alarmas::on_mas_min_spo2_pressed()
{
    emit sonido_click();

    int less, compare;
    QString text, prevent;


    text = ui->spo2_alarm_min->text();
    prevent = ui->spo2_alarm_max->text();
    less = text.toInt();
    compare = prevent.toInt();
    if(less == compare-1){}else{less = less + 1;}
    text = QString::number(less);
    ui->spo2_alarm_min->setText(text);
}

void config_alarmas::on_menos_min_rpm_pressed()
{
    emit sonido_click();

    int less, compare;
    QString text, prevent;

    text = ui->rpm_alarm_min->text();
    less = text.toInt();
    less = less - 1;
    text = QString::number(less);
    if(text == "0"){text="1";}
    ui->rpm_alarm_min->setText(text);
}

void config_alarmas::on_mas_min_rpm_pressed()
{
    emit sonido_click();

    int less, compare;
    QString text, prevent;

    text = ui->rpm_alarm_min->text();
    prevent = ui->rpm_alarm_max->text();
    less = text.toInt();
    compare = prevent.toInt();
    if(less == compare-1){}else{less = less + 1;}
    text = QString::number(less);
    ui->rpm_alarm_min->setText(text);
}

void config_alarmas::on_menos_max_rpm_pressed()
{
    emit sonido_click();

    int less, compare;
    QString text, prevent;

    text = ui->rpm_alarm_max->text();
    prevent = ui->rpm_alarm_min->text();
    less = text.toInt();
    compare = prevent.toInt();
    if(less == compare+1){}else{less = less - 1;}
    text = QString::number(less);
    ui->rpm_alarm_max->setText(text);
}

void config_alarmas::on_mas_max_rpm_pressed()
{
    emit sonido_click();

    int less, compare;
    QString text, prevent;

    text = ui->rpm_alarm_max->text();
    less = text.toInt();
    less = less + 1;
    text = QString::number(less);
    ui->rpm_alarm_max->setText(text);
}

void config_alarmas::on_menos_max_spo2_pressed()
{
    emit sonido_click();

    int less, compare;
    QString text, prevent;

    text = ui->spo2_alarm_max->text();
    prevent = ui->spo2_alarm_min->text();
    less = text.toInt();
    compare = prevent.toInt();
    if(less == compare+1){}else{less = less - 1;}
    text = QString::number(less);
    ui->spo2_alarm_max->setText(text);
}

void config_alarmas::on_mas_max_spo2_pressed()
{
    emit sonido_click();

    int less, compare;
    QString text, prevent;

    text = ui->spo2_alarm_max->text();
    less = text.toInt();
    less = less + 1;
    text = QString::number(less);
    if(text == "101"){text="100";}
    ui->spo2_alarm_max->setText(text);
}


