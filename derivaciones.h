#ifndef DERIVACIONES_H
#define DERIVACIONES_H

#include <QDialog>
#include <serialspo2.h>
#include <QCloseEvent>

namespace Ui {
class derivaciones;
}

class derivaciones : public QDialog
{
    Q_OBJECT

public:
    explicit derivaciones(QWidget *parent = 0, SerialSpo2 *serialspo2_derivaciones = NULL);
    int statebutton();
    void changebutton();
    ~derivaciones();

signals:
    void sonido_click();
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
    void bandera_perilla_4();
    void habilitar_perilla_4();


private slots:
    void on_d1_pressed();
    void on_d2_pressed();
    void on_d3_pressed();
    void on_d4_pressed();
    void on_d5_pressed();
    void on_d6_pressed();
    void on_d7_pressed();
    void on_d8_pressed();
    void on_d9_pressed();
    void on_d10_pressed();
    void on_d11_pressed();
    void on_d12_pressed();
    void boton_handle_5(QString k);
    void opciones_derivaciones();
    void on_okay_clicked();
    void closeEvent(QCloseEvent*);

private:
    Ui::derivaciones *ui;
    SerialSpo2 *spo2serial_5;
};

#endif // DERIVACIONES_H
