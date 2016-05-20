#ifndef AMPLITUDFINAL_H
#define AMPLITUDFINAL_H

#include <queue>
#include "nodofinal.h"
#include <stack>

class AmplitudFinal
{
    queue<NodoFinal> colaNodos;
    Entorno miEntorno;
    NodoFinal nodoRaiz;
    int nodosCreados;
    int nodosExpandidos;
public:
    AmplitudFinal();
    AmplitudFinal(NodoFinal * nodoRaiz, Entorno entorno);
    NodoFinal * busquedaPreferente();
    void crearHijos(NodoFinal nodo);
    void crearNodo(int posIHijo, int posJHijo, NodoFinal nodoCabeza);
    estados toEstado(int itemEntorno);
    int validaObjetivo(int flagObjetivos, estados estado);
    stack<NodoFinal> pilaNodosExp;
};

#endif // AMPLITUDFINAL_H
