#ifndef HISTLOCAL_H
#define HISTLOCAL_H

#include <QDialog>

namespace Ui {
class HistLocal;
}

class HistLocal : public QDialog
{
    Q_OBJECT

public:
    explicit HistLocal(int numfoto,QWidget *parent = nullptr);
    ~HistLocal();

private slots:
    void on_horizontalSlider_2_valueChanged(int value);

    void on_spinBox_2_valueChanged(int arg1);

    void on_HistLocal_accepted();

    void on_HistLocal_rejected();

private:
    Ui::HistLocal *ui;
    int nfoto;
    int radio;
};

#endif // HISTLOCAL_H
