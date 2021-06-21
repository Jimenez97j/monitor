#include "mod2.h"
#include "ui_mod2.h"
#include <QTimer>
#include <QDebug>
#include <QDesktopWidget>
#include <QScreen>

int contpos_8 = 0;


QString hora2;
int captura = 0, time_color = 0, time_check_alarms_value = 0;
bool capture_activated = false, capture_activated_animation = false, update_color_time = false;
QString *arrdata;
bool *activated_mod;
bool bocina = true, pani_toggle_style = true;
bool bandera_3= true;
//variables for alarms
//Juan
int numbers_alarms = 0;
bool cambio_numeros_mod2 = true, cambio_numeros2_mod2 = true, cambio_numeros3_mod2 = true;
QTimer *cronometro_mod2 =new QTimer();

MOD2::MOD2(QWidget *parent, SerialSpo2 *serialspo2_modelo_2) :
    QDialog(parent),
    ui(new Ui::MOD2)
{
    spo2serial_8 = serialspo2_modelo_2;
    ui->setupUi(this); QString nombre, consulta, maincolor;
    connect(spo2serial_8, SIGNAL(boton_ajustes(QString )), this, SLOT(boton_handle_8(QString )), Qt::QueuedConnection);
    connect(spo2serial_8, SIGNAL(cambiar_estado_bandera_3()), this, SLOT(cambiar_bandera_barra_2()));
    ui->sound->setCheckable(true);
    ui->pani->setCheckable(true);
    nombre.append("/opt/monitor_selespo2/bin/prueba.sqlite");
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(nombre);
    if(db.open()){

        //check the color choosen
        QSqlQuery crear;
        consulta.append("SELECT * FROM ajustes WHERE 1");
        crear.prepare(consulta);
        crear.exec();
        crear.next();
        maincolor = crear.value(1).toString();
        consulta.clear();

        //Color white is forbidden for numeric view
        if(maincolor == "#ffffff"){maincolor = "#000000";}
        ui->color->setStyleSheet("background-color:" + maincolor);
    }
    pani_toggle_style = get_pani_status();
    if(pani_toggle_style){
        //ui->pani->setStyleSheet("background-repeat:none;border-image: url(:/imagenes/detenerpani2.png);border: none;");
        ui->pani->setIcon(QIcon(":/imagenes/btn_Detener.png"));
    }else{
        //ui->pani->setStyleSheet("background-repeat:none;border-image: url(:/imagenes/inciarpani2.png);border: none;");
        ui->pani->setIcon(QIcon(":/imagenes/btn_Iniciar.png"));
    }
//++++++++++++++++++++++++++++++++++++++++++++++ TIMER ++++++++++++++++++++++++++++++++++++++++++++
    connect(cronometro_mod2, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer()));
    cronometro_mod2->start(1);

//++++++++++++++++++++++++++++++++++++++ Getting sound settings ++++++++++++++++++++++++++++++++++++

    bool sound_status = sonido_get_status();
    if(!sound_status){
        //ui->sound->setStyleSheet("background-repeat:none;border-image: url(:/imagenes/nosound.png);border: none;");
        bocina = false;
        ui->sound->setChecked(false);
        ui->sound->setIcon(QIcon(":/imagenes/btn_BocinaOFF.png"));
    }
    else{
        //ui->sound->setStyleSheet("background-repeat:none;border-image: url(:/imagenes/sonido.png);border: none;");
        bocina = true;
        ui->sound->setChecked(true);
        ui->sound->setIcon(QIcon(":/imagenes/btn_Bocina.png"));
    }
}

void MOD2::alarm_status_change(){
    qDebug()<<"works";
}

MOD2::~MOD2()
{
    delete ui;
}

void MOD2::boton_handle_8(QString y){
if (bandera_3 == true){
    if (y == "derecha"){
    contpos_8 = contpos_8 + 1;
    if(contpos_8 > 11){
        contpos_8 = 11;
    }
        opciones_mod2();
    }

    else if(y == "izquierda"){
        contpos_8 = contpos_8 - 1;
        if(contpos_8 < 0){
            contpos_8 = 0;
        }
        opciones_mod2();
    }

    else if(y == "click"){
        on_okay_clicked();

    }

}
}

