#include "lista.h"
#include <iostream>
#include "centro.h"

Lista::Lista()
{
    primero = 0;
    largo = 0;
}

bool Lista::vacia()
{
    return (largo == 0);
}

void Lista::alta(Centro d, int pos)
{
    Nodo* nuevo = new Nodo(d);
    if (pos == 1)
    {
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    }
    else
    {
        Nodo* anterior = obtener_nodo(pos - 1);
        Nodo* siguiente = anterior->obtener_siguiente();
        nuevo->cambiar_siguiente(siguiente);
        anterior->cambiar_siguiente(nuevo);
    }
    largo++;
}

Nodo* Lista::obtener_nodo(int pos)
{
    Nodo* aux = primero;
    for(int i = 1; i < pos; i++)
        aux = aux->obtener_siguiente();
    return aux;
}

Centro Lista::consulta(int pos)
{
    Nodo* aux = obtener_nodo(pos);
    return aux->obtener_dato();
}

void Lista::baja(int pos)
{
    cout << "entro baja\n";
    system("pause");
    Nodo* borrar;
    if (pos == 1)
    {
        cout << "entro if " << pos<< endl;
        //borrar = primero;
        //primero = borrar->obtener_siguiente();
    }
    else
    {
        cout << "entro else\n";
        Nodo* anterior = obtener_nodo(pos - 1);
        cout << "anterior\n";
        borrar = anterior->obtener_siguiente();//nodo a borrar
        cout << "borrar\n";
        Nodo* siguiente = borrar->obtener_siguiente();
        cout << "siguiente\n";
        anterior->cambiar_siguiente(siguiente);
        cout << " anterior=sig\n";
    }
    delete borrar;
    largo--;
    cout << "salio baja\n" ;
}

Lista::~Lista()
{
    while (! vacia())
        baja(1);
}

int Lista::obtener_largo()
{
    return largo;
}

void Lista::mostrar()
{
      cout<<"[" << endl;

      if(!vacia())
      {
          for (int i = 1; i < largo; i++)
            {
                cout << consulta(i).getDatos() << endl;
            }
            //cout<<this->consulta(i)<<",";
        cout << consulta(largo).getDatos() << endl;
      }

      cout<<"]"<<endl;
}