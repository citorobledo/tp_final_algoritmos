#include <iostream>
#include "proyecto.h"
#include "proyectos.cpp"
#include "Vertice.h"
#include "Vertice.cpp"
#include "Arista.h"
#include "Arista.cpp"
#include "nodo.h"
#include "nodo.cpp"
#include "centro.h"
#include "centro.cpp"
#include "lista.h"
#include "lista.cpp"
#include "Grafo.cpp"
#include "Grafo.h"
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    Grafo grafo;

    // Abrir el archivo proyectos.txt
    ifstream archivo("proyectos.txt");
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo proyectos.txt" << endl;
        return 1;
    }

    string linea;
    while (getline(archivo, linea)) {
        string cod_origen, cod_destino;
        float costo, duracion;

        // Procesar cada línea usando stringstream
        stringstream ss(linea);
        ss >> cod_origen >> cod_destino >> costo >> duracion;

        // Buscar o agregar nodos de origen y destino
        Vertice* origen = grafo.encontrarNodo(cod_origen);
        if (!origen) {
            // Crear el centro origen (Nodo) con el código correspondiente
            Centro* centroOrigen = new Centro();
            centroOrigen->setDatos(cod_origen, "", "", 0.0, 0, 0, 0);  // Asegúrate de llenar los datos correctamente
            Nodo* nodoOrigen = new Nodo(*centroOrigen);  // Crear un nodo con el centro
            origen = new Vertice(nodoOrigen);  // Crear un vértice con el nodo de origen
            grafo.agregarNodo(origen); // Agregar al grafo
        }

        Vertice* destino = grafo.encontrarNodo(cod_destino);
        if (!destino) {
            // Crear el centro destino (Nodo) con el código correspondiente
            Centro* centroDestino = new Centro();
            centroDestino->setDatos(cod_destino, "", "", 0.0, 0, 0, 0);  // Asegúrate de llenar los datos correctamente
            Nodo* nodoDestino = new Nodo(*centroDestino);  // Crear un nodo con el centro
            destino = new Vertice(nodoDestino);  // Crear un vértice con el nodo de destino
            grafo.agregarNodo(destino);
        }

        // Crear una arista entre origen y destino
        Arista* arista = new Arista(origen, destino, costo, duracion);
        grafo.agregarArista(arista);
    }

    // Cerrar el archivo
    archivo.close();

    // Mostrar los nodos y aristas del grafo para verificar
    grafo.mostrarNodos();
    grafo.mostrarAristas();

    // Interacción con el usuario para buscar colaboración
    string codigoOrigen, codigoDestino, criterio;

    cout << "Ingrese el codigo del centro de origen: ";
    cin >> codigoOrigen;
    cout << "Ingrese el codigo del centro de destino: ";
    cin >> codigoDestino;
    cout << "Si quieres buscar por costo ingresa costo, si es por duracion ingrese duracion: ";
    cin >> criterio;

    // Buscar la colaboración
    vector<Arista*> camino = grafo.buscarColaboracion(codigoOrigen, codigoDestino, criterio);
    
    // Mostrar los resultados
    grafo.mostrarResultados(camino, criterio);

    return 0;
}