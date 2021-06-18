#ifndef GUIAUSUARIO_H
#define GUIAUSUARIO_H

#include <QDialog>

namespace Ui {
class GuiaUsuario;
}

class GuiaUsuario : public QDialog
{
    Q_OBJECT

public:
    explicit GuiaUsuario(QWidget *parent = nullptr);
    ~GuiaUsuario();

private slots:
    void on_toolButton_pressed();

    void on_toolButton_2_pressed();

    void on_toolButton_3_pressed();

private:
    Ui::GuiaUsuario *ui;
};

#endif // GUIAUSUARIO_H
