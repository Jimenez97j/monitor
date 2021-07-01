#include "serialspo2.h"
#include <QtMath>
#include <QDebug>
QString cadena = "", savespo2_thread = "00";
int length = 0, promedio = 0, bpm_counting_pulse = 0, bpm_pulse = 0;
double saving_temperature_spo2  = 0;
bool save_bpm_once = true, bpm_send_data = false, search_down = true, search_confirm = false, pani_activated = false;
QByteArray  confirm_command = "";

QString spo2_string ="";
int times_max_n = 22, times_prom_output = 10;
int contador_max_min = 0, contador_output_spo2 = 0;
float max_spo2_red = 0, out_spo2 = 0;
float min_spo2_red = 0;
float x_compen = 0, y_compen = 0;
bool first_save_red = true, finger_out = true;
float max_spo2_ir = 0;
float min_spo2_ir = 0, bpm_data_compare = 0;
bool first_save_ir = false, values_ready = false;
float partial_result_ir = 0, partial_result_red = 0;
float R_ir = 0, spo2_new_value = 0, R_red = 0 , save_spo2_for_output = 0;

//variables para el cruce por cero de la señal roja
bool search_down_red = true, save_bpm_once_red = true;
float bpm_data_compare_red = 0;
int bpm_counting_pulse_red = 0;
bool save_posible = false;
//variables for reescale and erease the graph
int reescale_config = 0, countingdata = 0, cuadronegro_value = 0;

//variables for pestimographic graph
double datos_en_pantalla = 0, datos_grafica_max = 120, upset= 0, rango_max, rango_min, rescale_value=200, data_save = 0;

SerialSpo2::SerialSpo2(QObject *parent, QString port) : QObject(parent)
{
    my_thread2 = new QThread();
    spo2_port = new QSerialPort();
    init_port(port);
    this->moveToThread(my_thread2);
    spo2_port->moveToThread(my_thread2);
    my_thread2->start(); //start thread
    bufer = QByteArray();
    qRegisterMetaType<QVector<double>>();
    connect(this,SIGNAL(escribe(QByteArray)),this,SLOT(procesaDato(QByteArray)));
}


SerialSpo2::~SerialSpo2()
{
    spo2_port->close();
    spo2_port->deleteLater();
    my_thread2->quit();
    my_thread2->wait();
    my_thread2->deleteLater();
}

void SerialSpo2::init_port(QString port)

{
    //++++++++++++++++++++++++++++++ SERIAL PORT SPO2/TEMPERATURE/WARNINGS +++++++++++++++++++++++++++
    spo2_port= new QSerialPort();
    spo2_port->setPortName(port); //ttyUSB1
    spo2_port->setBaudRate(QSerialPort::Baud115200);
    spo2_port->setReadBufferSize(10);
    spo2_port->setParity(QSerialPort::NoParity);
    spo2_port->setDataBits(QSerialPort::Data8);
    spo2_port->setFlowControl(QSerialPort::NoFlowControl);
    spo2_port->setStopBits(QSerialPort::OneStop);
    spo2_port->open(QIODevice::ReadWrite);
    connect(spo2_port, SIGNAL(readyRead()), this, SLOT(handle_data()), Qt::QueuedConnection); //Qt::DirectConnection
    if(spo2_port->isOpen()){
        //qDebug()<< "abieerto";
    }else{
        //qDebug() << "no jala" + port;
    }
}


