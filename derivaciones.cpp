#include "derivaciones.h"
#include "ui_derivaciones.h"
#include <QDebug>

int contpos_5 = 0;

QString img[12] = {
    ":/imagenes/btn_der1OFF.png",
    ":/imagenes/btn_der2OFF.png",
    ":/imagenes/btn_der3OFF.png",
    ":/imagenes/btn_aVROFF.png",
    ":/imagenes/btn_aVLOFF.png",
    ":/imagenes/btn_aVFOFF.png",
    ":/imagenes/btn_V1OFF.png",
    ":/imagenes/btn_V2OFF.png",
    ":/imagenes/btn_V3OFF.png",
    ":/imagenes/btn_V4OFF.png",
    ":/imagenes/btn_V5OFF.png",
    ":/imagenes/btn_V6OFF.png"
};
QString imgon[12] = {
    ":/imagenes/btn_der1ON.png",
    ":/imagenes/btn_der2ON.png",
    ":/imagenes/btn_der3ON.png",
    ":/imagenes/btn_aVRON.png",
    ":/imagenes/btn_aVLON.png",
    ":/imagenes/btn_aVFON.png",
    ":/imagenes/btn_V1ON.png",
    ":/imagenes/btn_V2ON.png",
    ":/imagenes/btn_V3ON.png",
    ":/imagenes/btn_V4ON.png",
    ":/imagenes/btn_V5ON.png",
    ":/imagenes/btn_V6ON.png"
};

derivaciones::derivaciones(QWidget *parent, SerialSpo2 *serialspo2_derivaciones) :
    QDialog(parent),
    ui(new Ui::derivaciones)
{
    ui->setupUi(this);
    spo2serial_5 = serialspo2_derivaciones;
    opciones_derivaciones();
    connect(spo2serial_5, SIGNAL(boton_ajustes(QString )), this, SLOT(boton_handle_5(QString )), Qt::QueuedConnection);
    int value = statebutton();
    QToolButton *arr[12] = {ui->d1, ui->d2, ui->d3, ui->d4, ui->d5, ui->d6, ui->d7, ui->d8, ui->d9, ui->d10, ui->d11, ui->d12};
  for(int i = 0; i<12; i++)
  {
      //arr[i]->setStyleSheet(img[i]);
      arr[i]->setCheckable(true);
      arr[i]->setChecked(false);
      arr[i]->setIcon(QIcon(img[i]));
  }
 //arr[value]->setStyleSheet(imgon[value]);
 arr[value]->setChecked(true);
 arr[value]->setIcon(QIcon(imgon[value]));
 arr[value]->setStyleSheet("border: 2px solid green; border-radius:10px;");

}


derivaciones::~derivaciones(){
    delete ui;
}

void derivaciones::boton_handle_5(QString k){


    qDebug()<<"hola";
    if (k == "derecha"){
    contpos_5 = contpos_5 + 1;
    if(contpos_5 > 13){
        contpos_5 = 13;
    }
    opciones_derivaciones();
    }

    else if(k == "izquierda"){
        contpos_5 = contpos_5 - 1;
        if(contpos_5 < 0){
            contpos_5 = 0;
        }
    opciones_derivaciones();
    }
    else if(k == "click"){
        on_okay_clicked();

    }

}


void derivaciones:: on_okay_clicked(){

    switch(contpos_5)
    {
    case 0:
       on_d1_pressed();
        break;
    case 1:
        on_d2_pressed();
        break;
    case 2:
        on_d3_pressed();
        break;
    case 3:
        on_d4_pressed();
        break;
    case 4:
        on_d5_pressed();
        break;
    case 5:
        on_d6_pressed();
        break;
    case 6:
        on_d7_pressed();
        break;
    case 7:
        on_d8_pressed();
        break;
    case 8:
        on_d9_pressed();
        break;
    case 9:
        on_d10_pressed();
        break;
    case 10:
        on_d11_pressed();
        break;
    case 11:
        on_d12_pressed();
        break;
    }

}

