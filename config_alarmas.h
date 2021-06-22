#ifndef CONFIG_ALARMAS_H
#define CONFIG_ALARMAS_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <serialspo2.h>

namespace Ui {
class config_alarmas;
}

class config_alarmas : public QDialog
{
    Q_OBJECT

public:
    explicit config_alarmas(QWidget *parent = 0, SerialSpo2 *serialspo2_ajustes = NULL );
    ~config_alarmas();

signals:
    void sonido_click();
    void alarms_change();
    void habilitar_barra_desde_alarmas();

private slots:
    void on_menos_min_ecg_pressed();
    void on_mas_min_ecg_pressed();
    void on_menos_max_ecg_pressed();
    void on_menos_min_spo2_pressed();
    void on_mas_max_ecg_pressed();
    void on_mas_min_spo2_pressed();
    void on_menos_min_rpm_pressed();
    void on_mas_min_rpm_pressed();
    void on_menos_max_rpm_pressed();
    void on_mas_max_rpm_pressed();
    void on_menos_max_spo2_pressed();
    void on_mas_max_spo2_pressed();
    void on_CERRAR_pressed();
    void on_OK_pressed();
    void boton_handle_4(QString y);
    void opciones_alarmas();
    void on_oka_clicked();

private:
    Ui::config_alarmas *ui;
    QSqlDatabase db;
    SerialSpo2 *spo2serial_4;

};

#endif // CONFIG_ALARMAS_H
