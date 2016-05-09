#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "entorno.h"

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

    return 0;
}
