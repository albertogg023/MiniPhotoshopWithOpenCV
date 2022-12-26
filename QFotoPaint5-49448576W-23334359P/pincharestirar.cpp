#include "pincharestirar.h"
#include "ui_pincharestirar.h"
#include"imagenes.h"
int nfoto;
int cx,cy;
double radio_efecto,grado_efecto;

void cb_pincharestirar(int evento, int x, int y, int flags, void *pt)
{
    if(flags==EVENT_FLAG_LBUTTON)
    {
        cx=x;
        cy=y;
        ver_pinchar_estirar(nfoto,cx,cy,radio_efecto,grado_efecto);
    }
}

pinchar_estirar::pinchar_estirar(int numfoto,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pinchar_estirar)
{
    ui->setupUi(this);
    nfoto=numfoto;
    cx=200;
    cy=200;
    radio_efecto=ui->horizontalSlider->value();
    grado_efecto=radio_efecto*radio_efecto*ui->horizontalSlider_2->value()/1000.0;
    ver_pinchar_estirar(nfoto,cx,cy,radio_efecto,grado_efecto);
    setMouseCallback("Pinchar/Estirar",cb_pincharestirar);
}

pinchar_estirar::~pinchar_estirar()
{
    delete ui;
}

void pinchar_estirar::on_horizontalSlider_valueChanged(int value)
{
    radio_efecto=value;
    ui->spinBox->setValue(value);
    ver_pinchar_estirar(nfoto,cx,cy,radio_efecto,grado_efecto);
}

void pinchar_estirar::on_spinBox_valueChanged(int arg1)
{
    ui->horizontalSlider->setValue(arg1);
}

void pinchar_estirar::on_horizontalSlider_2_valueChanged(int value)
{
    grado_efecto=radio_efecto*radio_efecto*value/1000.0;
    ui->spinBox_2->setValue(value);
    ver_pinchar_estirar(nfoto,cx,cy,radio_efecto,grado_efecto);
}

void pinchar_estirar::on_spinBox_2_valueChanged(int arg1)
{
    ui->horizontalSlider_2->setValue(arg1);
}

void pinchar_estirar::on_buttonBox_rejected()
{
    destroyWindow("Pinchar/Estirar");
}

void pinchar_estirar::on_buttonBox_accepted()
{
    ver_pinchar_estirar(nfoto,cx,cy,radio_efecto,grado_efecto);
    destroyWindow("Pinchar/Estirar");
}

