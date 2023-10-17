#ifndef MODELOCOLOR_H
#define MODELOCOLOR_H

#include <QDialog>

namespace Ui {
class ModeloColor;
}

class ModeloColor : public QDialog
{
    Q_OBJECT

public:
    explicit ModeloColor(int nfoto,QWidget *parent = nullptr);
    ~ModeloColor();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_ModeloColor_rejected();

    void on_ModeloColor_accepted();


private:
    Ui::ModeloColor *ui;
    int foto;
    int modelo_actual;
};

#endif // MODELOCOLOR_H
