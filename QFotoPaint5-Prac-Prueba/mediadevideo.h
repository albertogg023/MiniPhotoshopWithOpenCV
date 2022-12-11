#ifndef MEDIADEVIDEO_H
#define MEDIADEVIDEO_H

#include <QDialog>
#include <QTimer>

namespace Ui {
    class mediadevideo;
}

class mediadevideo : public QDialog {
    Q_OBJECT
public:
    mediadevideo(QWidget *parent = nullptr);
    ~mediadevideo();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::mediadevideo *ui;
    QTimer timer;
    bool acumulando;

private slots:
    void on_pushButton_5_clicked();
    void on_mediadevideo_destroyed();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_timer();
};

#endif // MEDIADEVIDEO_H