void MOD2:: opciones_mod2(){
    switch(contpos_8)
    {
    case 0:
        ui->registros->setStyleSheet("background-color:red;");
        ui->captura->setStyleSheet("");
        break;
    case 1:
        ui->captura->setStyleSheet("background-color:red;");
        ui->registros->setStyleSheet("");
        ui->galeria->setStyleSheet("");
        break;
    case 2:
        ui->galeria->setStyleSheet("background-color:red;");
        ui->captura->setStyleSheet("");
        ui->alarmas->setStyleSheet("");
        break;
    case 3:
        ui->alarmas->setStyleSheet("background-color:red;");
        ui->galeria->setStyleSheet("");
        ui->pani->setStyleSheet("");
        break;
    case 4:
        ui->pani->setStyleSheet("background-color:red;");
        ui->alarmas->setStyleSheet("");
        ui->derivaciones->setStyleSheet("");
        break;
    case 5:
        ui->derivaciones->setStyleSheet("background-color:red;");
        ui->pani->setStyleSheet("");
        ui->registro->setStyleSheet("");
        break;
    case 6:
        ui->registro->setStyleSheet("background-color:red;");
        ui->derivaciones->setStyleSheet("");
        ui->paciente->setStyleSheet("");
        break;
    case 7:
        ui->paciente->setStyleSheet("background-color:red;");
        ui->registro->setStyleSheet("");
        ui->close->setStyleSheet("");
        break;
    case 8:
        ui->close->setStyleSheet("background-color:red;");
        ui->paciente->setStyleSheet("");
        ui->sound->setStyleSheet("");
        break;
    case 9:
        ui->sound->setStyleSheet("background-color:red;");
        ui->close->setStyleSheet("");
        ui->ajustes->setStyleSheet("");
        break;
    case 10:
        ui->ajustes->setStyleSheet("background-color:red;");
        ui->sound->setStyleSheet("");
        ui->internet->setStyleSheet("");
        break;
    case 11:
        ui->internet->setStyleSheet("background-color:red;");
        ui->ajustes->setStyleSheet("");
        break;
        break;
    }
}

void MOD2:: on_okay_clicked(){

    switch(contpos_8)
    {
    case 0:
       on_registros_pressed();
        break;
    case 1:
        on_captura_pressed();
        break;
    case 2:
        on_galeria_pressed();
        break;
    case 3:
        on_alarmas_pressed();
        break;
    case 4:
        on_pani_pressed();
        break;
    case 5:
        //on_derivaciones_pressed();
        break;
    case 6:
        on_registro_pressed();
        break;
    case 7:
        on_paciente_pressed();
        break;
    case 8:
        on_close_pressed();
        break;
    case 9:
        on_sound_pressed();
        break;
    case 10:
        on_ajustes_pressed();
        break;
    case 11:
        on_internet_clicked();
        break;
    }

}

void MOD2::cambiar_bandera_barra_2(){

    bandera_3 = true;
}

void MOD2::on_registros_pressed()
{
    bandera_3 = false;
    emit records_2();
}

void MOD2::on_close_pressed()
{

    cronometro_mod2->disconnect();
    cronometro_mod2->stop();
    emit closing_window(); //verificar si este metodo funciona o si es mejor una variable booleana y seguir recibiendo datos
    emit bandera_perilla_8();
    this->close();
    contpos_8 = 0;
    delete this;
}

