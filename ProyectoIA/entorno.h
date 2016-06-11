#ifndef ENTORNO_H
#define ENTORNO_H

#include <iostream>

using namespace std;

class Entorno
{
    int ancho = 0;
    int alto = 0;
    int posInitRobot[2];
    int **ambiente;
    int indMetaEncontrada;
    int posDori[2];
    int posNemo[2];
    int posMarlin[2];
public:
    Entorno();
    void loadFile(string pathFile);
    void imprimir();
    int getAncho();
    int getAlto();
    int** getAmbiente();
    void setAmbiente(int CoordI, int CoordJ, int estado);
    int* getPosInitRobot();
    int getIndMetaEncontrada();
    void setIndMetaEncontrada();
    int* getPosDori();
    int* getPosNemo();
    int* getPosMarlin();
    string validarEntorno();
};

#endif // ENTORNO_H
