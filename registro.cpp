#include "registro.h"
#include "ui_registro.h"
#include <qdebug.h>
int contpos_6 = 0, list_size_registro = 0;
bool status_list = false;

Registro::Registro(QWidget *parent, SerialSpo2 *serialspo2_registro) :
    QDialog(parent),
    ui(new Ui::Registro)
{
    spo2serial_6 = serialspo2_registro; //se pasa una instancia del puerto serial, que es el teclado
    ui->setupUi(this); //se carga el ui
    connect(spo2serial_6, SIGNAL(boton_ajustes(QString )), this, SLOT(boton_handle_6(QString )), Qt::QueuedConnection); //se conecta la señal del teclado
    //blood combobox set settings - se agregan los elementos a los combobox
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

     QString nombre, consulta; //se manda a abrir la base de datos
     nombre.append("/opt/monitor_selespo2/bin/prueba.sqlite");
     db = QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName(nombre);
     if(db.open())
     {
         // se manda a llenar el combobox con los pacientes registrados
         // ESTO SE PUEDE HACER CON UN SELECT * FROM pacientes order by id asc, o algo parecido, se necesita una instancia de la DB?
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
    //esto es del teclado serial
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
    //tambien es del teclado serial
    switch(contpos_6){
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
    //esto también es del serial
    switch(contpos_6){
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
    //borrar el dialog
    emit sonido_click();
    emit bandera_perilla_6();
    this->close();
    contpos_6 = 0;
    delete this;
}

void Registro::on_OK_pressed()
{
    //obtener los datos de los edit text y mandarlos a guardar a la base de datos
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
    //abrir teclado virtual que escribe en el campo name/nombre
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
    //escribe en campo name/nombre
    QString actual_text = ui->names->toPlainText();
    actual_text = actual_text + letter;
    ui->names->setText(actual_text);
}

void Registro::erase_names(){
    //borra en campo name/nombre
     QString actual_text = ui->names->toPlainText();
     QString resultado = "";
     int longitud = actual_text.length();
     for(int i = 0; i<longitud-1; i++){
         resultado[i] = actual_text[i];
     }
     ui->names->setText(resultado);
}

void Registro::erase_last_names(){
    //borra en campo last_name
     QString actual_text = ui->last_name->toPlainText();
     QString resultado = "";
     int longitud = actual_text.length();
     for(int i = 0; i<longitud-1; i++){
         resultado[i] = actual_text[i];
     }
     ui->last_name->setText(resultado);
}

void Registro::letter_press_lastname(QString letter){
    //escribir en campo last_name
    QString actual_text = ui->last_name->toPlainText();
    actual_text = actual_text + letter;
    ui->last_name->setText(actual_text);
}

void Registro::on_last_name_selectionChanged()
{
    //abrir teclado virtual que escribe en el campo last_name
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
    //abrir teclado virtual que escribe en el campo last_name_mother
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
    //borra en campo last_name_mother
     QString actual_text = ui->mother_last_name->toPlainText();
     QString resultado = "";
     int longitud = actual_text.length();
     for(int i = 0; i<longitud-1; i++){
         resultado[i] = actual_text[i];
     }
     ui->mother_last_name->setText(resultado);
}

void Registro::letter_press_mother_last_name(QString letter){
    //escribir en campo last_name_mother
    QString actual_text = ui->mother_last_name->toPlainText();
    actual_text = actual_text + letter;
    ui->mother_last_name->setText(actual_text);
}

void Registro::on_notes_selectionChanged()
{
    //abrir teclado virtual que escribe en el campo notas
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
    //no hace nada?
    //this->setGeometry(0,0,800,480);
}

void Registro::erase_notes(){
    //borra en campo notas
     QString actual_text = ui->notes->toPlainText();
     QString resultado = "";
     int longitud = actual_text.length();
     for(int i = 0; i<longitud-1; i++){
         resultado[i] = actual_text[i];
     }
     ui->notes->setText(resultado);
}

void Registro::letter_notes(QString letter){
    //escribir en campo nota
    QString actual_text = ui->notes->toPlainText();
    actual_text = actual_text + letter;
    ui->notes->setText(actual_text);
}

void Registro::on_names_2_selectionChanged()
{
    //abrir teclado virtual que escribe en el campo uid
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
    //borra en campo uid
     QString actual_text = ui->names_2->toPlainText();
     QString resultado = "";
     int longitud = actual_text.length();
     for(int i = 0; i<longitud-1; i++){
         resultado[i] = actual_text[i];
     }
     ui->names_2->setText(resultado);
}

void Registro::letter_press_uid(QString letter){
    //escribir en campo uid
    QString actual_text = ui->names_2->toPlainText();
    actual_text = actual_text + letter;
    ui->names_2->setText(actual_text);
}
