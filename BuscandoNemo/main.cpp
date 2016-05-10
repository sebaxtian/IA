#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "entorno.h"
#include "nodo.h"
#include "amplitud.h"

using namespace std;

int main(int argc, char *argv[])
{

    cout << "Prueba de Clase Entorno" << endl;

    string pathEntorno = "../BuscandoNemo/prueba1.txt";

    Entorno miEntorno;
    miEntorno.loadFile(pathEntorno);

    cout << "Ancho del Entorno: " << miEntorno.getAncho() << endl;
    cout << "Alto del Entorno: " << miEntorno.getAlto() << endl;
    cout << "Imprime el Entorno " << endl;
    miEntorno.imprimir();

    int postI = miEntorno.getPosInitRobot()[0];
    int postJ = miEntorno.getPosInitRobot()[1];

    cout << "Posicion Inicial del Robot: (" << postI << " , " << postJ << ")" << endl;

    Nodo nodoRaiz(postI, postJ, 0);
    Amplitud miAmplitud(nodoRaiz, miEntorno);    
    queue<string> solucion = miAmplitud.busquedaPreferente();
    /*
    int i = 1;
    while (!solucion.empty()) {
        cout << "Paso " << i << " : " << solucion.front() << endl;
        solucion.pop();
        i++;
    }
    */


    return 0;
}
