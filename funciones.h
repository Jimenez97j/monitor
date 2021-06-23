#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <exception>
#include <QDebug>


//Check if every port is open
bool usbready = false, spo2 = false, ecg = false, ecg_datos= false, database_exist = false, folder_img = false;
bool is_spo2_ready = false, reciving_spo2_data = false;;
//Wait for hardware to send an ok signal

//alarms values
int alarma_min_temp = 0, alarma_max_temp = 0;
int alarma_max_spo2 = 0, alarma_min_spo2 = 0;
int alarma_min_ecg = 0, alarma_max_ecg = 0;
float save_alarm_data_bpm = 0;
double saving_temperature = 0, savespo2= 0;
bool activated_before = true, desactivated_before = false;


//main color of the app
QString maincolor = "white", paciente_activo;
QString consulta, bpm_save_reg = "sin-datos", spo2_save_reg = "sin-datos",
rpm_save_reg = "sin-datos", ps_save_reg = "sin-datos", px_save_reg = "sin-datos",
bpm_mod2=" --",sop2_mod2="  --",temp_mod2="--",sys_mod2="--",dia_mod2=" --",
med_mod2="--", temp_save_reg ="sin-datos";

//variables for alarms toggle and priority
bool ecg_in = false, ecg_out = false, spo2_in = false, spo2_out = false, temp_in = false, temp_out = false;
bool is_graph_ples_activated = true; //if the second mode is on, graphs should stop

bool press_flag_data = false,silenciado = true, status = true, change_bottom_sound_status = false;
//variables for knowing if the serial command for alarms has been send before
bool alarm1 = false, alarm2 = false, alarm3 = false;
//variables for ecg detection
bool detection = false, detection_mode_change = false, banderapuntos=false;
//select the derivation of ecg to show
bool active = false,  activated=false, activated2=false, activated3=false;
bool arr[12] =   { false, false, false, false, false, false, false, false, false, false, false, false };
bool bandera_pani=false;

int estatebutton = 0, contador= 0;

int  pantalla= 0; //Error en PANI

int number_of_data_pm = 25, data_time_rate = 57000; //saving data per minute, 4320 savings for 72 hours

//variables for rpm graph
double datos_en_pantalla_rpm = 100, datos_grafica_max_rpm = 800, upset_rpm= 0, rango_max_rpm, rango_min_rpm, rescale_value_rpm=20, data_save_rpm = 0;
QByteArray presion = "A";


void MainWindow::alarmasonido(bool boton, bool activado){
   if(boton && activado){
       sonidoboton2("/home/pi/Music/sonidos/TRESbeeps.mp3");
       active_timer_for_alarms(true);
   }
   else{
       active_timer_for_alarms(false);
   }
}


void MainWindow::silenciar_alarmas(bool valor, bool boton){
    if(ecg_in){
           if(!alarm1){
               activated = true; //parpadeo numerico aquí
              // qDebug()<<"serialecgon"; //serial write el comando al arduino para el color rojo y sonido
               alarm1 = true;
               alarmasonido(boton, true);
           }
           //qDebug()<<"serialecgon";
           emit spo2serial->escribe("H");
           spo2_out = false;
           temp_out = false;
       }
       else{
           if(activated){
               alarm1 = false;
               activated = false; //apagar parpadeo numerico ecg
              // qDebug()<<"serialecgoff";
               // serial->write("L");
               emit spo2serial->escribe("L");
                if(spo2_in || temp_in){
                    alarmasonido(boton, true); // si hay otras alarmas dejamos encendido el sonido
                }else{
                    alarmasonido(boton, false); //apagamos sonido si no hay otras alarmas
                }
           }
       }
       if(spo2_in)
       {
           if(!alarm2){
               activated2 = true;//parpadeo numerico aquí
           }
           if(spo2_out){
              // qDebug()<<"serialspo2on"; //serial write el comando al arduino para el color amarillo y sonido
               alarm2 = true;
               temp_out = false;
               //serial->write("K");
               emit spo2serial->escribe("K");
           }
       }
       else{
           if(activated2){
                alarm2 = false;
                activated2 = false; //apagar parpadeo numerico spo2
              //  qDebug() << "serialspo2off";
               // serial->write("L");
                //spo2serial->write_value("L");
           }
       }
       if(temp_in){
           if(!alarm3){
               activated3 = true; //parpadeo numerico aquí
           }
           if(temp_out){
            //   qDebug()<<"serialtempon"; //serial write el comando al arduino para el color azul y sonido
              // serial->write("J");
               emit spo2serial->escribe("J");
               alarm3 = true;
           }
       }
       else{
           if(activated3){
               alarm3 = false;
               activated3 = false; //apagar parpadeo numerico temp
               qDebug()<< "serialtempoff";
               //serial->write("L");
               emit spo2serial->escribe("L");
            }
       }
       if(ecg_in && activated_before){
           //alarmasonido(boton, true);
           qDebug()<<"ecgsound";
           activated_before = false;
           desactivated_before = true;
       }
       else {
           if(spo2_out && activated_before){
           //alarmasonido(boton, true);
           qDebug()<<"spo2sound";
           activated_before = false;
           desactivated_before = true;
            }
           else{
               if(temp_out && activated_before){
               //alarmasonido(boton, true);
               qDebug()<<"tempsound";
               activated_before = false;
               desactivated_before = true;
               }
               else{
                   if(!ecg_in && !spo2_out && !temp_out && desactivated_before){
                      // alarmasonido(boton, false);
                       qDebug()<<"off";
                       activated_before = true;
                       desactivated_before = false;
                   }
               }
           }
       }
}


