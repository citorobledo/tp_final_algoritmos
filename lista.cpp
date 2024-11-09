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
    Nodo* borrar;
    if (pos == 1)
    {
        borrar = primero;
        primero = borrar->obtener_siguiente();
    }
    else
    {
        Nodo* anterior = obtener_nodo(pos - 1);
        borrar = anterior->obtener_siguiente();
        Nodo* siguiente = borrar->obtener_siguiente();
        anterior->cambiar_siguiente(siguiente);
    }
    delete borrar;
    largo--;
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
                cout << ",\n";
            }
        cout << consulta(largo).getDatos() << endl;
      }

      cout<<"]"<<endl;
}

void Lista::ordenarCentros( int at) {
    cout << "Ordenando centros... :" << endl;
    for (int i = 0; i < obtener_largo(); i++) {
        for (int j = 1; j < obtener_largo() ; j++) {
            
            // implementar un switch para ordenar por cualquier atributo
            if (consultarAtributo(j, at) > consultarAtributo(j+1, at)) {
                Centro temp = consulta(j);
                baja(j);
                alta(temp, j + 1);
            }
        }
    }
}

string Lista::consultarAtributo(int pos, int atributo) {
    string atributo_str = "Atributo no encontrado.";
    switch (atributo) {
        case 1:
            atributo_str = consulta(pos).getCodigo();
            break;
        case 2:
            atributo_str = consulta(pos).getNombre();
            break;
        case 3:
            atributo_str = consulta(pos).getPais();
            break;
        case 4:
            atributo_str = to_string(consulta(pos).getSuperficie());
            break;
        case 5:
            atributo_str = to_string(consulta(pos).getLaboratorios());
            break;
        case 6:
            atributo_str = to_string(consulta(pos).getProyectosNacionales());
            break;
        case 7:
            atributo_str = to_string(consulta(pos).getProyectosInternacionales());
            break;
    }
    return atributo_str;
}

string Lista::consultarCentro(string cod) {
    cout << "Consultando centro " << cod << endl;
    string centro = "Centro no encontrado.";
    for (int i = 1; i <= obtener_largo(); i++) {
        if (consulta(i).getCodigo() == cod ) {
            centro = consulta(i).getDatos();
        }
    }
    return centro;
}

int Lista::buscarPosicion(string codigo) {
    cout << "Buscando posicion del centro " << codigo << endl;
    int pos = 1;
    for (int i = 1; i < obtener_largo()+1; i++) {
        if (consulta(i).getCodigo() == codigo) {
            pos = i;
        }
    }
    return pos;
}