/*
#ifndef AMPLITUD2_H
#define AMPLITUD2_H

#include <iostream>
#include <queue>
#include "nodo2.h"
#include "entorno.h"

using namespace std;

class Amplitud2
{
    // Cola de nodos expandidos
    queue<Nodo2> colaNodos;
    // Nodo raiz del problema
    Nodo2 raiz;
    // Entorno del problema
    Entorno entorno;
    // Candidad de nodos creados
    int nodosCreados;
    // Cantidad de nodos expandidos
    int nodosExpandidos;
    // Contador para asignar un codigo a cada nodo generado
    int codNextNodo;
public:
    // Constructor de clase vacio
    Amplitud2();
    // Constructor de clase inicializado
    Amplitud2(Nodo2 raiz, Entorno entorno);
    // GETTERS
    int getNumNodosCreados();
    int getNumNodosExpandidos();
    // Funciones miembro
    queue<string> makeBusqueda();
    void crearNodosHijos(Nodo2 nodoCabeza);
    int nextCodNodo();
    estados getEstado(int item);
    int getNewFlagElementos(int flagElementos, estados estadoActual);
};

#endif // AMPLITUD2_H
*/
