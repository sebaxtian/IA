#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include "nodo.h"
#include "entorno.h"

using namespace std;


#ifndef AMPLITUD_H
#define AMPLITUD_H


class Amplitud
{
    queue<Nodo> colaNodos;
    Entorno miEntorno;
    Nodo nodoRaiz;
    int nodosCreados;
    int nodosExpandidos;
public:
    Amplitud();
    Amplitud(Nodo *nodoRaiz, Entorno entorno);
    Nodo *busquedaPreferente();
    void expandirNodos(Nodo nodo);
    stack<Nodo> pilaNodosExp;
};

#endif // AMPLITUD_H
