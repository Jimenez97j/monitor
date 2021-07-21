#include "funciones.h"
#include <QFileDialog>
#include <QProcess>
#include <ecghandle.h>
#include <QJsonDocument>
#include <QVariantMap>
#include <QMessageBox>
#include <QDebug>

//QString bocinaONN = ":/imagenes/btn_Bocina.png";
//QString bocinaOFF = ":/imagenes/btn_Bocina.png";

//Different flags for functions activations
QString aux, uid_value, uid_doctor;
int bandera=0, check_bpm_value_time = 0;
int indicadoranalisis = 0;
int continicio = 0;
int hora_captura=0, puntos=0 , numeros_ecg=0, numeros_spo2 = 0, numeros_temp = 0, ActivarAlarmas =0, AlarmaApagada = 0, TimerBateria = 0;//Resetea timers para Captura de Pantalla, "Realizando analisis" y cambio de color en números
int reg_save_data = 0; //flag for confirmation label of ss and flag for save data into a data base
bool reg_save_data_activated = true,  cambio_numeros=false,cambio_numeros2=false,cambio_numeros3=false;//flag to start getting data into a data base
QTimer *cronometro = new QTimer();
bool jsonrecibido = false;
QTimer *spo2_refresh_chart = new QTimer();
int registro_firebase = 0;
QString *arrdata_to_send;
int contpos = 0;
int conTouch = 0;
bool bandera_2= true, bandera_barra_2= true, bandera_click = true, banderaActAlarma = false;
bool deshabilitarTouch = true;
bool soundWait = false, activeTimer = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // MQTT
    mqtt_fc = 0;
    mqtt_porce_spo2 = 0;
    mqtt_bpm = 0;
    mqtt_sys = 0;
    mqtt_dia = 0;
    mqtt_resp = 12;
    mqtt_connected = false;
    mqttTimer = new QTimer;
    connect(mqttTimer, SIGNAL(timeout()),this, SLOT(envia_signos_mqtt()));
    mqttTimer->setInterval(10000);
    mqttTimer->start();
    mqtt_cont_ecg = 0;
    mqtt_list_ecg = new QStringList;

    //MQTT termo
    mqtt_connected_termo = false;
    msgBoxTemp = nullptr;
    color_msgBoxTemp = "black";

    //reconexion mqtt
    reconexionMqtt = new QTimer;
    connect(reconexionMqtt, SIGNAL(timeout()),this, SLOT(rec_mqtt()));
    reconexionMqtt->setSingleShot(true);

    //reconexion mqtt local
    reconexionMqttTermo = new QTimer;
    connect(reconexionMqttTermo, SIGNAL(timeout()),this, SLOT(rec_mqtt_termo()));
    reconexionMqttTermo->setSingleShot(true);

    //timer cierrar box temp
    timerCloseBoxTemp = new QTimer;
    connect(timerCloseBoxTemp, SIGNAL(timeout()),this, SLOT(cerrar_box_temp()));
    timerCloseBoxTemp->setSingleShot(true);



    //alarma reproducicnedo con qprocess
    alarma_reproduciendo = false;
    timerAlarmaR  = new QTimer;
    timerAlarmaR->setSingleShot(true);
    connect(timerAlarmaR, SIGNAL(timeout()), this, SLOT(terminaTimerAlarmaR()));

    processAlarmaR = new QProcess;
    connect(processAlarmaR, SIGNAL(finished(int)), this, SLOT(processFinishedAlarmaR(int)));
    //connect(processAlarmaR, &QProcess::finished, this, &MainWindow::processFinishedAlarmaR);

    audioAlarmaReproduciendoR = "";


    //valvula
    timerValvula = new QTimer;
    timerValvula->setSingleShot(true);
    connect(timerValvula, SIGNAL(timeout()), this, SLOT(cerrar_valvula()));

    //activado de sonido alarmas
    timerAlarmasSonido = new QTimer;
    timerAlarmasSonido->setSingleShot(true);
    connect(timerAlarmasSonido, SIGNAL(timeout()), this, SLOT(detenerSonido()));

    //
    ui->setupUi(this);
    opciones();
    //cambios serial

    //pequeña modificacion
    ui->ecg->iniciar_serial();


    //ecg-mqtt-publish
    connect(ui->ecg->local_serial, SIGNAL(envia_a_mqtt_publish(QString)), this, SLOT(publish_ecg_mqtt(QString)));

    //ui->ecg_2->set_serial_name("DATOSECG"); //ECG2
    ui->ecg_2->iniciar_serial();

    QProcess::execute(QString("sudo /bin/chmod 777 /etc/wpa_supplicant/wpa_supplicant.conf"));
    //connect(ui->ecg,SLOT(compartir_dato(QVector<double>,QVector<double>,int, double, double, double)),ui->ecg_2,SIGNAL(plot_ECG(QVector<double>,QVector<double>,int,double,double,double)));
    //connect(ui->ecg,SLOT(compartir_dato(QVector<double>,QVector<double>,int, double, double, double)),ui->ecg_2,SIGNAL(plot_ECG(QVector<double>,QVector<double>,int,double,double,double)));
    //
    m_networkManager = new QNetworkAccessManager(this);
    m_networkReply = m_networkManager->get(QNetworkRequest(QUrl("https://qtmonitor-b39a1-default-rtdb.firebaseio.com/listausuarios/2471085539xcqz.json")));
    //connect(m_networkReply, &QNetworkReply::readyRead, this, &MainWindow::networkReadyRead);
    // wifi
    /*QNetworkConfigurationManager ncm;
    netcfgList = ncm.allConfigurations(QNetworkConfiguration::PublicPurpose);
   // netcfgList = ncm.allConfigurations();
        WiFisList.clear();
        for (auto &x : netcfgList)
        {
                if(x.name() =!";
    mqtt_bpm =75;= "")
                    WiFisList << "Unknown(Other Network)";
                else
                    WiFisList << x.name();
                ui->comboBox->addItem(x.name());
                qDebug() << x.type();
        }*/
    //name of the data base for this proyect
    QString nombre;
    nombre.append("/opt/monitor_selespo/bin/prueba.sqlite");
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(nombre);
    if(db.open()){
        QSqlQuery crear;
        consulta.append("SELECT * FROM ajustes WHERE 1"); //get the color choosen
        crear.prepare(consulta);
        crear.exec();
        crear.next();
        maincolor = crear.value(1).toString();
        registro_firebase = crear.value(4).toInt();
        consulta.clear();
        ui->color->setStyleSheet("background-color:" + maincolor); //set color choosen
        //color_msgBoxTemp = maincolor;
        //check if detection is on or off
        if(crear.value(2).toString() == "true"){
            detection = true;
            banderapuntos = false;
        }
        else{
            detection = false;
            banderapuntos = false;
        }
        if(crear.value(3).toString() == "1"){
            data_time_rate = 57000;
        }
        if(crear.value(3).toString() == "2"){
            data_time_rate = 285000;
        }
        if(crear.value(3).toString() == "3"){
            data_time_rate = 855000;
        }
        if(crear.value(3).toString() == "4"){
            data_time_rate = 1710000;
        }
        if(crear.value(3).toString() == "5"){
            data_time_rate = 3420000;
        }

        //check name of the active pacient
        consulta.append("SELECT * FROM pacientes WHERE activo = '1'");
        crear.prepare(consulta);
        crear.exec();
        crear.next();
        paciente_activo = crear.value(1).toString();
        consulta.clear();
    }
    //++++++++++++++++++++++++++++++++++++ Values from alarms++++++++++++++++++++++++++++++++++++++++++
     get_alarms_value();

     //create new thread for ecg chart
     graficar = new ecghandle;

    qDebug()<<"btn_Bocina";
    //+++++++++++++++++++++++++++++++++++++++++++ SPO2 PLOT ++++++++++++++++++++++++++++++++++++++++++

    ui->plot->addGraph();  //add a graph to the wiget size in the screen interface
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssNone,0)); //without any extra dising
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsLine); // line type graph
    ui->plot->graph(0)->setPen(QPen(Qt::green, 1)); //color and width of the line
    ui->plot->axisRect()->setBackground(Qt::black); //background of the graph
    ui->plot->xAxis->grid()->setPen(QPen(Qt::black, Qt::SolidLine)); //x axis color
    ui->plot->yAxis->grid()->setPen(QPen(Qt::black, Qt::SolidLine)); //y axis color
    ui->plot->setBackground(Qt::black); //color del widget
    ui->plot->graph(0)->rescaleAxes(true);
    ui->plot->xAxis->setTicks(false);  //
    ui->plot->yAxis->setTicks(false);

    //++++++++++++++++++++++++++++++Re-write graph styles++++++++++++++++++++++++++++++++++++++++++++

    ui->color->setStyleSheet("background-color:" + maincolor);//background
    ui->borrargraph->setStyleSheet("background-color:" + maincolor);//background erase rectangle
    ui->ecg->change_square_ecg(maincolor);   //background erase rectangle
  //  ui->ecg_2->change_square_ecg(maincolor);

 if(maincolor == "#326d72"){
     //for the ples graph
     ui->plot->graph(0)->setPen(QPen(Qt::white, 1)); //color and width of the line
     ui->plot->axisRect()->setBackground(QColor(50, 109, 114)); //background of the graph
     ui->plot->xAxis->grid()->setPen(QPen(QColor(50, 109, 114), Qt::SolidLine)); //x axis color
     ui->plot->yAxis->grid()->setPen(QPen(QColor(50, 109, 114), Qt::SolidLine)); //y axis color
     ui->plot->xAxis->setBasePen(QPen(QColor(50, 109, 114)));
     ui->plot->yAxis->setBasePen(QPen(QColor(50, 109, 114)));
     ui->plot->setBackground(QColor(50, 109, 114));
     ui->plot->replot();

     //to change the sidebar
   // ui->TEMP->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
    // ui->OXBLOCK->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
    // ui->PANI->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
    // ui->ECGBLOCK->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
     //ui->DIAS->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
    // ui->SYS->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
    // ui->pres_sis->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white; border:none");
    // ui->pres_sis_label->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white; border:none");
     //ui->pres_sis_label_3->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white; border:none");

     //for the ecg graph
     ui->ecg->change_color_chart(1);
     ui->ecg_2->change_color_chart(1);
 }
 if(maincolor == "#20214f"){
     //for the ples graph
     ui->plot->graph(0)->setPen(QPen(Qt::white, 1)); //color and width of the line
     ui->plot->axisRect()->setBackground(QColor(32, 33, 79)); //background of the graph
     ui->plot->xAxis->grid()->setPen(QPen(QColor(32, 33, 79), Qt::SolidLine)); //x axis color
     ui->plot->yAxis->grid()->setPen(QPen(QColor(32, 33, 79), Qt::SolidLine)); //y axis color
     ui->plot->xAxis->setBasePen(QPen(QColor(32, 33, 79)));
     ui->plot->yAxis->setBasePen(QPen(QColor(32, 33, 79)));
     ui->plot->setBackground(QColor(32, 33, 79));
     ui->plot->replot();

     //to change the sidebar
     ui->TEMP->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
     ui->OXBLOCK->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
     ui->PANI->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
     ui->ECGBLOCK->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
     ui->DIAS->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
     ui->SYS->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
     ui->pres_sis->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white; border:none");
     ui->pres_sis_label->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white; border:none");
     ui->pres_sis_label_3->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white; border:none");

     //for the ecg graph
     ui->ecg->change_color_chart(2);
     ui->ecg_2->change_color_chart(2);
 }
 if(maincolor == "#ffffff"){
     //for the ples graph
     ui->plot->graph(0)->setPen(QPen(Qt::black, 1)); //color and width of the line
     ui->plot->axisRect()->setBackground(QColor(255, 255, 255)); //background of the graph
     ui->plot->xAxis->grid()->setPen(QPen(QColor(255, 255, 255), Qt::SolidLine)); //x axis color
     ui->plot->yAxis->grid()->setPen(QPen(QColor(255, 255, 255), Qt::SolidLine)); //y axis color
     ui->plot->xAxis->setBasePen(QPen(QColor(255, 255, 255)));
     ui->plot->yAxis->setBasePen(QPen(QColor(255, 255, 255)));
     ui->plot->setBackground(QColor(255, 255, 255));
     ui->plot->replot();

     //to change the sidebar
     //ui->TEMP->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: black;");
     //ui->OXBLOCK->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: black;");
     //ui->PANI->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: black;");
     //ui->ECGBLOCK->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: black;");
     //ui->DIAS->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: black;");
     //ui->SYS->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: black;");
     //ui->pres_sis->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:black; border:none");
     //ui->pres_sis_label->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:black; border:none");
     //
     ui->pres_sis_label_3->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:black; border:none");

     //for the ecg graph
     ui->ecg->change_color_chart(3);
     ui->ecg_2->change_color_chart(3);
 }
 if(maincolor == "#000000"){
     //for the ples graph
     ui->plot->graph(0)->setPen(QPen(Qt::green, 1)); //color and width of the line
     ui->plot->axisRect()->setBackground(QColor(0, 0, 0)); //background of the graph
     ui->plot->xAxis->grid()->setPen(QPen(QColor(0, 0, 0), Qt::SolidLine)); //x axis color
     ui->plot->yAxis->grid()->setPen(QPen(QColor(0, 0, 0), Qt::SolidLine)); //y axis color
     ui->plot->xAxis->setBasePen(QPen(QColor(0, 0, 0)));
     ui->plot->yAxis->setBasePen(QPen(QColor(0, 0, 0)));
     ui->plot->setBackground(QColor(0, 0, 0));
     ui->plot->replot();

     //to change the sidebar
     //ui->->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
     //ui->OXBLOCK->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
     //ui->PANI->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
     //ui->ECGBLOCK->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
     //ui->DIAS->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
     //ui->SYS->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
     //ui->pres_sis->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white; border:none");
     //ui->pres_sis_label->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white; border:none");
     //ui->pres_sis_label_3->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white; border:none");

     //for the ecg graph
     ui->ecg->change_color_chart(4);
     ui->ecg_2->change_color_chart(4);

 }
 if(maincolor == "#003e6c"){
     //for the ples graph
     ui->plot->graph(0)->setPen(QPen(Qt::green, 1)); //color and width of the line
     ui->plot->axisRect()->setBackground(QColor(0, 62, 108)); //background of the graph
     ui->plot->xAxis->grid()->setPen(QPen(QColor(0, 62, 108), Qt::SolidLine)); //x axis color
     ui->plot->yAxis->grid()->setPen(QPen(QColor(0, 62, 108), Qt::SolidLine)); //y axis color
     ui->plot->xAxis->setBasePen(QPen(QColor(0, 62, 108)));
     ui->plot->yAxis->setBasePen(QPen(QColor(0, 62, 108)));
     ui->plot->setBackground(QColor(0, 62, 108));
     ui->plot->replot();

     //to change the sidebar
     ui->TEMP->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
     ui->OXBLOCK->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
     ui->PANI->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
     ui->ECGBLOCK->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
     ui->DIAS->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
     ui->SYS->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
     ui->pres_sis->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white; border:none");
     ui->pres_sis_label->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white; border:none");
     ui->pres_sis_label_3->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white; border:none");

     ui->ecg->change_color_chart(5);
     ui->ecg_2->change_color_chart(5);
     //for the ecg graph
    //graficar->change_color_chart(5);
 }
 //this->show();

