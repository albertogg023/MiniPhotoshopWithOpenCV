#ifndef INFORMACION_H
#define INFORMACION_H

#include <QDialog>
#include <string>
using namespace std;
#include <opencv2/opencv.hpp>
using namespace cv;

namespace Ui {
class Informacion;
}

class Informacion : public QDialog
{
    Q_OBJECT

public:
    explicit Informacion(Mat img,QWidget *parent = nullptr);
    ~Informacion();

private slots:

private:
    Ui::Informacion *ui;
};

#endif // INFORMACION_H
