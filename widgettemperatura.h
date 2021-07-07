#ifndef WIDGETTEMPERATURA_H
#define WIDGETTEMPERATURA_H

#include <QWidget>
#include <QLabel>
#include <QFont>

class WidgetTemperatura : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetTemperatura(QWidget *parent = nullptr, int largo = 300, int alto = 150);
    QLabel *lblFondo;
    QLabel *lblValor;
    QLabel *lblNombre;
    QLabel *lblUnidad;

    void set_valor(QString valor);
signals:

};

#endif // WIDGETTEMPERATURA_H
