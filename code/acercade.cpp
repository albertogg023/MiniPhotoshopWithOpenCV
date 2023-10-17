#include "acercade.h"
#include "ui_acercade.h"

acercade::acercade(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::acercade)
{
    ui->setupUi(this);
}

acercade::~acercade()
{
    delete ui;
}

void acercade::changeEvent(QEvent *e)
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

void acercade::on_commandLinkButton_clicked()
{
    close();
}
