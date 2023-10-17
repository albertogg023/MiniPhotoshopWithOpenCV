#ifndef ACERCADE_H
#define ACERCADE_H

#include <QDialog>

namespace Ui {
    class acercade;
}

class acercade : public QDialog {
    Q_OBJECT
public:
    acercade(QWidget *parent = nullptr);
    ~acercade();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::acercade *ui;

private slots:
    void on_commandLinkButton_clicked();
};

#endif // ACERCADE_H
