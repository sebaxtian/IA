#ifndef PROFUNDIDAD_H
#define PROFUNDIDAD_H


#include "nodo.h"
#include "entorno.h"
#include <stack>



class Profundidad
{
    stack<Nodo> pilaNodos;
    Entorno miEntorno;
    Nodo nodoRaiz;
    bool ind_evita_devolverse;
    int nodosCreados;
    int nodosExpandidos;
    double costoSolucion;
public:
    Profundidad();
    Profundidad(Nodo * nodoRaiz, Entorno entorno, bool ind_evita_devol);
    stack<string> pilaCaminoNodosExp;
    string * busquedaProfundidad();
    int getNodosCreados();
    int getNodosExpandidos();
    double getCostoSolucion();
    void crearHijos(Nodo nodo);
    void crearNodo(int posIHijo, int posJHijo, Nodo nodoCabeza);
    // Configura el orden de los operadores
    void setOperadores();
    estados toEstado(int itemEntorno);
    // operadores
    // Mover derecha
    void moverDerecha(int derecha, int anchoEntorno, int posI, int posIPadre, int posJPadre, estados estadoCabeza, Nodo nodoCabeza);
    // Mover abajo
    void moverAbajo(int abajo, int altoEntorno, int posJ, int posJPadre, int posIPadre, estados estadoCabeza, Nodo nodoCabeza);
    // Mover izquierda
    void moverIzquierda(int izquierda, int posI, int posIPadre, int posJPadre, estados estadoCabeza, Nodo nodoCabeza);
    // Mover arriba
    void moverArriba(int arriba, int posJ, int posJPadre, int posIPadre, estados estadoCabeza, Nodo nodoCabeza);
};

#endif // PROFUNDIDAD_H
