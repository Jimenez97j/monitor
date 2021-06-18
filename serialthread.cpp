#include "serialthread.h"
#include <QDebug>
QString cadena2 = "";

double datos_en_pantalla_ECG = 0, datos_grafica_max_ECG = 600, upset_ECG= 0, rango_min_ECG, rescale_value_ECG=2500, data_save_ECG = 0;
int  reescale_config_ecg = 0 , cuadronegro_ecg = 0, countingdata_ecg = 0;

double datos_en_pantalla_ECG_2 = 0, datos_grafica_max_ECG_2 = 600, upset_ECG_2 = 0, rango_min_ECG_2, rescale_value_ECG_2=2500, data_save_ECG_2 = 0;
int  reescale_config_ecg_2 = 0 , cuadronegro_ecg_2 = 0, countingdata_ecg_2 = 0;

SerialThread::SerialThread(QObject *parent) : QObject(parent)
{
    my_thread = new QThread();
    ecg_port = new QSerialPort();
    init_port();
    this->moveToThread(my_thread);
    ecg_port->moveToThread(my_thread);
    my_thread->start(); //start thread
    bufer = QByteArray();
    qRegisterMetaType<QVector<double>>();
}


SerialThread::~SerialThread()
{
    ecg_port->close();
    ecg_port->deleteLater();
    my_thread->quit();
    my_thread->wait();
    my_thread->deleteLater();
}

void SerialThread::init_port()
{
    ecg_port = new QSerialPort();
    ecg_port ->setPortName("ECG");
    ecg_port ->setBaudRate(QSerialPort::Baud115200);
    ecg_port ->setReadBufferSize(1);
    ecg_port ->setParity(QSerialPort::NoParity);
    ecg_port ->setDataBits(QSerialPort::Data8);
    ecg_port ->setFlowControl(QSerialPort::HardwareControl);
    ecg_port ->setStopBits(QSerialPort::OneStop);
    ecg_port -> open(QIODevice::ReadOnly);
    connect(ecg_port, SIGNAL(readyRead()), this, SLOT(handle_data()), Qt::QueuedConnection); //Qt::DirectConnection
}

void SerialThread::handle_data()
{
    QByteArray arreglo; //variable donde recibirimos el dato serial
    int aux = 0; //Como limpiaremos el buffer es necesesario comprobar que nuestro dato continuo venga completo, esta variable ayudará a ese proposito
    arreglo.append(ecg_port->readLine());
    //port->clear();
    //Jeru
    cadena2.append(arreglo);
    int got = cadena2.indexOf('\n');
        if(got >= 0){
          //  QStringList list2 = cadena2.split(QLatin1Char('\n'));
            //foreach(QString resultado, list2){
            //dato,dato
            QStringList temp = cadena2.split(",");
            //qDebug() << "SERIAL " << temp;
            double grafica;
            double grafica_2;
            if(temp.size() == 2){
                //qDebug() << "ENTRA SERIAL";
                grafica = temp.at(0).toDouble();
                grafica_2 = temp.at(1).toDouble();
                //qDebug() << grafica;
                //qDebug() << grafica_2;

            }
            aux = cadena2.length();
               if(aux>8){ // Para el ECG esperamos un dato similar a -xxx.x- de un total de 7 espacios, por lo que con 6, es considerado dato completo
                   if(true){
                       //qDebug()<< "grafica";
                       datos_en_pantalla_ECG = datos_en_pantalla_ECG + 1; //Incrementamos en 1 el eje inferior (x) de nuestra grafica
                       addPoint_ECG(datos_en_pantalla_ECG,  grafica); //Se prepara el punto convirtiendo la variable data (string) a double ( numero)
                       ///datos_en_pantalla_ECG_2 = datos_en_pantalla_ECG_2 + 1; //Incrementamos en 1 el eje inferior (x) de nuestra grafica
                       ///addPoint_ECG_2(datos_en_pantalla_ECG_2,  grafica_2); //Se prepara el punto convirtiendo la variable data (string) a double ( numero)

                       cadena2.clear();
                       arreglo.clear();
                      // ecg_port->clear();
                    }
           }
               cadena2.clear();
               arreglo.clear();
          //          }
        }
}

