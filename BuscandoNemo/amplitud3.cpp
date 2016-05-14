#include "amplitud3.h"

Amplitud3::Amplitud3()
{

}

Amplitud3::Amplitud3(Nodo3 nodoRaiz, Entorno entorno)
{
    this->nodoRaiz = nodoRaiz;
    this->entorno = entorno;
    this->colaNodos.push(nodoRaiz);
}

Nodo3 Amplitud3::getNodoRaiz()
{
    return this->nodoRaiz;
}

Nodo3 Amplitud3::getNodoSolucion()
{
    return this->nodoSolucion;
}

Entorno Amplitud3::getEntorno()
{
    return this->entorno;
}

int Amplitud3::getNodosCreados()
{
    return this->nodosCreados;
}

int Amplitud3::getNodosExpandidos()
{
    return this->nodosExpandidos;
}

void Amplitud3::makeBusqueda()
{
    // Estado de parada del ciclo
    bool parada = false;
    // Cilos maximos, se usa para controlar el fin del algoritmo
    int maxCiclos = 10000000;
    cout << "Inicia Ciclo parada = " << parada << " maxCiclos = " << maxCiclos << endl;
    // Inicia ciclo para explorar arbol de soluciones
    while(!parada && maxCiclos > 0)
    {
        // Verifica si la cola de nodos es vacia
        if(this->colaNodos.empty())
        {
            // No encuentra solucion, termina el ciclo
            parada = true;
        }
        else
        {
            // Saca el nodo cabeza de la cola
            Nodo3 nodoCabeza = this->colaNodos.front();
            // Quita el nodo cabeza de la cola
            this->colaNodos.pop();
            // Aumenta el contandor de nodos expandidos
            this->nodosExpandidos++;
            // Verifica si el nodo cabeza es una meta
            if(nodoCabeza.esMeta())
            {
                // El nodo es una solucion
                this->nodoSolucion = nodoCabeza;
                // Si encuentra solucion, termina el ciclo
                parada = true;
            }
            else
            {
                // No encuentra solucion, expandir nodo cabeza y meter sus hijos al final de la cola
                this->crearHijos(nodoCabeza);
            }
        }
        // Controlador de numero maximo de ciclos
        maxCiclos--;
    }
    cout << "Sale del Ciclo parada = " << parada << " maxCiclos = " << maxCiclos << endl;
    cout << endl;
    // Imprime la solucion del nodo solucion encontrado
    this->imprimirSolucion(this->nodoSolucion);
}

void Amplitud3::crearHijos(Nodo3 nodoCabeza)
{
    // Limites del entorno para crear nodos hijos
    int altoEntorno = this->entorno.getAlto();
    int anchoEntorno = this->entorno.getAncho();

    // Coordenadas del nodo cabeza
    int posI = nodoCabeza.getCoordI();
    int posJ = nodoCabeza.getCoordJ();
    // Direccion de los movimientos
    int arriba = posI - 1;
    int abajo = posI + 1;
    int izquierda = posJ - 1;
    int derecha = posJ + 1;

    // item donde esta el nodo cabeza
    int itemCabeza = this->entorno.getAmbiente()[posI][posJ];
    // casilla sobre la que esta el nodo cabeza
    casillas casillaCabeza = this->toCasilla(itemCabeza);

    // Si el nodo cabeza no esta sobre la casilla de un humano, es decir, el humano no captura el robot
    if(casillaCabeza != onHumano)
    {
        // Aplica Operadores de Movimiento

        // Mover arriba
        if(arriba > 0)
        {
            // Si es posible, crea nodo hijo
            this->crearNodo(arriba, posJ, nodoCabeza);
        }
        // Mover abajo
        if(abajo < altoEntorno)
        {
            // Si es posible, crea nodo hijo
            this->crearNodo(abajo, posJ, nodoCabeza);
        }
        // Mover izquierda
        if(izquierda > 0)
        {
            // Si es posible, crea nodo hijo
            this->crearNodo(posI, izquierda, nodoCabeza);
        }
        // Mover derecha
        if(derecha < anchoEntorno)
        {
            // Si es posible, crea nodo hijo
            this->crearNodo(posI, derecha, nodoCabeza);
        }
    }
}

void Amplitud3::crearNodo(int posIHijo, int posJHijo, Nodo3 nodoCabeza)
{
    // Coordenadas del nodo hijo
    int coords[2] = {posIHijo, posJHijo};
    // Item donde esta el nodo hijo
    int itemHijo = this->entorno.getAmbiente()[coords[0]][coords[1]];
    // Casilla donde esta el nodo hijo
    casillas casillaHijo = this->toCasilla(itemHijo);
    // Verifica que la casilla no sea una roca
    if(casillaHijo != onRoca)
    {
        // Puede crear el nodo hijo
        int flagObjetivos = this->validaObjetivo(nodoCabeza.getFlagObjetivos(), casillaHijo);
        // Crea el nodo hijo
        string camino = nodoCabeza.getCamino();
        camino.append(to_string(posIHijo) + "-" + to_string(posJHijo) + ",");
        int profundidad = nodoCabeza.getProfundidad() + 1;
        int costoAcumulado = nodoCabeza.getCostoAcumulado();
        Nodo3 nodoHijo(camino,profundidad,costoAcumulado,flagObjetivos,coords[0],coords[1]);
        // Agrega el nodo creado a la cola de nodos
        this->colaNodos.push(nodoHijo);
        // Aumenta el contador de hijos creados
        this->nodosCreados++;
    }
}

casillas Amplitud3::toCasilla(int itemEntorno)
{
    casillas casilla;
    switch (itemEntorno)
    {
        case 1:
            casilla = onRoca;
            break;
        case 2:
            casilla = onLibre;
            break;
        case 3:
            casilla = onTiburon;
            break;
        case 4:
            casilla = onTortuga;
            break;
        case 5:
            casilla = onDori;
            break;
        case 6:
            casilla = onMarlin;
            break;
        case 7:
            casilla = onNemo;
            break;
        case 8:
            casilla = onHumano;
            break;
        default:
            break;
    }
    return casilla;
}

int Amplitud3::validaObjetivo(int flagObjetivos, casillas casilla)
{
    if(casilla == onNemo && flagObjetivos < 1)
    {
        return flagObjetivos++;
    }
    if(casilla == onMarlin && flagObjetivos < 2)
    {
        return flagObjetivos++;
    }
    if(casilla == onDori && flagObjetivos < 3)
    {
        return flagObjetivos++;
    }
    return flagObjetivos;
}

void Amplitud3::imprimirSolucion(Nodo3 nodo)
{
    cout << "Nodos Expandidos: " << this->nodosExpandidos << endl;
    cout << "Nodos Creados: " << this->nodosCreados << endl;

    cout << endl;

    /*
    Nodo3* nodoPadre = nodo.getNodoPadre();
    int profundidad = nodo.getProfundidad();
    cout << "Profundidad Nodo = " << profundidad << endl;
    while(profundidad > 0)
    {
        cout << "Paso" << profundidad << ": (" << nodoPadre->getCoordI() << ", " << nodoPadre->getCoordJ() << ")" << endl;
        nodoPadre = nodoPadre->getNodoPadre();
        profundidad--;
    }
    */
    cout << "Camino: " << nodo.getCamino() << endl;

    char * camino = new char [nodo.getCamino().length()+1];
    strcpy (camino, nodo.getCamino().c_str());
    char* tokens = strtok(camino,",");
    while(tokens != NULL)
    {
        cout << "Paso: " << "(" << tokens << ")" << endl;
        tokens = strtok(NULL,",");
    }

    cout << endl;
}
