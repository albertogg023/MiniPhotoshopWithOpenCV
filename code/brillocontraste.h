#ifndef BRILLOCONTRASTE_H
#define BRILLOCONTRASTE_H

#include <QDialog>

namespace Ui {
    class brillocontraste;
}

class brillocontraste : public QDialog {
    Q_OBJECT
public:
    brillocontraste(int numfoto, QWidget *parent = nullptr);
    ~brillocontraste();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::brillocontraste *ui;
    int nfoto;
    double suma;
    double multiplica;
    double gama;
    void actualizar();

private slots:
    void on_spinBox_valueChanged(int );
    void on_spinBox_2_valueChanged(int );
    void on_horizontalSlider_valueChanged(int value);
    void on_horizontalSlider_2_valueChanged(int value);
    void on_checkBox_stateChanged(int arg1);
    void on_brillocontraste_accepted();
    void on_brillocontraste_rejected();
    void on_horizontalSlider_3_valueChanged(int value);
    void on_spinBox_3_valueChanged(int value);
};

#endif // BRILLOCONTRASTE_H