//+++++++++++++++++++++++++++++++++++++ SERIAL PORT SPO2 +++++++++++++++++++++++++++++++++++

    spo2serial = new SerialSpo2(nullptr, "SPO2");
    connect(spo2serial, SIGNAL(pleth(QVector<double>, QVector<double>, int, double, double, double)), this, SLOT(plot_spo2(QVector<double>, QVector<double>, int, double, double, double)), Qt::QueuedConnection);
    connect(spo2serial, SIGNAL(cuadronegro(int)), this, SLOT(cuadronegro_spo2(int)), Qt::QueuedConnection);
    connect(spo2serial, SIGNAL(bpm_count(QString)), this, SLOT(bpm_count_spo2(QString)), Qt::QueuedConnection);
    connect(spo2serial, SIGNAL(not_data()), this, SLOT(not_data()), Qt::QueuedConnection);
    //porcentual value of spo2
    connect(spo2serial, SIGNAL(porcentualspo2(QString)), this, SLOT(porcentualspo2(QString)), Qt::QueuedConnection);
    //Value for temperature
    connect(spo2serial, SIGNAL(updatetemperature(QString, double)), this, SLOT(updatetemperature(QString, double)), Qt::QueuedConnection);
    //Values for pani
    connect(spo2serial, SIGNAL(panivalues(QString, QString, QString)), this, SLOT(panivalues(QString, QString, QString)), Qt::QueuedConnection);
    //error for pani
    connect(spo2serial, SIGNAL(errorpani()), this, SLOT(errorpani()), Qt::QueuedConnection);

    teclado = new SerialSpo2(nullptr,"teclado");
    connect(teclado, SIGNAL(boton_ajustes(QString)), this, SLOT(boton_ajustes2(QString)), Qt::QueuedConnection);
    connect(teclado,SIGNAL(boton_bateria(QString)),this,SLOT(actualizaEdoBateria(QString)),Qt::QueuedConnection);
   //connect(spo2serial, SIGNAL(boton_ajustes(QString)), this, SLOT(boton_ajustes2(QString)), Qt::QueuedConnection);
   //mqtt jeru
   connect(spo2serial, SIGNAL(spo2_plot_mqtt(double)),this, SLOT(publish_spo2_mqtt(double)));

