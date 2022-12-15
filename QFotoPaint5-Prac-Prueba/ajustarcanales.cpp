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
    valor=2;
}

AjustarCanales::~AjustarCanales()
{
    delete ui;
}

void AjustarCanales::on_horizontalSlider_2_valueChanged(int value)
{
    ui->spinBox_2->setValue(value);
    valor=value;
    ajustar_color_canales(nfoto,value,opcion);
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
     ajustar_color_canales(nfoto,valor,opcion,true);
}

void AjustarCanales::on_AjustarCanales_rejected()
{
    mostrar(nfoto);
}
