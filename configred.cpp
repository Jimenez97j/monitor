#include "configred.h"
#include "ui_configred.h"
#include <QListWidgetItem>

ConfigRed::ConfigRed(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigRed)
{
    ui->setupUi(this);
    ui->wifi->set_Strings("ON", "OFF");
    nombre.append("/opt/monitor_selespo/bin/prueba.sqlite");
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(nombre);
    qDebug()<<"BD" << db.open();
    if(db.open()){
        QSqlQuery crear;
        consulta.append("SELECT ipservidor FROM ajustes");
        crear.prepare(consulta);
        crear.exec();
        crear.next();
        qDebug()<<"RESULTADO" << crear.value(0).toString();
        ui->ipservidor->setText(crear.value(0).toString());
        crear.clear();
    }
    wificontrol = new WifiControl(this);
    timer1 = new QTimer;
    connect(timer1, SIGNAL(timeout()), this, SLOT(actualizaListas()));
    timer1->start(10000);
    revisa_estado();

}


ConfigRed::~ConfigRed()
{
    delete ui;
}

void ConfigRed::on_CERRAR_pressed()
{
    emit sonido_click();
    this->close();
}

void ConfigRed::actualizaListas()
{
    bool edoInterfaz = wificontrol->interface_state(WifiControl::WIFI);
    if (edoInterfaz)
    {
        lista_redesWifi(edoInterfaz);
    }
}

void ConfigRed::revisa_estado()
{
    bool edoInterfaz = wificontrol->interface_state(WifiControl::WIFI);
    if (edoInterfaz)
    {
        ui->wifi->setChecked(true);
        lista_redesWifi(edoInterfaz);
    }
    else
    {
        ui->wifi->setChecked(false);
        limpiaFull();
    }

}

//Click a swicth del wifi
void ConfigRed::on_wifi_clicked()
{
    est = ui->wifi->estaChecked();
    qDebug()<<"est" << est;
    if (est == true)
    {
        /// Cambiar el estado de una interfaz, WIFI o ETH
        qDebug("Entro true");
        wificontrol->set_interface(WifiControl::WIFI, true);
        qDebug("Salio");
        lista_redesWifi(est);
    }
    else
    {
        /// Cambiar el estado de una interfaz, WIFI o ETH
        limpiaFull();
        wificontrol->set_interface(WifiControl::WIFI, false);
    }
}
void ConfigRed::limpiaFull()
{
    ui->listDisponibles->clear();
    ui->listGuardadas->clear();
    ui->editNombre->setText("");
    ui->editContrasena->setText("");
    ui->btn_eliminar->setEnabled(false);
    ui->btn_guardar2->setEnabled(false);
    ui->mensajeTimer->setText("");

}