//+++++++++++++++++++++++++++++++++++++ SERIAL PORT ECG(DATOS) +++++++++++++++++++++++++++++++++++

    serial_ecg_data= new QSerialPort(); // Serial port for bpm, rpm
    serial_ecg_data->setPortName("DATOSECG"); //DATOSECG
    serial_ecg_data->setBaudRate(QSerialPort::Baud115200);
    serial_ecg_data->setReadBufferSize(5);
    serial_ecg_data->setParity(QSerialPort::NoParity);
    serial_ecg_data->setDataBits(QSerialPort::Data8);
    serial_ecg_data->setStopBits(QSerialPort::OneStop);
    serial_ecg_data->open(QIODevice::ReadWrite);

    //++++++++++++++++++++++++++++++++++++++++++++++ TIMER ++++++++++++++++++++++++++++++++++++++++++++

    aux= QDateTime::currentDateTime().toString("dd-MMM-yyyy hh:mm:ss");
    ui->fh->setText(aux);
    sonidoboton2("/home/pi/Music/sonidos/INICIO.mp3");

    //+++++++++++++++++++++++++++++++++++++++++ MQTT(ARRHYTHMIA) ++++++++++++++++++++++++++++++++++++++

    m_client = new QMqttClient(this);
    m_client->setHostname("192.168.1.248"); //192.168.1.248
    m_client->setPort(1883); //1883
    connect(m_client, &QMqttClient::stateChanged, this, &MainWindow::updateLogStateChange);
    connect(m_client, &QMqttClient::disconnected, this, &MainWindow::brokerDisconnected);
    connect(m_client, &QMqttClient::connected, this, &MainWindow::brokerConnected);
    connect(m_client, &QMqttClient::messageReceived, this, [this](const QByteArray &message, const QMqttTopicName &topic) {

    //this block works on,ly if detection is activated
       // qDebug()<<message;
        if(detection){
            if (message == "NORMAL")
            {

                ui->analisis->setText("<font color='#00ff00'>"+message+"</font>");
            }else
            {
                ui->analisis->setText("<font color='red'>Se ha detectado una "+message+"</font>");
            }
        }
    });

    m_client->connectToHost();
    reconexionMqtt->start(10000);

    //////////////////////////////////////// MQTT termometro

    m_client_termo = new QMqttClient(this);
    m_client_termo->setHostname("localhost"); //192.168.1.248
    m_client_termo->setPort(1883); //1883
    connect(m_client_termo, &QMqttClient::stateChanged, this, &MainWindow::updateLogStateChangeTermo);
    connect(m_client_termo, &QMqttClient::disconnected, this, &MainWindow::brokerDisconnectedTermo);
    connect(m_client_termo, &QMqttClient::connected, this, &MainWindow::brokerConnectedTermo);
    connect(m_client_termo, &QMqttClient::messageReceived, this, [this](const QByteArray &message, const QMqttTopicName &topic) {
        //mostrar el dialog con la temperatura
        qDebug() << "[MQTT TEMP] message: " << message;


        if(timerCloseBoxTemp->isActive()){
            qDebug() << "[MSG BOX] TERMINA TIMER";
            timerCloseBoxTemp->stop();
            //msgBoxTemp->done(0);
            widgetTemperatura->hide();
        }
        /*msgBoxTemp = new QMessageBox;
        msgBoxTemp->setWindowFlag(Qt::FramelessWindowHint);
        msgBoxTemp->setStandardButtons(0);
        msgBoxTemp->setStyleSheet("QMessageBox{background-color: " + color_msgBoxTemp + "; color: rgb(49, 150, 219); border-radius: 8px; border: 5px solid rgb(49, 150, 219);}"
                                  "QMessageBox QLabel{ color: rgb(49, 150, 219);}"); //rgb(49, 150, 219);
        msgBoxTemp->setGeometry(600, 400, 200, 50);
        QPalette pa;
        pa.setColor(QPalette::Text, QColor::fromRgb(49, 150, 219));
        msgBoxTemp->setPalette(pa);
        QFont *font = new QFont;
        font->setBold(true);
        font->setPixelSize(24);
        msgBoxTemp->setFont(*font);
        msgBoxTemp->setText("<p style='text-align: center;'>Termometro: " + message + " °C</p>");
        msgBoxTemp->setForegroundRole(QPalette::Mid);     // default is WindowText
        msgBoxTemp->setBackgroundRole(QPalette::Window);
        msgBoxTemp->show();
        //aqui va a ir el timer y con este puedo saber is hay un message abierto
        timerCloseBoxTemp->start(5000);*/
        widgetTemperatura->set_valor(message);
        widgetTemperatura->show();
        timerCloseBoxTemp->start(5000);
        qDebug() << "[MSG  BOX] Inicia timer";
    });

    m_client_termo->connectToHost();
    reconexionMqttTermo->start(10000);

    ///////////////////////////////////

    //connect(serial,SIGNAL(readyRead()),this , SLOT(RecibirArreglo()));
    connect(serial_ecg_data,SIGNAL(readyRead()),this , SLOT(RecibirArreglo_ECG_numerico()) );

    leds_inicio(); //inicia secuencia de leds al inciar monitor

    ui->toolButton->setCheckable(true);
    ui->toolButton->setChecked(true);
    ui->toolButton->setIcon(QIcon(":/imagenes/btn_Bocina.png"));

    ui->iniciarpani->setCheckable(true);
    ui->iniciarpani->setChecked(true);
    ui->iniciarpani->setIcon(QIcon(":/imagenes/btn_Iniciar.png"));
    //ui->toolButton->setStyleSheet("qproperty-icon: url(:/imagenes/btn_Bocina.png);");
    //ui->toolButton->setIcon(QIcon(QPixmap(":/imagenes/btn_Bocina.png")));

    //qDebug()<<"btn_Bocina";

    //widget temperatura
    widgetTemperatura = new WidgetTemperatura(this, 250, 100);
    widgetTemperatura->setGeometry(QRect(777, 245, 250, 100));
    widgetTemperatura->setWindowFlags( Qt::FramelessWindowHint | Qt::WindowSystemMenuHint); // | Qt::Popup //Qt::Window |
    //widgetTemperatura->setObjectName("widgetTemperatura");
    //widgetTemperatura->setStyleSheet("QWidget#widgetTemperatura { border: 5Px solid rgb(9, 150, 219); border-radius: 5Px;}"); //#widgetTemperatura
    widgetTemperatura->hide();

}

void MainWindow::cerrar_valvula(){
    qDebug() << "[VALVULA] Cerrar";
    emit spo2serial->escribe("Q");
}

void MainWindow::rec_mqtt(){
    if(!mqtt_connected){
        m_client->connectToHost();
        reconexionMqtt->start(10000);
       // qDebug() << "[MQTT] Reconexion";
    }

}

void MainWindow::rec_mqtt_termo(){
    if(!mqtt_connected_termo){
        m_client_termo->connectToHost();
        reconexionMqttTermo->start(10000);
       // qDebug() << "[MQTT] Reconexion";
    }

}

void MainWindow::cerrar_box_temp(){
    qDebug() <<"[msgBoxTemp] cerrar por timer" ;
    //msgBoxTemp->done(0);
    widgetTemperatura->hide();
}

void MainWindow::terminaTimerAlarmaR(){
    //comando = "omxplayer --vol -10000 -o local "+ audio + " &";
    qDebug() << "[terminaTimerAlarmaR] termina timer";
    QStringList params;
    params.append("--vol");
    params.append("-100");
    params.append("-o");
    params.append("local");
    params.append(audioAlarmaReproduciendoR);
    //params.append("&");
    processAlarmaR->start("omxplayer", params, QIODevice::ReadWrite);
}

void MainWindow::processFinishedAlarmaR(int val){
    qDebug() << "[processFinishedAlarmaR] termina proceso";
    alarma_reproduciendo = false;
}

void MainWindow::detenerSonido(){
    soundWait = false;
    activeTimer = true;
}

void MainWindow::envia_signos_mqtt(){
    if(mqtt_connected){
        /*mqtt_fc = 0;
        mqtt_porce_spo2 = 0;
        mqtt_bpm = 0;
        mqtt_sys = 0;
        mqtt_dia = 0;
        mqtt_resp = 12;*/
        QString temp = QString::number(mqtt_fc) + "," + QString::number(mqtt_porce_spo2) + ","  + QString::number(mqtt_bpm) + "," + QString::number(mqtt_sys) + "," + QString::number(mqtt_dia) + "," + QString::number(mqtt_resp);
        m_client->publish(QMqttTopicName("monitor/signos"), temp.toUtf8());
        //qDebug() << "[MQTT] Envia signos";
    }
}

void MainWindow::publish_spo2_mqtt(double data){
    if(mqtt_connected){
        QString temp = QString::number(data, 'f', 3);
        m_client->publish(QMqttTopicName("monitor/pleth"), temp.toUtf8());
        //qDebug() << "[MQTT] Envia pleth spo2";
    }
}

void MainWindow::publish_ecg_mqtt(QString data){
    if(mqtt_connected){
        //agregar contador
        if(mqtt_cont_ecg < 20){
            mqtt_list_ecg->append(data);
            mqtt_cont_ecg++;
        }
        else{
            mqtt_cont_ecg = 0;
            QString temp = mqtt_list_ecg->join(",");
            mqtt_list_ecg->clear();
            m_client->publish(QMqttTopicName("monitor/ecg"), temp.toUtf8());
            //qDebug() << "[MQTT] Envia ecg";
        }
    }
}

void MainWindow::boton_ajustes2(QString h)
{
    if (bandera_2 == true){
    if (h == "derecha"){
   if (deshabilitarTouch == true){
    contpos = contpos + 1;
    if(contpos > 11){
        contpos = 11;
    }
    qDebug()<<"Cuenta derecha "+QString::number(contpos);
    opciones();
   }
    }

    else if(h == "izquierda"){
          if (deshabilitarTouch == true){
                contpos = contpos - 1;
                    if(contpos < 0){
                        contpos = 0;
                    }
                 qDebug()<<"Cuenta izquierda "+QString::number(contpos);
                 opciones();
            }
    }

    else if(h == "click"){
         if (deshabilitarTouch == true){
                on_ok_clicked();
         }
    }

     else if(h == "numerico"){
       if (deshabilitarTouch == true){
         on_modelo2_pressed();
       }
     }

     else if(h == "sTouch"){
           conTouch = conTouch + 1;
           qDebug() <<  conTouch;
           deshabiliTouch();
     }

    else if(h == "pani"){
         if (deshabilitarTouch == true){
               on_iniciarpani_pressed();
               qDebug()<<"boton pani";
           }
    }
    else if(h == "mute"){
         if (deshabilitarTouch == true){
                recibeEdoBocinaMod2();
              }
        }
    }
}

void MainWindow::recibeEdoBocinaMod2(){
    banderaActAlarma = true;
    on_toolButton_pressed();
    AlarmaApagada = AlarmaApagada + 1;
    if(AlarmaApagada >= 2){
        qDebug()<<"Mute AlarmaApagada: "+QString::number(AlarmaApagada);
            AlarmaApagada = 0;
        }
}

void MainWindow::deshabiliTouch()
{
    if (conTouch == 1){
    deshabilitarTouch = false;
    }
    if (conTouch == 2){
        deshabilitarTouch = true;
        conTouch = 0;
    }
}
void MainWindow:: on_ok_clicked(){
    //qDebug() << "[on_ok_clicked]: " << contpos;
    switch(contpos)
    {
    case 0:
       on_open_records_pressed();
        break;
    case 1:
        on_screenshot_pressed();
        break;
    case 2:
        on_galeria_open_pressed();
        break;
    case 3:
        on_alarmas_pressed();
        break;
    case 4:
        on_iniciarpani_pressed();
        break;
    case 5:
        on_derivaciones_pressed();
        break;
    case 6:
        on_registro_usuario_pressed();
        break;
    case 7:
        on_Paciente_pressed();
        break;
    case 8:
        on_modelo2_pressed();
        break;
    case 9:
        banderaActAlarma = true;
        on_toolButton_pressed();
        AlarmaApagada = AlarmaApagada + 1;
        if(AlarmaApagada >= 2){
            AlarmaApagada = 0;
        }
        break;
    case 10:
        on_ajustes_pressed();
        break;
    case 11:
        on_toolButton_2_clicked();
        break;
    }

}


void MainWindow::cambiar_bandera(){
   if (bandera_barra_2) {
       bandera_2 = true;
   }
   else{
       emit cambiar_estado_bandera_3();

   }
}

void MainWindow::cambiar_bandera_barra_2(){
    bandera_barra_2 =true;
    bandera_2 = true;
}

