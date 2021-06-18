#ifndef PANTALLACARGA_H
#define PANTALLACARGA_H

#include <QDialog>

namespace Ui {
class PantallaCarga;
}

class PantallaCarga : public QDialog
{
    Q_OBJECT

public:
    explicit PantallaCarga(QWidget *parent = nullptr);
    bool* usb();

    ~PantallaCarga();
signals:
    void leds_t();
    void leds_l();
    void leds_o();
    void check_inicio();
private slots:
    void funcionActivacionTimer();

private:
    Ui::PantallaCarga *ui;
};

#endif // PANTALLACARGA_H
