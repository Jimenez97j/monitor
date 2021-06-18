#ifndef PACIENTE_H
#define PACIENTE_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <teclado.h>
#include <serialspo2.h>

namespace Ui {
class Paciente;
}

class Paciente : public QDialog
{
    Q_OBJECT

public:
    explicit Paciente(QWidget *parent = nullptr, SerialSpo2 *serialspo2_registro = NULL);
    void paciente_activo_change(QString name_active_pacient);
    ~Paciente();
signals:
    void sonido_click();
    void bandera_perilla_7();

private slots:
    void on_paciente1_clicked();
    void on_paciente2_clicked();
    void on_paciente3_clicked();
    void colorpaciente();
    void restore_position();
    void erase_last_names();
    void letter_press_lastname(QString letter);
    void on_notas_selectionChanged();
    void boton_handle_7(QString x);
    void opciones_Paciente();
    void  on_okay_clicked();


private:
    Ui::Paciente *ui;
      QSqlDatabase db;
      Teclado* teclado;
      SerialSpo2 *spo2serial_7;

};

#endif // PACIENTE_H
