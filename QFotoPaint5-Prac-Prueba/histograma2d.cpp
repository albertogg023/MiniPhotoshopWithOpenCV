#include "histograma2d.h"
#include "ui_histograma2d.h"

Histograma2D::Histograma2D(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Histograma2D)
{
    ui->setupUi(this);
}

Histograma2D::~Histograma2D()
{
    delete ui;
}