void MainWindow::plot_spo2(QVector<double> x, QVector<double> y, int upset_data, double min_range, double max_range, double size_max){  //function for ploting the spo2

   if(is_graph_ples_activated){
       //qDebug()<<x;
    // ui->plot->yrescaleAxis(true);
       ui->plot->yAxis->setRange(min_range, max_range);  //Reescale the Y axis if it is necessary
       ui->plot->xAxis->setRange(upset_data, size_max); //Reescale the X axis if it is necessary
       ui->plot->graph(0)->setData(x,y); //Add the array of values to the graph set
       ui->plot->replot(); //paint the new values in the screen
       ui->plot->update(); // update the graph
       RecibirArreglo(1);
    // datos_grafica_max=datos_grafica_max+1; //increment the variable to move the graph along with data.
    // upset=upset+1; //increment the value to move the array along with data.
   }
}

/*void MainWindow::spo2_chart(){
    ui->plot->replot(); //paint the new values in the screen
    ui->plot->update(); // update the graph
}*/

void MainWindow::on_toolButton_pressed(){
    if(silenciado){
        silenciado=false;
        //ui->toolButton->setStyleSheet("QToolButton {background-image: url(:/imagenes/btn_BocinaOFF.png); background-repeat:none; border:none}");
        ui->toolButton->setChecked(false);
        ui->toolButton->setIcon(QIcon(":/imagenes/btn_BocinaOFF.png"));
    }
    else{
        silenciado=true;
        ui->toolButton->setChecked(true);
        ui->toolButton->setIcon(QIcon(":/imagenes/btn_Bocina.png"));
        //ui->toolButton->setStyleSheet("QToolButton {background-image: url(:/imagenes/btn_Sonido.png); background-repeat:none; border:none}");
    }

    qDebug("PRESIONADO BOCINA");
}


void MainWindow::RecibirArreglo(int caso){


   if(caso == 1){
           if(!is_spo2_ready){
               ui->SPO2->setText("...");
               sop2_mod2 = "...";
               ui->bpmsp2_2->setText("<font color='yellow' size='2'>Midiendo</font>");
               ui->bpmsp2_2->setGeometry(35,15,61,31);
               ui->SPO2->setGeometry(40,10,111,51);
           }else{
                ui->bpmsp2_2->setText("<font color='#16ff17' size='2'>%</font>");
                ui->bpmsp2_2->setGeometry(119,30,41,31);
                ui->SPO2->setGeometry(10,10,111,51);
                if(savespo2 > alarma_max_spo2){
                    spo2_in = true;
                    spo2_out = true;
                  // silenciar_alarmas(true, silenciado);
                }
                else{
                    if(savespo2 < alarma_min_spo2){

                        spo2_in = true;
                        spo2_out = true;
                     //   silenciar_alarmas(true, silenciado);
                    }
                    else{
                        spo2_in = false;
                        spo2_out = false;
                       // silenciar_alarmas(false, silenciado);
                    }
                }
           }
       }
   if(caso == 2){
       //rutine for temperature alarms
       if(saving_temperature < alarma_min_temp){
           temp_in = true;
           temp_out = true;
          // silenciar_alarmas(true, silenciado);
       }
       else{
           if(saving_temperature > alarma_max_temp){
               temp_in = true;
               temp_out = true;
            //   silenciar_alarmas(true, silenciado);
           }
           else{
               temp_in = false;
               temp_out = false;
              // silenciar_alarmas(false, silenciado);
           }
       }
   }
}



