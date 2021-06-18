#ifndef ENVIARDATOS_H
#define ENVIARDATOS_H

#include <QDialog>

namespace Ui {
class enviardatos;
}

class enviardatos : public QDialog
{
    Q_OBJECT

public:
    explicit enviardatos(QWidget *parent = nullptr);
    ~enviardatos();

private slots:
    void on_bpm_envio_clicked();
    void on_spo2_envio_clicked();

    void on_pani_envio_clicked();

    void on_temp_envio_clicked();

    void on_toolButton_5_clicked();

signals:
    void send_data(int);
private:
    Ui::enviardatos *ui;
};

#endif // ENVIARDATOS_H
