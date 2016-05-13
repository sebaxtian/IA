#include <iostream>
#include <queue>
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
    queue<string> busquedaPreferente();
    void expandirNodos(Nodo nodo);
};

#endif // AMPLITUD_H