void MainWindow:: opciones(){
    switch(contpos)
    {
    case 0:
        ui->open_records->setStyleSheet("background-color:red;border-image: url(:/imagenes/datos2.png) 0 0 0 0 strech strech;");
        ui->screenshot->setStyleSheet("border-image: url(:/imagenes/camara.png) 0 0 0 0 strech strech;");
        break;
    case 1:
        ui->screenshot->setStyleSheet("background-color:red;border-image: url(:/imagenes/camara.png) 0 0 0 0 strech strech;");
        ui->open_records->setStyleSheet("border-image: url(:/imagenes/datos2.png) 0 0 0 0 strech strech;");
        ui->galeria_open->setStyleSheet("border-image: url(:/imagenes/Galeria.png) 0 0 0 0 strech strech;");
        break;
    case 2:
        ui->galeria_open->setStyleSheet("background-color:red;border-image: url(:/imagenes/Galeria.png) 0 0 0 0 strech strech;");
        ui->screenshot->setStyleSheet("border-image: url(:/imagenes/camara.png) 0 0 0 0 strech strech;");
        ui->alarmas->setStyleSheet("border-image: url(:/imagenes/alarmas2.png) 0 0 0 0 strech strech;");
        break;
    case 3:
        ui->alarmas->setStyleSheet("background-color:red;border-image: url(:/imagenes/alarmas2.png) 0 0 0 0 strech strech;");
        ui->galeria_open->setStyleSheet("border-image: url(:/imagenes/Galeria.png) 0 0 0 0 strech strech;");
        ui->iniciarpani->setStyleSheet("border-image: url(:/imagenes/inciarpani2.png);");
        break;
    case 4:
        ui->iniciarpani->setStyleSheet("background-color:red;border-image: url(:/imagenes/inciarpani2.png);");
        ui->alarmas->setStyleSheet("border-image: url(:/imagenes/alarmas2.png) 0 0 0 0 strech strech;");
        ui->derivaciones->setStyleSheet("border-image: url(:/imagenes/DERIVACIONES.png) 0 0 0 0 stretch stretch;");
        break;
    case 5:
        ui->derivaciones->setStyleSheet("background-color:red;border-image: url(:/imagenes/DERIVACIONES.png) 0 0 0 0 stretch stretch;");
        ui->iniciarpani->setStyleSheet("border-image: url(:/imagenes/inciarpani2.png);");
        ui->registro_usuario->setStyleSheet("border-image: url(:/imagenes/Registro.png) 0 0 0 0 stretch stretch;");
        break;
    case 6:
        ui->registro_usuario->setStyleSheet("background-color:red;border-image: url(:/imagenes/Registro.png) 0 0 0 0 stretch stretch;");
        ui->derivaciones->setStyleSheet("border-image: url(:/imagenes/DERIVACIONES.png) 0 0 0 0 stretch stretch;");
        ui->Paciente->setStyleSheet("border-image: url(:/imagenes/Paciente.png) 0 0 0 0 stretch stretch;");
        break;
    case 7:
        ui->Paciente->setStyleSheet("background-color:red;border-image: url(:/imagenes/Paciente.png) 0 0 0 0 stretch stretch;");
        ui->registro_usuario->setStyleSheet("border-image: url(:/imagenes/Registro.png) 0 0 0 0 stretch stretch;");
        ui->modelo2->setStyleSheet("border-image: url(:/imagenes/solonumerico.png) 0 0 0 0 stretch stretch;");
        break;
    case 8:
        ui->modelo2->setStyleSheet("background-color:red;border-image: url(:/imagenes/solonumerico.png) 0 0 0 0 stretch stretch;");
        ui->Paciente->setStyleSheet("border-image: url(:/imagenes/Paciente.png) 0 0 0 0 stretch stretch;");
        ui->toolButton->setStyleSheet("border-image: url(:/imagenes/sonido.png) 0 0 0 0 stretch stretch;");
        break;
    case 9:
        ui->toolButton->setStyleSheet("background-color:red;border-image: url(:/imagenes/sonido.png) 0 0 0 0 stretch stretch;");
        ui->modelo2->setStyleSheet("border-image: url(:/imagenes/solonumerico.png) 0 0 0 0 stretch stretch;");
        ui->ajustes->setStyleSheet("border-image:  url(:/imagenes/config.png) 0 0 0 0 stretch stretch;");
        break;
    case 10:
        ui->ajustes->setStyleSheet("background-color:red;border-image:  url(:/imagenes/config.png) 0 0 0 0 stretch stretch;");
        ui->toolButton->setStyleSheet("border-image: url(:/imagenes/sonido.png) 0 0 0 0 stretch stretch;");
        ui->toolButton_2->setStyleSheet("");
        break;
    case 11:
        ui->toolButton_2->setStyleSheet("background-color:red;");
        ui->ajustes->setStyleSheet("");
        break;
    }
}

void MainWindow::networkReadyRead(){

        QString var = m_networkReply->readAll();
        QStringList list2 = var.split(QLatin1Char('"'));
        if(list2.length()<3){
            QMessageBox msgBox;
            msgBox.setWindowTitle("Alerta");
            msgBox.setWindowFlags(Qt::Popup);
            msgBox.setText("Verifique su código de vinculación, ningún dato ha sido enviado.");
            msgBox.exec();
            jsonrecibido = false;
        }
        else{
            uid_value = list2[3];
            uid_doctor = list2[7];
            jsonrecibido = true;
        }
}
void MainWindow::errorpani(){
    bandera_pani = false;
    pantalla=0;
    contador=contador+1;
    ps_save_reg = "ERROR"; //value to save into database
    px_save_reg = "ERROR";
    rpm_save_reg = "ERROR";
    sys_mod2 = "ERR";
    dia_mod2 = "ERR";
    med_mod2 = "ERR";
    press_flag_data = false;
    reg_save_data = data_time_rate - 10;
    ui->rpm->setText("Err");
    ui->pres_sis->setText("Err");
    ui->pres_sis_2->setText("Err");
    ui->rpm->setText("Err");
    ui->label_5->setText("<font color='red' size='1'>Se ha detectado error en medición PANI, inicialize nuevamente </font>");
    //ui->iniciarpani->setStyleSheet("background-image: url(:/imagenes/inciarpani2.png);background-repeat:none;border: none");
    ui->iniciarpani->setIcon(QIcon(":/imagenes/btn_Iniciar.png"));

    //jeru timer
    timerValvula->start(20000);

}

void MainWindow::panivalues(QString s, QString d, QString m){

//*****************************Systolic*******************************************************
    ps_save_reg = s; //value to save into database
    ui->pres_sis->setText(s);
    sys_mod2 = s;
    mqtt_sys = s.toInt();

//*****************************Dystolic**************************************************
    px_save_reg = d; //value to save into database
    ui->pres_sis_2->setText(d);
    dia_mod2 = d;
    mqtt_dia = d.toInt();
//****************************MEDIA********************************************************
    ui->rpm->setText(m);
    if(m.toFloat()>0 || s.toFloat() > 30){
        //ui->iniciarpani->setStyleSheet("background-image: url(:/imagenes/inciarpani2.png);background-repeat:none;border: none");
        ui->iniciarpani->setChecked(false);
        ui->iniciarpani->setIcon(QIcon(":/imagenes/btn_Iniciar.png"));
        bandera_pani = false;
        press_flag_data = true;
        reg_save_data = data_time_rate - 10;
    }
    rpm_save_reg = m; // value to save for rpm register into database
    med_mod2 = m;

    //jeru timer
    timerValvula->start(20000);

}

void MainWindow::updatetemperature(QString temperature, double saving_temperature_number){

    ui->temp->setText(temperature);
    ui->temp->setStyleSheet("background-color:none");
    temp_mod2 = temperature;
    saving_temperature = saving_temperature_number;
    temp_save_reg = temperature;
    RecibirArreglo(2);
}

void MainWindow::porcentualspo2(QString spo2value){

    if(!(spo2value == "--")){
        ui->SPO2->setText(spo2value);
        sop2_mod2 = spo2value;
        savespo2 = spo2value.toDouble();
        spo2_save_reg = spo2value + " " + "%";
        mqtt_porce_spo2 = savespo2;
        if(savespo2<70){
            is_spo2_ready = false;
        }
        else{
         is_spo2_ready = true;
        }
        reciving_spo2_data = true;
    }
}

void MainWindow::cuadronegro_spo2(int square){
    ui->borrargraph->setGeometry(square, 250, 23, 151); //a rectange is moved as the system create the graph
}

void MainWindow::bpm_count_spo2(QString bpm){
    ui->bpmsp2->setText(bpm);
    //
    //qDebug() << "bpmspo2!!!!";
    mqtt_bpm =bpm.toInt();
}

void MainWindow::not_data(){
    sop2_mod2 = "not";
    ui->bpmsp2_2->setText("<font color='red' size='.3'>Coloque \r\n dedo</font>");
    ui->bpmsp2_2->setGeometry(95,30,210,61);
    savespo2 = 0;
    ui->SPO2->setText("00");
    ui->SPO2->setText("00");
    ui->SPO2->setGeometry(10,10,201,61);
    ui->bpmsp2->setText("00");
    is_spo2_ready = false;
    reciving_spo2_data = false;
}
void MainWindow::leds_inicio(){
   // leds = new PantallaCarga;
   // leds->setWindowFlags(Qt::FramelessWindowHint);
  //  QObject::connect(leds, SIGNAL(leds_t()), this, SLOT(leds_inicio_carga()));
   // QObject::connect(leds, SIGNAL(leds_o()), this, SLOT(leds_inicio_okey()));
   // QObject::connect(leds, SIGNAL(leds_l()), this, SLOT(leds_inicio_apagar()));
   // QObject::connect(leds, SIGNAL(check_inicio()), this, SLOT(puerto_carga_inicial()));
   // leds->exec();
   // show();
    //+++++++++++++++++++++++++++++++++++++++++ REFRESH TIMER ++++++++++++++++++++++++++++++++++++++++
    connect(cronometro, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer()));

    cronometro->start(100);
    connect(spo2_refresh_chart, SIGNAL(timeout()), this, SLOT(alarm_sound()));
    //+++++++++++++++++++++++++++++++++++++ INTERFAZ IS READY +++++++++++++++++++++++++++++++++
    serial_ecg_data->write("restart\n"); //Restart all the systems
   // spo2serial->write_value("restart\n");//Restar all the systems
}

void MainWindow::active_timer_for_alarms(bool state){
    if(state){
        spo2_refresh_chart->start(4000);
    }
    else{
        spo2_refresh_chart->stop();
    }
}

void MainWindow::alarm_sound(){
     sonidoboton2("/home/pi/Music/sonidos/TRESbeeps.mp3");
}

bool MainWindow::inital_check_ophyra(){
}

void MainWindow::puerto_carga_inicial(){
  // spo2 = serial->isWritable();
   //ecg = serial_ecg->isOpen();
   //ecg_datos = serial_ecg_data->isOpen();S

   if (QFile::exists("prueba.sqlite")) {
       database_exist = true;
   }
   if(QDir("imagenes").exists()){
       folder_img = true;
    }
   else{
       if(QDir().mkdir("imagenes")){
           folder_img = true;
       }
   }
}