void MainWindow::RecibirArreglo_ECG_numerico(){
   QByteArray arreglo;
   QSqlQuery sqlalarm;
   QString checkbeats;

   arreglo=serial_ecg_data->readLine();
  // qDebug()<<"comando recibido:"+arreglo;
   cadena=arreglo; // convert array into string in order to use string functions
   length = cadena.length()-1;
   if(cadena[0] == 'A'){
       QString data;
       for (int i = 2; i<length ;i++ ) {
           data[i] = cadena[i];
       }
        bpm_save_reg = data + " " + "bpm"; //save bpm register into database
        bpm_mod2 = data;
        mqtt_fc = bpm_mod2.toInt();
        ui->bpm_ecg->setText(data);
        save_alarm_data_bpm = data.toDouble();
   }

   if(cadena[0] == 'E'){
       QString data;
       for (int i = 1; i<length ;i++ ) {
           data[i] = cadena[i];
       }
        ui->rpm->setText(data);
   }
}



void MainWindow::addPoint_rpm(double x, double y){ //funcion que agrega un nuevo punto a nuestro array de puntos a graficar
   qv_x_rpm.append(x);
   qv_y_rpm.append(y);
}


//funcion para guardar el registro de los signos vitales del paciente cada min
void MainWindow::save_data_db(){
   qDebug()<<"guardando";
   bool  save_or_update = false;
   QSqlQuery crear;
   QString hora;
   int count_register = 0, last_update_register;
   hora  = QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss");
   consulta.clear();
   //Check is it necessary to insert a new data or update (the program is required to save up to 6 days0.............
   consulta.append("SELECT COUNT(id) FROM registros");
   crear.prepare(consulta);
   crear.exec();
   crear.next();
   consulta.clear();
   count_register = crear.value(0).toInt(); //count the number of registers in the database

   if(count_register==number_of_data_pm - 1){
       consulta.append("UPDATE registros SET bandera = '0' WHERE id = 1");
       crear.prepare(consulta);
       crear.exec();
       consulta.clear();
   }

   if(count_register<number_of_data_pm){
       save_or_update = false;
   }

   else{save_or_update = true;}
   // creamos las instancias para hacer un insert en la tabla (DB)

   //check if there is new data from de press

   if(press_flag_data){
       press_flag_data = false;
   }

   else{
     ps_save_reg = "sin-datos", px_save_reg = "sin-datos", rpm_save_reg = "sin-datos";
   }
    consulta.clear();
    consulta.append("SELECT id FROM registros WHERE bandera = '0'");
    crear.prepare(consulta);
    crear.exec();
    crear.next();
    last_update_register = crear.value(0).toInt() + 1;

   if(last_update_register == number_of_data_pm + 1)
    {last_update_register = 1;}
    QString value= QString::number(last_update_register);
    consulta.clear();

   if(save_or_update){
    consulta.append("UPDATE registros SET hora = '" + hora +"', paciente='" + paciente_activo +"', bpm = '" + bpm_save_reg
                    +"', spo2 = '" + spo2_save_reg +"', rpm = '" + rpm_save_reg +"', prem = '" +
                    ps_save_reg +"', prex =  '" + px_save_reg +"',temp = '" + temp_save_reg +"', bandera = '1' WHERE bandera = '0'");
    crear.prepare(consulta);
    crear.exec();
    consulta.clear();
    consulta.append("UPDATE registros SET bandera = '0' WHERE id = " + value );
    crear.prepare(consulta);
    crear.exec();
    consulta.clear();
   }

   else{
    consulta.append("INSERT INTO registros(hora,paciente, bpm, spo2, rpm, prem, prex, temp, bandera) "
                   "VALUES ('" + hora +"', '" + paciente_activo +"','"
                   + bpm_save_reg +"', '" +
                   spo2_save_reg +"', '" +
                   rpm_save_reg +"', '" +
                   ps_save_reg +"', '" +
                   px_save_reg +"', '" +
                   temp_save_reg +"', '1' )");
               crear.prepare(consulta);
               crear.exec();
               consulta.clear();
   }
}


int derivaciones::statebutton(){
  return estatebutton;
}

void MainWindow::alarmasnumeros(QLabel *label,QString color){
label->setStyleSheet(color);
}

