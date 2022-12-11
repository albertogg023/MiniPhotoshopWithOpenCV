#include "informacion.h"
#include "ui_informacion.h"
#include <string>
using namespace std;
#include <opencv2/opencv.hpp>
using namespace cv;

Informacion::Informacion(Mat img,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Informacion)
{
    Scalar valor=mean(img); //Se calcula la media y se obtiene el scalar
    printf("Color Medio:%f",valor.val[0]); //Se obtenie el valor medio del Scalar
    ui->setupUi(this);
    ui->lineEdit->setText(QString::number(img.total()));
    ui->lineEdit_2->setText(QString::number(img.depth()));
    ui->lineEdit_3->setText(QString::number(img.channels()));
    ui->lineEdit_4->setText(QString::number(img.elemSize()*img.total()));
    ui->lineEdit_5->setText(QString::number(valor.val[0]));
}

Informacion::~Informacion()
{
    delete ui;
}

