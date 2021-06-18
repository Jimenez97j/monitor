#ifndef GALERIA_H
#define GALERIA_H

#include <QDialog>
#include <serialspo2.h>

namespace Ui {
class galeria;
}

class galeria : public QDialog
{
    Q_OBJECT

public:
    explicit galeria(QWidget *parent = 0, SerialSpo2 *serialspo2_galeria = NULL );

    ~galeria();

signals:
    void sonido_click();
    void sonido_basura();
    void bandera_perilla_2();

private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);
    void on_min1_boton_pressed();
    void on_min2_boton_pressed();
    void on_min3_boton_pressed();
    void iniciar();
    void on_toolButton_pressed();
    void on_trash_pressed();
    void boton_handle(QString p);
    void opciones_galeria();
    void on_oka_clicked();

private:
    Ui::galeria *ui;
     SerialSpo2 *spo2serial_3;
};

#endif // GALERIA_H
