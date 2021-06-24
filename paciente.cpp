#include "paciente.h"
#include "ui_paciente.h"

bool pac1=false,pac2=false,pac3=false; //variables para indicar cual boton esta activado
Paciente::Paciente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Paciente)
{
    ui->setupUi(this);
    QString nombre, consulta;
    nombre.append("/opt/monitor_selespo/bin/prueba.sqlite");
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(nombre);
    if(db.open()){
        QSqlQuery crear;
        consulta.append("SELECT * FROM pacientes WHERE activo = '1'");
        crear.prepare(consulta);
        crear.exec();
        crear.next();
    //Asigna el valor de la base de datos prueba.sqlite a cada label siendo 0 ID por lo que se inicializa con 1 para Nombres
    ui->Escnombre->setText(crear.value(1).toString());
    ui->Apellido->setText(crear.value(2).toString()+" "+crear.value(3).toString());
    ui->Escdad->setText(crear.value(4).toString());
    ui->Escsex->setText(crear.value(5).toString());
    ui->Escsangre->setText(crear.value(6).toString());
    ui->notas->setPlainText(crear.value(7).toString());

    if(crear.value(0).toString()=="1"){
        ui->paciente1->setStyleSheet("background-color: rgb(138, 226, 52);"); //cambia color a VERDE en info del paciente
    }
    if(crear.value(0).toString()=="2"){
        ui->paciente2->setStyleSheet("background-color: rgb(32, 74, 135);"); //cambia color a AZUL en info del paciente
    }
    if(crear.value(0).toString()=="3"){
        ui->paciente3->setStyleSheet("background-color: rgb(239, 41, 41);"); //cambia color a ROJO en info del paciente
    }
}
}

Paciente::~Paciente(){
    delete ui;
}


void Paciente::on_paciente1_clicked(){
    emit sonido_click();
    pac1=true; //Se activa para marcar que es la seleccionada
    colorpaciente();
    pac1=false;// Se desactiva para no tener conflictos al cambiar el estado


}


void Paciente::on_paciente2_clicked(){
    emit sonido_click();
    pac2=true;
    colorpaciente();
    pac2=false;

}


void Paciente::on_paciente3_clicked(){
    emit sonido_click();
    pac3=true;
    colorpaciente();
    pac3=false;


}


void Paciente::colorpaciente(){
    QString consultas;
    QSqlQuery crear;
        //++++++++++++++++++++++ENCENDER SOLO COLOR VERDE EN BOTON 1+++++++++++++++++++
        if(pac1){
        ui->paciente1->setStyleSheet("background-color: rgb(138, 226, 52);");
        ui->paciente2->setStyleSheet("");
        ui->paciente3->setStyleSheet("");
        consultas.append("UPDATE pacientes SET activo = '0' WHERE 1");
        crear.prepare(consultas);
        crear.exec();
        consultas.clear();
        consultas.append("UPDATE pacientes SET activo = '1' WHERE id=1");
        crear.prepare(consultas);
        crear.exec();
        consultas.clear();
        }

        //++++++++++++++++++++++ENCENDER SOLO COLOR AZUL EN BOTON 2+++++++++++++++++++

        if(pac2){
        ui->paciente2->setStyleSheet("background-color: rgb(32, 74, 135);");
        ui->paciente1->setStyleSheet("");
        ui->paciente3->setStyleSheet("");
        consultas.append("UPDATE pacientes SET activo = '0' WHERE 1");
        crear.prepare(consultas);
        crear.exec();
        consultas.clear();
        consultas.append("UPDATE pacientes SET activo = '1' WHERE id=2");
        crear.prepare(consultas);
        crear.exec();
        consultas.clear();
        }

        //++++++++++++++++++++++ENCENDER SOLO COLOR ROJO EN BOTON 3+++++++++++++++++++

        if(pac3){
        ui->paciente3->setStyleSheet("background-color: rgb(239, 41, 41);");
        ui->paciente2->setStyleSheet("");
        ui->paciente1->setStyleSheet("");
        consultas.append("UPDATE pacientes SET activo = '0' WHERE 1");
        crear.prepare(consultas);
        crear.exec();
        consultas.clear();
        consultas.append("UPDATE pacientes SET activo = '1' WHERE id=3");
        crear.prepare(consultas);
        crear.exec();
        consultas.clear();
        }
        consultas.append("SELECT * FROM pacientes WHERE activo = '1'");
        crear.prepare(consultas);
        crear.exec();
        crear.next();
        paciente_activo_change(crear.value(1).toString());
        ui->Escnombre->setText(crear.value(1).toString());
        ui->Apellido->setText(crear.value(2).toString()+" "+crear.value(3).toString());
        ui->Escdad->setText(crear.value(4).toString());
        ui->Escsex->setText(crear.value(5).toString());
        ui->Escsangre->setText(crear.value(6).toString());
        ui->notas->setPlainText(crear.value(7).toString());
}

void Paciente::on_notas_selectionChanged()
{
    this->setGeometry(511, 10, 170, 294);
    teclado = new Teclado;
    teclado->setWindowFlags(Qt::FramelessWindowHint);
    QObject::connect(teclado, SIGNAL(letter_press(QString)), this, SLOT(letter_press_lastname(QString)));
    QObject::connect(teclado, SIGNAL(erase_names()), this, SLOT(erase_last_names()));
    QObject::connect(teclado, SIGNAL(close_keyboard()), this, SLOT(restore_position()));

    teclado->setWindowFlags(Qt::Popup);
    teclado->setGeometry(0,240,800,240);
    //this->setGeometry(0,1400,800,480);
    teclado->exec();
    show();
}

void Paciente::restore_position(){ // this functions allows the return the window to its initial position
    QString consultas;
    QSqlQuery crear;
    this->setGeometry(511, 151, 170, 294);
    QString actual_text = ui->notas->toPlainText();
    consultas.append("UPDATE pacientes SET notas ='"+ actual_text +"'WHERE  activo = 1");
    crear.prepare(consultas);
    crear.exec();
    consultas.clear();
}

void Paciente::erase_last_names(){
     QString actual_text = ui->notas->toPlainText();
     QString resultado = "";
     int longitud = actual_text.length();
     for(int i = 0; i<longitud-1; i++){
         resultado[i] = actual_text[i];
     }
     ui->notas->setPlainText(resultado);
}

void Paciente::letter_press_lastname(QString letter){
    QString actual_text = ui->notas->toPlainText();
    actual_text = actual_text + letter;
    ui->notas->setPlainText(actual_text);
}
