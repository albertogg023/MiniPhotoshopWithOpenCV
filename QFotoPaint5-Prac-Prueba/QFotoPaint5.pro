#-------------------------------------------------
#
# Project created by QtCreator 2022-09-01T12:00:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QFotoPaint5

TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
    ajustarcanales.cpp \
    ajustelineal.cpp \
    capturarvideo.cpp \
    dialogbajorelieve.cpp \
    histlocal.cpp \
    histograma2d.cpp \
    informacion.cpp \
    mainwindow.cpp \
    imagenes.cpp \
    dialognueva.cpp \
    brillocontraste.cpp \
    matsalutlum.cpp \
    modelocolor.cpp \
    movimiento.cpp \
    perfilado.cpp \
    perspectiva.cpp \
    pincharestirar.cpp \
    suavizados.cpp \
    video.cpp \
    rotaravideo.cpp \
    mediaponderada.cpp \
    acercade.cpp \
    mediadevideo.cpp

HEADERS  += mainwindow.h \
    ajustarcanales.h \
    ajustelineal.h \
    capturarvideo.h \
    dialogbajorelieve.h \
    histlocal.h \
    histograma2d.h \
    imagenes.h \
    dialognueva.h \
    brillocontraste.h \
    informacion.h \
    matsalutlum.h \
    modelocolor.h \
    movimiento.h \
    perfilado.h \
    perspectiva.h \
    pincharestirar.h \
    suavizados.h \
    video.h \
    rotaravideo.h \
    mediaponderada.h \
    acercade.h \
    mediadevideo.h

FORMS    += mainwindow.ui \
    ajustarcanales.ui \
    ajustelineal.ui \
    capturarvideo.ui \
    dialogbajorelieve.ui \
    dialognueva.ui \
    brillocontraste.ui \
    histlocal.ui \
    histograma2d.ui \
    informacion.ui \
    matsalutlum.ui \
    modelocolor.ui \
    movimiento.ui \
    perfilado.ui \
    perspectiva.ui \
    pincharestirar.ui \
    suavizados.ui \
    rotaravideo.ui \
    mediaponderada.ui \
    acercade.ui \
    mediadevideo.ui

INCLUDEPATH += "C:\OpenCV\OpenCV4.6.0G\include"

LIBS += -L"C:\OpenCV\OpenCV4.6.0G\lib"\
        -llibopencv_world460

RESOURCES += recursos.qrc

RC_ICONS = imagenes/icono.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    imagenes/AxureRP-Setup-3740.exe \
    imagenes/abrir.png \
    imagenes/arena.jpg \
    imagenes/cielo.jpg \
    imagenes/elipse.png \
    imagenes/guardar.png \
    imagenes/histbase.png \
    imagenes/icono.ico \
    imagenes/icono.png \
    imagenes/linea.png \
    imagenes/logo.png \
    imagenes/madera.jpg \
    imagenes/nuevo.png \
    imagenes/poligono.png \
    imagenes/punto.png \
    imagenes/rectangulo.png \
    imagenes/rellenar.png \
    imagenes/seleccionar.png