void SerialSpo2::handle_data()
{
    QString arreglo;
       arreglo = spo2_port->readLine();
       cadena.append(arreglo); //transform the array into a string for using string methods.
          length = cadena.length();
          int got = cadena.indexOf('\n');
          //qDebug()<<cadena;

        if(got >= 0){
            //
            if(cadena[0] == 'J'){
                //qDebug()<<"emitir";
                emit boton_ajustes("izquierda");
                cadena.clear();
            }

            if(cadena[0] == 'L'){
                qDebug()<<"emitir izquierda";
                emit boton_ajustes("derecha");
                cadena.clear();
            }

            if(cadena[0] == 'O'){
                //qDebug()<<"em";
                emit boton_ajustes("click");
                cadena.clear();
            }

            if(cadena[0] == 'P'){
                emit boton_ajustes("pani");
                cadena.clear();
            }
            if(cadena[0] == 'N'){
                emit boton_ajustes("mute");
                cadena.clear();
            }

            if(cadena[0] == 'D'){
                if(cadena.length()>4)
                {
                    QString data;
                    for (int i = 1; i < length;i++){
                        data.append(cadena[i]);
                    }
                    QStringList list3 = data.split(QLatin1Char(','));
                    if(list3.length()>1){
                        if (list3[0].toInt() ==  0){
                            estadoBateria(list3[1].toInt(),0);

                        }
                        else if (list3[0].toInt() ==  1){
                            estadoBateria(list3[1].toInt(), 1);
                        }
                    }
                }
            }
            //

            if(cadena[0] == 'A'){
               QString data;
                for (int i = 1; i<2;i++ ) {
                    data.append(cadena[i]);
                }
            if(search_confirm){
                if(data == confirm_command){
                    search_confirm = false;
                    pani_activated = false;

                   }
                   else{
                       procesaDato(confirm_command);
                       }
                   }
               }

               if(cadena[0] == 'R'){
                                  QString data;
                                  for (int i = 2; i<length;i++ ) {
                                      data.append(cadena[i]);
                                  }
                                  QStringList list2 = data.split(QLatin1Char(','));
                                  //calculamos el spo2 a partir del valor de los R e IR
                                  if(search_down_red){
                                      if(save_bpm_once_red){
                                          bpm_data_compare_red = list2[0].toFloat();
                                          save_bpm_once_red = false;
                                      }else{
                                          if( list2[0].toFloat()>bpm_data_compare_red){
                                              bpm_counting_pulse_red = 0;
                                              bpm_data_compare_red = list2[0].toFloat();
                                              if(save_posible){
                                                  search_down_red = false;
                                                  save_bpm_once_red = true;
                                                  save_posible = false;
                                                  qv_red.append(list2[0].toFloat());
                                                  qv_ir.append(list2[1].toFloat());
                                              }
                                          }else{
                                              if(save_posible){
                                                  qv_red.append(list2[0].toFloat());
                                                  qv_ir.append(list2[1].toFloat());
                                              }
                                              bpm_counting_pulse_red = bpm_counting_pulse_red + 1;
                                              bpm_data_compare_red =  list2[0].toFloat();
                                          }
                                          if(bpm_counting_pulse_red==2){
                                                  bpm_counting_pulse_red = 0;
                                                  save_posible = true;
                                          }
                                      }
                                  }else{
                                      if(save_bpm_once_red){
                                          bpm_data_compare_red = list2[0].toFloat();
                                          save_bpm_once_red = false;
                                      }else{
                                              if( list2[0].toFloat() < bpm_data_compare_red){
                                                  bpm_counting_pulse_red = 0;
                                                  bpm_data_compare_red =  list2[0].toFloat();
                                                  if(save_posible){
                                                      search_down_red = true;
                                                      save_bpm_once_red = true;
                                                      values_ready = true;
                                                      save_posible = false;
                                                      qv_red.append(list2[0].toFloat());
                                                      qv_ir.append(list2[1].toFloat());
                                                  }
                                              }else{
                                                  bpm_counting_pulse_red = bpm_counting_pulse_red + 1;
                                                  bpm_data_compare_red =  list2[0].toFloat();
                                                  if(save_posible){
                                                      qv_red.append(list2[0].toFloat());
                                                      qv_ir.append(list2[1].toFloat());
                                                  }
                                              }
                                              if(bpm_counting_pulse_red==2){
                                                      bpm_counting_pulse_red = 0;
                                                      save_posible = true;
                                              }
                                           }
                                      }

                                if(values_ready){
                                    min_spo2_red = *std::min_element(qv_red.begin(),qv_red.end());
                                    max_spo2_red = *std::max_element(qv_red.begin(),qv_red.end());
                                    min_spo2_ir  = *std::min_element(qv_ir.begin(),qv_ir.end());
                                    max_spo2_ir  = *std::max_element(qv_ir.begin(),qv_ir.end());
                                    qv_ir.clear();
                                    qv_red.clear();
                                    values_ready  = false;
                                    if(!(spo2_string == "nan")){
                                           R_red = qLn(min_spo2_red/max_spo2_red);
                                           R_ir = qLn(min_spo2_ir/max_spo2_ir);

                                           /* max_spo2_ir = 0;
                                            max_spo2_red = 0;
                                            min_spo2_ir = 0;
                                            min_spo2_red  = 0;*/
                                            //first_save_ir = true;
                                            //first_save_red = true;
                                          spo2_new_value = R_ir / R_red;
                                          //////qDebug()<< spo2_new_value;

                                          if(( min_spo2_red>13000) && spo2_new_value>0.60){
                                              finger_out = true;
                                          }
                                          if((spo2_new_value <0.45 )){
                                              finger_out = false;
                                              contador_output_spo2 = 0;
                                              qv_red.clear();
                                              qv_ir.clear();
                                          }


                                         // R_red = (R_red * spo2_new_value) + R_red * (1- spo2_new_value);
                                         // R_ir = (R_ir * spo2_new_value) + R_ir * (1- spo2_new_value);
                                         // partial_result_red = R_ir / R_red;
                                         // spo2_new_value = partial_result_red * 30 ;
                                           //  spo2_new_value = spo2_new_value + 47;
                                           // contador_max_min = 0;

                                            if(spo2_string == "nan"){
                                                first_save_ir = true;
                                                first_save_red = true;
                                                values_ready  = false;
                                                contador_max_min = 0;
                                                spo2_string = "--";
                                            }
                                            else{
                                                save_spo2_for_output = save_spo2_for_output + spo2_new_value;
                                                contador_output_spo2 += 1;
                                                 //contador_output_spo2 = 0;
                                                 if(contador_output_spo2>30){
                                                     partial_result_ir = save_spo2_for_output/contador_output_spo2;
                                                     if(partial_result_ir<0.73){
                                                         x_compen = 5.9263;
                                                         y_compen = 31.1111;
                                                     }else{
                                                         x_compen=0.2494;
                                                         y_compen = -3.1111;
                                                     }


                                                     spo2_new_value = 25*(partial_result_ir*y_compen);
                                                     spo2_new_value = (110*x_compen) - spo2_new_value;
                                                     //out_spo2 = save_spo2_for_output/contador_output_spo2;
                                                     //partial_result_red = partial_result_red + spo2_new_value;
                                                     out_spo2 = qRound(spo2_new_value);
                                                     if(out_spo2>99){
                                                         out_spo2 = 99;
                                                     }
                                                      QString output_spo2;
                                                      output_spo2 = QString::number(out_spo2, 'g', 3);
                                                      savespo2_thread=output_spo2;
                                                      if(finger_out){
                                                          emit porcentualspo2(output_spo2);
                                                      }
                                                     ////qDebug()<<partial_result_ir;
                                                     ////qDebug()<<"minR:"<<min_spo2_red<<"max:"<<max_spo2_red;
                                                     ////qDebug()<<"minIR:"<<min_spo2_ir<<"max:"<<max_spo2_ir;

                                                     partial_result_red = 0;
                                                     save_spo2_for_output= 0;
                                                     contador_output_spo2 = 0;
                                                     qv_red.clear();
                                                     qv_ir.clear();
                                                 }
                                            }
                                    }else{
                                        contador_max_min = 0;
                                        partial_result_red = 0;
                                        save_spo2_for_output = 0;
                                        contador_output_spo2 = 0;
                                        first_save_ir = true;
                                        first_save_red = true;
                                        values_ready  = false;
                                        spo2_string = "--";

                                    }
                                }

                                  data.clear();
               }



    //++++++++++++++++++++++++++++++++++ TEMPERATURE ++++++++++++++++++++++++++++++++++++++++

               if(cadena[0] == 'K'){
                   QString datat;

                  for (int i = 2; i<cadena.length()-1; i++ ) {
                          datat.append(cadena[i]);
                   }
                   if( datat.toDouble()<5){
                    promedio = promedio - 1 ;
                   }else{
                       saving_temperature_spo2 = saving_temperature_spo2 + datat.toDouble();
                      }
                      if(promedio>99){
                      saving_temperature_spo2 =  saving_temperature_spo2/100;
                      saving_temperature_spo2 = saving_temperature_spo2 + 1.71;
                      QString valueAsString = QString::number(saving_temperature_spo2, 'g', 3);
                      if(saving_temperature_spo2>50){
                          valueAsString = "ERR";
                      }
                      emit   updatetemperature(valueAsString, saving_temperature_spo2);
                      promedio = 0;
                      valueAsString.clear();
                      saving_temperature_spo2 = 0;
                  }
                      promedio = promedio + 1;
                      datat.clear();
               }
    //+++++++++++++++++++++++++++++++++++++ PLETH +++++++++++++++++++++++++++++++++++++++++

                   if(cadena[0] == 'B'){ //Search for the specific data simbol
                   QString data;   // variable donde guardaremos el valor numerico sin la letra B
                   for (int i = 2; i<length ;i++ ) { //recorremos la cadena bida por serial desde una posición después de la letra B hasta el final de la misma
                       data.append(cadena[i]);
                   }
                      // ////qDebug()<<data;

                   if(finger_out){

                    datos_en_pantalla = datos_en_pantalla + 1; //Incrementamos en 1 el eje inferior (x) de nuestra grafica
                    addPoint_spo2(datos_en_pantalla,  data.toDouble()); //Se prepara el punto convirtiendo la variable data (string) a double ( numero)

                    }
                    else {
                       qv_x_spo2.clear();
                       qv_y_spo2.clear();
                       qv_y_spo2_reescale.clear();
                       bpm_counting_pulse = 0;
                       bpm_pulse = 0;
                       countingdata = 0;
                       reescale_config = 0;
                       datos_en_pantalla = 0;
                       emit not_data();
                    }
                   data.clear();
               }

   //*****************************FOR PANI *****************************************
   //*************************** HERE WE NEED TO CAST FOR EVERY VALUE ***********************************
                   if(cadena[0] == 'S'){
                       ////qDebug()<<cadena;

                       QString data_s;   // variable donde guardaremos el valor numerico sin la letra B
                       for (int i = 1; i<12;i++ ) { //recorremos la cadena bida por serial desde una posición después de la letra B hasta el final de la misma
                           data_s.append(cadena[i]);
                       }
                         QStringList list2 = data_s.split(QLatin1Char(','));
                         if(list2.length()>2){
                          emit panivalues(list2[0], list2[1], list2[2]);
                         }
                   }

    //++++++++++++++++++++++++++++++++ PANI ERROR ++++++++++++++++++++++++++++++++++++++++

                   if(cadena[0] == 'E'){
                       emit errorpani();
                   }
           //when all finish arrys need to be cleaned
               cadena.clear();
           }
}

