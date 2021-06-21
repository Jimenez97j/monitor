#include "galeria.h"
#include "ui_galeria.h"
#include <QDir>
#include <QDebug>

bool miniatura = true;
int contpos_3 = 0, contpos_list_images = 0, list_size = 0;
bool list_images_show = false;

galeria::galeria(QWidget *parent, SerialSpo2 *serialspo2_galeria) :
    QDialog(parent),
    ui(new Ui::galeria)
{

    ui->setupUi(this);
    spo2serial_3 = serialspo2_galeria;
    opciones_galeria();
    connect(spo2serial_3, SIGNAL(boton_ajustes(QString )), this, SLOT(boton_handle(QString )), Qt::QueuedConnection);


    iniciar();
 }


void galeria::iniciar(){
    int i = 2;
    QStringList lista = QDir("./imagenes/").entryList();
    while (lista.length() > i) {
        ui->comboBox->addItem(lista[i]);
        i++;
        list_size = list_size + 1;

    }
    if(lista.length()>2){
    QPixmap mypix ("./imagenes/" + lista[lista.length()-1]);
    ui->min1->setPixmap(mypix);}
    if(lista.length()>3){
    QPixmap mypix2 ("./imagenes/" + lista[lista.length()-2]);
    ui->min2->setPixmap(mypix2);}
    if(lista.length()>4){
    QPixmap mypix3 ("./imagenes/" + lista[lista.length()-3]);
    ui->min3->setPixmap(mypix3);}

}


galeria::~galeria(){
    delete ui;
}



void galeria::boton_handle(QString p){

    if(list_images_show){
        if (p == "derecha"){
            contpos_list_images = contpos_list_images + 1;
            if(contpos_list_images > list_size){
                contpos_list_images = list_size;
            }
            //opciones_galeria();
            ui->comboBox->setCurrentIndex(contpos_list_images);
            ui->comboBox->setStyleSheet("QComboBox::item:active{background-color:red;}");

        }
        else if(p == "izquierda"){
            contpos_list_images = contpos_list_images - 1;
            if(contpos_list_images < 0){
                contpos_list_images = 0;
            }
            ui->comboBox->setCurrentIndex(contpos_list_images);
            ui->comboBox->setStyleSheet("QComboBox::item:active{background-color:red;}");

        }

        else if(p == "click"){
            on_oka_clicked();
        }
    }
    else{
        if (p == "derecha"){
            contpos_3 = contpos_3 + 1;
            if(contpos_3 > 5){
                contpos_3 = 5;
            }
            opciones_galeria();
        }

        else if(p == "izquierda"){
            contpos_3 = contpos_3 - 1;
            if(contpos_3 < 0){
                contpos_3 = 0;
            }
            opciones_galeria();
        }

        else if(p == "click"){
            on_oka_clicked();
        }
    }

}

void galeria:: on_oka_clicked(){
    qDebug()<<contpos_3;
    switch(contpos_3)
    {
         case 0:
                 list_images_show = !list_images_show;
                 if(list_images_show){
                     ui->comboBox->showPopup();
                 }else{
                     ui->comboBox->hidePopup();
                 }
                 break;
         case 1:
                 on_min1_boton_pressed();
                 break;
         case 2:
                 on_min2_boton_pressed();
                 break;
         case 3:
                 on_min3_boton_pressed();
                 break;
         case 4:
                 on_trash_pressed();
                 break;
         case 5:
                 on_toolButton_pressed();
                 break;
    }

}

void galeria:: opciones_galeria(){
    switch(contpos_3)
    {
    case 0:
        ui->comboBox->setStyleSheet("border-color:red;");
        ui->min1_boton->setStyleSheet("");
        break;
    case 1:
        ui->min1_boton->setStyleSheet("border-color:red;");
        ui->comboBox->setStyleSheet("");
        ui->min2_boton->setStyleSheet("");
        break;
    case 2:
        ui->min2_boton->setStyleSheet("border-color:red;");
        ui->min1_boton->setStyleSheet("");
        ui->min3_boton->setStyleSheet("");
        break;
    case 3:
        ui->min3_boton->setStyleSheet("border-color:red;");
        ui->min2_boton->setStyleSheet("");
        ui->trash->setStyleSheet("");
        break;
    case 4:
        ui->trash->setStyleSheet("border-color:red;");
        ui->min3_boton->setStyleSheet("");
        ui->toolButton->setStyleSheet("");
        break;
    case 5:
        ui->toolButton->setStyleSheet("border-color:red;");
        ui->trash->setStyleSheet("");
        break;
    }
}

void galeria::on_comboBox_currentIndexChanged(const QString &arg1){
   if(miniatura){
       QString data = ui->comboBox->currentText();
       QPixmap mypix ("./imagenes/" + data);
       ui->imagen->setPixmap(mypix);
  }else{
       miniatura = true;
   }
}


void galeria::on_min1_boton_pressed(){
    emit sonido_click();
    QStringList lista1 = QDir("./imagenes/").entryList();
    if(lista1.length()>2){
    QPixmap mypix ("./imagenes/" + lista1[lista1.length()-1]);
    ui->imagen->setPixmap(mypix);
    ui->comboBox->setCurrentIndex(lista1.length()-2);}
    miniatura = false;
}


void galeria::on_min2_boton_pressed(){
    emit sonido_click();
    QStringList lista2 = QDir("./imagenes/").entryList();
    if(lista2.length()>3){
    QPixmap mypix ("./imagenes/" + lista2[lista2.length()-2]);
    ui->imagen->setPixmap(mypix);
    ui->comboBox->setCurrentIndex(lista2.length()-3);}
}


void galeria::on_min3_boton_pressed(){
    emit sonido_click();
    QStringList lista3 = QDir("./imagenes/").entryList();
    if(lista3.length()>4){
    QPixmap mypix ("./imagenes/" + lista3[lista3.length()-3]);
    ui->imagen->setPixmap(mypix);
    ui->comboBox->setCurrentIndex(lista3.length()-4);}
}


void galeria::on_toolButton_pressed(){
    emit sonido_click();
    emit bandera_perilla_2();
    this->close();
    contpos_3 = 0;
    delete this;
}


void galeria::on_trash_pressed(){
    QString data = ui->comboBox->currentText();
    QDir("./imagenes/").remove(data);
    ui->comboBox->clear();
    ui->min1->clear();
    ui->min2->clear();
    ui->min3->clear();
    ui->imagen->setText("                                   "
                        "                      No hay imagenes disponibles");
    iniciar();
    emit sonido_basura();

}
