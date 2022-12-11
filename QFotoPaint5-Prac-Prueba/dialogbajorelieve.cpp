#include "dialogbajorelieve.h"
#include "ui_dialogbajorelieve.h"
#include "imagenes.h"

dialogBajoRelieve::dialogBajoRelieve(int num_foto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogBajoRelieve)
{
    ui->setupUi(this);
    nfoto=num_foto;
    fondo=0;
    grado=0;
    angulo=0;
    ver_bajo_relieve(nfoto,angulo,grado,fondo);
}

dialogBajoRelieve::~dialogBajoRelieve()
{
    delete ui;
}


void dialogBajoRelieve::on_dialogBajoRelieve_accepted()
{
    ver_bajo_relieve(nfoto,angulo,grado,fondo,true);
    destroyWindow("Bajorrelieve");
}

void dialogBajoRelieve::on_dialogBajoRelieve_rejected()
{
    destroyWindow("Bajorrelieve");
}

void dialogBajoRelieve::on_horizontalSlider_3_valueChanged(int value)
{
    grado=value/100.0;
    ver_bajo_relieve(nfoto,angulo,grado,fondo);
}

void dialogBajoRelieve::on_dial_valueChanged(int value)
{
    angulo=value;
    ver_bajo_relieve(nfoto,angulo,grado,fondo);
}

void dialogBajoRelieve::on_radioButton_clicked()
{
    fondo=0;
    ver_bajo_relieve(nfoto,angulo,grado,fondo);
}

void dialogBajoRelieve::on_radioButton_2_clicked()
{
    fondo=1;
    ver_bajo_relieve(nfoto,angulo,grado,fondo);
}

void dialogBajoRelieve::on_radioButton_3_clicked()
{
    fondo=2;
    ver_bajo_relieve(nfoto,angulo,grado,fondo);
}

