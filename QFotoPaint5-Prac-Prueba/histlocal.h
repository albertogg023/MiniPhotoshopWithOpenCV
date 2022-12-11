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
    explicit HistLocal(QWidget *parent = nullptr);
    ~HistLocal();

private:
    Ui::HistLocal *ui;
};

#endif // HISTLOCAL_H
