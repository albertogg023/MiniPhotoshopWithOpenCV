#ifndef AJUSTARCANALES_H
#define AJUSTARCANALES_H

#include <QDialog>

namespace Ui {
class AjustarCanales;
}

class AjustarCanales : public QDialog
{
    Q_OBJECT

public:
    explicit AjustarCanales(int numfoto,QWidget *parent = nullptr);
    ~AjustarCanales();

private slots:
    void on_horizontalSlider_2_valueChanged(int value);

    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

    void on_spinBox_2_valueChanged(int arg1);

    void on_AjustarCanales_accepted();

    void on_AjustarCanales_rejected();

private:
    Ui::AjustarCanales *ui;
    int nfoto;
    int opcion;
    int valor;
};

#endif // AJUSTARCANALES_H
