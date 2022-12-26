#include "mediadevideo.h"
#include "ui_mediadevideo.h"
#include <QMessageBox>

#include "video.h"

mediadevideo::mediadevideo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mediadevideo)
{
    ui->setupUi(this);
    timer.stop();
    acumulando= false;
    if (parent)
        move(parent->x()+DESP_X_HIJO, parent->y()+DESP_Y_HIJO);
}

mediadevideo::~mediadevideo()
{
    on_pushButton_2_clicked();
    delete ui;
}

void mediadevideo::changeEvent(QEvent *e)
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

void mediadevideo::on_pushButton_clicked()
{
    int miliseg= inic_camara(ui->spinBox->value());
    acumulando= false;
    if (miliseg) {
        timer.setInterval(miliseg);
        connect(&timer, SIGNAL(timeout()), this, SLOT(on_timer()));
        timer.start();
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setEnabled(false);
    }
    else
        QMessageBox::warning(this, "Error al abrir cámara",
                             "Lo siento. No se ha podido abrir la cámara " +
                             QString::number(ui->spinBox->value()));
}

void mediadevideo::on_timer()
{
    if (acumulando)
        acumular_media();
    else
        mostrar_camara();
}

void mediadevideo::on_pushButton_2_clicked()
{
    acumulando= false;
    timer.stop();
    fin_camara();
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
}

void mediadevideo::on_pushButton_3_clicked()
{
    acumular_media(true);
    ui->pushButton_4->setEnabled(true);
    acumulando= true;
}

void mediadevideo::on_pushButton_4_clicked()
{
    int pl= primera_libre();
    if (pl==-1)
        QMessageBox::warning(this, "Error al crear imagen",
                             "Lo siento. No se pueden crear más ventanas.");
    else
        media_a_nueva(pl);
}

void mediadevideo::on_mediadevideo_destroyed()
{
    on_pushButton_2_clicked();
}

void mediadevideo::on_pushButton_5_clicked()
{
    close();
}
