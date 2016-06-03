#include "entorno.h"
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

Entorno::Entorno()
{

}

void Entorno::setAmbiente(int CoordI, int CoordJ, int estado){
    this->ambiente[CoordI][CoordJ] = estado;
}
void Entorno::setIndMetaEncontrada(){
    this->indMetaEncontrada ++;
}

void Entorno::loadFile(string pathFile) {
    // Carga del ambiente desde un archivo de texto
    ifstream myfile (pathFile);
    if(myfile.is_open()) {
        // Variables auxiliares
        string line;
        char *cstr;
        char *tokenstr;
        this->indMetaEncontrada = 0;
        // Primero, lee todos los comentarios
        while(getline(myfile,line)) {
            if(line.substr(0,1).compare("#") == 0) {
                // Lee un comentario, continua con la siguiente linea
                continue;
            } else {
                // No hay mas comentarios, continua leyendo el ambiente
                break;
            }
        }
        // Segundo, lee los valores de ancho y alto
        cstr = strdup(line.c_str());
        tokenstr = strtok(cstr," ");
        while(tokenstr != NULL) {
            if(this->ancho == 0) {
                // El primer dato de la linea corresponde al ancho
                this->ancho = stoi(tokenstr);
            }
            if(this->alto == 0) {
                // El segundo dato de la linea corresponde al alto
                this->alto = stoi(tokenstr);
            }
            tokenstr = strtok(NULL," ");
        }
        // Tercero, lee los datos de las casillas del ambiente y se genera una matriz
        int i = 0;
        int j = 0;
        this->ambiente = new int*[this->alto];
        while(getline(myfile,line)) {
            cstr = strdup(line.c_str());
            tokenstr = strtok(cstr," ");
            j = 0;
            this->ambiente[i] = new int[this->ancho];
            while(tokenstr != NULL) {
                this->ambiente[i][j] = stoi(tokenstr);
                // Encuentra la posicion inicial del robot
                if(this->ambiente[i][j] == 0) {
                    this->posInitRobot[0] = i;
                    this->posInitRobot[1] = j;
                }
                j++;
                tokenstr = strtok(NULL," ");
            }
            i++;
        }
        // Libera recursos
        free(cstr);
        free(tokenstr);
        myfile.close();
    } else {
        cout << "No es posible abrir archivo" << endl;
    }
}

void Entorno::imprimir() {
    for(int i = 0; i < this->alto; i++) {
        for(int j = 0; j < this->ancho; j++) {
            cout << this->ambiente[i][j] << " ";
            if(j == this->ancho-1) {
                cout << endl;
            }
        }
    }
    cout << endl;
}

int Entorno::getAlto() {
    return this->alto;
}

int Entorno::getAncho() {
    return this->ancho;
}

int** Entorno::getAmbiente() {
    return this->ambiente;
}

int Entorno::getIndMetaEncontrada() {
    return this->indMetaEncontrada;
}

int* Entorno::getPosInitRobot() {
    int* puntero = this->posInitRobot;
    return puntero;
}