void SerialThread::addPoint_ECG(double x, double y){ //funcion que agrega un nuevo punto a nuestro array de puntos a graficar

    //qDebug()<< qv_x_spo2;
   if(qv_x_ECG.length() == datos_grafica_max_ECG){ // create a 300 data vector
           qv_x_ECG[countingdata_ecg] = countingdata_ecg + 1; // re-write the x axis
           qv_y_ECG[countingdata_ecg] = y;  // re-wrtie the y axis
           countingdata_ecg = countingdata_ecg + 1; // create the new index for re-write
           cuadronegro_ecg = countingdata_ecg/1.216; // the black rectangle needs to be forward of the graph
           if(countingdata_ecg == datos_grafica_max_ECG){countingdata_ecg = 0;} // if data get to the end of the vector, it needs to be update to 0 again
   }else{
       qv_x_ECG.append(x);
       qv_y_ECG.append(y);

   }
   if(qv_y_ecg_reescale.length()>300){
       qv_y_ecg_reescale[reescale_config_ecg] = y;
       reescale_config_ecg = reescale_config_ecg + 1;
       if(reescale_config_ecg>300){reescale_config_ecg=0;}
   }
   else{
       qv_y_ecg_reescale.append(y);
   }

   double minrangeLine = *std::min_element( qv_y_ecg_reescale.begin(),qv_y_ecg_reescale.end());
   double maxrangeLine = *std::max_element( qv_y_ecg_reescale.begin(),qv_y_ecg_reescale.end());
   //qDebug() << qv_y_ECG;

   emit receive_data(qv_x_ECG, qv_y_ECG, cuadronegro_ecg, datos_grafica_max_ECG, minrangeLine, maxrangeLine);
}

void SerialThread::addPoint_ECG_2(double x, double y){ //funcion que agrega un nuevo punto a nuestro array de puntos a graficar

    //qDebug()<< qv_x_spo2;
   if(qv_x_ECG_2.length() == datos_grafica_max_ECG_2){ // create a 300 data vector
           qv_x_ECG_2[countingdata_ecg_2] = countingdata_ecg_2 + 1; // re-write the x axis
           qv_y_ECG_2[countingdata_ecg_2] = y;  // re-wrtie the y axis
           countingdata_ecg_2 = countingdata_ecg_2 + 1; // create the new index for re-write
           cuadronegro_ecg_2 = countingdata_ecg_2/1.216; // the black rectangle needs to be forward of the graph
           if(countingdata_ecg_2 == datos_grafica_max_ECG_2){countingdata_ecg_2 = 0;} // if data get to the end of the vector, it needs to be update to 0 again
   }else{
       qv_x_ECG_2.append(x);
       qv_y_ECG_2.append(y);

   }
   if(qv_y_ecg_reescale_2.length()>300){
       qv_y_ecg_reescale_2[reescale_config_ecg_2] = y;
       reescale_config_ecg_2 = reescale_config_ecg_2 + 1;
       if(reescale_config_ecg_2>300){reescale_config_ecg_2=0;}
   }
   else{
       qv_y_ecg_reescale_2.append(y);
   }

   double minrangeLine = *std::min_element( qv_y_ecg_reescale_2.begin(),qv_y_ecg_reescale_2.end());
   double maxrangeLine = *std::max_element( qv_y_ecg_reescale_2.begin(),qv_y_ecg_reescale_2.end());
   //qDebug() << "receive_data_2";
   emit receive_data_2(qv_x_ECG_2, qv_y_ECG_2, cuadronegro_ecg_2, datos_grafica_max_ECG_2, minrangeLine, maxrangeLine);
}
