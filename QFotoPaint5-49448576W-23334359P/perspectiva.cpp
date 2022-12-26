#include "perspectiva.h"
#include "ui_perspectiva.h"
#include "imagenes.h"

int corresp[MAX_VENTANAS];
int nfoto1p, nfoto2p;
Point2f ptpers[2][4];


void pintar_esquinas ()
{
    Mat cop = foto [nfoto1p].img.clone ();
    for (int i = 0; i < 4; i++)
        line(cop, ptpers[0][i], ptpers[0][(i+1)%4], CV_RGB(0,0,0), 2);
    for (int i = 0; i < 4; i++)
        circle(cop, ptpers[0][i], 8, CV_RGB(255,0,0), -1);
    imshow("Origen", cop);
}

// Nos quedamos con el punto mas cercano a donde se ha hecho click
void callback_pers(int evento, int x, int y, int flags, void *num)
{
    if (flags==EVENT_FLAG_LBUTTON) {
        int nimg = (int)num;
        int vmin = 300;
        int pmin = 0;
        for(int i = 0; i<4; i++) {
            int dact = abs(x - ptpers[nimg][i].x) + abs(y - ptpers[nimg][i].y);
            if(dact < vmin) {
                vmin = dact;
                pmin = i;
            }
        }
        if (vmin<300) {
            ptpers [nimg][pmin].x = x;
            ptpers [nimg] [pmin].y = y;
            ver_perspectiva(nfoto1p, nfoto2p, ptpers[0], ptpers[1]);
            if(nimg == 0)
                pintar_esquinas();
        }
    }
}

Perspectiva::Perspectiva(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Perspectiva)
{
    ui->setupUi(this);
    int numImg = 0;
    for(int i = 0; i<MAX_VENTANAS; i++) {
        if(foto[i].usada){
            ui->listWidget->addItem(QString::fromStdString(foto[i].nombre));
            ui->listWidget_2->addItem(QString::fromStdString(foto[i].nombre));
            corresp[numImg++] = i;  // nos indica a que imagen del array de foto corresponde
        }
    }
    nfoto1p = corresp[0];
    nfoto2p = foto_activa();
    int W1= foto [nfoto1p].img.cols;
    int H1= foto [nfoto1p].img.rows;
    int W2= foto[nfoto2p].img.cols;
    int H2= foto[nfoto2p].img.rows;
    ptpers[0][0]= Point2f(0, 0);
    ptpers[0][1]= Point2f(W1, 0);
    ptpers[0][2]= Point2f(W1, H1);
    ptpers[0][3] = Point2f(0, H1) ;
    ptpers[1][0]= Point2f(0, 0);
    ptpers[1][1]= Point2f(W2, 0);
    ptpers[1][2]= Point2f(W2, H2);
    ptpers[1][3]= Point2f(0, H2);
    pintar_esquinas();
    ver_perspectiva(nfoto1p, nfoto2p, ptpers[0], ptpers [1]);
    setMouseCallback("Origen", callback_pers, (void*)0) ;
    setMouseCallback("Perspectiva", callback_pers, (void*)1);
}

Perspectiva::~Perspectiva()
{
    delete ui;
}

void Perspectiva::on_buttonBox_accepted()
{
    ver_perspectiva(nfoto1p, nfoto2p, ptpers[0], ptpers[1], true);
    destroyWindow("Origen");
    destroyWindow("Perspectiva");
}

void Perspectiva::on_buttonBox_rejected()
{
    destroyWindow("Origen");
    destroyWindow("Perspectiva");
}

void Perspectiva::on_listWidget_currentRowChanged(int currentRow)
{
    nfoto1p = corresp[currentRow];
    pintar_esquinas();
    ver_perspectiva(nfoto1p, nfoto2p, ptpers[0], ptpers[1]);
}

void Perspectiva::on_listWidget_2_currentRowChanged(int currentRow)
{
    nfoto2p = corresp[currentRow];
    pintar_esquinas();
    ver_perspectiva(nfoto1p, nfoto2p, ptpers[0], ptpers[1]);
}