void SerialSpo2::estadoBateria(int x, int p){
    if (p == 1)
    {
    if(x >= 0 && x<=25){
        emit boton_bateria("B1,rojo");
    }
    else if(x >= 26 && x<=50){
        emit boton_bateria("B1,naranja");
    }
    else if(x>= 51 && x<=75){
        emit boton_bateria("B1,amarillo");
    }
    else if(x >= 76 && x<=99){
        emit boton_bateria("B1,verde");
    }
    }
    else if (p == 0)
    {
    if(x >= 0 && x<=25){
        emit boton_bateria("B0,rojo");
    }
    else if(x >= 26 && x<=50){
        emit boton_bateria("B0,naranja");
    }
    else if(x>= 51 && x<=75){
        emit boton_bateria("B0,amarillo");
    }
    else if(x >= 76 && x<=99){
        emit boton_bateria("B0,verde");
    }
    }
}

void SerialSpo2::IsActive(){
    if(!(spo2_port->isReadable())){
        spo2_port->close();
        spo2_port->setPortName("SPO2"); //ttyUSB1
        spo2_port->setBaudRate(QSerialPort::Baud115200);
        spo2_port->setReadBufferSize(10);
        spo2_port->setParity(QSerialPort::NoParity);
        spo2_port->setDataBits(QSerialPort::Data8);
        spo2_port->setFlowControl(QSerialPort::NoFlowControl);
        spo2_port->setStopBits(QSerialPort::OneStop);
        spo2_port->open(QIODevice::ReadWrite);
        connect(spo2_port, SIGNAL(readyRead()), this, SLOT(handle_data()), Qt::QueuedConnection); //Qt::DirectConnection
    }
}


