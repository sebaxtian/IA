/*#ifndef AMPLITUD3_H
#define AMPLITUD3_H

#include <iostream>
#include <queue>
#include <string.h>
#include "nodo3.h"
#include "entorno.h"

using namespace std;

class Amplitud3
{
    // Cola de Nodos expandidos
    queue<Nodo3> colaNodos;
    // Nodo Raiz del problema
    Nodo3 nodoRaiz;
    // Nodo Solicion del problema
    Nodo3 nodoSolucion;
    // Entorno del problema
    Entorno entorno;
    // Candidad de Nodos creados
    int nodosCreados;
    // Cantidad de Nodos expandidos
    int nodosExpandidos;
public:
    Amplitud3();
    // Constructor de clase inicializado
    Amplitud3(Nodo3 nodoRaiz, Entorno entorno);
    // GETTERS
    Nodo3 getNodoRaiz();
    Nodo3 getNodoSolucion();
    Entorno getEntorno();
    int getNodosCreados();
    int getNodosExpandidos();
    // Funciones miembro
    void makeBusqueda();
    void crearHijos(Nodo3 nodoCabeza);
    void crearNodo(int posIHijo, int posJHijo, Nodo3 nodoCabeza);
    casillas toCasilla(int itemEntorno);
    int validaObjetivo(int flagObjetivos, casillas casilla);
    void imprimirSolucion(Nodo3 nodo);
};

#endif // AMPLITUD3_H
*/
