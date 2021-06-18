#ifndef PACIENTE_H
#define PACIENTE_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <teclado.h>

namespace Ui {
class Paciente;
}

class Paciente : public QDialog
{
    Q_OBJECT

public:
    explicit Paciente(QWidget *parent = nullptr);
    void paciente_activo_change(QString name_active_pacient);
    ~Paciente();
signals:
    void sonido_click();

private slots:
    void on_paciente1_clicked();
    void on_paciente2_clicked();
    void on_paciente3_clicked();
    void colorpaciente();
    void restore_position();
    void erase_last_names();
    void letter_press_lastname(QString letter);
    void on_notas_selectionChanged();

private:
    Ui::Paciente *ui;
      QSqlDatabase db;
      Teclado* teclado;

};

#endif // PACIENTE_H
