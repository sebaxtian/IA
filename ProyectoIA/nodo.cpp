#include "nodo.h"

Nodo::Nodo()
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

Nodo::Nodo(int p_coordI, int p_coordJ, estados p_estado, Entorno p_entorno)
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


Nodo::Nodo(int p_coordI, int p_coordJ, int p_coordIPadre, int p_coordJPadre, estados p_estado)
{
    this->coordI = p_coordI;
    this->coordJ = p_coordJ;
    this->coordIPadre = p_coordIPadre;
    this->coordJPadre = p_coordJPadre;
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


string *Nodo::getNodoPadre()
{
    return this->padre;
}

int Nodo::getProfundidad()
{
    return this->profundidad;
}

double Nodo::getCostoAcumulado()
{
    return this->costoAcumulado;
}

int Nodo::getFlagObjetivos()
{
    return this->flagObjetivos;
}

int Nodo::getCoordI()
{
    return this->coordI;
}

int Nodo::getCoordJ()
{
    return this->coordJ;
}

int Nodo::getCoordIPadre()
{
    return this->coordIPadre;
}

int Nodo::getCoordJPadre()
{
    return this->coordJPadre;
}

double Nodo::getHeuristica()
{
    return this->heuristica;
}

Entorno Nodo::getEntorno()
{
    return this->entorno;
}



void Nodo::setCoords(int p_coordI, int p_coordJ)
{
    this->coordI = p_coordI;
    this->coordJ = p_coordJ;
}

void Nodo::setEstado(estados p_estado)
{
    this->estadoNodo = p_estado;
}

void Nodo::setNodoPadre(string * p_padre)
{
    this->padre = p_padre;
}

void Nodo::setEntorno(Entorno p_entorno)
{
    this->entorno = p_entorno;
}

void Nodo::setProfundidad(int p_profundidad)
{
    this->profundidad = p_profundidad;
}

void Nodo::setCostoAcumulado(double p_costoAcumulado)
{
    this->costoAcumulado = p_costoAcumulado;
}

void Nodo::setHeuristica(double p_heuristica)
{
    this->heuristica = p_heuristica;
}

void Nodo::setFlagObjetivos(int p_flagObjetivos)
{
    this->flagObjetivos = p_flagObjetivos;
}



// Funciones miembro
bool Nodo::esMeta()
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

