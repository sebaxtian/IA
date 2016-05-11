#include "nodo2.h"

// Constructor de clase para un Nodo Raiz
Nodo2::Nodo2()
{
    this->coords[0] = 0;
    this->coords[1] = 0;
    this->codNodo = 0;
    this->referenciaPadre = 0;
    this->operadorAplicado = arriba;
    this->profundidad = 0;
    this->costoAcumulado = 0;
    this->estadoActual = onLibre;
    this->camino.push("0,0");
    this->flagElementos = 0;
}

// Constructor de clase para crear un Nodo Cualquiera
Nodo2::Nodo2(int coords[2], int codNodo, int refPadre, operadores opAplicado, int profundidad, int costoAcu, estados estadoActual, queue<string> camino, int flagElementos)
{
    this->coords[0] = coords[0];
    this->coords[1] = coords[1];
    this->codNodo = codNodo;
    this->referenciaPadre = refPadre;
    this->operadorAplicado = opAplicado;
    this->profundidad = profundidad;
    this->costoAcumulado = costoAcu;
    this->estadoActual = estadoActual;
    this->camino = camino;
    this->flagElementos = flagElementos;
}


// SETTERS
void Nodo2::setCoords(int coords[])
{
    this->coords[0] = coords[0];
    this->coords[1] = coords[1];
}

void Nodo2::setCodNodo(int codNodo)
{
    this->codNodo = codNodo;
}
void Nodo2::setCostoAcumulado(int costoAcumulado)
{
    this->costoAcumulado = costoAcumulado;
}
void Nodo2::setEstadoActual(estados estadoActual)
{
    this->estadoActual = estadoActual;
}
void Nodo2::setOpeAplicado(operadores operador)
{
    this->operadorAplicado = operador;
}
void Nodo2::setProfundidad(int profundidad)
{
    this->profundidad = profundidad;
}
void Nodo2::setRefPadre(int refPadre)
{
    this->referenciaPadre = refPadre;
}
void Nodo2::setCamino(queue<string> camino)
{
    this->camino = camino;
}


// GETTERS
int Nodo2::getCodNodo()
{
    return this->codNodo;
}
int Nodo2::getCostoAcumulado()
{
    return this->costoAcumulado;
}
estados Nodo2::getEstadoActual()
{
    return this->estadoActual;
}
operadores Nodo2::getOpeAplicado()
{
    return this->operadorAplicado;
}
int Nodo2::getProfundidad()
{
    return this->profundidad;
}
int Nodo2::getRefPadre()
{
    return this->referenciaPadre;
}
queue<string> Nodo2::getCamino()
{
    return this->camino;
}
int Nodo2::getFlagElementos()
{
    return this->flagElementos;
}


// Funciones miembro
int Nodo2::getPosI()
{
    return this->coords[0];
}
int Nodo2::getPosJ()
{
    return this->coords[1];
}
bool Nodo2::esMeta()
{
    if(this->flagElementos == 3)
    {
        return true;
    }
    return false;
}
