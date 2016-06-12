#include "profundidad.h"
#include <QStringList>
#include <iostream>
#include "math.h"

using namespace std;


Profundidad::Profundidad()
{
    this->nodosCreados = 0;
    this->nodosExpandidos = 0;
    this->costoSolucion = 0;
    this->operadores[0] = 'R';
    this->operadores[1] = 'D';
    this->operadores[2] = 'L';
    this->operadores[3] = 'U';
}


Profundidad::Profundidad(Nodo * nodoRaiz, Entorno entorno, bool ind_evita_devol)
{
    this->pilaNodos.push(*nodoRaiz);
    this->nodoRaiz = *nodoRaiz;
    this->miEntorno = entorno;
    this->ind_evita_devolverse = ind_evita_devol;
    this->operadores[0] = 'R';
    this->operadores[1] = 'D';
    this->operadores[2] = 'L';
    this->operadores[3] = 'U';
    this->nodosCreados = 0;
    this->nodosExpandidos = 0;
    this->costoSolucion = 0;
}



int Profundidad::getNodosCreados()
{
    return this->nodosCreados;
}

int Profundidad::getNodosExpandidos()
{
    return this->nodosExpandidos;
}

double Profundidad::getCostoSolucion()
{
    return this->costoSolucion;
}


void Profundidad::setOperadores(char op0, char op1, char op2, char op3)
{
    this->operadores[0] = op0;
    this->operadores[1] = op1;
    this->operadores[2] = op2;
    this->operadores[3] = op3;
}

double Profundidad::getFactorRamificacion()
{
    return this->factorRamificacion;
}

int Profundidad::getProfundidad()
{
    return this->profundidad;
}


string * Profundidad::busquedaProfundidad()
{
    cout << "Inicia Busqueda Profundidad" << endl;
    string * solucion;

    bool termina = false;
    int parada = 50000;
    Nodo nodoCabeza;
    int p = 0;

    //while(!termina && parada > 0)
    while(!termina)
    {
        // Si la cola esta vacia
        if(pilaNodos.empty()) {
            termina = true;
        } else {

            nodoCabeza = pilaNodos.top();

            pilaNodos.pop();

            string lvCamino = "";
            QStringList soluciontmp;

            if (p > 0){
                lvCamino = *nodoCabeza.getNodoPadre();
            }else{
                p++;
            }

            bool ciclo = false;
            if (lvCamino == ""){
                lvCamino = to_string(nodoCabeza.getCoordI()) +  "," +  to_string(nodoCabeza.getCoordJ());
            }else{

                //lvCamino = lvCamino + ";" + to_string(nodoCabeza.getCoordI()) +  "," +  to_string(nodoCabeza.getCoordJ());

                string pasosiguiente = to_string(nodoCabeza.getCoordI()) +  "," +  to_string(nodoCabeza.getCoordJ());

                soluciontmp = QString::fromStdString(lvCamino).split(";");
                if(soluciontmp.size() > 0) {
                    for(int i=nodoCabeza.getPosIniBuscarCiclo();i<soluciontmp.size();i++){
                        //cout << "soluciontmp.at(i) = " << soluciontmp.at(i).toStdString() << endl;
                        if(soluciontmp.at(i).toStdString().compare(pasosiguiente) == 0) {
                            ciclo = true;
                            break;
                        }
                    }
                }

                if(!ciclo) {
                    lvCamino = lvCamino + ";" + to_string(nodoCabeza.getCoordI()) +  "," +  to_string(nodoCabeza.getCoordJ());
                   // cout << "NO Hay Ciclo " << lvCamino << endl;
                }

                //cout << "lvCamino = " << lvCamino << endl;

            }

            if(!ciclo) {

                pilaCaminoNodosExp.push(lvCamino);
                // Aumenta los nodos expandidos
                nodosExpandidos++;


                // Si el nodo cabeza es meta
                int posArrCamino = soluciontmp.size();

                if(nodoCabeza.esMeta(posArrCamino)) {
                    // Terminar, encontro solucion
                    solucion = &pilaCaminoNodosExp.top();

                    this->factorRamificacion = pow((nodosCreados + 1.00),1.00/(nodoCabeza.getProfundidad() + 1.00));
                    this->profundidad = nodoCabeza.getProfundidad();

                    // Obtiene el costo de la solucion
                    costoSolucion = nodoCabeza.getCostoAcumulado();

                    termina = true;
                } else {
                    // Expandir y meter nodos al final de la cola
                    crearHijos(nodoCabeza);
                }
            }else{
                string lvCaminoTmp = lvCamino + ";" + to_string(nodoCabeza.getCoordI()) +  "," +  to_string(nodoCabeza.getCoordJ());
               // cout << "SI Hay Ciclo " << lvCaminoTmp << " posArrCiclo " << to_string(nodoCabeza.getPosIniBuscarCiclo())<< endl;
            }

        }
        parada--;
    }


    return solucion;
}


