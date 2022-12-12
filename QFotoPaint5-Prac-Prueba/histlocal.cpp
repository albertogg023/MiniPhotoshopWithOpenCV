#include "histlocal.h"
#include "ui_histlocal.h"
#include "imagenes.h"

HistLocal::HistLocal(int numfoto,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HistLocal)
{
    ui->setupUi(this);
    nfoto= numfoto;
    radio=1;
}

HistLocal::~HistLocal()
{
    delete ui;
}

void HistLocal::on_horizontalSlider_2_valueChanged(int value)
{
    ui->spinBox_2->setValue(value);
    ecualizacion_local_hist(nfoto,value);
}

void HistLocal::on_spinBox_2_valueChanged(int arg1)
{
    ui->horizontalSlider_2->setValue(arg1);
}

void HistLocal::on_HistLocal_accepted()
{
    ecualizacion_local_hist(nfoto,radio,true);
}

void HistLocal::on_HistLocal_rejected()
{
    mostrar(nfoto);
}
