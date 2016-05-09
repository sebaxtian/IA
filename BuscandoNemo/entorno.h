#include <iostream>

using namespace std;

#ifndef ENTORNO_H
#define ENTORNO_H


class Entorno
{
    int ancho = 0;
    int alto = 0;
    int **ambiente;
public:
    Entorno();
    void loadFile(string pathFile);
    void imprimir();
    int getAncho();
    int getAlto();
    int** getAmbiente();
};

#endif // ENTORNO_H
