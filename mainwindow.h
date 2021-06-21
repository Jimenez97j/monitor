#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtMqtt/qmqttclient.h>
#include <alarmas.h>
#include <config_alarmas.h>
#include <galeria.h>
#include <derivaciones.h>
#include <ajustes.h>
#include <registro.h>
#include <paciente.h>
#include <pantallacarga.h>
#include <enviardatos.h>
#include <error.h>
#include <QLabel>
#include <mod2.h>
#include <ecghandle.h>
#include <serialspo2.h>
#include <QNetworkReply>
#include <QNetworkConfiguration>
#include <QNetworkConfigurationManager>
#include <QNetworkSession>




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int foundCount;
        QNetworkConfiguration netcfg;
        QStringList WiFisList;
        QList<QNetworkConfiguration> netcfgList;

    QString* retornar_valores();
    bool inital_check_ophyra();
    void get_alarms_value();
    void silenciar_alarmas(bool valor, bool boton);
    void addPoint_ECG(double x, double y) ;
    void addPoint_rpm(double x, double y);
    void fecha_hora();
    void plot_rpm() ;
    void save_data_db();
    void selectder();
    void alarmasnumeros(QLabel *label,QString color);
    void alarmasonido(bool boton, bool activado);
    void leds_inicio();
    void sonidoboton2(QString audio);
    void active_timer_for_alarms(bool state);
  //  void RecibirArreglo_ECG();
public slots:
    void alarm_sound();
    void check_alarms_time_to();
    void startpani();
    void leds_inicio_carga();
    void leds_inicio_okey();
    void leds_inicio_apagar();
    void change_color_once();
    void detection_toggle();
    void sound_toggle();
    void der1();
    void der2();
    void der3();
    void der4();
    void der5();
    void der6();
    void der7();
    void der8();
    void der9();
    void der10();
    void der11();
    void der12();
    void close_mode2();
    void stoppani();
    void time_save_change(int x);
    void sonido_click();
    void sonido_basura();
    void puerto_carga_inicial();
    void alarms_change();
    void not_data();
    void bpm_count_spo2(QString);
    void cuadronegro_spo2(int);
    void porcentualspo2(QString);
    void updatetemperature(QString, double);
    void panivalues(QString, QString, QString);
    void errorpani();
    void plot_spo2(QVector<double>, QVector<double>, int, double, double, double);
    void networkReadyRead();
    void enviar_datos(int);
signals:
    void networkReplyReadyRead();
    void cambiar_estado_bandera_3();
private slots:
    void boton_ajustes2(QString h);
    void funcionActivacionTimer();
    void RecibirArreglo(int caso);
    void RecibirArreglo_ECG_numerico();
    //Cambio MQTT
    void updateLogStateChange();
    void brokerDisconnected();
    void brokerConnected();
    //++++++++++++++++++++++++++++++++
    void on_derivaciones_pressed();
    void on_toolButton_pressed();
    void on_modelo2_pressed();
    void on_galeria_open_pressed();
    void on_ajustes_pressed();
    void on_screenshot_pressed();
    void on_iniciar_pressed();
    void on_iniciarpani_pressed();
    void on_open_records_pressed();
    void on_Paciente_pressed();
    void on_registro_usuario_pressed();
    void on_alarmas_pressed();
    void on_cerrar_pressed();

    void on_MainWindow_destroyed();


    void on_toolButton_2_clicked();
    void on_Derecha_clicked();
    void opciones();

    void on_Izquierda_clicked();

    void on_ok_clicked();
    void cambiar_bandera();
    void cambiar_bandera_2();
    void cambiar_bandera_3();
    void cambiar_bandera_4();
private:
    QNetworkSession *session;
    QNetworkAccessManager * m_networkManager;
    QNetworkReply * m_networkReply;
    Ui::MainWindow *ui;
    //Cambio MQTT
    QMqttClient *m_client;
    QSerialPort *serial, *serial_ecg_data, *serial_alarmas;
    QString cadena="", cadena2="", cadena3="";
    int length, lenght2, lenght3;
    QVector<double> qv_x_rpm, qv_y_rpm;
    QSqlDatabase db;
    MOD2* numerico;
    ajustes* settings;
    PantallaCarga* leds;
    derivaciones* selection;
    alarmas* records;
    config_alarmas* alarma;
    galeria* galeria1;
    Registro* registros;
    enviardatos* enviardatosw;
    Paciente* paciente;
    ecghandle* graficar;
    SerialSpo2 *spo2serial, *teclado;

};
#endif // MAINWINDOW_H
