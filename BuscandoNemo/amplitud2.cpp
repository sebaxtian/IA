#include "amplitud2.h"

Amplitud2::Amplitud2()
{
    this->nodosCreados = 0;
    this->nodosExpandidos = 0;
    this->codNextNodo = 0;
}

Amplitud2::Amplitud2(Nodo2 raiz, Entorno entorno)
{
    this->raiz = raiz;
    this->entorno = entorno;
    this->nodosCreados = 0;
    this->nodosExpandidos = 0;
    this->colaNodos.push(raiz);
    this->codNextNodo = 0;
}


// GETTERS
int Amplitud2::getNumNodosExpandidos()
{
    return this->nodosExpandidos;
}
int Amplitud2::getNumNodosCreados()
{
    return this->nodosCreados;
}


// Funciones miembro
queue<string> Amplitud2::makeBusqueda()
{
    // Camino encontrado de la solucion
    queue<string> camino;
    // Estado de parada del ciclo
    bool parada = false;
    // Iteraciones maximas, se usa solo para controlar final de algoritmo
    int numciclos = 300000;
    // Se inicia un ciclo para explorar el arbol de soluciones
    while(!parada && numciclos != 0)
    {
        // Verifica si la cola de nodos esta vacia
        if(this->colaNodos.empty())
        {
            // No encuentra solucion, termina el ciclo
            parada = true;
        }
        else
        {
            // Obtiene el nodo cabeza de la cola
            Nodo2 nodoCabeza = this->colaNodos.front();
            // Quita el nodo cabeza de la cola
            this->colaNodos.pop();
            // Aumenta el contandor de nodos expandidos
            this->nodosExpandidos++;
            // Verifica si el nodo cabeza es una meta
            if(nodoCabeza.esMeta())
            {
                // Si encuentra solucion, termina el ciclo
                //camino = nodoCabeza.getCamino();
                cout << "Posicion Final = " << nodoCabeza.getPosI() << ", " << nodoCabeza.getPosJ() << endl;
                parada = true;
            }
            else
            {
                // No encuentra solucion, expandir nodo cabeza y meter sus hijos al final de la cola
                this->crearNodosHijos(nodoCabeza);
            }
        }
        // Controlamos el numero de ciclos
        numciclos--;
    }
    // Retorna el camino de la solucion
    return camino;
}

