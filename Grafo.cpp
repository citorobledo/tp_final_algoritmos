#include "Grafo.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <limits>

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
             << " -> Costo: " << arista->getCosto() << " pesos"
             << " -> Duracion: " << arista->getDuracion() << " horas" << endl;
    }
}

// Método para encontrar la colaboración más económica o más rápida
vector<Arista*> Grafo::buscarColaboracion(const string& codigoOrigen, const string& codigoDestino, const string& criterio) {
    // Busca los vértices de origen y destino
    Vertice* origen = encontrarNodo(codigoOrigen);
    Vertice* destino = encontrarNodo(codigoDestino);

    // Si alguno de los nodos no existe, se notifica y retorna un camino vacío
    if (!origen || !destino) {
        cout << "Uno de los centros no existe." << endl;
        return {};
    }

    // Inicializa el mapa de distancias con infinito, el mapa de vistos a false y el mapa de sucesores
    unordered_map<Vertice*, double> distancia;
    unordered_map<Vertice*, bool> visto;
    unordered_map<Vertice*, Arista*> sucesores;

    // Configura todas las distancias a infinito y los nodos a no vistos
    for (auto& nodo : nodos) {
        distancia[nodo] = numeric_limits<double>::infinity();
        visto[nodo] = false;
    }

    // Configura la distancia inicial y marca el nodo origen como visto
    distancia[origen] = 0;

    // Mientras existan vértices no vistos
    while (true) {
        // Encuentra el vértice con la menor distancia que aún no se ha visto
        Vertice* verticeMin = nullptr;
        double minDistancia = numeric_limits<double>::infinity();

        for (auto& nodo : nodos) {
            if (!visto[nodo] && distancia[nodo] < minDistancia) {
                minDistancia = distancia[nodo];
                verticeMin = nodo;
            }
        }

        // Si no se encuentra un vértice mínimo, salimos del bucle
        if (verticeMin == nullptr) break;

        // Marca el vértice mínimo como visto
        visto[verticeMin] = true;

        // Para cada vecino del vértice actual, calcula la distancia
        for (auto& arista : aristas) {
            if (arista->getOrigen() == verticeMin) {
                Vertice* vecino = arista->getDestino();

                double peso;
                if (criterio == "costo") {
                    peso = arista->getCosto();
                } else if (criterio == "duracion") {
                    peso = arista->getDuracion();
                } else {
                    cout << "Criterio incorrecto." << endl;
                    return {};  // Salimos de la función si el criterio no es válido
                }

                // Actualiza la distancia si encuentra un camino más corto
                if (distancia[vecino] > distancia[verticeMin] + peso) {
                    distancia[vecino] = distancia[verticeMin] + peso;
                    sucesores[vecino] = arista;  // Actualizamos el sucesor con la arista
                }
            }
        }
    }

    // Reconstrucción del camino desde origen a destino usando el mapa de sucesores
    vector<Arista*> camino;
    Vertice* v = destino;

    // Seguimos el camino desde el destino hacia el origen
    while (v != nullptr && v != origen) {
        if (sucesores.find(v) == sucesores.end()) {
            cout << "No hay conexión posible." << endl;
            return {};
        }

        Arista* arista = sucesores[v];
        camino.insert(camino.begin(), arista); // Insertamos la arista en el principio para no invertir después

        v = arista->getOrigen(); // Retrocedemos al origen de la arista
    }

    // Verificamos si el camino está vacío o si no conecta al origen
    if (camino.empty() || camino.front()->getOrigen() != origen) {
        cout << "No hay conexión posible." << endl;
        return {};
    }

    return camino;  // Retorna el camino en orden de origen a destino
}

// Método para mostrar los resultados del camino encontrado
void Grafo::mostrarResultados(const vector<Arista*>& camino, const string& criterio) {
    // Si el camino está vacío, no hay conexiones posibles
    if (camino.empty()) {
        cout << "No hay conexiones posibles." << endl;
        return;
    }

    double totalCosto = 0;
    double totalDuracion = 0;

    // Muestra cada arista del camino y acumula el costo y la duración totales
    cout << "Detalles del camino:" << endl;
    for (const auto& arista : camino) {
            cout << "Origen: " << arista->getOrigen()->nodo->obtener_dato().getCodigo()
                  << " -> Destino: " << arista->getDestino()->nodo->obtener_dato().getCodigo()
                  << " -> Costo: " << arista->getCosto() << " pesos"
                  << " -> Duracion: " << arista->getDuracion() << " horas" << endl;

        totalCosto += arista->getCosto();
        totalDuracion += arista->getDuracion();
    }

    // Muestra el total del costo o la duración dependiendo del criterio de búsqueda
    if (criterio == "costo") {
        cout << "Total costo: " << totalCosto << " pesos" << endl;
    } else if (criterio == "duracion") {
        cout << "Total duracion: " << totalDuracion << " horas" << endl;
    } else {
        cout << "Criterio no valido." << endl;
    }
}