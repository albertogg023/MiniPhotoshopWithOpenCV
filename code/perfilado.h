#ifndef PERFILADO_H
#define PERFILADO_H

#include <QDialog>

namespace Ui {
class Perfilado;
}

class Perfilado : public QDialog
{
    Q_OBJECT

public:
    explicit Perfilado(int nnumfoto,QWidget *parent = nullptr);
    ~Perfilado();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_spinBox_valueChanged(int arg1);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_spinBox_2_valueChanged(int arg1);

    void on_Perfilado_accepted();

    void on_Perfilado_rejected();

private:
    Ui::Perfilado *ui;
    int nfoto;
    int radio;
    double grado;
};

#endif // PERFILADO_H
