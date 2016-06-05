#ifndef PROFUNDIDAD_H
#define PROFUNDIDAD_H



//Función de comparación
//El operador le da mejor prioridad a los menores, si lo desea al reves cambie el operador por <=

class CompararPrioridad
{
public:
  CompararPrioridad()
    {}
  bool operator() (const Nodo& nodoA, const Nodo& nodoB) const
  {
     // cout << "nodoA.getCostoAcumulado() = " << nodoA.getCostoAcumulado() << endl;
      Nodo  nodA = nodoA;
      Nodo  nodB = nodoB;
      return (nodA.getCostoAcumulado() >= nodB.getCostoAcumulado());
  }
};


class Profundidad
{

public:
    Profundidad();
};

#endif // PROFUNDIDAD_H
