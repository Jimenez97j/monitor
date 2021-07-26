#ifndef TECLADO_H
#define TECLADO_H

#include <QDialog>

namespace Ui {
class Teclado;
}

class Teclado : public QDialog
{
    Q_OBJECT

public:
    explicit Teclado(QWidget *parent = nullptr);
    ~Teclado();
signals:
    void letter_press(QString letter);
    void erase_names();
    void close_keyboard();
private slots:


    void on_Q_pressed();

    void on_W_pressed();

    void on_E_pressed();

    void on_MAYUS_pressed();

    void on_R_pressed();

    void on_T_pressed();

    void on_Y_pressed();

    void on_U_pressed();

    void on_I_pressed();

    void on_O_pressed();

    void on_P_pressed();

    void on_A_pressed();

    void on_S_pressed();

    void on_D_pressed();

    void on_F_pressed();

    void on_G_pressed();

    void on_H_pressed();

    void on_J_pressed();

    void on_K_pressed();

    void on_L_pressed();

    void on_ENE_pressed();

    void on_Z_pressed();

    void on_X_pressed();

    void on_C_pressed();

    void on_V_pressed();


    void on_B_pressed();

    void on_N_pressed();

    void on_M_pressed();

    void on_SPACE_pressed();

    void on_BORRAR_pressed();

    void on_HIDE_pressed();

    void on_N7_pressed();

    void on_N8_pressed();

    void on_N9_pressed();

    void on_N4_pressed();

    void on_N5_pressed();

    void on_N6_pressed();

    void on_N1_pressed();

    void on_N2_pressed();

    void on_N3_pressed();

    void on_N0_pressed();

    void on_PUNTO_pressed();

    void on_COMA_pressed();

    void on_N0_2_pressed();

    void on_Teclado_finished(int result);

    void funcionActivacionTimer();

    void on_ENTER_pressed();

private:
    Ui::Teclado *ui;
};

#endif // TECLADO_H
