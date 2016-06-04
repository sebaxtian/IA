#include "costouniforme.h"

CostoUniforme::CostoUniforme()
{
    this->nodosCreados = 0;
    this->nodosExpandidos = 0;
    this->costoSolucion = 0;
}


CostoUniforme::CostoUniforme(Nodo *nodoRaiz, Entorno entorno, bool ind_evita_devol)
{
    this->nodoRaiz = *nodoRaiz;
    this->miEntorno = entorno;
    this->ind_evita_devolverse = ind_evita_devol;
    this->nodosCreados = 0;
    this->nodosExpandidos = 0;
    this->costoSolucion = 0;
}


int CostoUniforme::getNodosCreados()
{
    return this->nodosCreados;
}

int CostoUniforme::getNodosExpandidos()
{
    return this->nodosExpandidos;
}

double CostoUniforme::getCostoSolucion()
{
    return this->costoSolucion;
}


string * CostoUniforme::busquedaUniforme()
{
    cout << "Inicia Busqueda Uniforme" << endl;
    string * solucion;

    bool termina = false;
    int parada = 1000000;
    Nodo nodoCabeza;

    //while(!termina && parada > 0)
    while(!termina)
    {

    }

    return solucion;
}


