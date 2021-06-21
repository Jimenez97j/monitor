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
int hora_captura=0, puntos=0 , numeros_ecg=0, numeros_spo2 = 0, numeros_temp = 0; //Resetea timers para Captura de Pantalla, "Realizando analisis" y cambio de color en números
int reg_save_data = 0; //flag for confirmation label of ss and flag for save data into a data base
bool reg_save_data_activated = true,  cambio_numeros=false,cambio_numeros2=false,cambio_numeros3=false;//flag to start getting data into a data base
QTimer *cronometro = new QTimer();
bool jsonrecibido = false;
QTimer *spo2_refresh_chart = new QTimer();
int registro_firebase = 0;
QString *arrdata_to_send;
int contpos = 0;
bool bandera_2= true;
bool bandera_barra_2= true;
bool bandera_click = true;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //cambios serial
    //pequeña modificacion
    ui->ecg->iniciar_serial();
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

                if(x.name() == "")
                    WiFisList << "Unknown(Other Network)";
                else
                    WiFisList << x.name();
                ui->comboBox->addItem(x.name());

                qDebug() << x.type();

        }*/
    //name of the data base for this proyect
    QString nombre;
    nombre.append("/opt/monitor_selespo2/bin/prueba.sqlite");
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
    //ui->ecg_2->change_square_ecg(maincolor);

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
     //ui->ecg_2->change_color_chart(1);
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
     //ui->ecg_2->change_color_chart(2);
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
     //ui->ecg_2->change_color_chart(3);
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

     ui->ecg->change_color_chart(5);
     //ui->ecg_2->change_color_chart(5);
     //for the ecg graph
    //graficar->change_color_chart(5);
 }
 //this->show();

//+++++++++++++++++++++++++++++++++++++ SERIAL PORT SPO2 +++++++++++++++++++++++++++++++++++

    spo2serial = new SerialSpo2();
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
   connect(spo2serial, SIGNAL(boton_ajustes(QString)), this, SLOT(boton_ajustes2(QString)), Qt::QueuedConnection);
