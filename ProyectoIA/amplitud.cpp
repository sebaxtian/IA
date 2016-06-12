#include "amplitud.h"
#include "math.h"

Amplitud::Amplitud()
{
    this->nodosCreados = 0;
    this->nodosExpandidos = 0;
    this->costoSolucion = 0;
}

Amplitud::Amplitud(Nodo * nodoRaiz, Entorno entorno, bool ind_evita_devol)
{
    this->colaNodos.push(*nodoRaiz);
    this->miEntorno = entorno;
    this->nodoRaiz = *nodoRaiz;
    this->nodosCreados = 0;
    this->nodosExpandidos = 0;
    this->ind_evita_devolverse = ind_evita_devol;
    this->costoSolucion = 0;
}


int Amplitud::getNodosCreados()
{
    return this->nodosCreados;
}

int Amplitud::getNodosExpandidos()
{
    return this->nodosExpandidos;
}

double Amplitud::getCostoSolucion()
{
    return this->costoSolucion;
}

double Amplitud::getFactorRamificacion()
{
    return this->factorRamificacion;
}

int Amplitud::getProfundidad()
{
    return this->profundidad;
}



string * Amplitud::busquedaPreferente()
{

    cout << "Inicia Busqueda Preferente" << endl;


    bool termina = false;
    string * solucion;
    int parada = 90;
    Nodo nodoCabeza;
    int p = 0;

   // while(!termina && parada > 0) {
    while(!termina) {
        // Si la cola esta vacia
        if(colaNodos.empty()) {
            termina = true;
        } else {
            nodoCabeza = colaNodos.front();
            colaNodos.pop();
            string lvCamino = "";
            if (p > 0){
                lvCamino = *nodoCabeza.getNodoPadre();
            }else{
                p++;
            }

            if (lvCamino == ""){
                lvCamino = to_string(nodoCabeza.getCoordI()) +  "," +  to_string(nodoCabeza.getCoordJ());
            }else{
                lvCamino = lvCamino + ";" + to_string(nodoCabeza.getCoordI()) +  "," +  to_string(nodoCabeza.getCoordJ());
            }

            pilaCaminoNodosExp.push(lvCamino);
            // Aumenta los nodos expandidos
            nodosExpandidos++;
            // Si el nodo cabeza es meta
            if(nodoCabeza.esMeta(0)) {
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
        }
        parada--;
    }

    return solucion;
}


void Amplitud::crearHijos(Nodo nodoCabeza)
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
}

void Amplitud::crearNodo(int posIHijo, int posJHijo, Nodo nodoCabeza)
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
        //if (nodoHijo.getFlagObjetivos()>= 2){
        //if ((posIHijo== 3) && (posJHijo== 2)){
        /*
        if ((posIHijo== 4) && (posJHijo== 4) && (nodoHijo.getFlagObjetivos()>= 1)){
            cout << "camino: "  << *nodoHijo.getNodoPadre() << " costo: " << nodoHijo.getCostoAcumulado() << endl;
        }
        */

        // Agrega el nodo creado a la cola de nodos
        this->colaNodos.push(nodoHijo);
        // Aumenta el contador de hijos creados
        this->nodosCreados++;
        // Imprime el estado del entorno
        //this->entorno.imprimir();
    }
}


estados Amplitud::toEstado(int itemEntorno)
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
