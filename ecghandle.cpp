#include "ecghandle.h"
#include "ui_ecghandle.h"
#include <serialthread.h>
#include <QDebug>
#include <QTimer>

//variables for ECG graph
QTimer *cronometro_ecg =new QTimer();


ecghandle::ecghandle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ecghandle)
{
    ///local_serial = new SerialThread();
    ///connect(local_serial, SIGNAL(receive_data(QVector<double>, QVector<double>, int, double, double, double)), this, SLOT(plot_ECG(QVector<double>, QVector<double>, int, double, double, double)), Qt::QueuedConnection);
   // local_serial->comenzar();
    ui->setupUi(this);
    //++++++++++++++++++++++++++++++++++++++++++++++ PLOT ECG ++++++++++++++++++++++++++++++++++++++++

    ui->plot_ecg->addGraph();
    ui->plot_ecg->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssNone,0));
    ui->plot_ecg->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->plot_ecg->graph(0)->setPen(QPen(Qt::red, 1));
    ui->plot_ecg->axisRect()->setBackground(Qt::black);
    ui->plot_ecg->xAxis->grid()->setPen(QPen(Qt::black, Qt::SolidLine));
    ui->plot_ecg->yAxis->grid()->setPen(QPen(Qt::black, Qt::SolidLine));
    //ui->plot_ecg->setBackground(Qt::red);
    ui->plot_ecg->graph(0)->rescaleAxes(true);
    ui->plot_ecg->xAxis->setTicks(false);  //
    ui->plot_ecg->yAxis->setTicks(false);
    //nueva grafica
    //prueba ssh
    ///ui->plot_ecg->addGraph();
    ///ui->plot_ecg->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssNone,0));
    ///ui->plot_ecg->graph(1)->setLineStyle(QCPGraph::lsLine);
    ///ui->plot_ecg->graph(1)->setPen(QPen(Qt::red, 1));
    ///ui->plot_ecg->graph(1)->rescaleAxes(true);

    //serial name
    serial_name = "";

    connect(cronometro_ecg, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer()));
    cronometro_ecg->start(45);
}

void ecghandle::set_serial_name(QString name){
    serial_name = name;
}

ecghandle::~ecghandle()
{
    delete ui;
}

void ecghandle::iniciar_serial(){
    local_serial = new SerialThread();
    //local_serial->set_name(serial_name);
    connect(local_serial, SIGNAL(receive_data(QVector<double>, QVector<double>, int, double, double, double)), this, SLOT(plot_ECG(QVector<double>, QVector<double>, int, double, double, double)), Qt::QueuedConnection);
    //local_serial->iniciar();
    //connect(local_serial, SIGNAL(receive_data_2(QVector<double>, QVector<double>, int, double, double, double)), this, SLOT(plot_ECG_2(QVector<double>, QVector<double>, int, double, double, double)), Qt::QueuedConnection);
    //cronometro_ecg->start(45);
}

void ecghandle::funcionActivacionTimer(){


   ui->plot_ecg->replot(); //se vuelven a dibujar los valores
   ui->plot_ecg->update(); // se actualiza la gráfica
}

void ecghandle::plot_ECG(QVector<double> x , QVector<double> y , int square, double max, double minrangeLine, double maxrangeLine){  //función requerida para gráficar
   //qDebug() << "plot_ECG";
    ui->borrargraph_ecg->setGeometry(square, 8, 23, 151); //a rectange is moved as the system create the graph
   //ui->plot_ecg->yAxis->rescale(true);
   ui->plot_ecg->yAxis->setRange(minrangeLine, maxrangeLine);  //Reescale the Y axis if it is necessary
   ui->plot_ecg->xAxis->setRange(0,max); //Reescale the X axis if it is necessary
   ui->plot_ecg->graph(0)->setData(x,y);

   //datos_grafica_max_ECG=datos_grafica_max_ECG+1;
   //upset_ECG=upset_ECG+0.7;

}

void ecghandle::plot_ECG_2(QVector<double> x , QVector<double> y , int square, double max, double minrangeLine, double maxrangeLine){  //función requerida para gráficar
    //qDebug() << "plot_ECG_2";
    //emit compartir_dato(x,y,square, max, minrangeLine,maxrangeLine);
   ///ui->borrargraph_ecg_2->setGeometry(square, 8, 23, 151); //a rectange is moved as the system create the graph
   //ui->plot_ecg->yAxis->rescale(true);
   ///ui->plot_ecg->yAxis->setRange(minrangeLine, maxrangeLine);  //Reescale the Y axis if it is necessary
   ///ui->plot_ecg->xAxis->setRange(0,max); //Reescale the X axis if it is necessary
   ui->plot_ecg->graph(1)->setData(x,y);

}

void ecghandle::change_square_ecg(QString color_square){
    ui->borrargraph_ecg->setStyleSheet("backgroung-color:"+color_square);
}