//+++++++++++++++++++++++++++++++++++++ SERIAL PORT ECG(DATOS) +++++++++++++++++++++++++++++++++++

    serial_ecg_data= new QSerialPort(); // Serial port for bpm, rpm
    serial_ecg_data->setPortName("DATOSECG");
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
    m_client->setHostname("192.168.1.248");
    m_client->setPort(1883);
    connect(m_client, &QMqttClient::stateChanged, this, &MainWindow::updateLogStateChange);
    connect(m_client, &QMqttClient::disconnected, this, &MainWindow::brokerDisconnected);
    connect(m_client, &QMqttClient::connected, this, &MainWindow::brokerConnected);
    connect(m_client, &QMqttClient::messageReceived, this, [this](const QByteArray &message, const QMqttTopicName &topic) {

    //this block works on,ly if detection is activated
        qDebug()<<message;
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

    //qDebug("btn_Bocina");

}

void MainWindow::boton_ajustes2(QString h)
{
    if (bandera_2 == true){
    qDebug()<< "llegando";
    if (h == "derecha"){
    contpos = contpos + 1;
    if(contpos > 10){
        contpos = 10;
    }
    opciones();
    }

    else if(h == "izquierda"){
        contpos = contpos - 1;
        if(contpos < 0){
            contpos = 0;
        }
        opciones();
    }

    else if(h == "click"){
        on_ok_clicked();
    }
    }
}

void MainWindow:: on_Derecha_clicked(){
    contpos = contpos + 1;
    if(contpos > 10){
        contpos = 10;
    }
}

void MainWindow:: on_Izquierda_clicked(){
    contpos = contpos - 1;
    if (contpos < 0){
        contpos = 0;
    }

}

void MainWindow:: on_ok_clicked(){

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
        on_toolButton_pressed();
        break;
    case 10:
        on_ajustes_pressed();
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

void MainWindow::cambiar_bandera_2(){
    bandera_2 = true;
}

void MainWindow::cambiar_bandera_3(){
    bandera_2 = true;
}

void MainWindow::cambiar_bandera_4(){
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
}

void MainWindow::panivalues(QString s, QString d, QString m){

//*****************************Systolic*******************************************************
    ps_save_reg = s; //value to save into database
    ui->pres_sis->setText(s);
    sys_mod2 = s;

//*****************************Dystolic**************************************************
    px_save_reg = d; //value to save into database
    ui->pres_sis_2->setText(d);
    dia_mod2 = d;
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

}

void MainWindow::updatetemperature(QString temperature, double saving_temperature_number){

    ui->temp->setText(temperature);
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
}

void MainWindow::not_data(){
    sop2_mod2 = "not";
    ui->bpmsp2_2->setText("<font color='red' size='.3'>Coloque \r\n dedo</font>");
    ui->bpmsp2_2->setGeometry(95,30,51,31);
    savespo2 = 0;
    ui->SPO2->setText("00");
    ui->SPO2->setText("00");
    ui->SPO2->setGeometry(10,10,111,51);
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
    cronometro->start(1);
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
    const QString topic = "ecg";
    auto subscription = m_client->subscribe(topic);
    if (!subscription)
    {
        return;
    }
    qDebug()<<"holi";
}

void MainWindow::brokerDisconnected()
{

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

void MainWindow::sonidoboton2(QString audio)
{
    //QProcess::execute("omxplayer -o local "+ audio + " &");
    QString comando, sound;
    if(silenciado){
       comando = "omxplayer --vol -1500 -o local "+ audio + " &";
    }
    else{
        comando = "omxplayer --vol -10000 -o local "+ audio + " &";
    }
    int estado = system(comando.toStdString().c_str());
    //int def = system(sound.toStdString().c_str());
     if(estado == -1) {
         qDebug()<<"Error sonidoboton2";
     } else {
         qDebug()<<"Reproduciendo";
     }

}

void MainWindow::on_screenshot_pressed(){

    sonidoboton2("/home/pi/Music/sonidos/CAMARA.mp3");
    QScreen *QSCREEN = QGuiApplication::primaryScreen();
    QPixmap qpix = QSCREEN->grabWindow(this->winId(), 0, 0, QApplication::desktop()->width(),
                                       QApplication::desktop()->height());
    qpix.save("./imagenes/"+aux+".png");
    ui->label_6->setText("<font color='#08afff'>Se ha tomado una captura de pantalla</font>");

    hora_captura=0;
}
void MainWindow::on_toolButton_2_clicked(){
    qDebug("ON TOOL BUTTON");
    enviardatosw = new enviardatos;
    enviardatosw->setWindowFlags(Qt::FramelessWindowHint);
    enviardatosw->setWindowFlags(Qt::Popup);
    QObject::connect(enviardatosw, SIGNAL(sonido_click()), this, SLOT(sonido_click()));
    QObject::connect(enviardatosw, SIGNAL(send_data(int)), this, SLOT(enviar_datos(int)));
    //enviardatosw->setGeometry(87, 10, 510, 70);
    enviardatosw->setGeometry(0, 10, 602, 110);
    enviardatosw->exec();
    show();
}
void MainWindow::on_iniciar_pressed(){

    sonidoboton2("/home/pi/Music/sonidos/CLICK.mp3");
    indicadoranalisis = 1;
    //serial->write("Z");
     emit spo2serial->escribe("Z");
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
    sonidoboton2("/home/pi/Music/sonidos/CLICK.mp3");
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
        emit spo2serial->escribe("U");
        //ui->iniciarpani->setStyleSheet("border-image: url(:/imagenes/inciarpani2.png);background-repeat:none;border: none");
        ui->iniciarpani->setChecked(false);
        ui->iniciarpani->setIcon(QIcon(":/imagenes/btn_Iniciar.png"));
        bandera_pani=false;
        cadena3[0] = 'E'; //Al detener manualmente la medicion se manda "E" para lanzar activar label ERROR en medición
    }
}

void MainWindow::on_open_records_pressed(){
    sonidoboton2("/home/pi/Music/sonidos/CLICK.mp3");
    records = new alarmas;
    records->setWindowFlags(Qt::FramelessWindowHint);
    QObject::connect(records, SIGNAL(sonido_click()), this, SLOT(sonido_click()));
    records->exec();
    show();
}


void MainWindow::on_Paciente_pressed(){
    bandera_2 = false;
    sonidoboton2("/home/pi/Music/sonidos/CLICK.mp3");
    paciente = new Paciente(this, spo2serial);
    paciente->setWindowFlags(Qt::FramelessWindowHint);
    paciente->setWindowFlags(Qt::Popup);
    paciente->setGeometry(701, 105, 340, 588);
    QObject::connect(paciente, SIGNAL(sonido_click()), this, SLOT(sonido_click()));
    QObject::connect(paciente, SIGNAL(bandera_perilla_7()), this, SLOT(cambiar_bandera_2()));
    paciente->exec();
    show();
}

void MainWindow::on_registro_usuario_pressed(){
     bandera_2 = false;
    sonidoboton2("/home/pi/Music/sonidos/CLICK.mp3");
    registros = new Registro(this, spo2serial);
    registros->setWindowFlags(Qt::FramelessWindowHint);
    QObject::connect(registros, SIGNAL(sonido_click()), this, SLOT(sonido_click()));
    QObject::connect(registros, SIGNAL(bandera_perilla_6()), this, SLOT(cambiar_bandera()));
    registros->exec();
    show();
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
    bandera_2 = false;
    sonidoboton2("/home/pi/Music/sonidos/CLICK.mp3");
    alarma = new config_alarmas(this, spo2serial);
    alarma->setWindowFlags(Qt::FramelessWindowHint);
    QObject::connect(alarma, SIGNAL(sonido_click()), this, SLOT(sonido_click()));
    QObject::connect(alarma, SIGNAL(alarms_change()), this, SLOT(alarms_change()));
    QObject::connect(alarma, SIGNAL(bandera_perilla_3()), this, SLOT(cambiar_bandera_3()));
    alarma->exec();
    show();
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

    //Animación de puntos en label "Realizando Analisis..."
    if(puntos==1000 && banderapuntos){
        ui->analisis->setText("Realizando Analisis");
    }
    if(puntos==2000 && banderapuntos){
        ui->analisis->setText("Realizando Analisis.");
    }
    if(puntos==3000 && banderapuntos){
        ui->analisis->setText("Realizando Analisis..");
    }
    if(puntos==4000 && banderapuntos){
        ui->analisis->setText("Realizando Analisis...");
        puntos=0;
    }

    //return to blank the label that appers when takes a screenshot
    if(hora_captura>2000){
        ui->label_6->setText("");
         hora_captura=0;
    }
    if(check_bpm_value_time == 800){
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
             //   silenciar_alarmas(true, silenciado);
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
   if(pantalla>8300){
       ui->label_5->setText("");
        pantalla=0;
        spo2serial->bpm_flag_update();
   }

   //this blocks are for bliding the numbers when alarms are activated
   if(numeros_ecg==500){
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
   if(numeros_spo2==500){
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
   if(numeros_temp == 500){
       if(cambio_numeros3 && activated3){
           QLabel *label3=ui->temp;
           QString color="color:#003e56;border:none";
           alarmasnumeros(label3,color);
           cambio_numeros3=false;
           numeros_temp=0;
       }
       else{
           QLabel *label3=ui->temp;
           QString color="color:#1b50ff;border:none ";
           alarmasnumeros(label3,color);
           cambio_numeros3=true;
           numeros_temp=0;
       }
   }
}

//show galery window
void MainWindow::on_galeria_open_pressed(){
    bandera_2 = false;
    sonidoboton2("/home/pi/Music/sonidos/CLICK.mp3");
    galeria1 = new galeria(0, spo2serial);
    galeria1->setWindowFlags(Qt::FramelessWindowHint);
    QObject::connect(galeria1, SIGNAL(sonido_click()), this, SLOT(sonido_click()));
    QObject::connect(galeria1, SIGNAL(sonido_basura()), this, SLOT(sonido_basura()));
    QObject::connect(galeria1, SIGNAL(bandera_perilla_2()), this, SLOT(cambiar_bandera_2()));
    galeria1->exec();
    show();


}

//show settings window
void MainWindow::on_ajustes_pressed(){
    sonidoboton2("/home/pi/Music/sonidos/CLICK.mp3");
    settings = new ajustes;
    settings->setWindowFlags(Qt::FramelessWindowHint);
    QObject::connect(settings, SIGNAL(change_color_click()), this, SLOT(change_color_once()));
    QObject::connect(settings, SIGNAL(detection_change()), this, SLOT(detection_toggle()));
    QObject::connect(settings, SIGNAL(time_save_change(int)), this, SLOT(time_save_change(int)));
    QObject::connect(settings, SIGNAL(sonido_click()), this, SLOT(sonido_click()));
    settings->exec();
    show();
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
        //ui->ecg_2->change_square_ecg(maincolor);
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
         //ui->ecg_2->change_color_chart(1);

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
         //ui->ecg_2->change_color_chart(2);

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
         //ui->ecg_2->change_color_chart(3);


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
         //ui->ecg_2->change_color_chart(5);

     }
}

//derivation window open
void MainWindow::on_derivaciones_pressed(){
    bandera_2 = false;
    sonidoboton2("/home/pi/Music/sonidos/CLICK.mp3");

    selection = new derivaciones(this, spo2serial);
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
    QObject::connect(selection, SIGNAL(bandera_perilla_4()), this, SLOT(cambiar_bandera_4()));

    selection->exec();
    show();
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
      //cronometro->disconnect();
      bandera_barra_2 = false;
      bandera_2 = false;
      cronometro->stop();
     //  is_graph_ples_activated = false;
      //serial_ecg->close(); //verificar si este metodo funciona o si es mejor una variable booleana y seguir recibiendo datos
      numerico = new MOD2(0, spo2serial);
      numerico->setWindowFlags(Qt::FramelessWindowHint);
      sonidoboton2("/home/pi/Music/sonidos/CLICK.mp3");

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
      //QObject::connect(numerico, SIGNAL((), this, SLOT()))
      numerico->exec();
      show();
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
    cronometro->start(1);
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
}

void MainWindow::stoppani(){
    ui->iniciarpani->setChecked(false);
    ui->iniciarpani->setIcon(QIcon(":/imagenes/btn_Iniciar.png"));
    //ui->iniciarpani->setStyleSheet("background-image: url(:/imagenes/inciarpani2.png);background-repeat:none;border: none");
    bandera_pani=false;
    //serial->write("A");
    emit spo2serial->escribe("U");
}