void Profundidad::crearHijos(Nodo nodoCabeza)
{
    // Limites del entorno para crear nodos hijos
    int altoEntorno = this->miEntorno.getAlto();
    int anchoEntorno = this->miEntorno.getAncho();

    // Entorno del padre
    int **lvEntorno = nodoCabeza.getEntorno();
    // Coordenadas del nodo cabeza
    int posI = nodoCabeza.getCoordI();
    int posJ = nodoCabeza.getCoordJ();
    int posIPadre = nodoCabeza.getCoordIPadre();
    int posJPadre = nodoCabeza.getCoordJPadre();
    // Direccion de los movimientos
    int arriba = posI - 1;
    int abajo = posI + 1;
    int izquierda = posJ - 1;
    int derecha = posJ + 1;

    // item donde esta el nodo cabeza
    //int itemCabeza = this->miEntorno.getAmbiente()[posI][posJ];
    int itemCabeza = lvEntorno[posI][posJ];
    // estado sobre la que esta el nodo cabeza
    estados estadoCabeza = this->toEstado(itemCabeza);

    // Si el nodo cabeza no esta sobre la casilla de un humano, es decir, el humano no captura el robot
    if(estadoCabeza != onHumano)
    {

        // Aplica Operadores de Movimiento
        for(int i = 3; i >= 0; i--)
        {
            switch(operadores[i])
            {
                case 'R':
                    //cout << "Aplica Operador Derecha" << endl;
                    this->moverDerecha(derecha, anchoEntorno, posI, posIPadre, posJPadre, estadoCabeza, nodoCabeza);
                    break;
                case 'D':
                    //cout << "Aplica Operador Abajo" << endl;
                    this->moverAbajo(abajo, altoEntorno, posJ, posJPadre, posIPadre, estadoCabeza, nodoCabeza);
                    break;
                case 'L':
                    //cout << "Aplica Operador Izquierda" << endl;
                    this->moverIzquierda(izquierda, posI, posIPadre, posJPadre, estadoCabeza, nodoCabeza);
                    break;
                case 'U':
                    //cout << "Aplica Operador Arriba" << endl;
                    this->moverArriba(arriba, posJ, posJPadre, posIPadre, estadoCabeza, nodoCabeza);
                    break;
                default:
                    cout << "No Aplica Operador" << endl;
            }
        }
    }
}


void Profundidad::moverDerecha(int derecha, int anchoEntorno, int posI, int posIPadre, int posJPadre, estados estadoCabeza, Nodo nodoCabeza)
{
    // Mover derecha
    if (derecha < anchoEntorno)
    {
        if (this->ind_evita_devolverse) {
            if ((posI != posIPadre) || (derecha != posJPadre) || (estadoCabeza == onTortuga) ||
                 (estadoCabeza == onNemo) || (estadoCabeza == onDori) || (estadoCabeza == onMarlin))  {
                // Si es posible, crea nodo hijo
                this->crearNodo(posI, derecha, nodoCabeza);
            }
        }
        else
        {
            // Si es posible, crea nodo hijo
            this->crearNodo(posI, derecha, nodoCabeza);
        }
    }
}