void Amplitud2::crearNodosHijos(Nodo2 nodoCabeza)
{
    // Limites del entorno para crear nodos hijos
    int altoEntorno = this->entorno.getAlto();
    int anchoEntorno = this->entorno.getAncho();
    int roca = 1;
    int humano = 8;

    // Coordenadas del nodo cabeza
    int posI = nodoCabeza.getPosI();
    int posJ = nodoCabeza.getPosJ();
    // Direccion de los movimientos
    int arriba = posI - 1;
    int abajo = posI + 1;
    int izquierda = posJ - 1;
    int derecha = posJ + 1;

    // Aplica los operadores de movimiento

    // Mover arriba
    if(arriba >= 0)
    {
        // Item ubicado en la direccion del movimiento
        int itemArriba = this->entorno.getAmbiente()[arriba][posJ];
        // Si el item es diferente a un roca y humano entonces se puede mover
        if(itemArriba != roca && itemArriba != humano)
        {
            // Crea un nodo hijo en la ubicacion del item
            int coords[2] = {arriba, posJ};
            int codNodo = this->nextCodNodo();
            int refPadre = nodoCabeza.getCodNodo();
            operadores opAplicado = operadores::arriba;
            int profundidad = nodoCabeza.getProfundidad() + 1;
            int costoAcu = nodoCabeza.getCostoAcumulado(); // El costo es uniforme en Amplitud
            estados estadoActual = this->getEstado(itemArriba);
            //queue<string> camino = nodoCabeza.getCamino(); // El camino del nodo cabeza
            //camino.push(to_string(arriba) + "," + to_string(posJ)); // Al camino se agrega la posicion del nodo hijo
            int flagElementos = this->getNewFlagElementos(nodoCabeza.getFlagElementos(), estadoActual);
            // Nodo hijo
            //Nodo2 nodoHijo(coords,codNodo,refPadre,opAplicado,profundidad,costoAcu,estadoActual,camino,flagElementos);
            Nodo2 nodoHijo(coords,codNodo,refPadre,opAplicado,profundidad,costoAcu,estadoActual,flagElementos);
            // Se agrega el nodo hijo creado a la cola de nodos
            this->colaNodos.push(nodoHijo);
            // Aumenta el contador de hijos creados
            this->nodosCreados++;
        }
    }




    // Mover abajo
    if(abajo < altoEntorno)
    {
        // Item ubicado en la direccion del movimiento
        int itemAbajo = this->entorno.getAmbiente()[abajo][posJ];
        // Si el item es diferente a un roca y humano entonces se puede mover
        if(itemAbajo != roca && itemAbajo != humano)
        {
            // Crea un nodo hijo en la ubicacion del item
            int coords[2] = {abajo, posJ};
            int codNodo = this->nextCodNodo();
            int refPadre = nodoCabeza.getCodNodo();
            operadores opAplicado = operadores::abajo;
            int profundidad = nodoCabeza.getProfundidad() + 1;
            int costoAcu = nodoCabeza.getCostoAcumulado(); // El costo es uniforme en Amplitud
            estados estadoActual = this->getEstado(itemAbajo);
            //queue<string> camino = nodoCabeza.getCamino(); // El camino del nodo cabeza
            //camino.push(to_string(abajo) + "," + to_string(posJ)); // Al camino se agrega la posicion del nodo hijo
            int flagElementos = this->getNewFlagElementos(nodoCabeza.getFlagElementos(), estadoActual);
            // Nodo hijo
            //Nodo2 nodoHijo(coords,codNodo,refPadre,opAplicado,profundidad,costoAcu,estadoActual,camino,flagElementos);
            Nodo2 nodoHijo(coords,codNodo,refPadre,opAplicado,profundidad,costoAcu,estadoActual,flagElementos);
            // Se agrega el nodo hijo creado a la cola de nodos
            this->colaNodos.push(nodoHijo);
            // Aumenta el contador de hijos creados
            this->nodosCreados++;
        }
    }



    // Mover izquierda
    if(izquierda >= 0)
    {
        // Item ubicado en la direccion del movimiento
        int itemIzquierda = this->entorno.getAmbiente()[posI][izquierda];
        // Si el item es diferente a un roca y humano entonces se puede mover
        if(itemIzquierda != roca && itemIzquierda != humano)
        {
            // Crea un nodo hijo en la ubicacion del item
            int coords[2] = {posI, izquierda};
            int codNodo = this->nextCodNodo();
            int refPadre = nodoCabeza.getCodNodo();
            operadores opAplicado = operadores::izquierda;
            int profundidad = nodoCabeza.getProfundidad() + 1;
            int costoAcu = nodoCabeza.getCostoAcumulado(); // El costo es uniforme en Amplitud
            estados estadoActual = this->getEstado(itemIzquierda);
            //queue<string> camino = nodoCabeza.getCamino(); // El camino del nodo cabeza
            //camino.push(to_string(posI) + "," + to_string(izquierda)); // Al camino se agrega la posicion del nodo hijo
            int flagElementos = this->getNewFlagElementos(nodoCabeza.getFlagElementos(), estadoActual);
            // Nodo hijo
            //Nodo2 nodoHijo(coords,codNodo,refPadre,opAplicado,profundidad,costoAcu,estadoActual,camino,flagElementos);
            Nodo2 nodoHijo(coords,codNodo,refPadre,opAplicado,profundidad,costoAcu,estadoActual,flagElementos);
            // Se agrega el nodo hijo creado a la cola de nodos
            this->colaNodos.push(nodoHijo);
            // Aumenta el contador de hijos creados
            this->nodosCreados++;
        }
    }



    // Mover derecha
    if(derecha < anchoEntorno)
    {
        // Item ubicado en la direccion del movimiento
        int itemDerecha = this->entorno.getAmbiente()[posI][derecha];
        // Si el item es diferente a un roca y humano entonces se puede mover
        if(itemDerecha != roca && itemDerecha != humano)
        {
            // Crea un nodo hijo en la ubicacion del item
            int coords[2] = {posI, derecha};
            int codNodo = this->nextCodNodo();
            int refPadre = nodoCabeza.getCodNodo();
            operadores opAplicado = operadores::derecha;
            int profundidad = nodoCabeza.getProfundidad() + 1;
            int costoAcu = nodoCabeza.getCostoAcumulado(); // El costo es uniforme en Amplitud
            estados estadoActual = this->getEstado(itemDerecha);
            //queue<string> camino = nodoCabeza.getCamino(); // El camino del nodo cabeza
            //camino.push(to_string(posI) + "," + to_string(derecha)); // Al camino se agrega la posicion del nodo hijo
            int flagElementos = this->getNewFlagElementos(nodoCabeza.getFlagElementos(), estadoActual);
            // Nodo hijo
            //Nodo2 nodoHijo(coords,codNodo,refPadre,opAplicado,profundidad,costoAcu,estadoActual,camino,flagElementos);
            Nodo2 nodoHijo(coords,codNodo,refPadre,opAplicado,profundidad,costoAcu,estadoActual,flagElementos);
            // Se agrega el nodo hijo creado a la cola de nodos
            this->colaNodos.push(nodoHijo);
            // Aumenta el contador de hijos creados
            this->nodosCreados++;
        }
    }


}


int Amplitud2::getNewFlagElementos(int flagElementos, estados estadoActual)
{
    if(estadoActual == estados::onNemo && flagElementos < 1)
    {
        return flagElementos++;
    }
    if(estadoActual == estados::onMarlin && flagElementos < 2)
    {
        return flagElementos++;
    }
    if(estadoActual == estados::onDori && flagElementos < 3)
    {
        return flagElementos++;
    }
    return flagElementos;
}

estados Amplitud2::getEstado(int item)
{
    estados estado;
    switch (item)
    {
        case 2:
            estado = estados::onLibre;
            break;
        case 3:
            estado = estados::onTiburon;
            break;
        case 4:
            estado = estados::onTortuga;
            break;
        case 5:
            estado = estados::onDori;
            break;
        case 6:
            estado = estados::onMarlin;
            break;
        case 7:
            estado = estados::onNemo;
            break;
        default:
            break;
    }
    return estado;
}


int Amplitud2::nextCodNodo()
{
    this->codNextNodo++;
    return this->codNextNodo;
}
