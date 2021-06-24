#include "registro.h"
#include "ui_registro.h"
#include <qdebug.h>
int contpos_6 = 0, list_size_registro = 0;
bool status_list = false;

Registro::Registro(QWidget *parent, SerialSpo2 *serialspo2_registro) :
    QDialog(parent),
    ui(new Ui::Registro)
{
    spo2serial_6 = serialspo2_registro;
    ui->setupUi(this);
    connect(spo2serial_6, SIGNAL(boton_ajustes(QString )), this, SLOT(boton_handle_6(QString )), Qt::QueuedConnection);
    //blood combobox set settings
     ui->blood_type->addItem("A +");
     ui->blood_type->addItem("A -");
     ui->blood_type->addItem("B +");
     ui->blood_type->addItem("B -");
     ui->blood_type->addItem("AB +");
     ui->blood_type->addItem("AB -");
     ui->blood_type->addItem("O +");
     ui->blood_type->addItem("O -");
     ui->gender->addItem("MASCULNO");
     ui->gender->addItem("FEMENINO");

     QString nombre, consulta;
     nombre.append("/opt/monitor_selespo2/bin/prueba.sqlite");
     db = QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName(nombre);
     if(db.open())
     {
         QSqlQuery crear;
         consulta.append("SELECT * FROM pacientes WHERE id = 1");
         crear.prepare(consulta);
         crear.exec();
         crear.next();

     ui->num_paciente->addItem(crear.value(1).toString()+" "+crear.value(2).toString()+" "+crear.value(3).toString());
     consulta.clear();
     consulta.append("SELECT * FROM pacientes WHERE id = 2");
     crear.prepare(consulta);
     crear.exec();
     crear.next();
     ui->num_paciente->addItem(crear.value(1).toString()+" "+crear.value(2).toString()+" "+crear.value(3).toString());
     consulta.clear();
     consulta.append("SELECT * FROM pacientes WHERE id = 3");
     crear.prepare(consulta);
     crear.exec();
     crear.next();
     ui->num_paciente->addItem(crear.value(1).toString() + " " +crear.value(2).toString()+" "+crear.value(3).toString());
     }
}


Registro::~Registro(){
    delete ui;
}

void Registro::boton_handle_6(QString x){

    if(!status_list){
        if (x == "derecha"){
        contpos_6 = contpos_6 + 1;
        if(contpos_6 > 10){
            contpos_6 = 10;
        }
        opciones_registro();
        }

        else if(x == "izquierda"){
            contpos_6 = contpos_6 - 1;
            if(contpos_6 < 0){
                contpos_6 = 0;
            }
            opciones_registro();
        }
       else if(x == "click"){
            status_list = !status_list;

            on_okay_clicked();

        }
    }
    else{

    }
}

void Registro:: on_okay_clicked(){

    switch(contpos_6)
    {
    case 0:
      on_names_selectionChanged();
        break;
    case 1:
        on_names_2_selectionChanged();
        break;
    case 2:
        on_last_name_selectionChanged();
        break;
    case 3:
        on_mother_last_name_selectionChanged();
        break;
    case 4:

            if(status_list){
                ui->blood_type->showPopup();

            }else{
                ui->blood_type->hidePopup();
            }

        break;
    case 5:

        break;
    case 6:

        break;
    case 7:

        break;
    case 8:
        on_notes_selectionChanged();
        break;
    case 9:
        on_CERRAR_pressed();
        break;
    case 10:
        on_OK_pressed();
        break;
    }
}

