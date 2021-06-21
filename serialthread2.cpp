#include "serialthread2.h"
#include <QDebug>
QString cadena2_2 = "";

double datos_en_pantalla_ECG_22 = 0, datos_grafica_max_ECG_22 = 600, upset_ECG_22= 0, rango_min_ECG_22, rescale_value_ECG_22=2500, data_save_ECG_22 = 0;
int  reescale_config_ecg_22 = 0 , cuadronegro_ecg_22 = 0, countingdata_ecg_22 = 0;

double datos_en_pantalla_ECG_23 = 0, datos_grafica_max_ECG_23 = 600, upset_ECG_23 = 0, rango_min_ECG_23, rescale_value_ECG_23=2500, data_save_ECG_23 = 0;
int  reescale_config_ecg_23 = 0 , cuadronegro_ecg_23 = 0, countingdata_ecg_23 = 0;

SerialThread2::SerialThread2(QObject *parent) : QObject(parent)
{
    my_thread = new QThread();
    ecg_port = new QSerialPort();
    init_port(); //name
    this->moveToThread(my_thread);
    ecg_port->moveToThread(my_thread);
    my_thread->start(); //start thread
    bufer = QByteArray();
    qRegisterMetaType<QVector<double>>();
}

SerialThread2::~SerialThread2()
{
    ecg_port->close();
    ecg_port->deleteLater();
    my_thread->quit();
    my_thread->wait();
    my_thread->deleteLater();
}

void SerialThread2::init_port()
{
    ecg_port = new QSerialPort();
    ecg_port ->setPortName("DATOSECG"); //"ECG"
    ecg_port ->setBaudRate(QSerialPort::Baud115200);
    ecg_port ->setReadBufferSize(1);
    ecg_port ->setParity(QSerialPort::NoParity);
    ecg_port ->setDataBits(QSerialPort::Data8);
    ecg_port ->setFlowControl(QSerialPort::HardwareControl);
    ecg_port ->setStopBits(QSerialPort::OneStop);
    ecg_port -> open(QIODevice::ReadOnly);
    connect(ecg_port, SIGNAL(readyRead()), this, SLOT(handle_data()), Qt::QueuedConnection); //Qt::DirectConnection
}

void SerialThread2::handle_data()
{
    QByteArray arreglo; //variable donde recibirimos el dato serial
    int aux = 0; //Como limpiaremos el buffer es necesesario comprobar que nuestro dato continuo venga completo, esta variable ayudará a ese proposito
    arreglo.append(ecg_port->readLine());
    //port->clear();
    //Jeru
    cadena2_2.append(arreglo);
    int got = cadena2_2.indexOf('\n');
        if(got >= 0){
            qDebug() <<"serialThread2: " << cadena2_2;
            double grafica = cadena2_2.toDouble();
            aux = cadena2_2.length();
               if(aux>8){ // Para el ECG esperamos un dato similar a -xxx.x- de un total de 7 espacios, por lo que con 6, es considerado dato completo
                   if(true){
                       //qDebug()<< "grafica";
                       datos_en_pantalla_ECG_22 = datos_en_pantalla_ECG_22 + 1; //Incrementamos en 1 el eje inferior (x) de nuestra grafica
                       addPoint_ECG(datos_en_pantalla_ECG_22,  grafica); //Se prepara el punto convirtiendo la variable data (string) a double ( numero)
                       ///datos_en_pantalla_ECG_2 = datos_en_pantalla_ECG_2 + 1; //Incrementamos en 1 el eje inferior (x) de nuestra grafica
                       ///addPoint_ECG_2(datos_en_pantalla_ECG_2,  grafica_2); //Se prepara el punto convirtiendo la variable data (string) a double ( numero)

                       cadena2_2.clear();
                       arreglo.clear();
                      // ecg_port->clear();
                    }
           }
               cadena2_2.clear();
               arreglo.clear();
          //          }
        }
}

void SerialThread2::addPoint_ECG(double x, double y){ //funcion que agrega un nuevo punto a nuestro array de puntos a graficar

    //qDebug()<< qv_x_spo2;
   if(qv_x_ECG.length() == datos_grafica_max_ECG_22){ // create a 300 data vector
           qv_x_ECG[countingdata_ecg_22] = countingdata_ecg_22 + 1; // re-write the x axis
           qv_y_ECG[countingdata_ecg_22] = y;  // re-wrtie the y axis
           countingdata_ecg_22 = countingdata_ecg_22 + 1; // create the new index for re-write
           cuadronegro_ecg_22 = countingdata_ecg_22/1.216; // the black rectangle needs to be forward of the graph
           if(countingdata_ecg_22 == datos_grafica_max_ECG_22){countingdata_ecg_22 = 0;} // if data get to the end of the vector, it needs to be update to 0 again
   }else{
       qv_x_ECG.append(x);
       qv_y_ECG.append(y);

   }
   if(qv_y_ecg_reescale.length()>300){
       qv_y_ecg_reescale[reescale_config_ecg_22] = y;
       reescale_config_ecg_22 = reescale_config_ecg_23 + 1;
       if(reescale_config_ecg_22>300){reescale_config_ecg_22=0;}
   }
   else{
       qv_y_ecg_reescale.append(y);
   }

   double minrangeLine = *std::min_element( qv_y_ecg_reescale.begin(),qv_y_ecg_reescale.end());
   double maxrangeLine = *std::max_element( qv_y_ecg_reescale.begin(),qv_y_ecg_reescale.end());
   //qDebug() << qv_y_ECG;

   emit receive_data(qv_x_ECG, qv_y_ECG, cuadronegro_ecg_22, datos_grafica_max_ECG_22, minrangeLine, maxrangeLine);
}

void SerialThread2::addPoint_ECG_2(double x, double y){ //funcion que agrega un nuevo punto a nuestro array de puntos a graficar

    //qDebug()<< qv_x_spo2;
   if(qv_x_ECG_2.length() == datos_grafica_max_ECG_23){ // create a 300 data vector
           qv_x_ECG_2[countingdata_ecg_23] = countingdata_ecg_23 + 1; // re-write the x axis
           qv_y_ECG_2[countingdata_ecg_23] = y;  // re-wrtie the y axis
           countingdata_ecg_23 = countingdata_ecg_23 + 1; // create the new index for re-write
           cuadronegro_ecg_23 = countingdata_ecg_23/1.216; // the black rectangle needs to be forward of the graph
           if(countingdata_ecg_23 == datos_grafica_max_ECG_23){countingdata_ecg_23 = 0;} // if data get to the end of the vector, it needs to be update to 0 again
   }else{
       qv_x_ECG_2.append(x);
       qv_y_ECG_2.append(y);

   }
   if(qv_y_ecg_reescale_2.length()>300){
       qv_y_ecg_reescale_2[reescale_config_ecg_23] = y;
       reescale_config_ecg_23 = reescale_config_ecg_23 + 1;
       if(reescale_config_ecg_23>300){reescale_config_ecg_23=0;}
   }
   else{
       qv_y_ecg_reescale_2.append(y);
   }

   double minrangeLine = *std::min_element( qv_y_ecg_reescale_2.begin(),qv_y_ecg_reescale_2.end());
   double maxrangeLine = *std::max_element( qv_y_ecg_reescale_2.begin(),qv_y_ecg_reescale_2.end());
   //qDebug() << "receive_data_2";
   emit receive_data_2(qv_x_ECG_2, qv_y_ECG_2, cuadronegro_ecg_23, datos_grafica_max_ECG_23, minrangeLine, maxrangeLine);
}

