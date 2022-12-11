#ifndef DIALOGBAJORELIEVE_H
#define DIALOGBAJORELIEVE_H

#include <QDialog>

namespace Ui {
class dialogBajoRelieve;
}

class dialogBajoRelieve : public QDialog
{
    Q_OBJECT

public:
    explicit dialogBajoRelieve(int num_foto,QWidget *parent = nullptr);
    ~dialogBajoRelieve();

private slots:
    void on_horizontalSlider_3_valueChanged(int value);

    void on_dialogBajoRelieve_accepted();

    void on_dialogBajoRelieve_rejected();

    void on_dial_valueChanged(int value);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::dialogBajoRelieve *ui;
    int nfoto;
    int fondo;
    double grado;
    double angulo;
};

#endif // DIALOGBAJORELIEVE_H
