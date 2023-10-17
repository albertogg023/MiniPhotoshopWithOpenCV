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

    void on_horizontalSlider_3_valueChanged(int value);

    void on_horizontalSlider_4_valueChanged(int value);

    void on_spinBox_3_valueChanged(int arg1);

    void on_spinBox_4_valueChanged(int arg1);

private:
    Ui::AjustarCanales *ui;
    int nfoto;
    int opcion;
    int azul;
    int rojo;
    int verde;
};

#endif // AJUSTARCANALES_H
