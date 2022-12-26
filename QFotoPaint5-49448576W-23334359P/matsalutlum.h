#ifndef MATSALUTLUM_H
#define MATSALUTLUM_H

#include <QDialog>

namespace Ui {
class Matsalutlum;
}

class Matsalutlum : public QDialog
{
    Q_OBJECT

public:
    explicit Matsalutlum(int numfoto,QWidget *parent = nullptr);
    ~Matsalutlum();

private slots:
    void on_dial_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_horizontalSlider_valueChanged(int value);

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_Matsalutlum_accepted();

    void on_Matsalutlum_rejected();

private:
    Ui::Matsalutlum *ui;
    int nfoto;
    int matiz;
    double saturacion;
    double luminosidad;
};

#endif // MATSALUTLUM_H
