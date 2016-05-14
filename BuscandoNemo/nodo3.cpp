#include "nodo3.h"

Nodo3::Nodo3()
{

}

Nodo3::Nodo3(int coordI, int coordJ)
{
    //this->nodoPadre = NULL;
    this->camino = "0-0,";
    this->profundidad = 0;
    this->costoAcumulado = 0;
    this->flagObjetivos = 0;
    this->coordI = coordI;
    this->coordJ = coordJ;
    /*
    cout << "-- Nodo Raiz --" << endl;
    cout << "Camino: " << camino << endl;
    cout << "Profundidad: " << profundidad << endl;
    cout << "Costo Acumulado: " << costoAcumulado << endl;
    cout << "Objetivos: " << flagObjetivos << endl;
    */
}
/*
Nodo3::Nodo3(Nodo3* nodoPadre, int profundidad, int costoAcumulado, int flagObjetivos, int coordI, int coordJ)
{
    this->nodoPadre = nodoPadre;
    this->profundidad = profundidad;
    this->costoAcumulado = costoAcumulado;
    this->flagObjetivos = flagObjetivos;
    this->coordI = coordI;
    this->coordJ = coordJ;
}
*/
Nodo3::Nodo3(string camino, int profundidad, int costoAcumulado, int flagObjetivos, int coordI, int coordJ)
{
    //this->nodoPadre = nodoPadre;
    this->camino = camino;
    this->profundidad = profundidad;
    this->costoAcumulado = costoAcumulado;
    this->flagObjetivos = flagObjetivos;
    this->coordI = coordI;
    this->coordJ = coordJ;
    /*
    cout << "-- Nodo Hijo --" << endl;
    cout << "Camino: " << camino << endl;
    cout << "Profundidad: " << profundidad << endl;
    cout << "Costo Acumulado: " << costoAcumulado << endl;
    cout << "Objetivos: " << flagObjetivos << endl;
    */
}
/*
Nodo3* Nodo3::getNodoPadre()
{
    return this->nodoPadre;
}
*/
string Nodo3::getCamino()
{
    return this->camino;
}

int Nodo3::getProfundidad()
{
    return this->profundidad;
}

int Nodo3::getCostoAcumulado()
{
    return this->costoAcumulado;
}

int Nodo3::getFlagObjetivos()
{
    return this->flagObjetivos;
}

int Nodo3::getCoordI()
{
    return this->coordI;
}

int Nodo3::getCoordJ()
{
    return this->coordJ;
}


bool Nodo3::esMeta()
{
    if(this->flagObjetivos == 3)
    {
        return true;
    }
    return false;
}
