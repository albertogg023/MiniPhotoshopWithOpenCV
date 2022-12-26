#include "suavizados.h"
#include "ui_suavizados.h"

#include "imagenes.h"

suavizados::suavizados(int num_foto, int num_tipo, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::suavizados)
{
    ui->setupUi(this);
    nfoto= num_foto;
    tipo= num_tipo;
    set_callback_foto(nfoto, false);
    if (parent)
        move(parent->x()+DESP_X_HIJO, parent->y()+DESP_Y_HIJO);
    if(tipo==3){
        ui->horizontalSlider_2->setEnabled(false);
        ui->spinBox_2->setEnabled(false);
        ui->horizontalSlider->setMaximum(150);
        ui->spinBox->setMaximum(150);
    }
}

suavizados::~suavizados()
{
    set_callback_foto(nfoto, true);
    delete ui;
}

void suavizados::changeEvent(QEvent *e)
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

void suavizados::actualizar()
{
    if (ui->checkBox->isChecked())
        ver_suavizado(nfoto, tipo,
                      ui->horizontalSlider->value()*2-1,
                      ui->horizontalSlider_2->value()*2-1, false);
    else
        mostrar(nfoto);
}

void suavizados::on_spinBox_valueChanged(int valor)
{
    ui->horizontalSlider->setValue(valor);
}

void suavizados::on_spinBox_2_valueChanged(int valor)
{
    ui->horizontalSlider_2->setValue(valor);
}

void suavizados::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
    actualizar();
}

void suavizados::on_horizontalSlider_2_valueChanged(int value)
{
    ui->spinBox_2->setValue(value);
    actualizar();
}

void suavizados::on_checkBox_stateChanged(int arg1)
{
    actualizar();
}

void suavizados::on_suavizados_accepted()
{
    ver_suavizado(nfoto, tipo,
                  ui->horizontalSlider->value()*2-1,
                  ui->horizontalSlider_2->value()*2-1, true);
}

void suavizados::on_suavizados_rejected()
{
    mostrar(nfoto);
}
