#ifndef REGISTRO_H
#define REGISTRO_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <teclado.h>
#include <serialspo2.h>


namespace Ui {
class Registro;
}

class Registro : public QDialog
{
    Q_OBJECT

public:
    explicit Registro(QWidget *parent = nullptr, SerialSpo2 *serialspo2_registro = NULL);

    explicit Registro(QWidget *parent = nullptr);
    ~Registro();
signals:
      void sonido_click();
      void bandera_perilla_6();
public slots:
      void letter_press(QString letter);
      void letter_press_lastname(QString letter);
      void erase_names();
      void erase_last_names();
      void erase_mother_last_name();
      void erase_uid();
      void letter_press_uid(QString letter);
      void letter_press_mother_last_name(QString letter);
      void erase_notes();
      void letter_notes(QString letter);
      void close_keyboard();
private slots:
    void on_names_selectionChanged();

    void on_last_name_selectionChanged();

    void on_mother_last_name_selectionChanged();

    void on_notes_selectionChanged();

    void on_CERRAR_pressed();

    void on_OK_pressed();

    void on_names_2_selectionChanged();

    void boton_handle_6(QString x);

    void opciones_registro();

    void on_okay_clicked();




private:
    Ui::Registro *ui;
    QSqlDatabase db;
    Teclado* teclado;
    SerialSpo2 *spo2serial_6;

};

#endif // REGISTRO_H