void MainWindow::sonido_click(){
    sonidoboton2("/home/pi/Music/sonidos/CLICK.mp3");
}

void MainWindow::sonido_basura(){
    sonidoboton2("/home/pi/Music/sonidos/BASURA.mp3");
}

void MainWindow::leds_inicio_carga(){
    //serial->write("T");
  //  spo2serial->write_value("T");
      emit spo2serial->escribe("T");
}



void MainWindow::leds_inicio_okey(){
    //serial->write("O");
   // spo2serial->write_value("O");
      emit spo2serial->escribe("O");
}

void MainWindow::leds_inicio_apagar(){
    //serial->write("L");
  //  spo2serial->write_value("L");
      emit spo2serial->escribe("L");
}



void MainWindow::updateLogStateChange(){
    const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(": State Change")
                    + QString::number(m_client->state())
                    + QLatin1Char('\n');
}

void MainWindow::brokerConnected(){
    qDebug() << "[MQTT] Conectado";
    const QString topic = "ecg";
    mqtt_connected = true;
    auto subscription = m_client->subscribe(topic);
    if (!subscription)
    {
        return;
    }
    //qDebug()<<"holi";
}

void MainWindow::brokerDisconnected()
{
    qDebug() << "[MQTT] Desconectado";
    mqtt_connected = false;
    reconexionMqtt->start(3000);
}

void MainWindow::updateLogStateChangeTermo(){
    const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(": State Change")
                    + QString::number(m_client->state())
                    + QLatin1Char('\n');
}

void MainWindow::brokerConnectedTermo(){
    qDebug() << "[MQTT TERMO] Conectado";
    const QString topic = "ztp/temp";
    mqtt_connected_termo = true;
    auto subscription = m_client_termo->subscribe(topic);
    if (!subscription)
    {
        return;
    }
}

void MainWindow::brokerDisconnectedTermo()
{
    qDebug() << "[MQTT TERMO] Desconectado";
    mqtt_connected_termo = false;
    reconexionMqttTermo->start(3000);
}

void MainWindow::get_alarms_value(){
    QString alarm;
    QSqlQuery alarmas;
    alarm.append("SELECT * FROM alarmas WHERE ID = '1'");
    alarmas.prepare(alarm);
    alarmas.exec();
    alarmas.next();
    alarm.clear();
    alarma_min_ecg =  alarmas.value(0).toInt();
    alarma_max_ecg =  alarmas.value(1).toInt();
    alarma_min_spo2 = alarmas.value(2).toInt();
    alarma_max_spo2 = alarmas.value(3).toInt();
    alarma_min_temp = alarmas.value(4).toInt();
    alarma_max_temp = alarmas.value(5).toInt();
}

/*void MainWindow::sonidoboton2(QString audio)
{
    if(!soundWait){
        QString comando, sound;
        if(silenciado){
           comando = "omxplayer --vol -1500 -o local "+ audio + " &";
        }
        else{
            comando = "omxplayer --vol -10000 -o local "+ audio + " &";
        }
        int estado = system(comando.toStdString().c_str());
        if(estado == -1) {
             qDebug()<<"Error sonidoboton2";
        }
        else {
             qDebug()<<"Reproduciendo";
         }
    }
}*/

void MainWindow::sonidoboton2(QString audio)
{
    /*if(!soundWait){
        QString comando, sound;
        if(!silenciado){
            comando = "omxplayer --vol -10000 -o local "+ audio + " &";
        }
        int estado = system(comando.toStdString().c_str());
        if(estado == -1) {
             qDebug()<<"Error sonidoboton2";
        }
        else {
             qDebug()<<"Reproduciendo";
         }
    }*/
    qDebug() << "[sonidoboton2] entra";
    if(!silenciado && !alarma_reproduciendo){
        qDebug() << "[sonidoboton2] manda a iniciar el timer";
        alarma_reproduciendo = true;
        timerAlarmaR->start(2000);
        audioAlarmaReproduciendoR = audio;
    }
}

void MainWindow::on_screenshot_pressed(){
    if (deshabilitarTouch == true){
        sonidoboton2("/home/pi/Music/sonidos/CAMARA.mp3");
        QScreen *QSCREEN = QGuiApplication::primaryScreen();
        QPixmap qpix = QSCREEN->grabWindow(this->winId(), 0, 0, QApplication::desktop()->width(),
                                       QApplication::desktop()->height());
        qpix.save("./imagenes/"+aux+".png");
        ui->label_6->setText("<font color='#08afff'>Se ha tomado una captura de pantalla</font>");

        hora_captura=0;
    }
}
void MainWindow::on_toolButton_2_clicked(){
     if (deshabilitarTouch == true){
         bandera_2 = false;
         qDebug("ON TOOL BUTTON");
         enviardatosw = new enviardatos(nullptr, teclado);
         enviardatosw->setWindowFlags(Qt::FramelessWindowHint);
         enviardatosw->setWindowFlags(Qt::Popup);
         QObject::connect(enviardatosw, SIGNAL(sonido_click()), this, SLOT(sonido_click()));
         QObject::connect(enviardatosw, SIGNAL(send_data(int)), this, SLOT(enviar_datos(int)));
         QObject::connect(enviardatosw, SIGNAL(bandera_perilla_9()), this, SLOT(cambiar_bandera()));
         //enviardatosw->setGeometry(87, 10, 510, 70);
         enviardatosw->setGeometry(0, 10, 602, 110);
         enviardatosw->exec();
         show();
     }


}
void MainWindow::on_iniciar_pressed(){

    sonidoboton2("/home/pi/Music/sonidos/CLICK.mp3");
    indicadoranalisis = 1;
    //serial->write("Z");
    if(detection){
        ui->analisis->setText("Realizando Analisis");
        puntos = 0;
        banderapuntos = true;
       }
    else{
        ui->analisis->setText("<font color='red'>Analisis Apagado</font>");
        banderapuntos = false;
        puntos = 0;
    }
    reg_save_data = 0;
}


void MainWindow::on_iniciarpani_pressed(){
         if (deshabilitarTouch == true){
             sonidoboton2("/home/pi/Music/sonidos/CLICK.mp3");
             timerValvula->stop();
              if(!bandera_pani){
                  //serial->write("B");
                  //spo2serial->write_value("B");
                  emit spo2serial->escribe("B");
                  //ui->iniciarpani->setStyleSheet("border-image: url(:/imagenes/detenerpani2.png);background-repeat:none;border: none");
                  ui->iniciarpani->setChecked(true);
                  ui->iniciarpani->setIcon(QIcon(":/imagenes/btn_Detener.png"));
                  bandera_pani=true;
               }
             else{
                  //serial->write("U");
                  //spo2serial->write_value("U");
                  //spo2serial->write_value("B");
                  //JORGE
                  emit spo2serial->escribe("P");
                  //ui->iniciarpani->setStyleSheet("border-image: url(:/imagenes/inciarpani2.png);background-repeat:none;border: none");
                  ui->iniciarpani->setChecked(false);
                  ui->iniciarpani->setIcon(QIcon(":/imagenes/btn_Iniciar.png"));
                  bandera_pani=false;
                  cadena3[0] = 'E'; //Al detener manualmente la medicion se manda "E" para lanzar activar label ERROR en medición
             }
         }
}

void MainWindow::on_open_records_pressed(){
        if (deshabilitarTouch == true){
            bandera_2 = false;
            sonidoboton2("/home/pi/Music/sonidos/CLICK.mp3");
            records = new alarmas(nullptr, teclado);
            records->setWindowFlags(Qt::FramelessWindowHint);
            QObject::connect(records, SIGNAL(sonido_click()), this, SLOT(sonido_click()));
            QObject::connect(records, SIGNAL(habilitar_barra_desde_basedatos()), this, SLOT(cambiar_bandera()));
            records->exec();
            show();
        }
}


void MainWindow::on_Paciente_pressed(){
      if (deshabilitarTouch == true){
            bandera_2 = false;
            sonidoboton2("/home/pi/Music/sonidos/CLICK.mp3");
            paciente = new Paciente(nullptr, teclado);
            paciente->setWindowFlags(Qt::FramelessWindowHint);
            paciente->setWindowFlags(Qt::Popup);
            paciente->setGeometry(701, 105, 340, 588);
           QObject::connect(paciente, SIGNAL(sonido_click()), this, SLOT(sonido_click()));
           QObject::connect(paciente, SIGNAL(bandera_perilla_7()), this, SLOT(cambiar_bandera()));
           paciente->exec();
           show();
      }
}

void MainWindow::on_registro_usuario_pressed(){
     if (deshabilitarTouch == true){
         bandera_2 = false;
         sonidoboton2("/home/pi/Music/sonidos/CLICK.mp3");
         registros = new Registro(nullptr, teclado);
         registros->setWindowFlags(Qt::FramelessWindowHint);
         QObject::connect(registros, SIGNAL(sonido_click()), this, SLOT(sonido_click()));
         QObject::connect(registros, SIGNAL(bandera_perilla_6()), this, SLOT(cambiar_bandera()));
         registros->exec();
         show();
     }
}

