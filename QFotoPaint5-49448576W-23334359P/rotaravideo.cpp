#include "rotaravideo.h"
#include "ui_rotaravideo.h"
#include <QFileDialog>
#include "mainwindow.h"

#include "video.h"

rotaravideo::rotaravideo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rotaravideo)
{
    ui->setupUi(this);
    nfoto= foto_activa();
}

rotaravideo::~rotaravideo()
{
    delete ui;
}

void rotaravideo::changeEvent(QEvent *e)
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

void rotaravideo::on_rotaravideo_accepted()
{
    QString nombre= QFileDialog::getSaveFileName(w, "Guardar vídeo", ".", QString::fromLatin1(FiltroVideo.c_str()));
    if (!nombre.isEmpty()) {
        int modo= ui->radioButton->isChecked() ? 0 :
                 (ui->radioButton_2->isChecked() ? 1 : 2);
        int codigocc;
        QString cad= ui->comboBox->currentText();
        if (cad=="DEFAULT")
            codigocc= VideoWriter::fourcc('M','P','E','G');
        else {
            string cadena= cad.toLatin1().data();
            codigocc= VideoWriter::fourcc(cadena[0], cadena[1], cadena[2], cadena[3]);
        }
        rotar_video(nfoto, nombre.toLatin1().data(), modo, ui->spinBox->value(),
                    codigocc, ui->doubleSpinBox->value());
    }
}
