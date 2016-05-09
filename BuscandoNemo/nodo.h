#ifndef NODO_H
#define NODO_H
#include <iostream>       // std::cin, std::cout
#include <queue>          // std::queue
#include <string>
#include <string.h>

using namespace std;

class nodo
{
    int fila;
    int columna;
    queue<string> pasosSolucionM1;
    queue<string> pasosSolucionM2;
    queue<string> pasosSolucionM3;
    int indMeta;
    int costo;
    int heuristica;

public:
    nodo();
    void set_fila (int);
    void set_columna (int);
    void set_pasosSolucionM1 (string);
    void set_pasosSolucionM2 (string);
    void set_pasosSolucionM3 (string);
    void set_costo (int);
    void set_heuristica (int);

    int get_fila ();
    int get_columna ();
    queue<string> get_pasosSolucionM1 ();
    queue<string> get_pasosSolucionM2 ();
    queue<string> get_pasosSolucionM3 ();
    int get_costo ();
    int get_heuristica ();
    int get_costoHeuristica ();

};


#endif // NODO_H