void MainWindow::enviar_datos(int valor){
    QVariantMap newData;
    QMessageBox msgBox;
    msgBox.setWindowTitle("Envio correcto");
    msgBox.setWindowFlags(Qt::Popup);
    registro_firebase = registro_firebase + 1;
    QString s = QString::number(registro_firebase);
    QSqlQuery crear;
    arrdata_to_send = retornar_valores();
    QString save_settings_mode;
    save_settings_mode.append("UPDATE ajustes SET firebase ='"+ s +"'");
    crear.prepare(save_settings_mode);
    crear.exec();
    //tomamos el uid para ingresar los datos al usuario especifico
    save_settings_mode.clear();
    crear.clear();
    save_settings_mode.append("SELECT * FROM pacientes WHERE activo = '1'");
    crear.prepare(save_settings_mode);
    crear.exec();
    crear.next();
    m_networkReply = m_networkManager->get(QNetworkRequest(QUrl("https://qtmonitor-b39a1-default-rtdb.firebaseio.com/listausuarios/"+crear.value(8).toString()+".json")));
    connect(m_networkReply, &QNetworkReply::readyRead, this, &MainWindow::networkReadyRead);

    if(valor == 1 && jsonrecibido){
        newData["order"] = registro_firebase;
        newData["bpm"] =  arrdata_to_send[0];
        newData["dys"] = "--";
        newData["fecha"] = QDateTime::currentDateTime().toString("dd-MMM-yyyy hh:mm:ss");
        newData["spo"] = "--";
        newData["sys"] = "--";
        newData["temp"] = "--";
        newData["media"] = "--";
        QJsonDocument jsonDoc = QJsonDocument::fromVariant(newData);
        QNetworkRequest newDataRequest(QUrl("https://qtmonitor-b39a1-default-rtdb.firebaseio.com/doctores/"+uid_doctor+"/pacientes/"+uid_value+"/registros/registro"+s+".json"));
        newDataRequest.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
        m_networkManager->put(newDataRequest, jsonDoc.toJson());
        msgBox.setText("Los datos han sido enviados.");
        msgBox.exec();
    }
    if(valor == 2  && jsonrecibido){
        newData["order"] = registro_firebase;
        newData["bpm"] =  "--";
        newData["dys"] = "--";
        newData["fecha"] = QDateTime::currentDateTime().toString("dd-MMM-yyyy hh:mm:ss");
        newData["spo"] = arrdata_to_send[1];
        newData["sys"] = "--";
        newData["temp"] = "--";
        newData["media"] = "--";
        QJsonDocument jsonDoc = QJsonDocument::fromVariant(newData);
        QNetworkRequest newDataRequest(QUrl("https://qtmonitor-b39a1-default-rtdb.firebaseio.com/doctores/"+uid_doctor+"/pacientes/"+uid_value+"/registros/registro"+s+".json"));
        newDataRequest.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
        m_networkManager->put(newDataRequest, jsonDoc.toJson());
        msgBox.setText("Los datos han sido enviados.");
        msgBox.exec();
    }
    if(valor == 3  && jsonrecibido){
        newData["order"] = registro_firebase;
        newData["bpm"] =  "--";
        newData["dys"] = arrdata_to_send[4];
        newData["fecha"] = QDateTime::currentDateTime().toString("dd-MMM-yyyy hh:mm:ss");
        newData["spo"] = "--";
        newData["sys"] = arrdata_to_send[3];
        newData["temp"] = "--";
        newData["media"] = arrdata_to_send[5];
        QJsonDocument jsonDoc = QJsonDocument::fromVariant(newData);
        QNetworkRequest newDataRequest(QUrl("https://qtmonitor-b39a1-default-rtdb.firebaseio.com/doctores/"+uid_doctor+"/pacientes/"+uid_value+"/registros/registro"+s+".json"));
        newDataRequest.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
        m_networkManager->put(newDataRequest, jsonDoc.toJson());
        msgBox.setText("Los datos han sido enviados.");
        msgBox.exec();
    }
    if(valor == 4  && jsonrecibido){
        newData["order"] = registro_firebase;
        newData["bpm"] =  "--";
        newData["dys"] = "--";
        newData["fecha"] = QDateTime::currentDateTime().toString("dd-MMM-yyyy hh:mm:ss");
        newData["spo"] = "--";
        newData["sys"] = "--";
        newData["temp"] = arrdata_to_send[2];
        newData["media"] = "--";
        QJsonDocument jsonDoc = QJsonDocument::fromVariant(newData);
        QNetworkRequest newDataRequest(QUrl("https://qtmonitor-b39a1-default-rtdb.firebaseio.com/doctores/"+uid_doctor+"/pacientes/"+uid_value+"/registros/registro"+s+".json"));
        newDataRequest.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
        m_networkManager->put(newDataRequest, jsonDoc.toJson());
        msgBox.setText("Los datos han sido enviados.");
        msgBox.exec();
    }
    if(valor == 5  && jsonrecibido){
        newData["order"] = registro_firebase;
        newData["bpm"] =  bpm_mod2;
        newData["dys"] = dia_mod2;
        newData["fecha"] = QDateTime::currentDateTime().toString("dd-MMM-yyyy hh:mm:ss");
        newData["spo"] = sop2_mod2;
        newData["sys"] = sys_mod2;
        newData["temp"] = temp_mod2;
        newData["media"] = med_mod2;
        QJsonDocument jsonDoc = QJsonDocument::fromVariant(newData);
        QNetworkRequest newDataRequest(QUrl("https://qtmonitor-b39a1-default-rtdb.firebaseio.com/doctores/"+uid_doctor+"/pacientes/"+uid_value+"/registros/registro"+s+".json"));
        newDataRequest.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
        m_networkManager->put(newDataRequest, jsonDoc.toJson());
        msgBox.setText("Los datos han sido enviados.");
        msgBox.exec();
    }

}

void MainWindow::on_alarmas_pressed(){
        if (deshabilitarTouch == true){
            bandera_2 = false;
            sonidoboton2("/home/pi/Music/sonidos/CLICK.mp3");
            alarma = new config_alarmas(nullptr, teclado);
            alarma->setWindowFlags(Qt::FramelessWindowHint);
            QObject::connect(alarma, SIGNAL(sonido_click()), this, SLOT(sonido_click()));
            QObject::connect(alarma, SIGNAL(alarms_change()), this, SLOT(alarms_change()));
            QObject::connect(alarma, SIGNAL(habilitar_barra_desde_alarmas()), this, SLOT(cambiar_bandera()));
            alarma->exec();
            show();
        }
}

void MainWindow::alarms_change(){
    get_alarms_value();
}

void MainWindow::on_cerrar_pressed(){
    //serial->close();
    //serial_ecg->close();
    //spo2serial->close_port();
    //serial_ecg_data->close();
   // this->close();
}
void MainWindow::on_MainWindow_destroyed(){
    QProcess::startDetached(QApplication::applicationFilePath());
    exit(12);
    qDebug()<<"here";
}

MainWindow::~MainWindow(){
    //serial->close();
   // serial_ecg->close();


    spo2serial->close_port();
    serial_ecg_data->close();
  // delete ui;
}
void MainWindow::funcionActivacionTimer(){

    if ((ui->color->isVisible())) {
      //  qDebug()<<"holi";
    }
    else{
        QProcess::startDetached(QApplication::applicationFilePath());
        exit(12);
       qDebug()<<"here";
    }
    //TIMER se realizan operaciones para timers
    aux=QDateTime::currentDateTime().toString("dd-MM-yyyy");
    aux = aux + "\r\n" + QDateTime::currentDateTime().toString("hh:mm:ss");
    ui->fh->setText(aux);
    hora_captura=hora_captura+1; // Timer captura de pantalla
    pantalla=pantalla+1; // Timer de label en PANI
    numeros_ecg = numeros_ecg + 1;
    numeros_spo2 = numeros_spo2 + 1;
    check_bpm_value_time = check_bpm_value_time + 1;
    numeros_temp = numeros_temp + 1;// Timer cambio de color en numeros
    reg_save_data = 1 + reg_save_data;
    puntos=puntos+1;//Timer animacion de puntos en "Realizando Analisis
    ActivarAlarmas = ActivarAlarmas + 1;
    TimerBateria = TimerBateria +1;
    if(TimerBateria == 50){
        emit teclado->escribe("BOK\n");
        TimerBateria = 0 ;
    }


    if(AlarmaApagada == 1){
        if (banderaActAlarma){
            if (ActivarAlarmas==300){
                on_toolButton_pressed();
               // banderaActAlarma = false;
                emit cambiar_estado_bocina();
                ActivarAlarmas = 0;
                AlarmaApagada = 0;
            }
        }
} else{
        ActivarAlarmas = 0;
    }
    //Animación de puntos en label "Realizando Analisis..."


    /*if(puntos==10 && banderapuntos){
        emit spo2serial->escribe("Q"); //jeru junio 29
        ui->analisis->setText("Realizando Analisis");
    }*/
    if(puntos==20 && banderapuntos){
        ui->analisis->setText("Realizando Analisis.");
    }
    if(puntos==30 && banderapuntos){
        ui->analisis->setText("Realizando Analisis..");
    }
    if(puntos==40 && banderapuntos){
        ui->analisis->setText("Realizando Analisis...");
        puntos=0;
    }
     qDebug() << "puntos: "  << puntos;
    if(puntos == 145){
        spo2serial->bpm_flag_update();
        puntos =0;
    }
    //return to blank the label that appers when takes a screenshot
    if(hora_captura>2){
        ui->label_6->setText("");
         hora_captura=0;
    }
    if(check_bpm_value_time == 1){
        spo2serial->IsActive();
        if(save_alarm_data_bpm > alarma_max_ecg){
            ecg_in = true;
            ecg_out = true;
           //silenciar_alarmas(true, silenciado);
        }
        else{
            if(save_alarm_data_bpm < alarma_min_ecg){
                ecg_in = true;
                ecg_out = true;
            }
            else{
                ecg_in = false;
                ecg_out = false;
               // silenciar_alarmas(false, silenciado);
            }
        }
        silenciar_alarmas(true, silenciado);
        check_bpm_value_time = 0;
    }
    //timer for reg_save_data data every 57 seconds aprox
   if(reg_save_data>data_time_rate && reg_save_data_activated){
       save_data_db();
       reg_save_data= 0;
    }

   if(pantalla>80){
       ui->label_5->setText("");
        pantalla=0;

   }

   //this blocks are for bliding the numbers when alarms are activated

   if(numeros_ecg==10){
       if(cambio_numeros && activated){
           QLabel *label1=ui->bpm_ecg;
           QString color="color:#880e00; border:none";
           alarmasnumeros(label1,color);
           cambio_numeros=false;
           numeros_ecg=0;
           //ui->bpm_ecg->setStyleSheet("background-color: rgba(191, 64, 64, 0); border:none");
       }
       else{
           QLabel *label1=ui->bpm_ecg;
           QString color="color:#ff0000; border:none";
           alarmasnumeros(label1,color);
           cambio_numeros=true;
           numeros_ecg=0;
          // ui->bpm_ecg->setStyleSheet("background-color: rgba(191, 64, 64, 0); border:none");

       }
   }

   if(numeros_spo2==10){
       if(cambio_numeros2 && activated2){
             QLabel *label2=ui->SPO2;
             QString color="color:#005b01;border:none";
             alarmasnumeros(label2,color);
             cambio_numeros2=false;
             numeros_spo2=0;
        //     ui->SPO2->setStyleSheet("background-color: rgba(191, 64, 64, 0); border:none");

       }
       else{
             QLabel *label2=ui->SPO2;
             QString color="color:#6bff19;border:none";

             alarmasnumeros(label2,color);
             cambio_numeros2=true;
             numeros_spo2=0;
       //      ui->SPO2->setStyleSheet("background-color: rgba(191, 64, 64, 0); border:none");

       }
   }

   if(numeros_temp == 10){
       if(cambio_numeros3 && activated3){
           QLabel *label3=ui->temp;
           QString color="color:#003e56;border:none;background-color:none;";
           alarmasnumeros(label3,color);
           cambio_numeros3=false;
           numeros_temp=0;
       }
       else{
           QLabel *label3=ui->temp;
           QString color="color:#1b50ff;border:none;background-color:none; ";
           alarmasnumeros(label3,color);
           cambio_numeros3=true;
           numeros_temp=0;
       }
   }
}

