#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

#include <QObject>
#include <QThread>
#include <QSerialPort>
#include <QWidget>

namespace Ui {
class SerialThread;
}
class SerialThread : public QObject
{
  Q_OBJECT
public:
  explicit SerialThread(QObject *parent = nullptr);
  ~SerialThread();
    void addPoint_ECG(double x, double y);
    void addPoint_ECG_2(double x, double y);
    bool is_available();
    //void set_name(QString name);
    //void iniciar();
  void init_port(); //Initialize the serial port
  QSerialPort *ecg_port;
public slots:
    void handle_data(); //Process the received data
private slots:

signals:
  void receive_data(QVector<double>, QVector<double>, int, double, double, double);
  void receive_data_2(QVector<double>, QVector<double>, int, double, double, double);
  void envia_a_mqtt_publish(QString data);

private:
  QThread *my_thread;
  Ui::SerialThread *ui;
  QByteArray bufer;
  QVector<double> qv_x_ECG, qv_y_ECG, qv_y_ecg_reescale;
  QVector<double> qv_x_ECG_2, qv_y_ECG_2, qv_y_ecg_reescale_2;

};

#endif
