#include "modelocolor.h"
#include "ui_modelocolor.h"
#include "imagenes.h"

ModeloColor::ModeloColor(int nfoto,int nres,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModeloColor)
{
    ui->setupUi(this);
    foto=nfoto;
    res=nres;
}

ModeloColor::~ModeloColor()
{
    delete ui;
}

void ModeloColor::on_radioButton_clicked()
{
    cambiar_modelo(foto,res,0);
}

void ModeloColor::on_radioButton_2_clicked()
{
    cambiar_modelo(foto,res,1);
}

void ModeloColor::on_radioButton_3_clicked()
{
    cambiar_modelo(foto,res,2);
}

void ModeloColor::on_radioButton_4_clicked()
{
    cambiar_modelo(foto,res,3);
}

void ModeloColor::on_radioButton_5_clicked()
{
    cambiar_modelo(foto,res,4);
}
