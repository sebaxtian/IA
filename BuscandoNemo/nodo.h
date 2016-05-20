#ifndef NODO_H
#define NODO_H
#include <iostream>       // std::cin, std::cout
#include <queue>          // std::queue
#include <string>
#include <string.h>

using namespace std;

class Nodo
{
    int fila;
    int columna;
    int codNodo; // Buscar nombre para identificar el tipo de nodo
    Nodo * padre;
    int indMeta;
    int costo;
    int heuristica;

    int profundidad;
    string operadorAplicado;
public:
    Nodo();
    Nodo(int i, int j, int codNodo);

    void set_fila (int);
    void set_columna (int);
    void set_padre(Nodo * ppadre);
    void set_costo (int);
    void set_heuristica (int);
    void setCodNodo(int);
    void setProfundidad(int);
    void set_indMeta(int);


    int get_fila ();
    int get_columna ();
    Nodo * get_padre();
    int get_costo ();
    int get_heuristica ();
    int get_costoHeuristica ();
    int get_indMeta();

    bool esMeta();
    int getCodNodo();
    int getProfundidad();
};


#endif // NODO_H
