#ifndef VIDEO_H
#define VIDEO_H

#include "imagenes.h"
// Se usa el módulo de procesamiento de imágenes

extern string FiltroVideo;

///////////////////////////////////////////////////////////////////
/////////  FUNCIONES DE PROCESAMIENTO DE VIDEO       //////////////
///////////////////////////////////////////////////////////////////

void rotar_video (int nfoto, string nombre, int modo, int nframes, int codec, double fps= 30.0);
// Crea un vídeo, con el nombre dado (que debe tener extensión .avi, .mp4 o .wmv) de tamaño
// nframes, con una rotación de 360º de la imagen nfoto

int inic_camara (int numero= 0);
// Inicializa la cámara con el número de índice indicado. La imagen se muestra
// en una ventana. Si no se puede abrir la cámara devuelve 0. En otro caso
// devuelve el número de milisegundos entre cada par de frames

void fin_camara (void);
// Finaliza la captura de cámara, cerrando la ventana correspondiente

void movimiento(string nombre, int framei,int frmaf, int nres);
// Operación de acumular movimeinto en vídeo.

void acumular_media (bool primera= false);
// Captura una imagen de la cámara y la acumula en una media. La cámara debe
// estar inicializada. Si primera==true significa que es la primera imagen

void media_a_nueva (int nfoto);
// Almacena la imagen media actual en la entrada nfoto

void mostrar_camara (void);
// Captura una imagen de la cámara y la muestra en la ventana correspondiente

void capturar_camara(int nres);
//Capturar de cámara

#endif // VIDEO_H
