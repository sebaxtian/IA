#include "mainwindow.h"
#include <QApplication>

#include <queue>
#include <vector>
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
      return (a.getCostoAcumulado() <= b.getCostoAcumulado());
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
/*
    priority_queue<Nodo, vector<Nodo>, mycomparison> colaPrioridad;
    Nodo ap1 = Nodo(0, 0, 0, 0, onRobot);
    ap1.setCostoAcumulado(1.8);
    Nodo ap2 = Nodo(1, 1, 1, 1, onRobot);
    ap1.setCostoAcumulado(1);
    Nodo ap3 = Nodo(2, 2, 2, 2, onRobot);
    ap1.setCostoAcumulado(2.8);
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
*/
    cout << endl;
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    // Prueba colas con prioridad
    pruebaColaPrioridad();


    return a.exec();
}
