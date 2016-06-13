#ifndef AASTERISCO_H
#define AASTERISCO_H


#include <queue>
#include "nodo.h"
#include "entorno.h"
#include <stack>

class CompararPrioridadHeuristaCosto
{
public:
  CompararPrioridadHeuristaCosto()
    {}
  bool operator() (const Nodo& nodoA, const Nodo& nodoB) const
  {
     // cout << "nodoA.getCostoAcumulado() = " << nodoA.getCostoAcumulado() << endl;
      Nodo  nodA = nodoA;
      Nodo  nodB = nodoB;
      return ((nodA.getHeuristica() + nodA.getCostoAcumulado()) > (nodB.getHeuristica() + nodB.getCostoAcumulado() ));
  }
};


class AAsterisco
{
    priority_queue<Nodo, vector<Nodo>, CompararPrioridadHeuristaCosto> colaPrioridadNodos;
    Entorno miEntorno;
    Nodo nodoRaiz;
    bool ind_evita_devolverse;
    int nodosCreados;
    int nodosExpandidos;
    double costoSolucion;
    double factorRamificacion;
    int profundidad;
    string indHeuristica;
public:
    AAsterisco();
    AAsterisco(Nodo * nodoRaiz, Entorno entorno, bool ind_evita_devol, string pindHeuristica);
    stack<string> pilaCaminoNodosExp;
    string * busquedaAAsterico();
    int getNodosCreados();
    int getNodosExpandidos();
    double getCostoSolucion();
    void crearHijos(Nodo nodo);
    void crearNodo(int posIHijo, int posJHijo, Nodo nodoCabeza);
    estados toEstado(int itemEntorno);
    double obtenerHeuristica(Nodo pnodo);
    double h_distanciaL(Nodo pnodo);
    double h_distanciaEuclideana(Nodo pnodo);
    double getFactorRamificacion();
    int getProfundidad();
};


#endif // AASTRISCO_H