void ecghandle::change_color_chart(int what_style){

    if(what_style == 1){
        ui->plot_ecg->graph(0)->setPen(QPen(Qt::white, 1)); //color and width of the line
        //ui->plot_ecg->graph(1)->setPen(QPen(Qt::white, 1));
        ui->plot_ecg->axisRect()->setBackground(QColor(50, 109, 114)); //background of the graph
        ui->plot_ecg->xAxis->grid()->setPen(QPen(QColor(50, 109, 114), Qt::SolidLine)); //x axis color
        ui->plot_ecg->yAxis->grid()->setPen(QPen(QColor(50, 109, 114), Qt::SolidLine)); //y axis color
        ui->plot_ecg->xAxis->setBasePen(QPen(QColor(50, 109, 114)));
        ui->plot_ecg->yAxis->setBasePen(QPen(QColor(50, 109, 114)));
        ui->plot_ecg->setBackground(QColor(50, 109, 114));
    }
    if(what_style == 2){
         ui->plot_ecg->graph(0)->setPen(QPen(Qt::white, 1)); //color and width of the line
         //ui->plot_ecg->graph(1)->setPen(QPen(Qt::white, 1));
         ui->plot_ecg->axisRect()->setBackground(QColor(32, 33, 79)); //background of the graph
         ui->plot_ecg->xAxis->grid()->setPen(QPen(QColor(32, 33, 79), Qt::SolidLine)); //x axis color
         ui->plot_ecg->yAxis->grid()->setPen(QPen(QColor(32, 33, 79), Qt::SolidLine)); //y axis color
         ui->plot_ecg->xAxis->setBasePen(QPen(QColor(32, 33, 79)));
         ui->plot_ecg->yAxis->setBasePen(QPen(QColor(32, 33, 79)));
         ui->plot_ecg->setBackground(QColor(32, 33, 79));
         qDebug()<<"hi2";
    }
    if(what_style == 3){
         ui->plot_ecg->graph(0)->setPen(QPen(Qt::black, 1)); //color and width of the line
         //ui->plot_ecg->graph(1)->setPen(QPen(Qt::black, 1));
         ui->plot_ecg->axisRect()->setBackground(QColor(255, 255, 255)); //background of the graph
         ui->plot_ecg->xAxis->grid()->setPen(QPen(QColor(255, 255, 255), Qt::SolidLine)); //x axis color
         ui->plot_ecg->yAxis->grid()->setPen(QPen(QColor(255, 255, 255), Qt::SolidLine)); //y axis color
         ui->plot_ecg->xAxis->setBasePen(QPen(QColor(255, 255, 255)));
         ui->plot_ecg->yAxis->setBasePen(QPen(QColor(255, 255, 255)));
         ui->plot_ecg->setBackground(QColor(255, 255, 255));
       qDebug()<<"hi3";
    }
    if(what_style == 4){
           ui->plot_ecg->graph(0)->setPen(QPen(Qt::red, 1)); //color and width of the line
           //ui->plot_ecg->graph(1)->setPen(QPen(Qt::red, 1));
           ui->plot_ecg->axisRect()->setBackground(QColor(0, 0, 0)); //background of the graph
           ui->plot_ecg->xAxis->grid()->setPen(QPen(QColor(0, 0, 0), Qt::SolidLine)); //x axis color
           ui->plot_ecg->yAxis->grid()->setPen(QPen(QColor(0, 0, 0), Qt::SolidLine)); //y axis color
           ui->plot_ecg->xAxis->setBasePen(QPen(QColor(0, 0, 0)));
           ui->plot_ecg->yAxis->setBasePen(QPen(QColor(0, 0, 0)));
           ui->plot_ecg->setBackground(QColor(0, 0, 0));
       qDebug()<<"hi4";
    }
    if(what_style == 5){
         ui->plot_ecg->graph(0)->setPen(QPen(Qt::red, 1)); //color and width of the line
         //ui->plot_ecg->graph(1)->setPen(QPen(Qt::red, 1));
         ui->plot_ecg->axisRect()->setBackground(QColor(0, 62, 108)); //background of the graph
         ui->plot_ecg->xAxis->grid()->setPen(QPen(QColor(0, 62, 108), Qt::SolidLine)); //x axis color
         ui->plot_ecg->yAxis->grid()->setPen(QPen(QColor(0, 62, 108), Qt::SolidLine)); //y axis color
         ui->plot_ecg->xAxis->setBasePen(QPen(QColor(0, 62, 108)));
         ui->plot_ecg->yAxis->setBasePen(QPen(QColor(0, 62, 108)));
         ui->plot_ecg->setBackground(QColor(0, 62, 108));
       qDebug()<<"hi5";
    }
    ui->plot_ecg->update();
    ui->plot_ecg->replot();
}




