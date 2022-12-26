#include "ajustarcanales.h"
#include "ui_ajustarcanales.h"
#include "imagenes.h"

AjustarCanales::AjustarCanales(int numfoto,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjustarCanales)
{
    ui->setupUi(this);
    nfoto=numfoto;
    opcion=0;
    azul=rojo=verde=2;
}

AjustarCanales::~AjustarCanales()
{
    delete ui;
}

void AjustarCanales::on_horizontalSlider_2_valueChanged(int value)
{
    ui->spinBox_2->setValue(value);
    azul=value;
    ajustar_color_canales(nfoto,azul,verde,rojo,opcion);
}

void AjustarCanales::on_radioButton_2_clicked()
{
    opcion=1;
}

void AjustarCanales::on_radioButton_clicked()
{
    opcion=0;
}

void AjustarCanales::on_spinBox_2_valueChanged(int arg1)
{
    ui->horizontalSlider_2->setValue(arg1);
}

void AjustarCanales::on_AjustarCanales_accepted()
{
     ajustar_color_canales(nfoto,azul,verde,rojo,opcion,true);
}

void AjustarCanales::on_AjustarCanales_rejected()
{
    mostrar(nfoto);
}

void AjustarCanales::on_horizontalSlider_3_valueChanged(int value)
{
    verde=value;
    ajustar_color_canales(nfoto,azul,verde,rojo,opcion);
}

void AjustarCanales::on_horizontalSlider_4_valueChanged(int value)
{
    rojo=value;
    ajustar_color_canales(nfoto,azul,verde,rojo,opcion);
}

void AjustarCanales::on_spinBox_3_valueChanged(int arg1)
{
    ui->horizontalSlider_3->setValue(arg1);
}

void AjustarCanales::on_spinBox_4_valueChanged(int arg1)
{
    ui->horizontalSlider_4->setValue(arg1);
}