//show galery window
void MainWindow::on_galeria_open_pressed(){
    if (deshabilitarTouch == true){
        bandera_2 = false;
        sonidoboton2("/home/pi/Music/sonidos/CLICK.mp3");
        galeria1 = new galeria(nullptr, teclado);
        galeria1->setWindowFlags(Qt::FramelessWindowHint);
        QObject::connect(galeria1, SIGNAL(sonido_click()), this, SLOT(sonido_click()));
        QObject::connect(galeria1, SIGNAL(sonido_basura()), this, SLOT(sonido_basura()));
        QObject::connect(galeria1, SIGNAL(bandera_perilla_2()), this, SLOT(cambiar_bandera()));
        galeria1->exec();
        show();
    }
}


//show settings window
void MainWindow::on_ajustes_pressed(){
    if (deshabilitarTouch == true){
        bandera_2 = false;
        sonidoboton2("/home/pi/Music/sonidos/CLICK.mp3");
        settings = new ajustes(nullptr, teclado);
        settings->setWindowFlags(Qt::FramelessWindowHint);
        QObject::connect(settings, SIGNAL(change_color_click()), this, SLOT(change_color_once()));
        QObject::connect(settings, SIGNAL(detection_change()), this, SLOT(detection_toggle()));
        QObject::connect(settings, SIGNAL(time_save_change(int)), this, SLOT(time_save_change(int)));
        QObject::connect(settings, SIGNAL(sonido_click()), this, SLOT(sonido_click()));
        QObject::connect(settings, SIGNAL(bandera_perilla()), this, SLOT(cambiar_bandera()));
        settings->exec();
        show();
    }
}

//signal for change the saving time

void MainWindow::time_save_change(int x){
   QSqlQuery crear;
   QString save_settings_mode;
   QString s = QString::number(x);
   save_settings_mode.append("UPDATE ajustes SET time_save ='"+ s +"'");
   crear.prepare(save_settings_mode);
   crear.exec();
   reg_save_data = 0;
   if(s == "1"){
       data_time_rate = 57000;
   }
   if(s == "2"){
       data_time_rate = 285000;
   }
   if(s == "3"){
       data_time_rate = 855000;
   }
   if(s == "4"){
       data_time_rate = 1710000;
   }
   if(s == "5"){
       data_time_rate = 3420000;
   }
}

//signal from settings window for toggle detection mode
void MainWindow::detection_toggle(){
    if(detection){
        ui->analisis->setText("<font color='#3DDEC7'>Realizando Analisis...</font>");
        detection_mode_change = true;
        banderapuntos = true;
        puntos = 0;
    }
    else{
        ui->analisis->setText("<font color='red'>Analisis Apagado</font>");
        detection_mode_change = false;
        banderapuntos = false;
    }
}

//signal from settings window for change the color view
void MainWindow::change_color_once(){
        ui->color->setStyleSheet("background-color:" + maincolor);//background
        ui->borrargraph->setStyleSheet("background-color:" + maincolor);//background erase rectangle
        ui->ecg->change_square_ecg(maincolor);
        //color_msgBoxTemp = maincolor;
      //  ui->ecg_2->change_square_ecg(maincolor);
        //ui->borrargraph_ecg->setStyleSheet("background-color:" + maincolor);//background erase rectangle

     if(maincolor == "#326d72"){
         //for the ples graph
         ui->plot->graph(0)->setPen(QPen(Qt::black, 1)); //color and width of the line
         ui->plot->axisRect()->setBackground(QColor(50, 109, 114)); //background of the graph
         ui->plot->xAxis->grid()->setPen(QPen(QColor(50, 109, 114), Qt::SolidLine)); //x axis color
         ui->plot->yAxis->grid()->setPen(QPen(QColor(50, 109, 114), Qt::SolidLine)); //y axis color
         ui->plot->xAxis->setBasePen(QPen(QColor(50, 109, 114)));
         ui->plot->yAxis->setBasePen(QPen(QColor(50, 109, 114)));
         ui->plot->setBackground(QColor(50, 109, 114));
         ui->plot->replot();

         //to change the sidebar
         ui->TEMP->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
         ui->OXBLOCK->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
         ui->PANI->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
         ui->ECGBLOCK->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
         ui->DIAS->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
         ui->SYS->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
         ui->pres_sis->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white; border:none");
         ui->pres_sis_label->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white; border:none");
         ui->pres_sis_label_3->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white; border:none");

         //for the ecg graph
         ui->ecg->change_color_chart(1);
         ui->ecg_2->change_color_chart(1);

     }
     if(maincolor == "#20214f"){
         //for the ples graph
         ui->plot->graph(0)->setPen(QPen(Qt::black, 1)); //color and width of the line
         ui->plot->axisRect()->setBackground(QColor(32, 33, 79)); //background of the graph
         ui->plot->xAxis->grid()->setPen(QPen(QColor(32, 33, 79), Qt::SolidLine)); //x axis color
         ui->plot->yAxis->grid()->setPen(QPen(QColor(32, 33, 79), Qt::SolidLine)); //y axis color
         ui->plot->xAxis->setBasePen(QPen(QColor(32, 33, 79)));
         ui->plot->yAxis->setBasePen(QPen(QColor(32, 33, 79)));
         ui->plot->setBackground(QColor(32, 33, 79));
         ui->plot->replot();

         //to change the sidebar
         ui->TEMP->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
         ui->OXBLOCK->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
         ui->PANI->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
         ui->ECGBLOCK->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
         ui->DIAS->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
         ui->SYS->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
         ui->pres_sis->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white; border:none");
         ui->pres_sis_label->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white; border:none");
         ui->pres_sis_label_3->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white; border:none");

         //for the ecg graph
         ui->ecg->change_color_chart(2);
         ui->ecg_2->change_color_chart(2);

     }
     if(maincolor == "#ffffff"){
         //for the ples graph
         ui->plot->graph(0)->setPen(QPen(Qt::black, 1)); //color and width of the line
         ui->plot->axisRect()->setBackground(QColor(255, 255, 255)); //background of the graph
         ui->plot->xAxis->grid()->setPen(QPen(QColor(255, 255, 255), Qt::SolidLine)); //x axis color
         ui->plot->yAxis->grid()->setPen(QPen(QColor(255, 255, 255), Qt::SolidLine)); //y axis color
         ui->plot->xAxis->setBasePen(QPen(QColor(255, 255, 255)));
         ui->plot->yAxis->setBasePen(QPen(QColor(255, 255, 255)));
         ui->plot->setBackground(QColor(255, 255, 255));
         ui->plot->replot();

         //to change the sidebar
         ui->TEMP->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: black;");
         ui->OXBLOCK->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: black;");
         ui->PANI->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: black;");
         ui->ECGBLOCK->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: black;");
         ui->DIAS->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: black;");
         ui->SYS->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: black;");
         ui->pres_sis->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:black; border:none");
         ui->pres_sis_label->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:black; border:none");
         ui->pres_sis_label_3->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:black; border:none");

         //for the ecg graph
         ui->ecg->change_color_chart(3);
         ui->ecg_2->change_color_chart(3);


     }
     if(maincolor == "#000000"){
         //for the ples graph
         ui->plot->graph(0)->setPen(QPen(Qt::green, 1)); //color and width of the line
         ui->plot->axisRect()->setBackground(QColor(0, 0, 0)); //background of the graph
         ui->plot->xAxis->grid()->setPen(QPen(QColor(0, 0, 0), Qt::SolidLine)); //x axis color
         ui->plot->yAxis->grid()->setPen(QPen(QColor(0, 0, 0), Qt::SolidLine)); //y axis color
         ui->plot->xAxis->setBasePen(QPen(QColor(0, 0, 0)));
         ui->plot->yAxis->setBasePen(QPen(QColor(0, 0, 0)));
         ui->plot->setBackground(QColor(0, 0, 0));
         ui->plot->replot();

         //to change the sidebar
         //ui->TEMP->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
         //ui->OXBLOCK->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
         //ui->PANI->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
         //ui->ECGBLOCK->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
         //ui->DIAS->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
         //ui->SYS->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
         //ui->pres_sis->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white; border:none");
         //ui->pres_sis_label->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white; border:none");
         //ui->pres_sis_label_3->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white; border:none");

         //for the ecg graph
         ui->ecg->change_color_chart(4);
         //ui->ecg_2->change_color_chart(4);


     }
     if(maincolor == "#003e6c"){
         //for the ples graph
         ui->plot->graph(0)->setPen(QPen(Qt::green, 1)); //color and width of the line
         ui->plot->axisRect()->setBackground(QColor(0, 62, 108)); //background of the graph
         ui->plot->xAxis->grid()->setPen(QPen(QColor(0, 62, 108), Qt::SolidLine)); //x axis color
         ui->plot->yAxis->grid()->setPen(QPen(QColor(0, 62, 108), Qt::SolidLine)); //y axis color
         ui->plot->xAxis->setBasePen(QPen(QColor(0, 62, 108)));
         ui->plot->yAxis->setBasePen(QPen(QColor(0, 62, 108)));
         ui->plot->setBackground(QColor(0, 62, 108));
         ui->plot->replot();

         //to change the sidebar
         ui->TEMP->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
         ui->OXBLOCK->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
         ui->PANI->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
         ui->ECGBLOCK->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
         ui->DIAS->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
         ui->SYS->setStyleSheet("background-color: rgba(0, 0, 0, 0);border-style: outset;border-width: 2px;border-color: white;");
         ui->pres_sis->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white; border:none");
         ui->pres_sis_label->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white; border:none");
         ui->pres_sis_label_3->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white; border:none");

         //for the ecg graph
         ui->ecg->change_color_chart(5);
         ui->ecg_2->change_color_chart(5);

     }
}

