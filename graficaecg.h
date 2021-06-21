#ifndef GRAFICAECG_H
#define GRAFICAECG_H

#include <QWidget>
#include <QQueue>
#include <QThread>
#include <serialthread2.h>

namespace Ui {
class GraficaEcg;
}

class GraficaEcg : public QWidget
{
    Q_OBJECT

public:
    explicit GraficaEcg(QWidget *parent = nullptr);
    ~GraficaEcg();
    void change_color_chart(int what_style);
    void change_square_ecg(QString color_square);
    void iniciar_serial();
    void set_serial_name(QString name);
    QString serial_name;
private slots:
    void plot_ECG(QVector<double> x , QVector<double> y , int square, double max, double minrangeLine, double maxrangeLine);
    void plot_ECG_2(QVector<double> x , QVector<double> y , int square, double max, double minrangeLine, double maxrangeLine);
    void funcionActivacionTimer();
signals:
    void compartir_dato(QVector<double> x , QVector<double> y , int square, double max, double minrangeLine, double maxrangeLine);
private:
    Ui::GraficaEcg *ui;
    SerialThread2 *local_serial;
};

#endif // GRAFICAECG_H
