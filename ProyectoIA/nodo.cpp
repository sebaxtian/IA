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

Nodo::Nodo(int p_coordI, int p_coordJ, int p_coordIPadre, int p_coordJPadre, estados p_estado, int **p_entorno)
{
    this->coordI = p_coordI;
    this->coordJ = p_coordJ;
    this->coordIPadre = p_coordIPadre;
    this->coordJPadre = p_coordJPadre;
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
    // Indicador para saber si esta en compañia de la tortoga
    this->indAyudaTortuga = false;
    // Cantidad de pasos que lleva con la tortuga
    this->pasosAyudaTortuga = 0;
    // Posicion del array list en la que debe iniciar a buscar los ciclos.
    this->posIniBuscarCiclo = 0;
}

/*
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
    // Indicador para saber si esta en compañia de la tortoga
    this->indAyudaTortuga = false;
    // Cantidad de pasos que lleva con la tortuga
    this->pasosAyudaTortuga = 0;
}
*/

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
/*
Entorno Nodo::getEntorno()
{
    return this->entorno;
}
*/

bool Nodo::getIndAyudaTortuga() {
    return this->indAyudaTortuga;
}

int Nodo::getPasosAyudaTortuga() {
    return this->pasosAyudaTortuga;
}


int** Nodo::getEntorno() {
    return this->entorno;
}

int Nodo::getPosIniBuscarCiclo() {
    return this->posIniBuscarCiclo;
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

void Nodo::setEntorno(int CoordI, int CoordJ, int estado){
    this->entorno[CoordI][CoordJ] = estado;
}


/*
void Nodo::setEntorno(Entorno p_entorno)
{
    this->entorno = p_entorno;
}
*/

void setEntorno(int CoordI, int CoordJ, int estado);

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

void Nodo::setIndAyudaTortuga(bool p_indAyudaTortuga)
{
    this->indAyudaTortuga = p_indAyudaTortuga;
}

void Nodo::setPasosAyudaTortuga(int p_pasosAyudaTortuga)
{
    this->pasosAyudaTortuga = p_pasosAyudaTortuga;
}

void Nodo::setPosIniBuscarCiclo(int p_posIni) {
    this->posIniBuscarCiclo = p_posIni;
}

// Funciones miembro
bool Nodo::esMeta(int p_posArrCamino)
{

    if(this->estadoNodo == onNemo && this->flagObjetivos == 0)
    {
        this->flagObjetivos++;
        this->posIniBuscarCiclo = p_posArrCamino;
    }
    if(this->estadoNodo == onMarlin && this->flagObjetivos == 1)
    {
        this->flagObjetivos++;
        this->posIniBuscarCiclo = p_posArrCamino;
    }
    if(this->estadoNodo == onDori && this->flagObjetivos == 2)
    {
        this->flagObjetivos++;
        this->posIniBuscarCiclo = p_posArrCamino;
    }

    if(this->flagObjetivos == 3)
    {
        return true;
    }

    return false;
}

