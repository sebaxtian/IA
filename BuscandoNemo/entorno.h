#include <iostream>

using namespace std;

#ifndef ENTORNO_H
#define ENTORNO_H

// Posibles casillas presentes en el entorno
enum casillas {onLibre, onTiburon, onTortuga, onHumano, onDori, onMarlin, onNemo, onRoca};

class Entorno
{
    int ancho = 0;
    int alto = 0;
    int **ambiente;
    int posInitRobot[2];
public:
    Entorno();
    void loadFile(string pathFile);
    void imprimir();
    int getAncho();
    int getAlto();
    int** getAmbiente();
    int* getPosInitRobot();
};

#endif // ENTORNO_H
