#ifndef AMPLITUD3_H
#define AMPLITUD3_H

#include <iostream>
#include <queue>
#include "nodo3.h"
#include "entorno.h"

using namespace std;

class Amplitud3
{
    // Cola de Nodos expandidos
    queue<Nodo3> colaNodos;
    // Nodo Raiz del problema
    Nodo3 nodoRaiz;
    // Entorno del problema
    Entorno entorno;
    // Candidad de Nodos creados
    int nodosCreados;
    // Cantidad de Nodos expandidos
    int nodosExpandidos;
public:
    // Constructor de clase inicializado
    Amplitud3(Nodo3 nodoRaiz, Entorno entorno);
    // GETTERS
    Nodo3 getNodoRaiz();
    Entorno getEntorno();
    int getNodosCreados();
    int getNodosExpandidos();
    // Funciones miembro
    void makeBusqueda();
    void crearHijos(Nodo3 nodoCabeza);
    casillas toCasilla(int itemEntorno);
    int validaObjetivo(int flagObjetivos, casillas casilla);
    void imprimirSolucion(Nodo3 nodo);
};

#endif // AMPLITUD3_H
