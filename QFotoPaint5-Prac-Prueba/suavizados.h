#ifndef SUAVIZADOS_H
#define SUAVIZADOS_H

#include <QDialog>

namespace Ui {
    class suavizados;
}

class suavizados : public QDialog {
    Q_OBJECT
public:
    suavizados(int num_foto, int num_tipo, QWidget *parent = nullptr);
    ~suavizados();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::suavizados *ui;
    int nfoto;
    int tipo;            // Tipo de suavizado que se aplica: 1=GAUSIANO, 2=MEDIA, 3=MEDIANA
    void actualizar();

private slots:
    void on_spinBox_valueChanged(int );
    void on_spinBox_2_valueChanged(int );
    void on_horizontalSlider_valueChanged(int value);
    void on_horizontalSlider_2_valueChanged(int value);
    void on_checkBox_stateChanged(int arg1);
    void on_suavizados_accepted();
    void on_suavizados_rejected();
};

#endif // SUAVIZADOS_H
