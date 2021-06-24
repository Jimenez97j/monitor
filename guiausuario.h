#ifndef GUIAUSUARIO_H
#define GUIAUSUARIO_H

#include <QDialog>
#include <serialspo2.h>

namespace Ui {
class GuiaUsuario;
}

class GuiaUsuario : public QDialog
{
    Q_OBJECT

public:
    explicit GuiaUsuario(QWidget *parent = nullptr, SerialSpo2 *serialspo2_ajustes = NULL);
    ~GuiaUsuario();
signals:
    void habilitar_barra_ajustes();
private slots:
    void on_toolButton_pressed();

    void on_toolButton_2_pressed();

    void on_toolButton_3_pressed();
    void boton_handle_guiusuario(QString x);
    void opciones_guiusuario();
    void on_okay_clicked();

private:
    Ui::GuiaUsuario *ui;
    SerialSpo2 *spo2serial_guiusuario;
};

#endif // GUIAUSUARIO_H