void MOD2::funcionActivacionTimer(){

    pani_toggle_style = get_pani_status();

    if(pani_toggle_style){
        //ui->pani->setStyleSheet("background-repeat:none;border-image: url(:/imagenes/detenerpani2.png);border: none;");
        ui->pani->setIcon(QIcon(":/imagenes/btn_Detener.png"));
    }else{
        //ui->pani->setStyleSheet("background-repeat:none;border-image: url(:/imagenes/inciarpani2.png);border: none;");
        ui->pani->setIcon(QIcon(":/imagenes/btn_Iniciar.png"));
    }

    time_check_alarms_value = time_check_alarms_value + 1;
    arrdata =labels();
    activated_mod = alarm_status();
    if(update_color_time)
    {
        if(time_color>30000)
        {
            update_color_time = false;
        }
        QString colormain = getcolor();
        if(colormain == "#ffffff"){
            colormain = "#000000";
        }
         ui->color->setStyleSheet("background-color:" + colormain);

    }

    hora2=QDateTime::currentDateTime().toString("dd-MM-yyyy");
    hora2 = hora2 + "\r\n" + QDateTime::currentDateTime().toString("hh:mm:ss");
    ui->label_10->setText(hora2);
    ui->bpm_ecg->setText(arrdata[0]);
    if(arrdata[1] == "not"){
        ui->SPO2->setText("00");
        ui->tex3->setText("<font color='red' size='.3'>No Finger</font>");
        ui->tex3->setGeometry(200,60,140,41);
        ui->SPO2->setGeometry(0,0,271,151);
    }
    if(arrdata[1] == "..."){
        ui->SPO2->setText(arrdata[1]);
        ui->tex3->setText("<font color='yellow' size='.3'>Midiendo</font>");
        ui->tex3->setGeometry(120,60,140,41);
        ui->SPO2->setGeometry(120,0,271,151);
    }
    if(!(arrdata[1] == "not") && !(arrdata[1] == "...")){
        ui->SPO2->setText(arrdata[1]);
        ui->tex3->setText("<font color='#16ff17' size='2'>%</font>");
        ui->tex3->setGeometry(300,60,140,41);
        ui->SPO2->setGeometry(0,0,271,151);
    }
    ui->temp->setText(arrdata[2]);
    ui->sisto->setText(arrdata[3]);
    ui->dias->setText(arrdata[4]);
    ui->media->setText(arrdata[5]);

    captura = captura + 1;
    numbers_alarms = numbers_alarms + 1;
    //clean the letters of notification after 2 seconds
    if(captura==2000 && capture_activated){
        ui->notificacion->setText("");
        ui->notificacion2->setText("");
        ui->notificacion3->setText("");
        ui->notificacion4->setText("");
        ui->notificacion5->setText("");
        ui->notificacion6->setText("");
        ui->notificacion7->setText("");
        ui->notificacion8->setText("");
        ui->notificacion9->setText("");
        ui->notificacion10->setText("");
        ui->notificacion11->setText("");
        ui->notificacion12->setText("");
        ui->notificacion13->setText("");
        captura=0;
        capture_activated = false;
    }

    //create an effect for screenshot
    if(captura==100 && capture_activated_animation)
    {
         ui->frame->setStyleSheet("background-color: rgba(255, 255, 255, 183);");
    }
    if(captura==140 && capture_activated_animation)
    {
         ui->frame->setStyleSheet("background-color: rgba(255, 255, 255, 155);");
    }
    if(captura==190 && capture_activated_animation)
    {
         ui->frame->setStyleSheet("background-color: rgba(255, 255, 255, 105);");
    }
    if(captura==240 && capture_activated_animation)
    {
         ui->frame->setStyleSheet("background-color: rgba(255, 255, 255, 80);");
    }
    if(captura==290 && capture_activated_animation)
    {
         ui->frame->hide();
         capture_activated_animation = false;
    }
     if(time_check_alarms_value == 400){
         emit time_check_alarms();
         time_check_alarms_value = 0;
     }

    if(numbers_alarms == 500){
        if(cambio_numeros_mod2 && activated_mod[0]){
            QLabel *label1=ui->bpm_ecg;
            QString color="color:#880e00;border:none";
            alarmasnumeros(label1,color);
            cambio_numeros_mod2=false;
            numbers_alarms=0;
          //  ui->bpm_ecg->setStyleSheet("background-color: rgba(191, 64, 64, 0); border:none");

        }
        else{
            QLabel *label1=ui->bpm_ecg;
            QString color="color:#ff0000;border:none";
            alarmasnumeros(label1,color);
            cambio_numeros_mod2=true;
            numbers_alarms=0;
          //  ui->bpm_ecg->setStyleSheet("background-color: rgba(191, 64, 64, 0); border:none");


        }
        if(cambio_numeros2_mod2 && activated_mod[1]){
              QLabel *label2=ui->SPO2;
              QString color="color:#005b01;border:none";
              alarmasnumeros(label2,color);
              cambio_numeros2_mod2=false;
              numbers_alarms=0;
             // ui->SPO2->setStyleSheet("background-color: rgba(191, 64, 64, 0); border:none");


        }
        else{
              QLabel *label2=ui->SPO2;
              QString color="color:#6bff19;border:none ";
              alarmasnumeros(label2,color);
              cambio_numeros2_mod2=true;
              numbers_alarms=0;
           //   ui->SPO2->setStyleSheet("background-color: rgba(191, 64, 64, 0); border:none");


        }
        if(cambio_numeros3_mod2 && activated_mod[2]){
            QLabel *label3=ui->temp;
            QString color="color:#003e56;border:none";
            alarmasnumeros(label3,color);
            cambio_numeros3_mod2=false;
            numbers_alarms=0;
           // ui->temp->setStyleSheet("background-color: rgba(191, 64, 64, 0); border:none");


        }
        else{
            QLabel *label3=ui->temp;
            QString color="color:#1b50ff;border:none ";
            alarmasnumeros(label3,color);
            cambio_numeros3_mod2=true;
            numbers_alarms=0;
          //  ui->temp->setStyleSheet("background-color: rgba(191, 64, 64, 0); border:none");

        }
    }

}

void MOD2::on_galeria_pressed()
{
    bandera_3 = false;
    emit galeria_2();
}

