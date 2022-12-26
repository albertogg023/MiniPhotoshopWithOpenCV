#ifndef AJUSTELINEAL_H
#define AJUSTELINEAL_H

#include <QDialog>

namespace Ui {
class Ajustelineal;
}

class Ajustelineal : public QDialog
{
    Q_OBJECT

public:
    explicit Ajustelineal(int numfoto, QWidget *parent = nullptr);
    ~Ajustelineal();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_spinBox_valueChanged(int arg1);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_spinBox_2_valueChanged(int arg1);

    void on_checkBox_stateChanged(int arg1);

    void on_Ajustelineal_accepted();

    void on_Ajustelineal_rejected();

private:
    Ui::Ajustelineal *ui;
    int nfoto;
    double pmin;
    double pmax;
};

#endif // AJUSTELINEAL_H
