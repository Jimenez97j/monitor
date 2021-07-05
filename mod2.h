#ifndef MOD2_H
#define MOD2_H

#include <QDialog>
#include <alarmas.h>
#include <QDateTime>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <galeria.h>
#include <config_alarmas.h>
#include <ajustes.h>
#include <derivaciones.h>
#include <registro.h>
#include <paciente.h>
#include <QLabel>
#include <enviardatos.h>
#include <serialspo2.h>

namespace Ui {
class MOD2;
}
class QMediaPlayer;

class MOD2 : public QDialog
{
    Q_OBJECT
signals:
    void records_2();
    void paciente_2();
    void registro_2();
    void alarmas_2();
    void ajustes_2();
    void galeria_2();
    void iniciarpani_2();
    void time_check_alarms();


public:
    explicit MOD2(QWidget *parent = nullptr, SerialSpo2 *serialspo2_modelo_2 = NULL );
    ~MOD2();
    QString* labels();
    void sonido_toggle(bool toggle);
    bool sonido_get_status();
    bool* alarm_status();
    bool get_pani_status();
    void alarmasnumeros(QLabel *label,QString color);
    void changebackground(QString color);
    void recibirBanderaTouch(bool);
    void deshabilitaTouch();



    QString getcolor();

public slots:
    void alarm_status_change();
    void change_color_mod2();
private slots:
    void detection_toggle_once();
    void time_save_change_once(int x);
    void on_registros_pressed();
    void on_close_pressed();
    void funcionActivacionTimer();
    void on_galeria_pressed();
    void on_alarmas_pressed();
    void on_ajustes_pressed();
    void on_sound_pressed();
    void on_captura_pressed();
    void on_internet_clicked();
    void on_registro_pressed();
    void on_paciente_pressed();
    void on_pani_pressed();
    void boton_handle_8(QString y);
    void opciones_mod2();
    void on_okay_clicked();
    void cambiar_bandera_barra();
    void estadoBocinaPrincipal();


signals:
    void change_color();
    void detection_change();
    void time_save_change(int);
    void startpani();
    void sound_change_on();
    void closing_window();
    void stoppani();
    void bandera_perilla_8();
    void cambioEstadBtnBocina();

private:
    Ui::MOD2 *ui;
    QSqlDatabase db;
    ajustes* settings;
    enviardatos* envdat;
    SerialSpo2 *spo2serial_8;
    bool  banderaEdoTouch;
};

#endif // MOD2_H
