#include "dialognueva.h"
#include "ui_dialognueva.h"

#include "imagenes.h"

#include <QColorDialog>

DialogNueva::DialogNueva(int numfoto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNueva)
{
    ui->setupUi(this);
    nfoto= numfoto;
    qcolor= QColor(0,0,0);
    if (parent)
        move(parent->x()+DESP_X_HIJO, parent->y()+DESP_Y_HIJO);
}

DialogNueva::~DialogNueva()
{
    delete ui;
}

void DialogNueva::changeEvent(QEvent *e)
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

void DialogNueva::on_pushButton_clicked()
{
    QColor r_color= QColorDialog::getColor();
    if (r_color.isValid()) {
        qcolor= r_color;
        QString estilo= "background-color: rgb("
                        + QString::number(qcolor.red())+","
                        + QString::number(qcolor.green())+","
                        + QString::number(qcolor.blue())+")";
        ui->pushButton->setStyleSheet(estilo);
    }
}

void DialogNueva::on_DialogNueva_accepted()
{
    Scalar color= CV_RGB(qcolor.red(), qcolor.green(), qcolor.blue());
    crear_nueva(nfoto, ui->spinBox->value(), ui->spinBox_2->value(), color);
}