void MOD2::alarmasnumeros(QLabel *label,QString color){
label->setStyleSheet(color);
}

void ajustes::cleanAll(){
   QSqlQuery crear;
   consulta.append("DELETE FROM registros WHERE 1");
   crear.prepare(consulta);
   crear.exec();
   consulta.clear();
}

void ajustes::changebackground(QString color){
  maincolor = color;
  QSqlQuery crear;
  QString windowcolor;
  windowcolor.append("UPDATE ajustes SET color = '" + color + "' WHERE 1");
  crear.prepare(windowcolor);
  crear.exec();
  windowcolor.clear();
}

QString MOD2::getcolor(){
   return maincolor;
}

void MOD2::changebackground(QString color){
  maincolor = color;
  QSqlQuery crear;
  QString windowcolor;
  windowcolor.append("UPDATE ajustes SET color = '" + color + "' WHERE 1");
  crear.prepare(windowcolor);
  crear.exec();
  windowcolor.clear();
}

QString ajustes::getajustes(){
   QSqlQuery crear;
   QString actualcolor, windowcolor;
   windowcolor.append("SELECT * FROM ajustes WHERE 1");
   crear.prepare(windowcolor);
   crear.exec();
   crear.next();
   actualcolor = crear.value(1).toString();
   windowcolor.clear();

   if(actualcolor == "#326d72"){
       actualcolor = "Verde Aqua";
   }

   if(actualcolor == "#20214f"){
       actualcolor = "Morado renaciente";
   }

   if(actualcolor == "#ffffff"){
       actualcolor = "Blanco Luminoso";
   }

   if(actualcolor == "#000000"){
       actualcolor = "Negro Espacial";
   }

   if(actualcolor == "#003e6c"){
       actualcolor = "Azul Opaco";
   }

   return actualcolor;
}

QString ajustes::gettime(){
   QSqlQuery timequery;
   QString actualtime,  actualtimereturn;
   actualtime.append("SELECT * FROM ajustes WHERE 1");
   timequery.prepare(actualtime);
   timequery.exec();
   timequery.next();
   actualtimereturn = timequery.value(3).toString();
   timequery.clear();

   return actualtimereturn;
}

QString* MOD2::labels()
{
   QString* arr = new QString[6];
   arr[0] = bpm_mod2;
   arr[1] = sop2_mod2;
   arr[2] = temp_mod2;
   arr[3] = sys_mod2;
   arr[4] = dia_mod2;
   arr[5] = med_mod2;
   return arr;
}

QString* MainWindow::retornar_valores(){
    QString* arr2 = new QString[6];
    arr2[0] = bpm_mod2;
    arr2[1] = sop2_mod2;
    arr2[2] = temp_mod2;
    arr2[3] = sys_mod2;
    arr2[4] = dia_mod2;
    arr2[5] = med_mod2;
    return arr2;
}

QString ajustes::detection_status(){
   QSqlQuery crear;
   QString get_settings_mode, result;
   get_settings_mode.append("SELECT * FROM ajustes WHERE 1");
   crear.prepare(get_settings_mode);
   crear.exec();
   crear.next();
   result = crear.value(2).toString();
   get_settings_mode.clear();
   return result;
}

void ajustes::detection_mode(bool state_mode){
   detection_mode_change = true;
   QSqlQuery crear;
   QString save_settings_mode;

   if(state_mode){
        save_settings_mode.append("UPDATE ajustes SET detection_mode = 'true' WHERE 1");
        detection = true;
        banderapuntos=true;
   }

   else{
       save_settings_mode.append("UPDATE ajustes SET detection_mode = 'false' WHERE 1");
       detection = false;
       banderapuntos=false;
   }
   crear.prepare(save_settings_mode);
   crear.exec();
}

void Paciente::paciente_activo_change(QString name_active_pacient){
   paciente_activo = name_active_pacient;
}

bool MOD2::sonido_get_status(){
   return silenciado;
}

bool MOD2::get_pani_status(){
   return bandera_pani;
}

bool* MOD2::alarm_status()
{
   bool *arr = new bool[3];
   arr[0] = activated;
   arr[1] = activated2;
   arr[2] = activated3;
   return arr;
}

//ask for values of usb status
bool* PantallaCarga::usb()
{
   bool* arr = new bool[4];
   arr[0] = true; //spo2;
   arr[1] = true;//ecg;
   arr[2] = true;//ecg_datos;
   arr[3] = true; //database_exist;

   return arr;
}


#endif // FUNCIONES_H