//derivation window open
void MainWindow::on_derivaciones_pressed(){
    if (deshabilitarTouch == true){
        bandera_2 = false;
        sonidoboton2("/home/pi/Music/sonidos/CLICK.mp3");

        selection = new derivaciones(nullptr, teclado);
        selection->setWindowFlags(Qt::FramelessWindowHint);
        selection->setWindowFlags(Qt::Popup);
        //selection->setGeometry(0,378,721,61);
        selection->setGeometry(0,590,1021,100);//modificacion ADRIAN

        QObject::connect(selection, SIGNAL(der1()), this, SLOT(der1()));
        QObject::connect(selection, SIGNAL(der2()), this, SLOT(der2()));
        QObject::connect(selection, SIGNAL(der3()), this, SLOT(der3()));
        QObject::connect(selection, SIGNAL(der4()), this, SLOT(der4()));
        QObject::connect(selection, SIGNAL(der5()), this, SLOT(der5()));
        QObject::connect(selection, SIGNAL(der6()), this, SLOT(der6()));
        QObject::connect(selection, SIGNAL(der7()), this, SLOT(der7()));
        QObject::connect(selection, SIGNAL(der8()), this, SLOT(der8()));
        QObject::connect(selection, SIGNAL(der9()), this, SLOT(der9()));
        QObject::connect(selection, SIGNAL(der10()), this, SLOT(der10()));
        QObject::connect(selection, SIGNAL(der11()), this, SLOT(der11()));
        QObject::connect(selection, SIGNAL(der12()), this, SLOT(der12()));
        QObject::connect(selection, SIGNAL(sonido_click()), this, SLOT(sonido_click()));
        QObject::connect(selection, SIGNAL(bandera_perilla_4()), this, SLOT(cambiar_bandera()));
        QObject::connect(selection, SIGNAL(habilitar_perilla_4()), this, SLOT(cambiar_bandera()));

        selection->exec();
        show();
    }
}

//the next 12 blocks handdle the signal to write the instruction into the serial port
void MainWindow::der1(){
    serial_ecg_data->write("a\n");
    estatebutton = 0;
}
void MainWindow::der2(){
    serial_ecg_data->write("b\n");
    estatebutton = 1;
}
void MainWindow::der3(){
    serial_ecg_data->write("c\n");
    estatebutton = 2;
}
void MainWindow::der4(){
    serial_ecg_data->write("d\n");
    estatebutton = 3;
}
void MainWindow::der5(){
    serial_ecg_data->write("e\n");
    estatebutton = 4;
}
void MainWindow::der6(){
    serial_ecg_data->write("f\n");
    estatebutton = 5;
}
void MainWindow::der7(){
    serial_ecg_data->write("g\n");
    estatebutton = 6;
}
void MainWindow::der8(){
    serial_ecg_data->write("h\n");
    estatebutton = 7;
}
void MainWindow::der9(){
    serial_ecg_data->write("i\n");
    estatebutton = 8;
}
void MainWindow::der10(){
    serial_ecg_data->write("j\n");
    estatebutton = 9;
}
void MainWindow::der11(){
    serial_ecg_data->write("k\n");
    estatebutton = 10;
}
void MainWindow::der12(){
    serial_ecg_data->write("l\n");
    estatebutton = 11;
}


//show the numeric view
void MainWindow::on_modelo2_pressed(){
      if (deshabilitarTouch == true){
          //cronometro->disconnect();
          bandera_barra_2 = false;
          bandera_2 = false;
          //cronometro->stop();
         //  is_graph_ples_activated = false;
          //serial_ecg->close(); //verificar si este metodo funciona o si es mejor una variable booleana y seguir recibiendo datos
          numerico = new MOD2(nullptr, teclado);
          numerico->recibirBanderaTouch(deshabilitarTouch);
          numerico->setWindowFlags(Qt::FramelessWindowHint);
          sonidoboton2("/home/pi/Music/sonidos/CLICK.mp3");
          QObject::connect(this, SIGNAL(cambiar_estado_bandera_3()), numerico, SLOT(cambiar_bandera_barra()));
          QObject::connect(this, SIGNAL(cambiar_estado_bocina()), numerico, SLOT(estadoBocinaPrincipal()));

          //the next signals is to handle changes in the settings windows when it is oppened from the numeric view
          QObject::connect(numerico, SIGNAL(change_color()), this, SLOT(change_color_once()));
          QObject::connect(numerico, SIGNAL(detection_change()), this, SLOT(detection_toggle()));
          QObject::connect(numerico, SIGNAL(time_save_change(int)), this, SLOT(time_save_change(int)));
          //signals for serial ports, sound and start graphics again
          QObject::connect(numerico, SIGNAL(startpani()), this, SLOT(startpani()));
          QObject::connect(numerico, SIGNAL(stoppani()), this, SLOT(stoppani()));
          QObject::connect(numerico, SIGNAL(sound_change_on()), this, SLOT(sound_toggle()));
          QObject::connect(numerico, SIGNAL(closing_window()), this, SLOT(close_mode2()));

          QObject::connect(numerico, SIGNAL(records_2()), this, SLOT(on_open_records_pressed()));
          QObject::connect(numerico, SIGNAL(paciente_2()), this, SLOT(on_Paciente_pressed()));
          QObject::connect(numerico, SIGNAL(alarmas_2()), this, SLOT(on_alarmas_pressed()));
          QObject::connect(numerico, SIGNAL(iniciarpani_2()), this, SLOT(on_iniciarpani_pressed()));
          QObject::connect(numerico, SIGNAL(ajustes_2()), this, SLOT(on_ajustes_pressed()));
          QObject::connect(numerico, SIGNAL(galeria_2()), this, SLOT(on_galeria_open_pressed()));
          QObject::connect(numerico, SIGNAL(registro_2()), this, SLOT(on_registro_usuario_pressed()));
          QObject::connect(numerico, SIGNAL(time_check_alarms()), this, SLOT(check_alarms_time_to()));
          QObject::connect(numerico, SIGNAL(bandera_perilla_8()), this, SLOT(cambiar_bandera_barra_2()));
          QObject::connect(numerico, SIGNAL( cambioEstadBtnBocina()), this, SLOT(recibeEdoBocinaMod2()));
          //QObject::connect(numerico, SIGNAL((), this, SLOT()))
          numerico->exec();
          show();
      }
}
//check the values for the alarms every 400 ms
void MainWindow::check_alarms_time_to(){
    if(save_alarm_data_bpm > alarma_max_ecg){
        ecg_in = true;
        ecg_out = true;
       //silenciar_alarmas(true, silenciado);
    }
    else{
        if(save_alarm_data_bpm < alarma_min_ecg){
            ecg_in = true;
            ecg_out = true;
         //   silenciar_alarmas(true, silenciado);
        }
        else{
            ecg_in = false;
            ecg_out = false;
           // silenciar_alarmas(false, silenciado);
        }
    }
    silenciar_alarmas(true, silenciado);
}


//signal from numeric view when this closed
void MainWindow::close_mode2(){
    //serial_ecg->open(QIODevice::ReadWrite);
   // cronometro->destroyed();
    //QTimer *cronometro =new QTimer();
   // cronometro->connect(cronometro, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer()));
    cronometro->start(100);
 //   is_graph_ples_activated = true;
}

//signal from numeric view when alarms button is clicked
void MainWindow::sound_toggle(){
    /*if(silenciado){
        //ui->toolButton->setStyleSheet("QToolButton {background-image: url(:/imagenes/nosound.png); background-repeat:none; border:none}");
        ui->toolButton->setChecked(false);
        ui->toolButton->setIcon(QIcon("/imagenes/bocina.png"));
        silenciado = false;
    }
    else{
        //ui->toolButton->setStyleSheet("QToolButton {background-image: url(:/imagenes/sonido.png); background-repeat:none; border:none}");
        ui->toolButton->setChecked(true);
        ui->toolButton->setIcon(QIcon("/imagenes/bocina_OFF.png"));
        silenciado = true;
    }*/

}

//signal from numeric view when button pani is clicked
void MainWindow::startpani(){
    //serial->write("B");
   emit spo2serial->escribe("B");
    ui->iniciarpani->setChecked(true);
    ui->iniciarpani->setIcon(QIcon(":/imagenes/btn_Detener.png"));
    //ui->iniciarpani->setStyleSheet("background-image: url(:/imagenes/detenerpani2.png);background-repeat:none;border: none");
    bandera_pani=true;
    //jeru
    if(timerValvula->isActive()){
        qDebug() << "[PANI] detener timer por reinicio";
        timerValvula->stop();
    }
}

void MainWindow::stoppani(){
    ui->iniciarpani->setChecked(false);
    ui->iniciarpani->setIcon(QIcon(":/imagenes/btn_Iniciar.png"));
    //ui->iniciarpani->setStyleSheet("background-image: url(:/imagenes/inciarpani2.png);background-repeat:none;border: none");
    bandera_pani=false;
    //serial->write("A");
    emit spo2serial->escribe("P");
}

void MainWindow::actualizaEdoBateria(QString dato)
{
    QStringList dato1 = dato.split(",");
    bool cargando = false;
    if (dato1[0] == "B0")
    {
        cargando = false;
    }
    else
    {
        cargando = true;
    }

    if (dato1[1] == "rojo")
    {
        if (cargando == true)
        {
            ui->imgBateria->setPixmap(QPixmap (":/imagenes/bateria25c.png"));

        }
        else
        {
            ui->imgBateria->setPixmap(QPixmap (":/imagenes/bateria25.png"));
        }
    }

    else if (dato1[1] == "naranja")
    {
        if (cargando == true)
        {
            ui->imgBateria->setPixmap(QPixmap (":/imagenes/bateria50c.png"));

        }
        else
        {
            ui->imgBateria->setPixmap(QPixmap (":/imagenes/bateria50.png"));
        }
    }

    else if (dato1[1] == "amarillo")
    {
        if (cargando == true)
        {
            ui->imgBateria->setPixmap(QPixmap (":/imagenes/bateria75c.png"));

        }
        else
        {
            ui->imgBateria->setPixmap(QPixmap (":/imagenes/bateria75.png"));
        }
    }

    else if (dato1[1] == "verde")
    {
        if (cargando == true)
        {
            ui->imgBateria->setPixmap(QPixmap (":/imagenes/bateria100c.png"));

        }
        else
        {
            ui->imgBateria->setPixmap(QPixmap (":/imagenes/bateria100.png"));
        }
    }
}
