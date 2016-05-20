#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include "entorno.h"
#include "nodo.h"
#include "amplitud.h"
//#include "nodo2.h"
//#include "amplitud2.h"
#include "amplitud3.h"

#include "amplitudfinal.h"
#include "nodofinal.h"

using namespace std;



string PATHENTORNO = "../BuscandoNemo/prueba1.txt";


void pruebaColaCamino()
{
    cout << "Ejemplo Cola de Camino" << endl;

    // Define una cola
    queue<string> camino;

    // Inserta elementos
    camino.push("0,1");
    camino.push("1,1");
    camino.push("4,0");
    camino.push("1,3");
    camino.push("2,1");
    camino.push("1,1");

    // Imprime los elementos
    while(!camino.empty())
    {
        cout << "Elemento: (" << camino.front() << ")" << endl;
        // Elimina el elemento
        camino.pop();
    }

    cout << endl;
}


void pruebaColaPrioridad()
{
    cout << "Ejemplo Cola de Prioridad" << endl;

    // Define una cola de prioridad, la prioridad es el menor
    priority_queue<int, deque<int>, greater<int>> colaPrioridad;

    // Inserta elementos
    colaPrioridad.push(10);
    colaPrioridad.push(30);
    colaPrioridad.push(4);
    colaPrioridad.push(60);
    colaPrioridad.push(11);
    colaPrioridad.push(30);

    // Imprime los elementos
    while(!colaPrioridad.empty())
    {
        cout << "Elemento: " << colaPrioridad.top() << endl;
        // Elimina el elemento
        colaPrioridad.pop();
    }

    cout << endl;
}



Entorno cargarEntorno(string pathEntorno)
{
    cout << "Inicia la carga del Entorno" << endl;

    Entorno entorno;
    entorno.loadFile(pathEntorno);

    cout << "Archivo de Entorno: " << pathEntorno << endl;
    cout << "Alto del Entorno: " << entorno.getAlto() << endl;
    cout << "Ancho del Entorno: " << entorno.getAncho() << endl;
    // Posicion del Robot en el Entorno
    int posI = entorno.getPosInitRobot()[0];
    int posJ = entorno.getPosInitRobot()[1];
    cout << "Posicion Inicial del Robot: (" << posI << "," << posJ << ")" << endl;
    // Elementos del Entorno
    cout << "Elementos del Entorno" << endl;
    cout << "Robot: [0]" << endl;
    cout << "Roca: [1]" << endl;
    cout << "Espacio Libre: [2]" << endl;
    cout << "Tiburon: [3]" << endl;
    cout << "Tortuga: [4]" << endl;
    cout << "Dori: [5]" << endl;
    cout << "Marlin: [6]" << endl;
    cout << "Nemo: [7]" << endl;
    cout << "Humano: [8]" << endl;

    cout << endl;

    return entorno;
}


void busquedaAmplitud()
{
    cout << "Busqueda por Amplitud" << endl;

    Entorno entorno = cargarEntorno(PATHENTORNO);

    // Imprime el entorno
    entorno.imprimir();

    // Crea el Nodo Raiz del problema, en la posicion del Robot
    int posI = entorno.getPosInitRobot()[0];
    int posJ = entorno.getPosInitRobot()[1];
    Nodo raiz(posI, posJ, 0);

    // Aplica el algoritmo de Bisqueda Preferente por Amplitud
    Amplitud amplitud(&raiz, entorno);
    //queue<string> solucion = amplitud.busquedaPreferente();
    Nodo *solucion;

   solucion = amplitud.busquedaPreferente();

  queue<Nodo>  ggg;

    // Imprime los pasos de la solucion
    int i = 1;
    while(solucion->getProfundidad() !=0)
    {
        Nodo tmp;
        tmp.set_fila( solucion->get_fila());
        tmp.set_columna( solucion->get_columna());

        cout << "Paso " << i << " : " << solucion->get_fila() << " , " << solucion->get_columna() << endl;
        ggg.push(tmp);
        solucion = solucion->get_padre();
        i++;
    }


    cout << endl;
}


