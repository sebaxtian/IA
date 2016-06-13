#include "avara.h"
#include "math.h"


Avara::Avara()
{
    this->nodosCreados = 0;
    this->nodosExpandidos = 0;
    this->costoSolucion = 0;
}


Avara::Avara(Nodo *nodoRaiz, Entorno entorno, bool ind_evita_devol, string pindHeuristica)
{
    Nodo lvNodo = *nodoRaiz;
    this->indHeuristica = pindHeuristica;
    lvNodo.setHeuristica(obtenerHeuristica(lvNodo));
    this->colaPrioridadNodos.push(lvNodo);
    this->nodoRaiz = *nodoRaiz;
    this->miEntorno = entorno;
    this->ind_evita_devolverse = ind_evita_devol;
    this->nodosCreados = 0;
    this->nodosExpandidos = 0;
    this->costoSolucion = 0;
}


int Avara::getNodosCreados()
{
    return this->nodosCreados;
}

int Avara::getNodosExpandidos()
{
    return this->nodosExpandidos;
}

double Avara::getCostoSolucion()
{
    return this->costoSolucion;
}

double Avara::getFactorRamificacion()
{
    return this->factorRamificacion;
}

int Avara::getProfundidad()
{
    return this->profundidad;
}


string * Avara::busquedaAvara()
{
    cout << "Inicia Busqueda Avara" << endl;
    string * solucion;

    bool termina = false;
    int parada = 180000;
    Nodo nodoCabeza;
    int p = 0;

   //while(!termina && parada > 0)
    while(!termina)
    {
        // Si la cola esta vacia
        if(colaPrioridadNodos.empty()) {
            termina = true;
        } else {
            nodoCabeza = colaPrioridadNodos.top();
            colaPrioridadNodos.pop();
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


void Avara::crearHijos(Nodo nodoCabeza)
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

void Avara::crearNodo(int posIHijo, int posJHijo, Nodo nodoCabeza)
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
        // Si encuentra objetivo, en orden, lo quita del entorno
        // Crea el nodo hijo
        Nodo nodoHijo(posIHijo, posJHijo, nodoCabeza.getCoordI(), nodoCabeza.getCoordJ(), estadoHijo, lvEntorno);

        nodoHijo.setProfundidad(profundidad);
        nodoHijo.setCostoAcumulado(costoAcumulado);
        nodoHijo.setFlagObjetivos(nodoCabeza.getFlagObjetivos());
        nodoHijo.setNodoPadre(&pilaCaminoNodosExp.top());
        nodoHijo.setIndAyudaTortuga(lvIndAyudaTortuga);
        nodoHijo.setPasosAyudaTortuga(lvPasosAyudaTortuga);
        nodoHijo.setHeuristica(obtenerHeuristica(nodoHijo));


        // Agrega el nodo creado a la cola de nodos
        this->colaPrioridadNodos.push(nodoHijo);
        // Aumenta el contador de hijos creados
        this->nodosCreados++;
    }
}


estados Avara::toEstado(int itemEntorno)
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


double Avara::obtenerHeuristica(Nodo pnodo){
    double LvHueristica = 0.0;
    if (this->indHeuristica == "L"){
        LvHueristica = h_distanciaL(pnodo);
    }
    if (this->indHeuristica == "E"){
        LvHueristica = h_distanciaEuclideana(pnodo);
    }
    return LvHueristica;
}

double Avara::h_distanciaL(Nodo pnodo){

    double LvDistManhattan = 0.0;
    int coordNodoI = pnodo.getCoordI();
    int coordNodoJ = pnodo.getCoordJ();
    int coordNemoI = this->miEntorno.getPosNemo()[0];
    int coordNemoJ = this->miEntorno.getPosNemo()[1];
    int coordMarlinI = this->miEntorno.getPosMarlin()[0];
    int coordMarlinJ = this->miEntorno.getPosMarlin()[1];
    int coordDoriI = this->miEntorno.getPosDori()[0];
    int coordDoriJ = this->miEntorno.getPosDori()[1];

    if(pnodo.getFlagObjetivos() == 0) {
        LvDistManhattan = 0;
        LvDistManhattan += abs(coordNemoI - coordNodoI) + abs(coordNemoJ - coordNodoJ);
    }

    if(pnodo.getFlagObjetivos() == 1) {
        LvDistManhattan = 0;
        LvDistManhattan += abs(coordMarlinI - coordNodoI) + abs(coordMarlinJ - coordNodoJ);
    }

    if(pnodo.getFlagObjetivos() == 2) {
        LvDistManhattan = 0;
        LvDistManhattan += abs(coordDoriI - coordNodoI) + abs(coordDoriJ - coordNodoJ);
    }

    return LvDistManhattan * 0.5;

}

double Avara::h_distanciaEuclideana(Nodo pnodo){

    double LvDistEuclideana = 0.0;
    int coordNodoI = pnodo.getCoordI();
    int coordNodoJ = pnodo.getCoordJ();
    int coordNemoI = this->miEntorno.getPosNemo()[0];
    int coordNemoJ = this->miEntorno.getPosNemo()[1];
    int coordMarlinI = this->miEntorno.getPosMarlin()[0];
    int coordMarlinJ = this->miEntorno.getPosMarlin()[1];
    int coordDoriI = this->miEntorno.getPosDori()[0];
    int coordDoriJ = this->miEntorno.getPosDori()[1];


    if(pnodo.getFlagObjetivos() == 0) {
        LvDistEuclideana = 0;
        LvDistEuclideana += pow((coordNemoI - coordNodoI) ,2.0) + pow((coordNemoJ - coordNodoJ) ,2.0);
    }

    if(pnodo.getFlagObjetivos() == 1) {
        LvDistEuclideana = 0;
        LvDistEuclideana += pow((coordMarlinI - coordNodoI) ,2.0) + pow((coordMarlinJ - coordNodoJ) ,2.0);
    }

    if(pnodo.getFlagObjetivos() == 2) {
        LvDistEuclideana = 0;
        LvDistEuclideana += pow((coordDoriI - coordNodoI) ,2.0) + pow((coordDoriJ - coordNodoJ) ,2.0);
    }

    LvDistEuclideana = pow(LvDistEuclideana, 1.0/2.0);
    return LvDistEuclideana;

}
