#include "mainwindow.h"
#include "pantallacarga.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  //  PantallaCarga c;
    MainWindow w;
 //   c.setWindowFlags(Qt::FramelessWindowHint);
 //   c.show();
    //w.setWindowState(Qt::WindowMaximized);
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.show();
    return a.exec();
    if(!w.isEnabled()){
         w.show();
    }
}
