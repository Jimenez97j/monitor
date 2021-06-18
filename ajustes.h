#ifndef AJUSTES_H
#define AJUSTES_H

#include <QDialog>

namespace Ui {
class ajustes;
}

class ajustes : public QDialog
{
    Q_OBJECT

public:
    explicit ajustes(QWidget *parent = 0);
    void cleanAll();
    void detection_mode(bool state_mode);
    QString detection_status();
    ~ajustes();
signals:
    void change_color_click();
    void detection_change();
    void time_save_change(int x);
    void sonido_click();
private slots:
    void on_cleanAll_pressed();
    void changebackground(QString color);
    void on_comboBox_currentIndexChanged(int index);
    void on_toolButton_pressed();
    void on_checkBox_toggled(bool checked);
    QString getajustes();
    QString gettime();
    void on_Guia_Usu_pressed();

    void on_time_save_currentIndexChanged(int index);

    void on_toolButton_2_clicked();

private:
    Ui::ajustes *ui;
};

#endif // AJUSTES_H
