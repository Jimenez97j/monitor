#ifndef AJUSTES_H
#define AJUSTES_H

#include <QDialog>
#include <serialspo2.h>
#include <guiausuario.h>

namespace Ui {
class ajustes;
}

class ajustes : public QDialog
{
    Q_OBJECT

public:
    explicit ajustes(QWidget *parent = 0, SerialSpo2 *serialspo2_ajustes = NULL);
    void cleanAll();
    void detection_mode(bool state_mode);
    QString detection_status();
    ~ajustes();
signals:
    void change_color_click();
    void detection_change();
    void time_save_change(int x);
    void sonido_click();
    void bandera_perilla();
private slots:
    void on_cleanAll_pressed();
    void changebackground(QString color);
    void on_comboBox_currentIndexChanged(int index);
    void on_toolButton_pressed();
    void on_checkBox_toggled(bool checked);
    QString getajustes();
    QString gettime();
    void on_Guia_Usu_pressed();
    void boton_handle(QString x);
    void on_okay_clicked();
    void cambiar_bandera_barra_ajustes();


    void on_time_save_currentIndexChanged(int index);

    void on_toolButton_2_clicked();
    void opciones_ajustes();

private:
    Ui::ajustes *ui;
    SerialSpo2 *spo2serial_2;
    GuiaUsuario* Data;

};

#endif // AJUSTES_H
