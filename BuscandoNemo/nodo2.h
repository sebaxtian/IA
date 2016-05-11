#ifndef NODO2_H
#define NODO2_H

#include <iostream>
#include <queue>

using namespace std;

// Posibles estados del problema
enum estados {onLibre, onTiburon, onTortuga, onDori, onMarlin, onNemo};
// Posibles operadores aplicados
enum operadores {arriba, abajo, izquierda, derecha};

class Nodo2
{
    // Identificador unico del nodo
    int codNodo;
    // Un identificador de referencia al nodo padre
    int referenciaPadre;
    // Operador aplicado para generar el nodo
    operadores operadorAplicado;
    // Profundidad del nodo
    int profundidad;
    // Costo acumulado para llegar hasta el nodo
    int costoAcumulado;
    // Estado actual del problema
    estados estadoActual;
    // Pasos del camino hasta el nodo
    queue<string> camino;
    // Variable que marca los elementos encontrados, en orden, primero 1, 2 y 3 (Si es 3 significa que ha encontrado 1 y 2)
    int flagElementos;
    // Coordenadas del nodo en el entorno
    int coords[2];
public:
    // Constructor de clase para un Nodo Raiz
    Nodo2();
    // Constructor de clase para crear un Nodo Cualquiera
    Nodo2(int coords[2], int codNodo, int refPadre, operadores opAplicado, int profundidad, int costoAcu, estados estadoActual, queue<string> camino, int flagElementos);
    // SETTERS
    void setCoords(int coords[2]);
    void setCodNodo(int codNodo);
    void setRefPadre(int refPadre);
    void setOpeAplicado(operadores operador);
    void setProfundidad(int profundidad);
    void setCostoAcumulado(int costoAcumulado);
    void setEstadoActual(estados estadoActual);
    void setCamino(queue<string> camino);
    // GETTERS
    int getCodNodo();
    int getRefPadre();
    operadores getOpeAplicado();
    int getProfundidad();
    int getCostoAcumulado();
    estados getEstadoActual();
    queue<string> getCamino();
    int getFlagElementos();
    // Funciones miembro
    int getPosI();
    int getPosJ();
    bool esMeta();
};

#endif // NODO2_H
