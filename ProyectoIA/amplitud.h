#ifndef AMPLITUD_H
#define AMPLITUD_H

#include <queue>
#include "nodo.h"
#include <stack>
#include "entorno.h"

class Amplitud
{
    queue<Nodo> colaNodos;
    Entorno miEntorno;
    Nodo nodoRaiz;
    int nodosCreados;
    int nodosExpandidos;
public:
    Amplitud();
    Amplitud(Nodo * nodoRaiz, Entorno entorno);
    Nodo * busquedaPreferente();
    void crearHijos(Nodo nodo);
    void crearNodo(int posIHijo, int posJHijo, Nodo nodoCabeza);
    estados toEstado(int itemEntorno);
    int validaObjetivo(int flagObjetivos, estados estado);
    stack<Nodo> pilaNodosExp;
};

#endif // AMPLITUD_H