void Registro:: opciones_registro(){
    switch(contpos_6)
    {
    case 0:
        ui->names->setStyleSheet("background-color:red;");
        ui->names_2->setStyleSheet("");
        break;
    case 1:
        ui->names_2->setStyleSheet("background-color:red;");
        ui->names->setStyleSheet("");
        ui->last_name->setStyleSheet("");
        break;
    case 2:
        ui->last_name->setStyleSheet("background-color:red;");
        ui->names_2->setStyleSheet("");
        ui->mother_last_name->setStyleSheet("");
        break;
    case 3:
        ui->mother_last_name->setStyleSheet("background-color:red;");
        ui->last_name->setStyleSheet("");
        ui->blood_type->setStyleSheet("");
        break;
    case 4:
        ui->blood_type->setStyleSheet("background-color:red;");
        ui->mother_last_name->setStyleSheet("");
        ui->gender->setStyleSheet("");
        break;
    case 5:
        ui->gender->setStyleSheet("background-color:red;");
        ui->blood_type->setStyleSheet("");
        ui->age_c->setStyleSheet("");
        break;
    case 6:
        ui->age_c->setStyleSheet("background-color:red;");
        ui->gender->setStyleSheet("");
        ui->num_paciente->setStyleSheet("");
        break;
    case 7:
        ui->num_paciente->setStyleSheet("background-color:red;");
        ui->age_c->setStyleSheet("");
        ui->notes->setStyleSheet("");
        break;
    case 8:
        ui->notes->setStyleSheet("background-color:red;");
        ui->num_paciente->setStyleSheet("");
        ui->CERRAR->setStyleSheet("");
        break;
    case 9:
        ui->CERRAR->setStyleSheet("background-color:red;");
        ui->notes->setStyleSheet("");
        ui->OK->setStyleSheet("");
        break;
    case 10:
        ui->OK->setStyleSheet("background-color:red;");
        ui->CERRAR->setStyleSheet("");
        break;
    }
}




void Registro::on_CERRAR_pressed()
{
    emit sonido_click();
    emit bandera_perilla_6();
    this->close();
    contpos_6 = 0;
    delete this;
}

void Registro::on_OK_pressed()
{
    QString name, last_name, mother_name, age, gender, blood_type, notes, id, uid;
    int current;
    current = ui->num_paciente->currentIndex() + 1;
    id = QString::number(current);
    name = ui->names->toPlainText();
    last_name = ui->last_name->toPlainText();
    mother_name = ui->mother_last_name->toPlainText();
    age = ui->age_c->text();
    gender = ui->gender->currentText();
    blood_type = ui->blood_type->currentText();
    notes = ui->notes->toPlainText();
    uid = ui->names_2->toPlainText();
    QSqlQuery crear;
    QString save_settings_mode;
    save_settings_mode.clear();
    save_settings_mode.append("UPDATE pacientes SET nombres ='"+name+"', apellidop ='"+last_name+"'"
                              ", apellidom ='"+mother_name+"', edad ='"+age+"'"
                              ", sexo ='"+gender+"', tiposangre ='"+blood_type+"', notas ='"+notes+"', firebase ='"+uid+"'  WHERE id =" +id);
    crear.prepare(save_settings_mode);
    qDebug()<<save_settings_mode;
    crear.exec();
    save_settings_mode.clear();
    emit sonido_click();
    emit bandera_perilla_6();
    this->close();
    contpos_6 = 0;
    delete this;

}


void Registro::on_names_selectionChanged()
{
    teclado = new Teclado;
    teclado->setWindowFlags(Qt::FramelessWindowHint);
    QObject::connect(teclado, SIGNAL(letter_press(QString)), this, SLOT(letter_press(QString)));
    QObject::connect(teclado, SIGNAL(erase_names()), this, SLOT(erase_names()));
    teclado->setWindowFlags(Qt::Popup);
    teclado->setGeometry(80,260,1121,340);
    //this->setGeometry(0,240,800,480);
    teclado->exec();
    show();
}

void Registro::letter_press(QString letter){
    QString actual_text = ui->names->toPlainText();
    actual_text = actual_text + letter;
    ui->names->setText(actual_text);
}

void Registro::erase_names(){
     QString actual_text = ui->names->toPlainText();
     QString resultado = "";
     int longitud = actual_text.length();
     for(int i = 0; i<longitud-1; i++){
         resultado[i] = actual_text[i];
     }
     ui->names->setText(resultado);
}

void Registro::erase_last_names(){
     QString actual_text = ui->last_name->toPlainText();
     QString resultado = "";
     int longitud = actual_text.length();
     for(int i = 0; i<longitud-1; i++){
         resultado[i] = actual_text[i];
     }
     ui->last_name->setText(resultado);
}

