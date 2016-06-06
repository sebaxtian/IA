#include "mainwindow.h"
#include <QApplication>

#include <queue>
#include <vector>
#include <stack>
#include "nodo.h"


//Función de comparación
//El operador le da mejor prioridad a los menores, si lo desea al reves cambie el operador por <=
/*
struct CompararPrioridad
{
    bool operator() (const Nodo &a, const Nodo &b) const
    {
        //return a.prioridad>=b.prioridad;
        return a.getCostoAcumulado() >= b.getCostoAcumulado();
    }

};
*/

/*
class mycomparison
{
public:
  mycomparison()
    {}
  bool operator() (const int& lhs, const int&rhs) const
  {
      return lhs<=rhs;
  }
};
*/

class mycomparison
{
public:
  mycomparison()
    {}
  bool operator() (const Nodo& nodoA, const Nodo& nodoB) const
  {
     // cout << "nodoA.getCostoAcumulado() = " << nodoA.getCostoAcumulado() << endl;
      Nodo  a = nodoA;
      Nodo  b = nodoB;
      return (a.getCostoAcumulado() >= b.getCostoAcumulado());
  }
};


void pruebaColaPrioridad()
{
    cout << "Ejemplo Cola de Prioridad" << endl;

    /*
    // Define una cola de prioridad, la prioridad es el menor
    priority_queue<int, deque<int>, greater<int>> colaPrioridad;

    // Inserta elementos
    colaPrioridad.push(10);
    colaPrioridad.push(30);
    colaPrioridad.push(4);
    colaPrioridad.push(60);
    colaPrioridad.push(11);
    colaPrioridad.push(30);

    // Imprime los elementos
    while(!colaPrioridad.empty())
    {
        cout << "Elemento: " << colaPrioridad.top() << endl;
        // Elimina el elemento
        colaPrioridad.pop();
    }
    */

    int ** a;
    priority_queue<Nodo, vector<Nodo>, mycomparison> colaPrioridad;

    Nodo ap1 = Nodo(0, 0, 0, 0, onRobot, a);
    ap1.setCostoAcumulado(1.8);

    Nodo ap2 = Nodo(1, 1, 1, 1, onRobot, a);
    ap2.setCostoAcumulado(1);

    Nodo ap3 = Nodo(2, 2, 2, 2, onRobot, a);
    ap3.setCostoAcumulado(2.8);

    colaPrioridad.push(ap1);
    colaPrioridad.push(ap2);
    colaPrioridad.push(ap3);

    while(!colaPrioridad.empty())
    {
        Nodo p = colaPrioridad.top();
        cout << "Elemento: (" << p.getCoordI() << "," << p.getCoordJ() << ")" << endl;
        // Elimina el elemento
        colaPrioridad.pop();
    }

    cout << endl;
}



void pruebaOrdenOps(char op0, char op1, char op2, char op3)
{
    char operadores [4];

    operadores[0] = op0;
    operadores[1] = op1;
    operadores[2] = op2;
    operadores[3] = op3;

    for(int i = 0; i < 4; i++)
    {
        switch(operadores[i])
        {
            case 'L':
                cout << "Aplica Operador Izquierda" << endl;
                break;
            case 'U':
                cout << "Aplica Operador Arriba" << endl;
                break;
            case 'R':
                cout << "Aplica Operador Derecha" << endl;
                break;
            case 'D':
                cout << "Aplica Operador Abajo" << endl;
                break;
            default:
                cout << "No Aplica Operador" << endl;
        }
    }

    cout << endl;
    cout << endl;

}



void pruebaEvitarCiclos()
{
    cout << "Prueba de Evitar Ciclos" << endl;

    stack<int> pila;

    pila.push(2);
    pila.push(5);
    pila.push(3);
    pila.push(0);
    pila.push(1);
    pila.push(42);
    pila.push(3);
    pila.push(9);

    int n = pila.size();
    queue<int> pila2;

    for(int i = 0; i < n; i++) {
        int elem = pila.top();
        pila.pop();
        cout << "elem " << elem << endl;
        pila2.push(elem);
    }

    cout << endl;

    int m = pila2.size();
    for(int i = 0; i < m; i++) {
        int elem2 = pila2.front();
        pila2.pop();
        cout << "elem2: " << elem2 << endl;
        pila.push(elem2);
    }

    cout << endl;

    int w = pila.size();
    for(int i = 0; i < w; i++) {
        int elem = pila.top();
        pila.pop();
        cout << "elem " << elem << endl;
    }

    cout << endl;
}



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    // Prueba colas con prioridad
    pruebaColaPrioridad();


    // Prueba orden de operadores
    pruebaOrdenOps('U','L','R','D');
    pruebaOrdenOps('D','R','U','L');

    // Prueba de evitar ciclos
    //pruebaEvitarCiclos();


    return a.exec();
}
