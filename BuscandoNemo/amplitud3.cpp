#include "amplitud3.h"

Amplitud3::Amplitud3(Nodo3 nodoRaiz, Entorno entorno)
{
    this->nodoRaiz = nodoRaiz;
    this->entorno = entorno;
}

Nodo3 Amplitud3::getNodoRaiz()
{
    return this->nodoRaiz;
}

Entorno Amplitud3::getEntorno()
{
    return this->entorno;
}

int Amplitud3::getNodosCreados()
{
    return this->nodosCreados;
}

int Amplitud3::getNodosExpandidos()
{
    return this->nodosExpandidos;
}

void Amplitud3::makeBusqueda()
{

}

void Amplitud3::crearHijos(Nodo3 nodoCabeza)
{

}

casillas Amplitud3::toCasilla(int itemEntorno)
{
    casillas casilla;
    switch (itemEntorno)
    {
        case 2:
            casilla = onLibre;
            break;
        case 3:
            casilla = onTiburon;
            break;
        case 4:
            casilla = onTortuga;
            break;
        case 5:
            casilla = onDori;
            break;
        case 6:
            casilla = onMarlin;
            break;
        case 7:
            casilla = onNemo;
            break;
        case 8:
            casilla = onHumano;
            break;
        default:
            break;
    }
    return casilla;
}

int Amplitud3::validaObjetivo(int flagObjetivos, casillas casilla)
{
    if(casilla == onNemo && flagObjetivos < 1)
    {
        return flagObjetivos++;
    }
    if(casilla == onMarlin && flagObjetivos < 2)
    {
        return flagObjetivos++;
    }
    if(casilla == onDori && flagObjetivos < 3)
    {
        return flagObjetivos++;
    }
    return flagObjetivos;
}

void Amplitud3::imprimirSolucion(Nodo3 nodo)
{
    Nodo3 nodoPadre = nodo.getNodoPadre();
    int profundidad = nodo.getProfundidad();
    while(nodoPadre != NULL)
    {
        cout << "Paso" << profundidad << ": (" << nodoPadre.getCoordI() << ", " << nodoPadre.getCoordJ() << ")" << endl;
        nodoPadre = nodoPadre.getNodoPadre();
        profundidad--;
    }
}
