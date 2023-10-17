#ifndef PERSPECTIVA_H
#define PERSPECTIVA_H

#include <QDialog>

namespace Ui {
class Perspectiva;
}

class Perspectiva : public QDialog
{
    Q_OBJECT

public:
    explicit Perspectiva(QWidget *parent = nullptr);
    ~Perspectiva();

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

    void on_listWidget_currentRowChanged(int currentRow);

    void on_listWidget_2_currentRowChanged(int currentRow);

private:
    Ui::Perspectiva *ui;
};

#endif // PERSPECTIVA_H
