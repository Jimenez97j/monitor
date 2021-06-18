#ifndef ALARMAS_H
#define ALARMAS_H
#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

QT_BEGIN_NAMESPACE
namespace Ui {class alarmas;}
QT_END_NAMESPACE

class alarmas : public QDialog
{
    Q_OBJECT

public:
    explicit alarmas(QWidget *parent = nullptr);
    ~alarmas();
    void crearTabla();
signals:
    void sonido_click();

private slots:
    void on_pushButton_pressed();

private:
    Ui::alarmas *ui;
    QSqlDatabase db;
};

#endif // ALARMAS_H
