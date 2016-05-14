#ifndef NODO3_H
#define NODO3_H

#include <iostream>
#include <string>

using namespace std;

class Nodo3
{
    // Referencia al nodo padre
    //Nodo3 nodoPadre;
    string camino;
    // Profundidad del nodo en el arbol
    int profundidad;
    // Costo Acumulado de llegar al nodo
    int costoAcumulado;
    // Variable que marca los objetivos encontrados, en orden, primero 1, 2 y 3 (Si es 3 significa que ha encontrado 1 y 2)
    int flagObjetivos;
    // Coordenada I del nodo en el Entorno
    int coordI;
    // Coordenada I del nodo en el Entorno
    int coordJ;
public:
    Nodo3();
    // Metodo constructor para un Nodo Raiz
    Nodo3(int coordI, int coordJ);
    // Metodo constructor para un Nodo Hijo
    //Nodo3(Nodo3 nodoPadre, int profundidad, int costoAcumulado, int flagObjetivos, int coordI, int coordJ);
    Nodo3(string camino, int profundidad, int costoAcumulado, int flagObjetivos, int coordI, int coordJ);
    // GETTERS
    //Nodo3* getNodoPadre();
    string getCamino();
    int getProfundidad();
    int getCostoAcumulado();
    int getFlagObjetivos();
    int getCoordI();
    int getCoordJ();
    // Funciones miembro
    bool esMeta();
};

#endif // NODO3_H
