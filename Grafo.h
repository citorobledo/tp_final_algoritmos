#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <string>
#include "Vertice.h"    // Include Vertice instead of Centro
#include "Arista.h"     // Assuming Arista uses Vertice as well

class Grafo {
private:
    std::vector<Vertice*> nodos;   // Change Centro* to Vertice*
    std::vector<Arista*> aristas;

public:
    Grafo() = default;

    void cargarDesdeArchivo(const std::string& filename);
    void agregarNodo(Vertice* vertice);      // Update parameter type to Vertice*
    void agregarArista(Arista* arista);
    bool hayNodo(const std::string& codigo);
    Vertice* encontrarNodo(const std::string& codigo);
    void mostrarNodos();
    void mostrarAristas();
    std::vector<Arista*> getAristas(Vertice* vertice);
};

#endif // GRAFO_H
