#include "histlocal.h"
#include "ui_histlocal.h"

HistLocal::HistLocal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HistLocal)
{
    ui->setupUi(this);
}

HistLocal::~HistLocal()
{
    delete ui;
}
