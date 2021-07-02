#include "paciente.h"
#include "ui_paciente.h"

int contpos_7 = 0;
bool pac1=false,pac2=false,pac3=false; //variables para indicar cual boton esta activado
Paciente::Paciente(QWidget *parent, SerialSpo2 *serialspo2_registro) :
    QDialog(parent),
    ui(new Ui::Paciente)
{
    spo2serial_7 = serialspo2_registro; //pasar el serial del teclado
    ui->setupUi(this);
    connect(spo2serial_7, SIGNAL(boton_ajustes(QString )), this, SLOT(boton_handle_7(QString )), Qt::QueuedConnection);
    QString nombre, consulta;
    nombre.append("/opt/monitor_selespo/bin/prueba.sqlite");
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(nombre);
    if(db.open()){ //abrir db y ver que paciente está activo
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

        //poner los colores del seleccionado
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

void Paciente::boton_handle_7(QString x){
    //teclado. seleccionador cursor
    if (x == "derecha"){
        contpos_7 = contpos_7 + 1;
        if(contpos_7 > 8){
            contpos_7= 8;
        }
        opciones_Paciente();
    }
    else if(x == "izquierda"){
        contpos_7 = contpos_7 - 1;
        if(contpos_7 < 0){
            contpos_7 = 0;
        }
        opciones_Paciente();
    }
    else if(x == "click"){
        on_okay_clicked();
    }
}

void Paciente::on_paciente1_clicked(){
    // se seleccioando paciente 1
    emit sonido_click();
    pac1=true; //Se activa para marcar que es la seleccionada
    colorpaciente();
    pac1=false;// Se desactiva para no tener conflictos al cambiar el estado
    emit bandera_perilla_7();
    this->close();
    contpos_7 = 0;
    delete this;
}

void Paciente:: opciones_Paciente(){
    //colorear elemento seleccionado con el teclado/perilla
    switch(contpos_7){
        case 0:
            ui->notas->setStyleSheet("background-color:red;");
            ui->paciente1->setStyleSheet("");
            break;
        case 1:
            ui->paciente1->setStyleSheet("background-color:red;");
            ui->notas->setStyleSheet("");
            ui->paciente2->setStyleSheet("");
            break;
        case 2:
            ui->paciente2->setStyleSheet("background-color:red;");
            ui->paciente1->setStyleSheet("");
            ui->paciente3->setStyleSheet("");
            break;
        case 3:
            ui->paciente3->setStyleSheet("background-color:red;");
            ui->paciente2->setStyleSheet("");
            break;
    }
}

void Paciente:: on_okay_clicked(){
    //click en elemento desde teclado/perilla
    switch(contpos_7){
        case 0:
           on_notas_selectionChanged();
            break;
        case 1:
            on_paciente1_clicked();
            break;
        case 2:
            on_paciente2_clicked();
            break;
        case 3:
            on_paciente3_clicked();
            break;
    }
}

void Paciente::on_paciente2_clicked(){
    // se seleccioando paciente 2
    emit sonido_click();
    pac2=true;
    colorpaciente();
    pac2=false;
    emit bandera_perilla_7();
    this->close();
    contpos_7 = 0;
    delete this;
}


void Paciente::on_paciente3_clicked(){
    // se seleccioando paciente 3
    emit sonido_click();
    pac3=true;
    colorpaciente();
    pac3=false;
    emit bandera_perilla_7();
    this->close();
    contpos_7 = 0;
    delete this;
}

void Paciente::colorpaciente(){
    //cambiar colores del paciente seleccionado y cargar sus datos a los campos
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
    //mostrar teclado para escribir en notas ---ESTO SE VA A QUITAR
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
    //mueve el dialog, y guarda las notas
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
    //escribir en las notas
     QString actual_text = ui->notas->toPlainText();
     QString resultado = "";
     int longitud = actual_text.length();
     for(int i = 0; i<longitud-1; i++){
         resultado[i] = actual_text[i];
     }
     ui->notas->setPlainText(resultado);
}

void Paciente::letter_press_lastname(QString letter){
    //borrar en las notas
    QString actual_text = ui->notas->toPlainText();
    actual_text = actual_text + letter;
    ui->notas->setPlainText(actual_text);
}
