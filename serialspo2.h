#ifndef SERIALSPO2_H
#define SERIALSPO2_H

#include <QObject>
#include <QThread>
#include <QSerialPort>

namespace Ui {
class SerialSpo2;
}
class SerialSpo2 : public QObject
{
  Q_OBJECT
public:
  explicit SerialSpo2(QObject *parent = nullptr);
  ~SerialSpo2();
    void addPoint_spo2(double x, double y);
    void init_port(); //Initialize the serial port
    void init_port_2();
    void close_port();
    void IsActive();
    bool check_allowed_values();
    void bpm_flag_update();
  QSerialPort *spo2_port;

public slots:
    void handle_data(); //Process the received data
    void procesaDato(QByteArray);

signals:
  void boton_ajustes(QString);
  void receive_data(QVector<double>, QVector<double>, int, double, double, double);
  void not_data();
  void bpm_count(QString);
  void cuadronegro(int);
  void pleth(QVector<double>, QVector<double>, int, double, double, double);
  void porcentualspo2(QString);
  void updatetemperature(QString, double);
  void errorpani();
  void panivalues(QString, QString, QString);
  void escribe(QByteArray);
  void spo2_plot_mqtt(double data);
private:
  QThread *my_thread2;
  QByteArray bufer;
  QVector<double> qv_x_spo2, qv_y_spo2, qv_y_spo2_reescale;
  QVector<float> qv_red, qv_ir;

};

#endif
