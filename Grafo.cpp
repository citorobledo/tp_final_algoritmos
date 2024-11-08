#include "Grafo.h"
#include <algorithm>
#include <iostream>

using namespace std;

// Agregar un nodo (Centro)
void Grafo::agregarNodo(Centro* centro) {
    nodos.push_back(centro);
}

// Agregar una arista
void Grafo::agregarArista(Arista* arista) {
    // Añade una arista al grafo
    aristas.push_back(arista);
}

// Comprobar si existe  el nodo con el código dado 
bool Grafo::hayNodo(const string& codigo) {
    for (const auto& nodo : nodos) {
        if (nodo->getCodigo() == codigo) {
            return true;
        }
    }
    return false;
}

// Encontrar un nodo específico con el código dado
Centro* Grafo::encontrarNodo(const string& codigo) {
    for (auto& nodo : nodos) {
        if (nodo->getCodigo() == codigo) {
            return nodo;
        }
    }
    return nullptr;
}

// Mostrar todos los nodos (centros) en el grafo
void Grafo::mostrarNodos() {
    cout << "Nodos en el grafo:" << endl;
    for (const auto& nodo : nodos) {
        cout << "Nodo " << nodo->getCodigo() << endl;
    }
}

// Mostrar todas las aristas en el grafo
void Grafo::mostrarAristas() {
    cout << "Aristas en el grafo:" << endl;
    for (const auto& nodo : nodos) {
        cout << "Nodo " << nodo->getCodigo() << ":" << endl;
        for (const auto& arista : aristas) {
            // Compara el código del nodo origen con el nodo actual
            if (arista->getOrigen()->getCodigo() == nodo->getCodigo()) {
                cout << " (Nodo origen: " << arista->getOrigen()->getCodigo()
                     << " -> Nodo destino: " << arista->getDestino()->getCodigo()
                     << " -> Costo del proyecto: " << arista->getCosto()
                     << " -> Duración del proyecto: " << arista->getDuracion() << " horas)"
                     << endl;
            }
        }
        cout << endl;
    }
}

// Obtener todas las aristas de un nodo específico
vector<Arista*> Grafo::getAristas(Centro* centro) {
    vector<Arista*> aristasDeNodo;
    for (const auto& arista : aristas) {
        // Comparar el nodo origen con el centro proporcionado
        if (arista->getOrigen() == centro) {
            aristasDeNodo.push_back(arista);
        }
    }
    return aristasDeNodo;
}