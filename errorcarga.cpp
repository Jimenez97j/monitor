#include "errorcarga.h"
#include "ui_errorcarga.h"

ErrorCarga::ErrorCarga(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorCarga)
{
    ui->setupUi(this);
}

ErrorCarga::~ErrorCarga()
{
    delete ui;
}
