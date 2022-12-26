#ifndef DIALOGNUEVA_H
#define DIALOGNUEVA_H

#include <QDialog>

namespace Ui {
    class DialogNueva;
}

class DialogNueva : public QDialog {
    Q_OBJECT
public:
    DialogNueva(int numfoto, QWidget *parent = nullptr);
    ~DialogNueva();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DialogNueva *ui;
    QColor qcolor;
    int nfoto;

private slots:
    void on_pushButton_clicked();
    void on_DialogNueva_accepted();
};

#endif // DIALOGNUEVA_H