void busquedaAmplitudFinal()
{
    cout << "Busqueda por Amplitud Final" << endl;

    Entorno entorno = cargarEntorno(PATHENTORNO);

    // Imprime el entorno
    entorno.imprimir();

    // Crea el Nodo Raiz del problema, en la posicion del Robot
    int posI = entorno.getPosInitRobot()[0];
    int posJ = entorno.getPosInitRobot()[1];

    //Nodo raiz(posI, posJ, 0);
    //NodoFinal raiz(posI, posJ, onRobot, entorno);
    NodoFinal raiz(posI, posJ, onRobot);


    // Aplica el algoritmo de Bisqueda Preferente por Amplitud
    AmplitudFinal amplitud(&raiz, entorno);
    //queue<string> solucion = amplitud.busquedaPreferente();
    NodoFinal * solucion;

    solucion = amplitud.busquedaPreferente();

    stack<NodoFinal>  ggg;

    // Imprime los pasos de la solucion
    int i = 1;
    while(solucion->getProfundidad() !=0)
    {
        NodoFinal tmp;
        tmp.setCoords(solucion->getCoordI(), solucion->getCoordJ());

        cout << "Paso " << i << " : " << solucion->getCoordI() << " , " << solucion->getCoordJ() << endl;
        ggg.push(tmp);
        solucion = solucion->getNodoPadre();
        i++;
    }

    cout << endl;
}

/*
void pruebaAmplitud2()
{
    cout << "Prueba Busqueda por Amplitud2" << endl;

    Entorno entorno = cargarEntorno(PATHENTORNO);

    // Imprime el entorno
    entorno.imprimir();

    // Crea el Nodo Raiz del problema, en la posicion del Robot
    Nodo2 raiz;
    raiz.setCoords(entorno.getPosInitRobot());

    // Aplica el algoritmo de Bisqueda Preferente por Amplitud
    Amplitud2 amplitud(raiz, entorno);
    queue<string> solucion = amplitud.makeBusqueda();

    // Imprime el numero de nodos expandidos y creados
    int numNodosExpandidos = amplitud.getNumNodosExpandidos();
    int numNodosCreados = amplitud.getNumNodosCreados();
    cout << "Numero de Nodos Expandidos: " << numNodosExpandidos << endl;
    cout << "Numero de Nodos Creados: " << numNodosCreados << endl;

    // Imprime los pasos de la solucion
    int i = 1;
    while(!solucion.empty())
    {
        cout << "Paso " << i << " : " << solucion.front() << endl;
        solucion.pop();
        i++;
    }

    cout << endl;
}
*/

/*
void pruebaAmplitud3()
{
    cout << "Prueba Busqueda por Amplitud3" << endl;

    Entorno entorno = cargarEntorno(PATHENTORNO);

    // Imprime el entorno
    entorno.imprimir();

    // Crea el Nodo Raiz del problema, en la posicion del Robot
    Nodo3 nodoRaiz(entorno.getPosInitRobot()[0], entorno.getPosInitRobot()[0]);

    // Aplica algoritmo de Busqueda Preferente por Amplitud
    Amplitud3 amplitud(nodoRaiz, entorno);
    amplitud.makeBusqueda();

    cout << endl;
}
*/

int main(int argc, char *argv[])
{
    // Prueba Cola de Prioridad
    //pruebaColaPrioridad();

    // Prueba Cola de Camino
    //pruebaColaCamino();

    // Realiza busqueda preferente por amplitud
    //busquedaAmplitud();

    busquedaAmplitudFinal();

    // Prueba Busqueda Preferente por Amplitud2
    //pruebaAmplitud2();

    // Prueba Busqueda Preferente por Amplitud3
    //pruebaAmplitud3();

    return 0;
}
