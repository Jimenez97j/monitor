#include "guiausuario.h"
#include "ui_guiausuario.h"
GuiaUsuario::GuiaUsuario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GuiaUsuario)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);

}

GuiaUsuario::~GuiaUsuario()
{
    delete ui;
}

void GuiaUsuario::on_toolButton_pressed()
{
    this->close();
}

void GuiaUsuario::on_toolButton_2_pressed()
{
    int index = ui->tabWidget->currentIndex();
    ui->tabWidget->setCurrentIndex(index + 1);
}


void GuiaUsuario::on_toolButton_3_pressed()
{
    int index = ui->tabWidget->currentIndex();
    ui->tabWidget->setCurrentIndex(index - 1);
}
