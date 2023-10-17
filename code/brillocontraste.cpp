#include "brillocontraste.h"
#include "ui_brillocontraste.h"

#include "imagenes.h"

brillocontraste::brillocontraste(int numfoto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::brillocontraste)
{
    ui->setupUi(this);
    nfoto= numfoto;
    set_callback_foto(nfoto, false);
    suma= 0.0;
    multiplica= 1.0;
    gama=1.0;
    if (parent)
        move(parent->x()+DESP_X_HIJO, parent->y()+DESP_Y_HIJO);
}

brillocontraste::~brillocontraste()
{
    set_callback_foto(nfoto, true);
    delete ui;
}

void brillocontraste::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void brillocontraste::actualizar()
{
    double brillo= ui->horizontalSlider->value();
    double contraste= ui->horizontalSlider_2->value();
    if (contraste>0)
        multiplica= 1.0/(1.01-contraste/100);
    else
        multiplica= 1.0+contraste/100;
    suma= (multiplica+1)*brillo/2-128*(multiplica-1);
    gama=ui->horizontalSlider_3->value()/100.0;
    if (ui->checkBox->isChecked())
        ver_brillo_contraste(nfoto, suma, multiplica, gama, false);
    else
        mostrar(nfoto);
}

void brillocontraste::on_spinBox_valueChanged(int valor)
{
    ui->horizontalSlider->setValue(valor);
}

void brillocontraste::on_spinBox_2_valueChanged(int valor)
{
    ui->horizontalSlider_2->setValue(valor);
}

void brillocontraste::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
    actualizar();
}

void brillocontraste::on_horizontalSlider_2_valueChanged(int value)
{
    ui->spinBox_2->setValue(value);
    actualizar();
}

void brillocontraste::on_checkBox_stateChanged(int arg1)
{
    actualizar();
}

void brillocontraste::on_brillocontraste_accepted()
{
    actualizar();
    ver_brillo_contraste(nfoto, suma, multiplica, gama,true);
}

void brillocontraste::on_brillocontraste_rejected()
{
    mostrar(nfoto);
}



void brillocontraste::on_spinBox_3_valueChanged(int arg1)
{
    ui->horizontalSlider_3->setValue(arg1);
}


void brillocontraste::on_horizontalSlider_3_valueChanged(int value)
{
    ui->spinBox_3->setValue(value);
    actualizar();
}
