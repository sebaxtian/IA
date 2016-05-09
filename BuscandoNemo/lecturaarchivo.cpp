#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

// Atributos GLOBALES
int ALTO = 0;
int ANCHO = 0;
int **AMBIENTE;



void cargarAmbiente(string pathFile) {
    // Carga del ambiente desde un archivo de texto
    ifstream myfile (pathFile);
    if(myfile.is_open()) {
        // Variables auxiliares
        string line;
        char *cstr;
        char *tokenstr;
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
            if(ANCHO == 0) {
                // El primer dato de la linea corresponde al ancho
                ANCHO = stoi(tokenstr);
            }
            if(ALTO == 0) {
                // El segundo dato de la linea corresponde al alto
                ALTO = stoi(tokenstr);
            }
            tokenstr = strtok(NULL," ");
        }
        // Tercero, lee los datos de las casillas del ambiente y se genera una matriz
        int i = 0;
        int j = 0;
        AMBIENTE = new int*[ALTO];
        while(getline(myfile,line)) {
            cstr = strdup(line.c_str());
            tokenstr = strtok(cstr," ");
            j = 0;
            AMBIENTE[i] = new int[ANCHO];
            while(tokenstr != NULL) {
                AMBIENTE[i][j] = stoi(tokenstr);
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



void imprimirMatriz(int **matriz, int alto, int ancho) {
    for(int i = 0; i < alto; i++) {
        for(int j = 0; j < ancho; j++) {
            cout << matriz[i][j] << " ";
            if(j == ancho-1) {
                cout << endl;
            }
        }
    }
}



void liberarMemoria(int **matriz, int alto) {
    // Elimino cada arreglo de la matriz
    for (int i = 0; i < alto; i++) {
        delete[] matriz[i];
    }
    // Elimino el arreglo principal
    delete[] matriz;
}


/*
int main(int argc, char *argv[])
{
    cout << "Agente Inteligente de Software de Reflejo Simple" << endl;


    // Carga de ambiente desde un archivo de texto
    //string pathFile = argv[1];
    string pathFile = "../agente-reflejo-simple/entorno.txt";
    cargarAmbiente(pathFile);


    // Imprime la matriz de ambiente
    imprimirMatriz(AMBIENTE, ALTO, ANCHO);



    // Libera recursos
    liberarMemoria(AMBIENTE, ALTO);

    return 0;
}
*/
