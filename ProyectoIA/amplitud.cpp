#include "amplitud.h"

Amplitud::Amplitud()
{
    this->nodosCreados = 0;
    this->nodosExpandidos = 0;
}

Amplitud::Amplitud(Nodo * nodoRaiz, Entorno entorno)
{
    this->colaNodos.push(*nodoRaiz);
    this->miEntorno = entorno;
    this->nodoRaiz = *nodoRaiz;
    this->nodosCreados = 0;
    this->nodosExpandidos = 0;
}


Nodo * Amplitud::busquedaPreferente()
{

    cout << "Inicia Busqueda Preferente" << endl;


    bool termina = false;
    Nodo * solucion;
    int parada = 30000000;
    Nodo nodoCabeza;

    while(!termina && parada > 0) {
        // Si la cola esta vacia
        if(colaNodos.empty()) {
            termina = true;
        } else {
            nodoCabeza = colaNodos.front();
            colaNodos.pop();
            pilaNodosExp.push(nodoCabeza);
            // Aumenta los nodos expandidos
            nodosExpandidos++;
            // Si el nodo cabeza es meta
            if(nodoCabeza.esMeta()) {
                // Terminar, encontro solucion
                solucion = &pilaNodosExp.top();
                //return solucion;


                termina = true;
            } else {
                // Expandir y meter nodos al final de la cola
                crearHijos(nodoCabeza);
            }
            /*
            if (nodoCabeza.get_indMeta() >=2) {

                cout << " NC : " << nodosCreados<< " => inMeta : " << nodoCabeza.get_indMeta() <<  " => inMeta : " << nodoCabeza.get_indMeta() <<  " => Prof : " << nodoCabeza.getProfundidad() <<  " ***** "  << endl;
            }
            */
        }
        parada--;
    }
    cout << "HOLA !!" << endl;

    cout << " NC : " << nodosCreados << " => inMeta : " << nodoCabeza.getFlagObjetivos() <<  " => Prof : " << nodoCabeza.getProfundidad() <<  " ***** "  << endl;

    return solucion;
}


void Amplitud::crearHijos(Nodo nodoCabeza)
{
    // Limites del entorno para crear nodos hijos
    int altoEntorno = this->miEntorno.getAlto();
    int anchoEntorno = this->miEntorno.getAncho();

    // Coordenadas del nodo cabeza
    int posI = nodoCabeza.getCoordI();
    int posJ = nodoCabeza.getCoordJ();
    // Direccion de los movimientos
    int arriba = posI - 1;
    int abajo = posI + 1;
    int izquierda = posJ - 1;
    int derecha = posJ + 1;

    // item donde esta el nodo cabeza
    int itemCabeza = this->miEntorno.getAmbiente()[posI][posJ];
    // estado sobre la que esta el nodo cabeza
    estados estadoCabeza = this->toEstado(itemCabeza);

    // Si el nodo cabeza no esta sobre la casilla de un humano, es decir, el humano no captura el robot
    if(estadoCabeza != onHumano)
    {
        // Aplica Operadores de Movimiento

        // Mover derecha
        if(derecha < anchoEntorno)
        {
            // Si es posible, crea nodo hijo
            this->crearNodo(posI, derecha, nodoCabeza);
        }
        // Mover abajo
        if(abajo < altoEntorno)
        {
            // Si es posible, crea nodo hijo
            this->crearNodo(abajo, posJ, nodoCabeza);
        }
        // Mover izquierda
        if(izquierda >= 0)
        {
            // Si es posible, crea nodo hijo
            this->crearNodo(posI, izquierda, nodoCabeza);
        }
        // Mover arriba
        if(arriba >= 0)
        {
            // Si es posible, crea nodo hijo
            this->crearNodo(arriba, posJ, nodoCabeza);
        }



    }
}

void Amplitud::crearNodo(int posIHijo, int posJHijo, Nodo nodoCabeza)
{
    // Item donde esta el nodo hijo
    int itemHijo = this->miEntorno.getAmbiente()[posIHijo][posJHijo];
    // Casilla donde esta el nodo hijo
    estados estadoHijo = this->toEstado(itemHijo);
    // Verifica que la casilla no sea una roca
    if(estadoHijo != onRoca)
    {
        // Puede crear el nodo hijo
        //int flagObjetivosPadre = nodoCabeza.getFlagObjetivos();
        //int flagObjetivos = this->validaObjetivo(nodoCabeza.getFlagObjetivos(), estadoHijo);
        // Si encuentra objetivo, en orden, lo quita del entorno
        // Crea el nodo hijo

        int profundidad = nodoCabeza.getProfundidad() + 1;
        int costoAcumulado = nodoCabeza.getCostoAcumulado();

        //Nodo nodoHijo(camino,profundidad,costoAcumulado,flagObjetivos,posIHijo,posJHijo);
        //Nodo nodoHijo(posIHijo, posJHijo, estadoHijo, nodoCabeza.getEntorno());
        Nodo nodoHijo(posIHijo, posJHijo, estadoHijo);

        nodoHijo.setProfundidad(profundidad);
        nodoHijo.setCostoAcumulado(costoAcumulado);
        nodoHijo.setFlagObjetivos(nodoCabeza.getFlagObjetivos());
        nodoHijo.setNodoPadre(&pilaNodosExp.top());

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
