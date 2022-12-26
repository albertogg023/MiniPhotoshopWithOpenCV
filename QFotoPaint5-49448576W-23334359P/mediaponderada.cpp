#include "mediaponderada.h"
#include "ui_mediaponderada.h"

mediaponderada::mediaponderada(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mediaponderada)
{
    ui->setupUi(this);
    int cur_row= 0;
    nfoto1= foto_activa();
    nfoto2= nfoto1;
    for (int i= 0, pos= 0; i<MAX_VENTANAS; i++) {
        if (foto[i].usada) {
            ui->listWidget->addItem(QString::fromStdString(foto[i].nombre));
            corresp[pos++]= i;
            if (i!=nfoto1 && (nfoto1==nfoto2 || foto[i].orden>foto[nfoto2].orden)) {
                nfoto2= i;
                cur_row= pos-1;
            }
        }
    }
    imgUno= foto[nfoto1].img;
    imgDos.create(imgUno.size(), imgUno.type());
    imgRes.create(imgUno.size(), imgUno.type());
    ui->listWidget->setCurrentRow(cur_row);
    if (parent)
        move(parent->x()+DESP_X_HIJO, parent->y()+DESP_Y_HIJO);
}

mediaponderada::~mediaponderada()
{
    destroyWindow("Media ponderada");
    delete ui;
}

void mediaponderada::changeEvent(QEvent *e)
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

void mediaponderada::actualizar ()
{
    if (ui->checkBox->isChecked()) {
        double peso= ui->horizontalSlider->value()/100.0;
        addWeighted(imgUno, peso, imgDos, 1.0-peso, 0, imgRes);
        namedWindow("Media ponderada", 0);
        imshow("Media ponderada", imgRes);
    }
}

void mediaponderada::on_horizontalSlider_valueChanged(int value)
{
    actualizar();
}

void mediaponderada::on_listWidget_currentRowChanged(int currentRow)
{
    nfoto2= corresp[currentRow];
    cv::resize(foto[nfoto2].img, imgDos, imgUno.size(), 0, 0, INTER_CUBIC);
    actualizar();
}

void mediaponderada::on_checkBox_stateChanged(int arg1)
{
    actualizar();
}

void mediaponderada::on_mediaponderada_accepted()
{
    double peso= ui->horizontalSlider->value()/100.0;
    media_ponderada(nfoto1, nfoto2, primera_libre(), peso);
}