//Lista las redes wifi disponibles
void ConfigRed::lista_redesWifi(bool estado)
{
    try
    {
        limpiaFull();
        qDebug() << estado;
        if (estado == true)
        {
            qDebug() << "EntroListado";
            //ui->mensajes->setText("");
            /// Obtener una lista de las redes wifi disponibles
            QStringList availableList = wificontrol->get_available_wifi_list();
            for (int i = 0; i<availableList.count(); i++)
            {
                QListWidgetItem *itemd = new QListWidgetItem;
                QStringList r = availableList[i].split(';');
                QString red = r[0];
                QString potencia = r[1];
                itemd ->setText(red);
                if (potencia == "excelente")
                {
                    itemd ->setIcon(QIcon(":/imagenes/img_wifi_100.png"));
                }
                else if (potencia == "buena")
                {
                    itemd ->setIcon(QIcon(":/imagenes/img_wifi_75.png"));
                }
                else if (potencia == "mala")
                {
                    itemd ->setIcon(QIcon(":/imagenes/img_wifi_50.png"));
                }
                else if (potencia == "baja")
                {
                    itemd ->setIcon(QIcon(":/imagenes/img_wifi_25.png"));
                }
                ui->listDisponibles->addItem(itemd);
            }
            /// Obtener la lista de las redes wifi guardadas
            tempSaved = wificontrol->get_saved_wifi_list();
            qDebug() << tempSaved.count();
            for (int i = 0; i<tempSaved.count(); i++)
            {
                ui->listGuardadas->addItem(tempSaved[i]);
            }
        }
    }
    catch(...)
    {

    }
}
//Cuando se le da click a un red disponible
void ConfigRed::on_listDisponibles_itemClicked(QListWidgetItem *item)
{
    ui->accion_red->setText("Agregar red");
    ui->editNombre->setText(item->text());
    tipoRed = 1;
    ui->btn_eliminar->setEnabled(false);
    ui->btn_guardar2->setEnabled(true);
    ui->mensajes->setText("");
    timer1->stop();
}
//Cuando se le da click a una red guardad
void ConfigRed::on_listGuardadas_itemClicked(QListWidgetItem *item)
{
    ui->accion_red->setText("Editar red");
    ui->editNombre->setText(item->text());
    tipoRed = 2;
    ui->btn_eliminar->setEnabled(true);
    ui->btn_guardar2->setEnabled(true);
    ui->mensajes->setText("");
    timer1->stop();
}
//Aparecer teclado cuando se de click en contraseña de la red
void ConfigRed::on_editContrasena_selectionChanged()
{
    teclado = new Teclado;
    teclado->setWindowFlags(Qt::FramelessWindowHint);
    QObject::connect(teclado, SIGNAL(letter_press(QString)), this, SLOT(letter_contrasena(QString)));
    QObject::connect(teclado, SIGNAL(erase_names()), this, SLOT(erase_contrasena()));
    QObject::connect(teclado, SIGNAL(close_keyboard()), this, SLOT(close_keyboard()));
    teclado->setWindowFlags(Qt::Popup);
    teclado->setGeometry(80,450,1121,340);
    teclado->exec();
    show();
}
//Aparecer teclado cuando se de click en Ip servidor central de enfermeras
void ConfigRed::on_ipservidor_selectionChanged()
{
    ui->mensajeTimer->setText("");
    teclado = new Teclado;
    teclado->setWindowFlags(Qt::FramelessWindowHint);
    QObject::connect(teclado, SIGNAL(letter_press(QString)), this, SLOT(letter_servidor(QString)));
    QObject::connect(teclado, SIGNAL(erase_names()), this, SLOT(erase_servidor()));
    QObject::connect(teclado, SIGNAL(close_keyboard()), this, SLOT(close_keyboard()));
    teclado->setWindowFlags(Qt::Popup);
    teclado->setGeometry(80,200,1121,340);
    teclado->exec();
    show();

}
//Borrar ip servidor central de enfermeras
void ConfigRed::erase_servidor(){
     QString actual_text = ui->ipservidor->toPlainText();
     QString resultado = "";
     int longitud = actual_text.length();
     for(int i = 0; i<longitud-1; i++)
     {
         resultado[i] = actual_text[i];
     }
     ui->ipservidor->setText(resultado);
}
//Escribir ip servidor central de enfermeras
void ConfigRed::letter_servidor(QString letter){
    QString actual_text = ui->ipservidor->toPlainText();
    actual_text = actual_text + letter;
    ui->ipservidor->setText(actual_text);
}
//Borrar contraseña de la red
void ConfigRed::erase_contrasena(){
     QString actual_text = ui->editContrasena->toPlainText();
     QString resultado = "";
     int longitud = actual_text.length();
     for(int i = 0; i<longitud-1; i++)
     {
         resultado[i] = actual_text[i];
     }
     ui->editContrasena->setText(resultado);
}
//Escribir contraseña de la red
void ConfigRed::letter_contrasena(QString letter){
    QString actual_text = ui->editContrasena->toPlainText();
    actual_text = actual_text + letter;
    ui->editContrasena->setText(actual_text);
}
//Guarda la red wifi
void ConfigRed::on_btn_guardar2_clicked()
{
    if (tipoRed == 1)/// Agregar una red wifi
    {
        QString nom_red = ui->editNombre->toPlainText();
        QString redg = "";
        for (int i = 0; i<tempSaved.count(); i++)
        {
            if (tempSaved[i] != nom_red)
            {
                redg ="";
            }
            else
            {
                redg = tempSaved[i];
                ui->mensajes->setText("La red Wifi ya se encuentra guardada");
                qDebug("YA ESTA GUARDADA");
                revisa_estado();
            }
        }
        QString contra_red = ui->editContrasena->toPlainText();
        if (contra_red.count()> 0 and redg.count() <= 0)
        {
            qDebug("ENTRO A NO ESTA GUARDADA");

            wificontrol->add_wifi(nom_red, contra_red);
            ui->mensajes->setText("La red Wifi se guardo correctamente");
            revisa_estado();
        }
    }
    else if (tipoRed == 2)// Modificar una red wifi
    {
        QString nom_red = ui->editNombre->toPlainText();
        QString contra_red = ui->editContrasena->toPlainText();
        bool ch = wificontrol->change_wifi_pass(nom_red, contra_red);
        if (ch == true)
        {
            ui->mensajes->setText("Red Wifi modificada correctamente");
            revisa_estado();
        }
        else
        {
            ui->mensajes->setText("La red Wifi no se modifico, intente nuevamente");
            revisa_estado();
        }
    }
    timer1->start();
}
//Elimina la red wifi
void ConfigRed::on_btn_eliminar_clicked()
{
    if (tipoRed ==2)
    {
        //Borrar una red wifi

        QString nom_red = ui->editNombre->toPlainText();
        bool del = wificontrol->delete_wifi(nom_red);
        if (del == true)
        {
            ui->mensajes->setText("Red Wifi eliminada correctamente");
            ui->btn_eliminar->setEnabled(false);
            revisa_estado();
        }
        else
        {
            ui->mensajes->setText("La red Wifi no se elimino, intente nuevamente");
            ui->btn_eliminar->setEnabled(false);
            revisa_estado();
        }
        timer1->start();

    }

}

void ConfigRed::on_btn_guardar2_pressed()
{
    if (tipoRed ==1)
    {
        ui->mensajeTimer->setText("Guardando red wifi, espero un momento. . .");
    }
    else
    {
        ui->mensajeTimer->setText("Modificando red wifi, espero un momento. . .");

    }
}

void ConfigRed::on_btn_eliminar_pressed()
{
    if (tipoRed ==2)
    {
        ui->mensajeTimer->setText("Eliminando red wifi, espero un momento. . .");
    }
}

void ConfigRed::on_btn_guardar_clicked()
{
    QString consultas;
    QSqlQuery crear;
    QString ip = ui->ipservidor->toPlainText();
    if(ip.length() >= 7)
    {
        consultas.append("UPDATE ajustes SET ipservidor = '" + ip + "'");
        crear.prepare(consultas);
        crear.exec();
        consultas.clear();
        consultas.append("SELECT ipservidor FROM ajustes");
        crear.prepare(consultas);
        crear.exec();
        crear.next();
        qDebug()<<"RESULTADO" << crear.value(0).toString();
        ui->ipservidor->setText(crear.value(0).toString());
        crear.clear();
    }
    else
    {
        ui->mensajeTimer->setText("Escriba una dirección valida");
    }
}
