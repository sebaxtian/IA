#ifndef COSTOUNIFORME_H
#define COSTOUNIFORME_H

#include <queue>
#include "nodo.h"
#include "entorno.h"


//Función de comparación
//El operador le da mejor prioridad a los menores, si lo desea al reves cambie el operador por <=
/*
struct CompararPrioridad
{
    bool operator() (const Nodo &a, const Nodo &b) const
    {
        //return a.prioridad>=b.prioridad;
        return a.getCostoAcumulado() >= b.getCostoAcumulado();
    }

};
*/


class CostoUniforme
{
    //priority_queue<Nodo, vector<Nodo>, CompararPrioridad> colaPrioridadNodos;
    Entorno miEntorno;
    Nodo nodoRaiz;
    bool ind_evita_devolverse;
    int nodosCreados;
    int nodosExpandidos;
    double costoSolucion;
public:
    CostoUniforme();
    CostoUniforme(Nodo * nodoRaiz, Entorno entorno, bool ind_evita_devol);
    string * busquedaUniforme();
    int getNodosCreados();
    int getNodosExpandidos();
    double getCostoSolucion();
};

#endif // COSTOUNIFORME_H
