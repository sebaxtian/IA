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
    // Coordenada I del nodo padre
    int coordIPadre;
    // Coordenada I del nodo padre
    int coordJPadre;
    // Heuristica
    double heuristica;
    // Entorno del problema
     int **entorno;
    // Indicador para saber si esta en compañia de la tortoga
     bool indAyudaTortuga;
     // Cantidad de pasos que lleva con la tortuga
     int pasosAyudaTortuga;
    // Estado donde esta el nodo
    estados estadoNodo;
    // Posicion del array list en la que debe iniciar a buscar los ciclos.
    int posIniBuscarCiclo;
public:
    Nodo();
    // Metodo constructor para un Nodo Raiz
    Nodo(int p_coordI, int p_coordJ, int p_coordIPadre, int p_coordJPadre, estados p_estado, int **p_entorno);
    /*OJO SE COMENTA POR PRUEBA DE ENTORNO
    Nodo(int p_coordI, int p_coordJ, int p_coordIPadre, int p_coordJPadre, estados p_estado);
    */
    // SETTERS
    void setCoords(int p_coordI, int p_coordJ);
    void setEstado(estados p_estado);
    void setNodoPadre(string * p_padre);
    //void setEntorno(Entorno p_entorno);
    void setEntorno(int CoordI, int CoordJ, int estado);
    void setProfundidad(int p_profundidad);
    void setCostoAcumulado(double p_costoAcumulado);
    void setHeuristica(double p_heuristica);
    void setFlagObjetivos(int p_flagObjetivos);
    void setIndAyudaTortuga(bool p_indAyudaTortuga);
    void setPasosAyudaTortuga(int p_pasosAyudaTortuga);
    void setPosIniBuscarCiclo(int p_posIni);


    // GETTERS
    int getCoordI();
    int getCoordJ();
    int getCoordIPadre();
    int getCoordJPadre();
    estados getEstado();
    string * getNodoPadre();
   // Entorno getEntorno();
    int **getEntorno();
    int getProfundidad();
    double getCostoAcumulado();
    double getHeuristica();
    int getFlagObjetivos();
    bool getIndAyudaTortuga();
    int getPasosAyudaTortuga();
    int getPosIniBuscarCiclo();
    // Funciones miembro
    bool esMeta(int p_posArrCamino);
};

#endif // NODO_H