void Profundidad::moverAbajo(int abajo, int altoEntorno, int posJ, int posJPadre, int posIPadre, estados estadoCabeza, Nodo nodoCabeza)
{
    // Mover abajo
    if (abajo < altoEntorno)
    {
        if (this->ind_evita_devolverse) {
            if ((abajo != posIPadre) || (posJ != posJPadre) || (estadoCabeza == onTortuga) ||
                    (estadoCabeza == onNemo) || (estadoCabeza == onDori) || (estadoCabeza == onMarlin))  {
                // Si es posible, crea nodo hijo
                this->crearNodo(abajo, posJ, nodoCabeza);
            }
        }
        else
        {
            // Si es posible, crea nodo hijo
            this->crearNodo(abajo, posJ, nodoCabeza);
        }
    }
}


void Profundidad::moverIzquierda(int izquierda, int posI, int posIPadre, int posJPadre, estados estadoCabeza, Nodo nodoCabeza)
{
    // Mover izquierda
    if(izquierda >= 0)
    {
        if (this->ind_evita_devolverse) {
            if ((posI != posIPadre) || (izquierda != posJPadre) || (estadoCabeza == onTortuga) ||
                    (estadoCabeza == onNemo) || (estadoCabeza == onDori) || (estadoCabeza == onMarlin))  {
                // Si es posible, crea nodo hijo
                this->crearNodo(posI, izquierda, nodoCabeza);
            }
        }
        else
        {
            // Si es posible, crea nodo hijo
            this->crearNodo(posI, izquierda, nodoCabeza);
        }
    }
}


void Profundidad::moverArriba(int arriba, int posJ, int posJPadre, int posIPadre, estados estadoCabeza, Nodo nodoCabeza)
{
    // Mover arriba
    if(arriba >= 0)
    {
        if (this->ind_evita_devolverse) {
            if ((arriba != posIPadre) || (posJ != posJPadre) || (estadoCabeza == onTortuga) ||
                    (estadoCabeza == onNemo) || (estadoCabeza == onDori) || (estadoCabeza == onMarlin))  {
                // Si es posible, crea nodo hijo
                this->crearNodo(arriba, posJ, nodoCabeza);
            }
        }
        else
        {
            // Si es posible, crea nodo hijo
            this->crearNodo(arriba, posJ, nodoCabeza);
        }
    }
}


