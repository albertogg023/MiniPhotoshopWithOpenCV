#include "ajustelineal.h"
#include "ui_ajustelineal.h"
#include "imagenes.h"

Ajustelineal::Ajustelineal(int numfoto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajustelineal)
{
    ui->setupUi(this);
    nfoto = numfoto;
    pmin = 2;
    pmax = 2;
    ver_ajuste_lineal(nfoto, pmin, pmax);
    set_callback_foto(nfoto, false);
}

Ajustelineal::~Ajustelineal()
{
    delete ui;
    set_callback_foto(nfoto, true);
}


void Ajustelineal::on_horizontalSlider_valueChanged(int value)
{
    pmin = value;
    ui->spinBox->setValue(value);
    if(pmin + pmax > 100) {
        on_horizontalSlider_2_valueChanged(100-pmin);
    }
    if(ui->checkBox->isChecked())
        ver_ajuste_lineal(nfoto, pmin, pmax);
}

void Ajustelineal::on_spinBox_valueChanged(int arg1)
{
    pmin = arg1;
    ui->horizontalSlider->setValue(arg1);
    if(pmin + pmax > 100) {
        on_horizontalSlider_2_valueChanged(100-pmin);
    }
    if(ui->checkBox->isChecked())
        ver_ajuste_lineal(nfoto, pmin, pmax);
}

void Ajustelineal::on_horizontalSlider_2_valueChanged(int value)
{
    pmax = value;
    ui->spinBox_2->setValue(value);
    if(pmin + pmax > 100) {
        on_horizontalSlider_valueChanged(100-pmax);
    }
    if(ui->checkBox->isChecked())
        ver_ajuste_lineal(nfoto, pmin, pmax);
}

void Ajustelineal::on_spinBox_2_valueChanged(int arg1)
{
    pmax = arg1;
    ui->horizontalSlider_2->setValue(arg1);
    if(pmin + pmax > 100) {
        on_horizontalSlider_valueChanged(100-pmax);
    }
    if(ui->checkBox->isChecked())
        ver_ajuste_lineal(nfoto, pmin, pmax);
}

void Ajustelineal::on_checkBox_stateChanged(int arg1)
{
    if(arg1)
        ver_ajuste_lineal(nfoto, pmin, pmax);
    else
        mostrar(nfoto);
}

void Ajustelineal::on_Ajustelineal_accepted()
{
     ver_ajuste_lineal(nfoto, pmin, pmax, true);
}

void Ajustelineal::on_Ajustelineal_rejected()
{
     mostrar(nfoto);
}
