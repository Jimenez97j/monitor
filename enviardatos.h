#ifndef ENVIARDATOS_H
#define ENVIARDATOS_H

#include <QDialog>
#include <serialspo2.h>
#include <QCloseEvent>
#include <QDebug>

namespace Ui {
class enviardatos;
}

class enviardatos : public QDialog
{
    Q_OBJECT

public:
    explicit enviardatos(QWidget *parent = nullptr, SerialSpo2 *serialspo2_ajustes = NULL );
    ~enviardatos();
    void on_okay_clicked();

private slots:
    void on_bpm_envio_clicked();
    void on_spo2_envio_clicked();

    void on_pani_envio_clicked();

    void on_temp_envio_clicked();

    void on_toolButton_5_clicked();

    void boton_handle_9(QString x);

    void opciones_enviardatos();

    void closeEvent(QCloseEvent*);

signals:
    void send_data(int);
    void bandera_perilla_9();
private:
    Ui::enviardatos *ui;
    SerialSpo2 *spo2serial_9;
};

#endif // ENVIARDATOS_H
