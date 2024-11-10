#include "Grafo.h"
#include <algorithm>
#include <iostream>

using namespace std;

// Agregar un nodo (Vertice) al grafo
void Grafo::agregarNodo(Vertice* vertice) {
    nodos.push_back(vertice);
}

// Agregar una arista al grafo
void Grafo::agregarArista(Arista* arista) {
    aristas.push_back(arista);
}

// Comprobar si existe un nodo con el código dado (por ejemplo, por código de centro)
bool Grafo::hayNodo(const string& codigo) {
    for (const auto& nodo : nodos) {
        if (nodo->nodo->obtener_dato().getCodigo() == codigo) {  // Compara con el código del Centro
            return true;
        }
    }
    return false;
}

// Encontrar un nodo específico por su código (por ejemplo, por código de centro)
Vertice* Grafo::encontrarNodo(const string& codigo) {
    for (auto& nodo : nodos) {
        if (nodo->nodo->obtener_dato().getCodigo() == codigo) {  // Compara con el código del Centro
            return nodo;
        }
    }
    return nullptr;  // Si no se encuentra, devuelve nullptr
}

// Mostrar todos los nodos (vértices) en el grafo
void Grafo::mostrarNodos() {
    cout << "Nodos en el grafo:" << endl;
    for (const auto& nodo : nodos) {
        cout << "Codigo del Centro: " << nodo->nodo->obtener_dato().getCodigo() << endl;
    }
}

// Mostrar todas las aristas en el grafo
void Grafo::mostrarAristas() {
    cout << "Aristas en el grafo:" << endl;
    for (const auto& arista : aristas) {
        cout << "Origen: " << arista->getOrigen()->nodo->obtener_dato().getCodigo()  // Código del centro origen
             << " -> Destino: " << arista->getDestino()->nodo->obtener_dato().getCodigo()  // Código del centro destino
             << " -> Costo: " << arista->getCosto()
             << " -> Duracion: " << arista->getDuracion() << " horas" << endl;
    }
}