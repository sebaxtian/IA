#include "nodo.h"
#include <queue>          // std::queue
#include <string>
#include <string.h>

using namespace std;

// constructor
nodo::nodo()
{

}


// set

void nodo::set_fila (int pfila) {
    fila = pfila;
}
void nodo::set_columna (int pcolumna) {
    columna = pcolumna;
}
void nodo::set_pasosSolucionM1 (string pposicion)  {
    pasosSolucionM1.push(pposicion);
}
void nodo::set_pasosSolucionM2 (string pposicion)  {
    pasosSolucionM2.push(pposicion);
}
void nodo::set_pasosSolucionM3 (string pposicion)  {
    pasosSolucionM3.push(pposicion);
}
void nodo::set_costo (int pcosto) {
    costo = costo + pcosto;
}
void nodo::set_heuristica (int pheuristica) {
    heuristica = pheuristica;
}

// get
int nodo::get_fila () {
    return fila;
}
int nodo::get_columna () {
    return columna;
}
queue<string> nodo::get_pasosSolucionM1() {
    return pasosSolucionM1;
}
queue<string> nodo::get_pasosSolucionM2() {
    return pasosSolucionM2;
}
queue<string> nodo::get_pasosSolucionM3() {
    return pasosSolucionM3;
}
int nodo::get_costo () {
    return costo;
}
int nodo::get_heuristica () {
    return heuristica;
}
int nodo::get_costoHeuristica () {
    return costo + heuristica;
}