void Profundidad::crearNodo(int posIHijo, int posJHijo, Nodo nodoCabeza)
{

    // Limites del entorno para crear nodos hijos
    int altoEntorno = this->miEntorno.getAlto();
    int anchoEntorno = this->miEntorno.getAncho();
    // Entorno del padre
    //int **lvEntorno = nodoCabeza.getEntorno();
    // Entorno del padre
    int ** lvEntorno = new int*[altoEntorno];
    for(int i=0;i<altoEntorno;i++){
        lvEntorno[i] = new int[anchoEntorno];
        for(int j=0;j<anchoEntorno;j++){
            lvEntorno[i][j] = nodoCabeza.getEntorno()[i][j];
        }
    }


    // Item donde esta el nodo hijo
   //int itemHijo = this->miEntorno.getAmbiente()[posIHijo][posJHijo];
    int itemHijo = lvEntorno[posIHijo][posJHijo];
    // Casilla donde esta el nodo hijo
    estados estadoHijo = this->toEstado(itemHijo);
    // Verifica que la casilla no sea una roca
    if(estadoHijo != onRoca)
    {

        // Calculo del costo acumulado para llegar al nodo..
        int profundidad = nodoCabeza.getProfundidad() + 1;
        double costoAcumulado = nodoCabeza.getCostoAcumulado();
        double tmpCostoAcumulado = 0;
        double lvReducionCosto = 0;
        bool lvIndAyudaTortuga = nodoCabeza.getIndAyudaTortuga() ;
        int lvPasosAyudaTortuga = 0;

        if(estadoHijo == estados::onTiburon) {
            tmpCostoAcumulado = 10;
        } else {
            tmpCostoAcumulado = 1;
        }

        if((nodoCabeza.getIndAyudaTortuga() == true) && (nodoCabeza.getPasosAyudaTortuga() <=3) ) {
            lvReducionCosto = 0.5;
            lvPasosAyudaTortuga = nodoCabeza.getPasosAyudaTortuga() + 1;
        }else{
            lvReducionCosto = 1;
            lvPasosAyudaTortuga = 0;
        }


        if ((lvPasosAyudaTortuga > 4) || (lvPasosAyudaTortuga == 0)  ){
            if (estadoHijo == onTortuga){
               lvIndAyudaTortuga = true;
               lvEntorno[posIHijo][posJHijo]=2;
            }else{
                lvIndAyudaTortuga = false;
            }
        }

        tmpCostoAcumulado = tmpCostoAcumulado * lvReducionCosto;
        costoAcumulado = costoAcumulado + tmpCostoAcumulado;


        // Puede crear el nodo hijo
        //int flagObjetivosPadre = nodoCabeza.getFlagObjetivos();
        //int flagObjetivos = this->validaObjetivo(nodoCabeza.getFlagObjetivos(), estadoHijo);
        // Si encuentra objetivo, en orden, lo quita del entorno
        // Crea el nodo hijo
        Nodo nodoHijo(posIHijo, posJHijo, nodoCabeza.getCoordI(), nodoCabeza.getCoordJ(), estadoHijo, lvEntorno);

        nodoHijo.setProfundidad(profundidad);
        nodoHijo.setCostoAcumulado(costoAcumulado);
        nodoHijo.setFlagObjetivos(nodoCabeza.getFlagObjetivos());
        nodoHijo.setNodoPadre(&pilaCaminoNodosExp.top());
        nodoHijo.setIndAyudaTortuga(lvIndAyudaTortuga);
        nodoHijo.setPasosAyudaTortuga(lvPasosAyudaTortuga);
        nodoHijo.setPosIniBuscarCiclo(nodoCabeza.getPosIniBuscarCiclo());

        //if (nodoHijo.getFlagObjetivos()>= 2){
        //if ((posIHijo== 3) && (posJHijo== 2)){
        /*
        if ((posIHijo== 4) && (posJHijo== 4) && (nodoHijo.getFlagObjetivos()>= 1)){
            cout << "camino: "  << *nodoHijo.getNodoPadre() << " costo: " << nodoHijo.getCostoAcumulado() << endl;
        }
        */

        // Agrega el nodo creado a la pila de nodos
        this->pilaNodos.push(nodoHijo);
        // Aumenta el contador de hijos creados
        this->nodosCreados++;

        //cout << "Camino: " << *nodoHijo.getNodoPadre() << endl;

        // Imprime el estado del entorno
        //this->entorno.imprimir();
    }
}


estados Profundidad::toEstado(int itemEntorno)
{
    estados estado;
    switch (itemEntorno)
    {
    case 0:
        estado = onRobot;
        break;
    case 1:
        estado = onRoca;
        break;
    case 2:
        estado = onLibre;
        break;
    case 3:
        estado = onTiburon;
        break;
    case 4:
        estado = onTortuga;
        break;
    case 5:
        estado = onDori;
        break;
    case 6:
        estado = onMarlin;
        break;
    case 7:
        estado = onNemo;
        break;
    case 8:
        estado = onHumano;
        break;
    default:
        break;
    }
    return estado;
}