void SerialSpo2::addPoint_spo2(double x, double y){ //fuction to add a new point to the array for graph
   if(y < 100){

   }else{
        emit spo2_plot_mqtt(y);
   if(qv_x_spo2.length() == datos_grafica_max){ // create a 300 data vector

       qv_x_spo2[countingdata] = countingdata + 1; // re-write the x axis
       qv_y_spo2[countingdata] = y;  // re-wrtie the y axis
       countingdata = countingdata + 1; // create the new index for re-write
       cuadronegro_value = countingdata *5 ; // the black rectangle needs to be forward of the graph
       if(countingdata == datos_grafica_max){
           countingdata = 0;
           spo2_port->write("Z");
       } // if data get to the end of the vector, it needs to be update to 0 again

       if(cuadronegro_value  > 500){
           cuadronegro_value = cuadronegro_value + 25;
           emit cuadronegro(cuadronegro_value);
       }else{
           cuadronegro_value = cuadronegro_value + 28;
           emit cuadronegro(cuadronegro_value);
       }

   }else{
       qv_x_spo2.append(x);
       qv_y_spo2.append(y);
       //////qDebug()<< qv_x_spo2;
   }

   if(qv_y_spo2_reescale.length()>75){
       qv_y_spo2_reescale[reescale_config] = y;
       reescale_config = reescale_config + 1;
       if(reescale_config>75){reescale_config=0;}
   }
   else{
       qv_y_spo2_reescale.append(y);
   }
   if(search_down){
        if(save_bpm_once){
            bpm_data_compare = y;
            save_bpm_once = false;
        }else{
            if(y>bpm_data_compare){
                bpm_counting_pulse = 0;
                bpm_data_compare = y;
            }else{
                bpm_counting_pulse = bpm_counting_pulse + 1;
                bpm_data_compare = y;
            }
            if(bpm_counting_pulse==3){
                    bpm_pulse = bpm_pulse + 1;
                    bpm_counting_pulse = 0;
                    search_down = false;
                    save_bpm_once = true;
            }
        }
    }else{
        if(save_bpm_once){
            bpm_data_compare = y;
            save_bpm_once = false;
        }else{
                if(y<bpm_data_compare){
                    bpm_counting_pulse = 0;
                    bpm_data_compare = y;
                }else{
                    bpm_counting_pulse = bpm_counting_pulse + 1;
                    bpm_data_compare = y;
                }
                if(bpm_counting_pulse==3){
                       // bpm_pulse = bpm_pulse + 1;
                        bpm_counting_pulse = 0;
                        search_down = true;
                        save_bpm_once = true;

                }
             }
        }
    //qDebug()<<bpm_pulse;
       if(bpm_send_data){
           bpm_send_data = false;;
           bpm_pulse = bpm_pulse * 4;
           QString s = QString::number(bpm_pulse);
           //qDebug()<< bpm_pulse;

           emit bpm_count(s);

           bpm_pulse = 0;
           bpm_counting_pulse = 0;
         }
    double minrangeLine = *std::min_element(qv_y_spo2_reescale.begin(),qv_y_spo2_reescale.end());
    double maxrangeLine = *std::max_element(qv_y_spo2_reescale.begin(),qv_y_spo2_reescale.end());
    emit pleth(qv_x_spo2, qv_y_spo2, upset, minrangeLine, maxrangeLine, datos_grafica_max);
   }
}


