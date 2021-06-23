QT       += core gui serialport sql
QT       += network mqtt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alarmas.cpp \
    derivaciones.cpp \
    ecghandle.cpp \
    enviardatos.cpp \
    error.cpp \
    galeria.cpp \
    graficaecg.cpp \
    main.cpp \
    mainwindow.cpp \
    paciente.cpp \
    pantallacarga.cpp \
    qcustomplot.cpp \
    config_alarmas.cpp \
    ajustes.cpp \
    mod2.cpp \
    registro.cpp \
    guiausuario.cpp \
    serialspo2.cpp \
    serialthread.cpp \
    serialthread2.cpp \
    teclado.cpp

HEADERS += \
    alarmas.h \
    derivaciones.h \
    ecghandle.h \
    enviardatos.h \
    error.h \
    funciones.h \
    galeria.h \
    graficaecg.h \
    mainwindow.h \
    paciente.h \
    pantallacarga.h \
    qcustomplot.h \
    config_alarmas.h \
    ajustes.h \
    mod2.h \
    registro.h \
    guiausuario.h \
    serialspo2.h \
    serialthread.h \
    serialthread2.h \
    teclado.h

FORMS += \
    alarmas.ui \
    derivaciones.ui \
    ecghandle.ui \
    enviardatos.ui \
    error.ui \
    galeria.ui \
    graficaecg.ui \
    mainwindow.ui \
    config_alarmas.ui \
    ajustes.ui \
    mod2.ui \
    paciente.ui \
    pantallacarga.ui \
    registro.ui \
    guiausuario.ui \
    teclado.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recursos.qrc

DISTFILES += \
    imagenes/SalirGuia.png
