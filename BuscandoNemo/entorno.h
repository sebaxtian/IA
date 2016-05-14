#include <iostream>

using namespace std;

#ifndef ENTORNO_H
#define ENTORNO_H

// Posibles casillas donde puede estar ubicado el Robot
enum casillas {onLibre, onTiburon, onTortuga, onHumano, onDori, onMarlin, onNemo};

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
