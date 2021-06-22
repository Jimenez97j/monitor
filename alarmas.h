#ifndef ALARMAS_H
#define ALARMAS_H
#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <serialspo2.h>
#include <teclado.h>

QT_BEGIN_NAMESPACE
namespace Ui {class alarmas;}
QT_END_NAMESPACE

class alarmas : public QDialog
{
    Q_OBJECT

public:
    explicit alarmas(QWidget *parent = nullptr, SerialSpo2 *serialspo2_registro = NULL);
    ~alarmas();
    void crearTabla();
signals:
    void sonido_click();

private slots:
    void on_pushButton_pressed();
    void boton_handle_7(QString x);
private:
    Ui::alarmas *ui;
    QSqlDatabase db;
    Teclado* teclado;
    SerialSpo2 *spo2serial_7;
};

#endif // ALARMAS_H
