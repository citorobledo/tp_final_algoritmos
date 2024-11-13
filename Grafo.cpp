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
             << " -> Costo: " << arista->getCosto()
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

    // Inicializa el mapa de distancias con infinito y el mapa de vistos a false
    unordered_map<Vertice*, double> distancia;
    unordered_map<Vertice*, bool> visto;
    unordered_map<Vertice*, Arista*> predecesores;

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
                    predecesores[vecino] = arista;
                }
            }
        }
    }

    // Reconstrucción del camino desde destino a origen usando el mapa de predecesores
   vector<Arista*> camino;

    // Partimos desde el destino y seguimos hacia el origen usando predecesores
    for (Vertice* v = destino; v != nullptr && v != origen; v = predecesores[v] ? predecesores[v]->getOrigen() : nullptr) {
        if (predecesores.find(v) == predecesores.end()) {
            cout << "No hay conexion posible." << endl;
            return {};
        }
        // Insertamos cada arista al inicio del vector para evitar la inversión posterior
        camino.insert(camino.begin(), predecesores[v]);
    }

    // Si el camino está vacío o no conecta al origen, significa que no hay conexión posible
    if (camino.empty() || camino.front()->getOrigen() != origen) {
        cout << "No hay conexion posible." << endl;
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
                  << " -> Costo: " << arista->getCosto()
                  << " -> Duracion: " << arista->getDuracion() << " horas" << endl;

        totalCosto += arista->getCosto();
        totalDuracion += arista->getDuracion();
    }

    // Muestra el total del costo o la duración dependiendo del criterio de búsqueda
    if (criterio == "costo") {
        cout << "Total costo: " << totalCosto << endl;
    } else if (criterio == "duracion") {
        cout << "Total duracion: " << totalDuracion << " horas" << endl;
    } else {
        cout << "Criterio no valido." << endl;
    }
}