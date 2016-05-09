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
    queue<string> pasosSolucion;
    queue<string> pasosSolucionM1;
    queue<string> pasosSolucionM2;
    queue<string> pasosSolucionM3;
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
    void set_pasosSolucion (string);
    void set_pasosSolucion (queue<string> pasosSolucionPapa);
    void set_pasosSolucionM1 (string);
    void set_pasosSolucionM2 (string);
    void set_pasosSolucionM3 (string);
    void set_costo (int);
    void set_heuristica (int);
    void setCodNodo(int);
    void setProfundidad(int);
    void set_indMeta(int);


    int get_fila ();
    int get_columna ();
    queue<string> get_pasosSolucion ();
    queue<string> get_pasosSolucionM1 ();
    queue<string> get_pasosSolucionM2 ();
    queue<string> get_pasosSolucionM3 ();
    int get_costo ();
    int get_heuristica ();
    int get_costoHeuristica ();
    int get_indMeta();

    bool esMeta();
    int getCodNodo();
    int getProfundidad();
};


#endif // NODO_H
