#ifndef NODO_H
#define NODO_H

#include "entorno.h"

// Posibles estados del problema
enum estados {onRobot, onRoca, onLibre, onTiburon, onTortuga, onDori, onMarlin, onNemo, onHumano};

class Nodo
{
    // Referencia al nodo padre
    string * padre;
    // Profundidad del nodo en el arbol
    int profundidad;
    // Costo Acumulado de llegar al nodo
    double costoAcumulado;
    // Variable que marca los objetivos encontrados, en orden, primero 1, 2 y 3 (Si es 3 significa que ha encontrado 1 y 2)
    int flagObjetivos;
    // Coordenada I del nodo en el Entorno
    int coordI;
    // Coordenada I del nodo en el Entorno
    int coordJ;
    // Heuristica
    double heuristica;
    // Entorno del problema
    Entorno entorno;
    // Estado donde esta el nodo
    estados estadoNodo;
public:
    Nodo();
    // Metodo constructor para un Nodo Raiz
    Nodo(int p_coordI, int p_coordJ, estados p_estado, Entorno p_entorno);
    Nodo(int p_coordI, int p_coordJ, estados p_estado);
    // SETTERS
    void setCoords(int p_coordI, int p_coordJ);
    void setEstado(estados p_estado);
    void setNodoPadre(string * p_padre);
    void setEntorno(Entorno p_entorno);
    void setProfundidad(int p_profundidad);
    void setCostoAcumulado(double p_costoAcumulado);
    void setHeuristica(double p_heuristica);
    void setFlagObjetivos(int p_flagObjetivos);
    // GETTERS
    int getCoordI();
    int getCoordJ();
    estados getEstado();
    string * getNodoPadre();
    Entorno getEntorno();
    int getProfundidad();
    double getCostoAcumulado();
    double getHeuristica();
    int getFlagObjetivos();
    // Funciones miembro
    bool esMeta();
};

#endif // NODO_H