//method for writting a caracter into the serial port
void SerialSpo2::procesaDato(QByteArray value_write)
{
    if(value_write == "Q"){
        qDebug() << "[PANI] fuera cierra valvula";
        spo2_port->write(value_write);
    }
    if(value_write == "BOK\n"){
        qDebug() << "ESTADO_BATERIA";
        spo2_port->write(value_write);
    }
    //qDebug()<<value_write;
    if(value_write == "B"){
        spo2_port->write("B");
        pani_activated = true;
        confirm_command = "B";
    }
    if(value_write == "P"){
      spo2_port->write(value_write);
      pani_activated = false;
      confirm_command = "P";
    }
    if(pani_activated){
       search_confirm = true;
    }
    else{
       spo2_port->write(value_write);
       confirm_command = value_write;
       search_confirm = true;
       //qDebug() << "[PANI] cierra valvula";
       /*if(value_write == "Q"){
           qDebug() << "[PANI] cierra valvula";
       }*/
    }
}

void SerialSpo2::close_port(){
    spo2_port->close();
}

void SerialSpo2::bpm_flag_update(){
    bpm_send_data = true;
}

bool SerialSpo2::check_allowed_values(){
    float value_one= 1;
    float value_two =1;
    if(value_one<0){
        return false;
    }
    else{
        if(value_two<0){
            return false;
        }
        else{
            return true;
        }
    }
}
