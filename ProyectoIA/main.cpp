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
      cout << "nodoA.getCostoAcumulado() = " << nodoA.getCostoAcumulado() << endl;
      return (nodoA.getCostoAcumulado() >= nodoB.getCostoAcumulado());
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

    priority_queue<Nodo, vector<Nodo>, mycomparison> colaPrioridad;

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
