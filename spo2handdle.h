#ifndef SPO2HANDDLE_H
#define SPO2HANDDLE_H

#include <QWidget>

namespace Ui {
class spo2handdle;
}

class spo2handdle : public QWidget
{
    Q_OBJECT

public:
    explicit spo2handdle(QWidget *parent = nullptr);
    ~spo2handdle();

private:
    Ui::spo2handdle *ui;
};

#endif // SPO2HANDDLE_H
