#include <iostream>
#include "centro.h"
#include "centro.cpp"
#include "proyecto.h"
#include "Grafo.h"
#include "Arista.h"

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
        Centro* origen = grafo.encontrarNodo(cod_origen);
        if (!origen) {
            origen = new Centro(); // Crear un nuevo centro si no existe
            origen->setDatos(cod_origen, "", "", 0.0, 0, 0, 0); // Asegúrate de llenar los datos correctamente
            grafo.agregarNodo(origen); // Agregar al grafo
        }

        Centro* destino = grafo.encontrarNodo(cod_destino);
        if (!destino) {
            destino = new Centro(); // Crear un nuevo centro si no existe
            destino->setDatos(cod_destino, "", "", 0.0, 0, 0, 0); // Asegúrate de llenar los datos correctamente
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

    return 0;
}