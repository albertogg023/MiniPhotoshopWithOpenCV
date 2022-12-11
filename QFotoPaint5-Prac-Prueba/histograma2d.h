#ifndef HISTOGRAMA2D_H
#define HISTOGRAMA2D_H

#include <QDialog>

namespace Ui {
class Histograma2D;
}

class Histograma2D : public QDialog
{
    Q_OBJECT

public:
    explicit Histograma2D(QWidget *parent = nullptr);
    ~Histograma2D();

private:
    Ui::Histograma2D *ui;
};

#endif // HISTOGRAMA2D_H
