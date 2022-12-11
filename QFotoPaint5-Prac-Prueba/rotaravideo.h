#ifndef ROTARAVIDEO_H
#define ROTARAVIDEO_H

#include <QDialog>

namespace Ui {
    class rotaravideo;
}

class rotaravideo : public QDialog {
    Q_OBJECT
public:
    rotaravideo(QWidget *parent = nullptr);
    ~rotaravideo();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::rotaravideo *ui;
    int nfoto;

private slots:
    void on_rotaravideo_accepted();
};

#endif // ROTARAVIDEO_H