void MOD2::on_alarmas_pressed()
{
   bandera_3 = false;
   emit alarmas_2();
}

void MOD2::on_ajustes_pressed()
{
    bandera_3 = false;
    emit ajustes_2();
    update_color_time = true;
}

void MOD2::detection_toggle_once(){
        emit detection_change();
}

void MOD2::time_save_change_once(int x){
    emit time_save_change(x);
}

void MOD2::change_color_mod2(){
     //emit change_color();
    QString colormain = getcolor();
    if(colormain == "#ffffff"){
        colormain = "#000000";
    }
     ui->color->setStyleSheet("background-color:" + colormain);
}

void MOD2::on_sound_pressed()
{
    bandera_3 = false;
    if(bocina){
        bocina=false;
        ui->sound->setChecked(false);
        ui->sound->setIcon(QIcon(":/imagenes/btn_BocinaOFF.png"));
        //ui->sound->setStyleSheet("QToolButton {background-image: url(:/imagenes/nosound.png); background-repeat:none; border:none}");
        emit sound_change_on();
    }
    else{
        bocina=true;
        ui->sound->setChecked(true);
        ui->sound->setIcon(QIcon(":/imagenes/btn_Bocina.png"));
        //ui->sound->setStyleSheet("QToolButton {background-image: url(:/imagenes/sonido.png); background-repeat:none; border:none}");
        emit sound_change_on();
    }
}



void MOD2::on_captura_pressed()
{
    bandera_3 = false;
    QScreen *QSCREEN = QGuiApplication::primaryScreen();
    QPixmap qpix = QSCREEN->grabWindow(this->winId(), 0, 0, QApplication::desktop()->width(),
                                       QApplication::desktop()->height());
    qpix.save("./imagenes/"+hora2+".png");
     ui->notificacion->setText("<font color='#08afff'>C</font>");
    ui->notificacion2->setText("<font color='#08afff'>A</font>");
    ui->notificacion3->setText("<font color='#08afff'>P</font>");
    ui->notificacion4->setText("<font color='#08afff'>T</font>");
    ui->notificacion5->setText("<font color='#08afff'>U</font>");
    ui->notificacion6->setText("<font color='#08afff'>R</font>");
    ui->notificacion7->setText("<font color='#08afff'>A</font>");
    ui->notificacion8->setText("<font color='#08afff'>T</font>");
    ui->notificacion9->setText("<font color='#08afff'>O</font>");
   ui->notificacion10->setText("<font color='#08afff'>M</font>");
   ui->notificacion11->setText("<font color='#08afff'>A</font>");
   ui->notificacion12->setText("<font color='#08afff'>D</font>");
   ui->notificacion13->setText("<font color='#08afff'>A</font>");
   ui->frame->show();
   ui->frame->setStyleSheet("background-color: #ffffff;");
    captura = 0;
    capture_activated = true;
    capture_activated_animation = true;
       // hora_captura=0;
}

void MOD2::on_internet_clicked(){
    bandera_3 = false;
    envdat = new enviardatos;
    //enviardatosw = new enviardatos;
    envdat->setWindowFlags(Qt::FramelessWindowHint);
    envdat->setWindowFlags(Qt::Popup);
    QObject::connect(envdat, SIGNAL(sonido_click()), this, SLOT(sonido_click()));
    QObject::connect(envdat, SIGNAL(send_data(int)), this, SLOT(enviar_datos(int)));
    //enviardatosw->setGeometry(87, 10, 510, 70);
    envdat->setGeometry(0, 10, 602, 110);
    envdat->exec();
    show();
}

void MOD2::on_registro_pressed()
{
    bandera_3 = false;
    emit registro_2();
}

void MOD2::on_paciente_pressed()
{
    bandera_3 = false;
    emit paciente_2();
}



void MOD2::on_pani_pressed()
{
    bandera_3 = false;

    if(!pani_toggle_style)
    {
        emit startpani();
        pani_toggle_style = true;
        ui->pani->setChecked(true);
        ui->pani->setIcon(QIcon(":/imagenes/btn_Detener.png"));
        //ui->pani->setStyleSheet("background-image: url(:/imagenes/detenerpani2.png);background-repeat:none;border: none");
    }
    else{
        emit stoppani();
        pani_toggle_style = false;
        ui->pani->setChecked(false);
        ui->pani->setIcon(QIcon(":/imagenes/btn_Iniciar.png"));
        //ui->pani->setStyleSheet("background-image: url(:/imagenes/inciarpani2.png);background-repeat:none;border: none");
    }
}

void MOD2::on_internet_pressed()
{

}
