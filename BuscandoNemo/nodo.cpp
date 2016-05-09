#include "nodo.h"
#include <queue>          // std::queue
#include <string>
#include <string.h>

using namespace std;

// constructor
Nodo::Nodo()
{

}

Nodo::Nodo(int i, int j, int codNodo)
{
    this->codNodo = codNodo;
    this->fila = i;
    this->columna = j;
    this->indMeta = 0;
}

// set

void Nodo::set_fila (int pfila) {
    fila = pfila;
}
void Nodo::set_columna (int pcolumna) {
    columna = pcolumna;
}
void Nodo::set_pasosSolucionM1 (string pposicion)  {
    pasosSolucionM1.push(pposicion);
}
void Nodo::set_pasosSolucionM2 (string pposicion)  {
    pasosSolucionM2.push(pposicion);
}
void Nodo::set_pasosSolucionM3 (string pposicion)  {
    pasosSolucionM3.push(pposicion);
}
void Nodo::set_costo (int pcosto) {
    costo = costo + pcosto;
}
void Nodo::set_heuristica (int pheuristica) {
    heuristica = pheuristica;
}

// get
int Nodo::get_fila () {
    return fila;
}
int Nodo::get_columna () {
    return columna;
}
queue<string> Nodo::get_pasosSolucionM1() {
    return pasosSolucionM1;
}
queue<string> Nodo::get_pasosSolucionM2() {
    return pasosSolucionM2;
}
queue<string> Nodo::get_pasosSolucionM3() {
    return pasosSolucionM3;
}
int Nodo::get_costo () {
    return costo;
}
int Nodo::get_heuristica () {
    return heuristica;
}
int Nodo::get_costoHeuristica () {
    return costo + heuristica;
}


bool Nodo::esMeta() {

    if(this->codNodo == 7 && this->indMeta == 0) {
        indMeta++;
    }
    if(this->codNodo == 6 && this->indMeta == 1) {
        indMeta++;
    }
    if(this->codNodo == 5 && this->indMeta == 2) {
        indMeta++;
    }

    if(this->indMeta == 3) {
        return true;
    }

    return false;
}


void Nodo::set_pasosSolucion (string pposicion)  {
    pasosSolucion.push(pposicion);
}
void Nodo::set_pasosSolucion (queue<string> pasosSolucionPapa)  {
    this->pasosSolucion = pasosSolucionPapa;
}

queue<string> Nodo::get_pasosSolucion() {
    return pasosSolucion;
}

void Nodo::setCodNodo(int codNodo) {
    this->codNodo = codNodo;
}

int Nodo::getCodNodo() {
    return codNodo;
}

int Nodo::getProfundidad() {
    return profundidad;
}

void Nodo::setProfundidad(int profundidad) {
    this->profundidad = profundidad;
}

void Nodo::set_indMeta(int indMeta) {
    this->indMeta = indMeta;
}

int Nodo::get_indMeta() {
    return indMeta;
}
