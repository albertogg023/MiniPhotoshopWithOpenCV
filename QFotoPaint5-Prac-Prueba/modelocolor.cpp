#include "modelocolor.h"
#include "ui_modelocolor.h"
#include "imagenes.h"

ModeloColor::ModeloColor(int nfoto,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModeloColor)
{
    ui->setupUi(this);
    foto=nfoto;
    modelo_actual=0;
}

ModeloColor::~ModeloColor()
{
    delete ui;
}

void ModeloColor::on_radioButton_clicked()
{
    cambiar_modelo(foto,0);
    modelo_actual=0;
}

void ModeloColor::on_radioButton_2_clicked()
{
    cambiar_modelo(foto,1);
    modelo_actual=1;
}

void ModeloColor::on_radioButton_3_clicked()
{
    cambiar_modelo(foto,2);
    modelo_actual=2;
}

void ModeloColor::on_radioButton_4_clicked()
{
    cambiar_modelo(foto,3);
    modelo_actual=3;
}

void ModeloColor::on_radioButton_5_clicked()
{
    cambiar_modelo(foto,4);
    modelo_actual=4;
}

void ModeloColor::on_ModeloColor_rejected()
{
     mostrar(foto);
}

void ModeloColor::on_ModeloColor_accepted()
{
    cambiar_modelo(foto,modelo_actual,true);
     mostrar(foto);
}