void derivaciones:: opciones_derivaciones(){
    switch(contpos_5)
    {
    case 0:
        ui->d1->setStyleSheet("background-color:red;");
        ui->d2->setIcon(QIcon(":/imagenes/btn_der2OFF.png"));
        break;
    case 1:
        ui->d2->setStyleSheet("background-color:red;");
        ui->d1->setStyleSheet("");
        ui->d3->setStyleSheet("");
        break;
    case 2:
        ui->d3->setStyleSheet("background-color:red;");
        ui->d2->setStyleSheet("");
        ui->d4->setStyleSheet("");
        break;
    case 3:
        ui->d4->setStyleSheet("background-color:red;");
        ui->d3->setStyleSheet("");
        ui->d5->setStyleSheet("");
        break;
    case 4:
        ui->d5->setStyleSheet("background-color:red;");
        ui->d4->setStyleSheet("");
        ui->d6->setStyleSheet("");
        break;
    case 5:
        ui->d6->setStyleSheet("background-color:red;");
        ui->d5->setStyleSheet("");
        ui->d7->setStyleSheet("");
        break;
    case 6:
        ui->d7->setStyleSheet("background-color:red;");
        ui->d6->setStyleSheet("");
        ui->d8->setStyleSheet("");
        break;
    case 7:
        ui->d8->setStyleSheet("background-color:red;");
        ui->d7->setStyleSheet("");
        ui->d9->setStyleSheet("");
        break;
    case 8:
        ui->d9->setStyleSheet("background-color:red;");
        ui->d8->setStyleSheet("");
        ui->d10->setStyleSheet("");
        break;
    case 9:
        ui->d10->setStyleSheet("background-color:red;");
        ui->d9->setStyleSheet("");
        ui->d11->setStyleSheet("");
        break;
    case 10:
        ui->d11->setStyleSheet("background-color:red;");
        ui->d10->setStyleSheet("");
        ui->d12->setStyleSheet("");
        break;
    case 11:
        ui->d12->setStyleSheet("background-color:red;");
        ui->d11->setStyleSheet("");
        break;
    }
}





void derivaciones::changebutton(){
     int value = statebutton();
     QToolButton *arr[12] = {ui->d1, ui->d2, ui->d3, ui->d4, ui->d5, ui->d6, ui->d7, ui->d8, ui->d9, ui->d10, ui->d11, ui->d12};
     for(int i = 0; i<12; i++)
     {
         arr[i]->setChecked(false);
         arr[i]->setIcon(QIcon(img[i]));
         arr[i]->setStyleSheet("border: 0px;");

     }
    //arr[value]->setStyleSheet(imgon[value]);
    arr[value]->setChecked(true);
    arr[value]->setIcon(QIcon(imgon[value]));
    arr[value]->setStyleSheet("border: 2px solid green; border-radius:10px;");
}


void derivaciones::on_d1_pressed(){
    emit sonido_click();
    emit der1();
    emit bandera_perilla_4();
    changebutton();
    this->close();
    contpos_5 = 0;
    delete this;

    /*if (ui->d1->isChecked())
    {
        ui->d1->setChecked(false);
        ui->d1->setIcon(QIcon(":/imagenes/btn_der1OFF.png"));
        ui->d1->setStyleSheet("border:0px;");
        qDebug()<<"OFF";
    }
    else
        ui->d1->setChecked(true);
        ui->d1->setIcon(QIcon(":/imagenes/btn_der1ON.png"));
        ui->d1->setStyleSheet("border: 2px solid red; border-radius:10px;");
        qDebug()<<"O";
    }*/
}


void derivaciones::on_d2_pressed(){
    emit sonido_click();
    emit der2();
    emit bandera_perilla_4();
        changebutton();
        this->close();
        contpos_5 = 0;
        delete this;
}


void derivaciones::on_d3_pressed(){
    emit sonido_click();
    emit der3();
    emit bandera_perilla_4();
        changebutton();
        this->close();
        contpos_5 = 0;
        delete this;
}


void derivaciones::on_d4_pressed(){
    emit sonido_click();
    emit der4();
    emit bandera_perilla_4();
        changebutton();
        this->close();
        contpos_5 = 0;
        delete this;
}


void derivaciones::on_d5_pressed(){
    emit sonido_click();
    emit der5();
    emit bandera_perilla_4();
        changebutton();
        this->close();
        contpos_5 = 0;
        delete this;
}


void derivaciones::on_d6_pressed(){
    emit sonido_click();
    emit der6();
    emit bandera_perilla_4();
        changebutton();
        this->close();
        contpos_5 = 0;
        delete this;
}


void derivaciones::on_d7_pressed(){
    emit sonido_click();
    emit der7();
    emit bandera_perilla_4();
        changebutton();
        this->close();
        contpos_5 = 0;
        delete this;
}


void derivaciones::on_d8_pressed(){
    emit sonido_click();
    emit der8();
    emit bandera_perilla_4();
        changebutton();
        this->close();
        contpos_5 = 0;
        delete this;
}


void derivaciones::on_d9_pressed(){
    emit sonido_click();
    emit der9();
        emit bandera_perilla_4();
        changebutton();
        this->close();
        contpos_5 = 0;
        delete this;
}


void derivaciones::on_d10_pressed(){
    emit sonido_click();
    emit der10();
    emit bandera_perilla_4();
        changebutton();
        this->close();
        contpos_5 = 0;
        delete this;
}


void derivaciones::on_d11_pressed(){
    emit sonido_click();
    emit der11();
    emit bandera_perilla_4();
        changebutton();
        this->close();
        contpos_5 = 0;
        delete this;
}


void derivaciones::on_d12_pressed(){
    emit sonido_click();
    emit der12();
    emit bandera_perilla_4();
        changebutton();
         this->close();
        contpos_5 = 0;
        delete this;
}
