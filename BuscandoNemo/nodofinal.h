#ifndef NODOFINAL_H
#define NODOFINAL_H

#include "entorno.h"

// Posibles estados del problema
enum estados {onRobot, onRoca, onLibre, onTiburon, onTortuga, onDori, onMarlin, onNemo, onHumano};

class NodoFinal
{
    // Referencia al nodo padre
    NodoFinal * padre;
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
    NodoFinal();
    // Metodo constructor para un Nodo Raiz
    NodoFinal(int p_coordI, int p_coordJ, estados p_estado, Entorno p_entorno);
    NodoFinal(int p_coordI, int p_coordJ, estados p_estado);
    // SETTERS
    void setCoords(int p_coordI, int p_coordJ);
    void setEstado(estados p_estado);
    void setNodoPadre(NodoFinal * p_padre);
    void setEntorno(Entorno p_entorno);
    void setProfundidad(int p_profundidad);
    void setCostoAcumulado(double p_costoAcumulado);
    void setHeuristica(double p_heuristica);
    void setFlagObjetivos(int p_flagObjetivos);
    // GETTERS
    int getCoordI();
    int getCoordJ();
    estados getEstado();
    NodoFinal * getNodoPadre();
    Entorno getEntorno();
    int getProfundidad();
    double getCostoAcumulado();
    double getHeuristica();
    int getFlagObjetivos();
    // Funciones miembro
    bool esMeta();
};

#endif // NODOFINAL_H
