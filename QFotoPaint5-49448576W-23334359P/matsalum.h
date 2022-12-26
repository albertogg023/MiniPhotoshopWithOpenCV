#ifndef MATSALUM_H
#define MATSALUM_H

#include <QDialog>

namespace Ui {
class Matsalum;
}

class Matsalum : public QDialog
{
    Q_OBJECT

public:
    explicit Matsalum(int num_foto,QWidget *parent = nullptr);
    ~Matsalum();

private slots:
    void on_dial_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_horizontalSlider_valueChanged(int value);

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

private:
    Ui::Matsalum *ui;
    int nfoto;
    int matiz;
    double saturacion;
    double luminosidad;
};

#endif // MATSALUM_H
