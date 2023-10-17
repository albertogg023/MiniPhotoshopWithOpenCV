#include "capturarvideo.h"
#include "ui_capturarvideo.h"
#include "imagenes.h"

Capturarvideo::Capturarvideo(QString nombre, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Capturarvideo)
{
    ui->setupUi(this);
    cap.open(nombre.toLatin1().data());
    if(cap.isOpened()) {
       int nframes = cap.get(CAP_PROP_FRAME_COUNT);
       ui->horizontalSlider->setMaximum(nframes-1);
       ui->spinBox->setMaximum(nframes-1);
       Mat frame;
       cap.read(frame);
       imshow("Frame del vídeo", frame);
    }
}

Capturarvideo::~Capturarvideo()
{
    delete ui;
}

bool Capturarvideo::isOpened()
{
    return cap.isOpened();
}


void Capturarvideo::on_horizontalSlider_valueChanged(int value)
{
     if(cap.isOpened()) {
          ui->spinBox->setValue(value);
          cap.set(CAP_PROP_POS_FRAMES, value);
          Mat frame;
          cap.read(frame);
          if(!frame.empty())
            imshow("Frame del vídeo", frame);

     }
}

void Capturarvideo::on_spinBox_valueChanged(int arg1)
{
    ui->horizontalSlider->setValue(arg1);
}


void Capturarvideo::on_Capturarvideo_accepted()
{
    cap.set(CAP_PROP_POS_FRAMES, ui->spinBox->value());
    Mat frame;
    cap.read(frame);
    if(!frame.empty())
      crear_nueva(primera_libre(), frame);
    destroyWindow("Frame del vídeo");
}

void Capturarvideo::on_Capturarvideo_rejected()
{
    destroyWindow("Frame del vídeo");
}
