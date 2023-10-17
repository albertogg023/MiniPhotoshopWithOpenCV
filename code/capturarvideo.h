#ifndef CAPTURARVIDEO_H
#define CAPTURARVIDEO_H

#include <QDialog>
#include <opencv2/opencv.hpp>
using namespace cv;

namespace Ui {
class Capturarvideo;
}

class Capturarvideo : public QDialog
{
    Q_OBJECT

public:
    explicit Capturarvideo(QString nombre, QWidget *parent = nullptr);
    ~Capturarvideo();
    bool isOpened();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_spinBox_valueChanged(int arg1);

    void on_Capturarvideo_accepted();
    
    void on_Capturarvideo_rejected();
    
private:
    Ui::Capturarvideo *ui;
    VideoCapture cap;
};

#endif // CAPTURARVIDEO_H
