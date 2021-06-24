#ifndef CONFIGRED_H
#define CONFIGRED_H

#include <QDialog>
#include "wificontrol.h"
#include <QListWidgetItem>
#include "teclado.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

namespace Ui {
class ConfigRed;
}

class ConfigRed : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigRed(QWidget *parent = nullptr);
    ~ConfigRed();
    WifiControl *wificontrol;
    Teclado* teclado;
    bool est;
    int tipoRed = 0;
    QStringList tempSaved ;
    QTimer *timer1;


signals:
      void sonido_click();

private slots:
    void on_CERRAR_pressed();
    void revisa_estado();
    void actualizaListas();
    void on_wifi_clicked();
    void lista_redesWifi(bool estad);

    void on_listDisponibles_itemClicked(QListWidgetItem *item);
    void on_editContrasena_selectionChanged();
    void erase_servidor();
    void letter_servidor(QString letter);
    void erase_contrasena();
    void letter_contrasena(QString letter);
    void on_ipservidor_selectionChanged();
    void on_listGuardadas_itemClicked(QListWidgetItem *item);
    void on_btn_guardar2_clicked();
    void on_btn_eliminar_clicked();
    void limpiaFull();
    void on_btn_guardar2_pressed();

    void on_btn_eliminar_pressed();
    void on_btn_guardar_clicked();

private:
    Ui::ConfigRed *ui;
    QSqlDatabase db;
    //QSqlQuery consulta;
    QString nombre, consulta;
};

#endif // CONFIGRED_H
