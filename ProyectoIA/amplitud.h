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
    bool ind_evita_devolverse;
    int nodosCreados;
    int nodosExpandidos;
    double costoSolucion;
    double factorRamificacion;
    int profundidad;
public:
    Amplitud();
    Amplitud(Nodo * nodoRaiz, Entorno entorno, bool ind_evita_devol);
    string * busquedaPreferente();
    void crearHijos(Nodo nodo);
    void crearNodo(int posIHijo, int posJHijo, Nodo nodoCabeza);
    estados toEstado(int itemEntorno);
    int validaObjetivo(int flagObjetivos, estados estado);
    stack<string> pilaCaminoNodosExp;
    int getNodosCreados();
    int getNodosExpandidos();
    double getCostoSolucion();
    double getFactorRamificacion();
    int getProfundidad();
};

#endif // AMPLITUD_H
