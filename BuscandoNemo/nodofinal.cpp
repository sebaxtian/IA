#include "nodofinal.h"

NodoFinal::NodoFinal()
{
    // Profundidad del nodo en el arbol
    this->profundidad = 0;
    // Costo Acumulado de llegar al nodo
    this->costoAcumulado = 0;
    // Variable que marca los objetivos encontrados, en orden, primero 1, 2 y 3 (Si es 3 significa que ha encontrado 1 y 2)
    this->flagObjetivos = 0;
    // Coordenada I del nodo en el Entorno
    this->coordI = 0;
    // Coordenada I del nodo en el Entorno
    this->coordJ = 0;
    // Heuristica
    this->heuristica = 0;
}

NodoFinal::NodoFinal(int p_coordI, int p_coordJ, estados p_estado, Entorno p_entorno)
{
    this->coordI = p_coordI;
    this->coordJ = p_coordJ;
    this->estadoNodo = p_estado;
    this->entorno = p_entorno;
    // Profundidad del nodo en el arbol
    this->profundidad = 0;
    // Costo Acumulado de llegar al nodo
    this->costoAcumulado = 0;
    // Variable que marca los objetivos encontrados, en orden, primero 1, 2 y 3 (Si es 3 significa que ha encontrado 1 y 2)
    this->flagObjetivos = 0;
    // Heuristica
    this->heuristica = 0;
}


NodoFinal::NodoFinal(int p_coordI, int p_coordJ, estados p_estado)
{
    this->coordI = p_coordI;
    this->coordJ = p_coordJ;
    this->estadoNodo = p_estado;
    // Profundidad del nodo en el arbol
    this->profundidad = 0;
    // Costo Acumulado de llegar al nodo
    this->costoAcumulado = 0;
    // Variable que marca los objetivos encontrados, en orden, primero 1, 2 y 3 (Si es 3 significa que ha encontrado 1 y 2)
    this->flagObjetivos = 0;
    // Heuristica
    this->heuristica = 0;
}


NodoFinal * NodoFinal::getNodoPadre()
{
    return this->padre;
}

int NodoFinal::getProfundidad()
{
    return this->profundidad;
}

double NodoFinal::getCostoAcumulado()
{
    return this->costoAcumulado;
}

int NodoFinal::getFlagObjetivos()
{
    return this->flagObjetivos;
}

int NodoFinal::getCoordI()
{
    return this->coordI;
}

int NodoFinal::getCoordJ()
{
    return this->coordJ;
}

double NodoFinal::getHeuristica()
{
    return this->heuristica;
}

Entorno NodoFinal::getEntorno()
{
    return this->entorno;
}



void NodoFinal::setCoords(int p_coordI, int p_coordJ)
{
    this->coordI = p_coordI;
    this->coordJ = p_coordJ;
}

void NodoFinal::setEstado(estados p_estado)
{
    this->estadoNodo = p_estado;
}

void NodoFinal::setNodoPadre(NodoFinal * p_padre)
{
    this->padre = p_padre;
}

void NodoFinal::setEntorno(Entorno p_entorno)
{
    this->entorno = p_entorno;
}

void NodoFinal::setProfundidad(int p_profundidad)
{
    this->profundidad = p_profundidad;
}

void NodoFinal::setCostoAcumulado(double p_costoAcumulado)
{
    this->costoAcumulado = p_costoAcumulado;
}

void NodoFinal::setHeuristica(double p_heuristica)
{
    this->heuristica = p_heuristica;
}

void NodoFinal::setFlagObjetivos(int p_flagObjetivos)
{
    this->flagObjetivos = p_flagObjetivos;
}



// Funciones miembro
bool NodoFinal::esMeta()
{

    if(this->estadoNodo == onNemo && this->flagObjetivos == 0)
    {
        this->flagObjetivos++;
    }
    if(this->estadoNodo == onMarlin && this->flagObjetivos == 1)
    {
        this->flagObjetivos++;
    }
    if(this->estadoNodo == onDori && this->flagObjetivos == 2)
    {
        this->flagObjetivos++;
    }

    if(this->flagObjetivos == 3)
    {
        return true;
    }

    return false;
}

