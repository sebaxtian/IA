#ifndef COSTOUNIFORME_H
#define COSTOUNIFORME_H

#include <queue>
#include "nodo.h"
#include "entorno.h"
#include <stack>


//Función de comparación
//El operador le da mejor prioridad a los menores, si lo desea al reves cambie el operador por <=

class CompararPrioridad
{
public:
  CompararPrioridad()
    {}
  bool operator() (const Nodo& nodoA, const Nodo& nodoB) const
  {
     // cout << "nodoA.getCostoAcumulado() = " << nodoA.getCostoAcumulado() << endl;
      Nodo  nodA = nodoA;
      Nodo  nodB = nodoB;
      return (nodA.getCostoAcumulado() >= nodB.getCostoAcumulado());
  }
};


class CostoUniforme
{
    priority_queue<Nodo, vector<Nodo>, CompararPrioridad> colaPrioridadNodos;
    Entorno miEntorno;
    Nodo nodoRaiz;
    bool ind_evita_devolverse;
    int nodosCreados;
    int nodosExpandidos;
    double costoSolucion;
    double factorRamificacion;
    int profundidad;
public:
    CostoUniforme();
    CostoUniforme(Nodo * nodoRaiz, Entorno entorno, bool ind_evita_devol);
    stack<string> pilaCaminoNodosExp;
    string * busquedaUniforme();
    int getNodosCreados();
    int getNodosExpandidos();
    double getCostoSolucion();
    void crearHijos(Nodo nodo);
    void crearNodo(int posIHijo, int posJHijo, Nodo nodoCabeza);
    estados toEstado(int itemEntorno);
    double getFactorRamificacion();
    int getProfundidad();
};

#endif // COSTOUNIFORME_H
