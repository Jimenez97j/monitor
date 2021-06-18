#ifndef ERRORCARGA_H
#define ERRORCARGA_H

#include <QDialog>

namespace Ui {
class ErrorCarga;
}

class ErrorCarga : public QDialog
{
    Q_OBJECT

public:
    explicit ErrorCarga(QWidget *parent = nullptr);
    ~ErrorCarga();

private:
    Ui::ErrorCarga *ui;
};

#endif // ERRORCARGA_H
