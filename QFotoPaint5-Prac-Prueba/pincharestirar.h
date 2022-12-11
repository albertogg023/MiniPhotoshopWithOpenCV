#ifndef PINCHAR_ESTIRAR_H
#define PINCHAR_ESTIRAR_H

#include <QDialog>

namespace Ui {
class pinchar_estirar;
}

class pinchar_estirar : public QDialog
{
    Q_OBJECT

public:
    explicit pinchar_estirar(int numfoto,QWidget *parent = nullptr);
    ~pinchar_estirar();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_spinBox_valueChanged(int arg1);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_spinBox_2_valueChanged(int arg1);

    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::pinchar_estirar *ui;
};

#endif // PINCHAR_ESTIRAR_H
