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
};

#endif // ENTORNO_H