void Registro::letter_press_lastname(QString letter){
    QString actual_text = ui->last_name->toPlainText();
    actual_text = actual_text + letter;
    ui->last_name->setText(actual_text);
}

void Registro::on_last_name_selectionChanged()
{
    teclado = new Teclado;
    teclado->setWindowFlags(Qt::FramelessWindowHint);
    QObject::connect(teclado, SIGNAL(letter_press(QString)), this, SLOT(letter_press_lastname(QString)));
    QObject::connect(teclado, SIGNAL(erase_names()), this, SLOT(erase_last_names()));
    teclado->setWindowFlags(Qt::Popup);
    teclado->setGeometry(80,350,1121,340);
    //this->setGeometry(0,1400,800,480);
    teclado->exec();
    show();
}

void Registro::on_mother_last_name_selectionChanged()
{
    teclado = new Teclado;
    teclado->setWindowFlags(Qt::FramelessWindowHint);
    QObject::connect(teclado, SIGNAL(letter_press(QString)), this, SLOT(letter_press_mother_last_name(QString)));
    QObject::connect(teclado, SIGNAL(erase_names()), this, SLOT(erase_mother_last_name()));
    teclado->setWindowFlags(Qt::Popup);
    teclado->setGeometry(80,350,1121,340);
    //this->setGeometry(0,1400,800,480);
    teclado->exec();
    show();
}

void Registro::erase_mother_last_name(){
     QString actual_text = ui->mother_last_name->toPlainText();
     QString resultado = "";
     int longitud = actual_text.length();
     for(int i = 0; i<longitud-1; i++){
         resultado[i] = actual_text[i];
     }
     ui->mother_last_name->setText(resultado);
}

void Registro::letter_press_mother_last_name(QString letter){
    QString actual_text = ui->mother_last_name->toPlainText();
    actual_text = actual_text + letter;
    ui->mother_last_name->setText(actual_text);
}

void Registro::on_notes_selectionChanged()
{
    teclado = new Teclado;
    teclado->setWindowFlags(Qt::FramelessWindowHint);
    QObject::connect(teclado, SIGNAL(letter_press(QString)), this, SLOT(letter_notes(QString)));
    QObject::connect(teclado, SIGNAL(erase_names()), this, SLOT(erase_notes()));
    QObject::connect(teclado, SIGNAL(close_keyboard()), this, SLOT(close_keyboard()));
    teclado->setWindowFlags(Qt::Popup);
    teclado->setGeometry(80,100,1121,340);
    //this->setGeometry(0,-240,800,480);
    teclado->exec();
    show();
}

void Registro::close_keyboard(){
    //this->setGeometry(0,0,800,480);
}

void Registro::erase_notes(){
     QString actual_text = ui->notes->toPlainText();
     QString resultado = "";
     int longitud = actual_text.length();
     for(int i = 0; i<longitud-1; i++){
         resultado[i] = actual_text[i];
     }
     ui->notes->setText(resultado);
}

void Registro::letter_notes(QString letter){
    QString actual_text = ui->notes->toPlainText();
    actual_text = actual_text + letter;
    ui->notes->setText(actual_text);
}





void Registro::on_names_2_selectionChanged()
{
    teclado = new Teclado;
    teclado->setWindowFlags(Qt::FramelessWindowHint);
    QObject::connect(teclado, SIGNAL(letter_press(QString)), this, SLOT(letter_press_uid(QString)));
    QObject::connect(teclado, SIGNAL(erase_names()), this, SLOT(erase_uid()));
    QObject::connect(teclado, SIGNAL(close_keyboard()), this, SLOT(close_keyboard()));
    teclado->setWindowFlags(Qt::Popup);
    teclado->setGeometry(80,240,1121,340);
    teclado->exec();
    show();
}


void Registro::erase_uid(){
     QString actual_text = ui->names_2->toPlainText();
     QString resultado = "";
     int longitud = actual_text.length();
     for(int i = 0; i<longitud-1; i++){
         resultado[i] = actual_text[i];
     }
     ui->names_2->setText(resultado);
}

void Registro::letter_press_uid(QString letter){
    QString actual_text = ui->names_2->toPlainText();
    actual_text = actual_text + letter;
    ui->names_2->setText(actual_text);
}
