#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <string>
#include <unordered_map>
#include <limits>
#include "Vertice.h"    // Incluye Vertice
#include "Arista.h"     // Incluye Arista

class Grafo {
private:
    std::vector<Vertice*> nodos;   // Lista de nodos (vértices)
    std::vector<Arista*> aristas;  // Lista de aristas

public:
    Grafo() = default;

    void cargarDesdeArchivo(const std::string& filename);
    void agregarNodo(Vertice* vertice);
    void agregarArista(Arista* arista);
    bool hayNodo(const std::string& codigo);
    Vertice* encontrarNodo(const std::string& codigo);
    void mostrarNodos();
    void mostrarAristas();
    
    // Método para buscar la colaboración más económica o más rápida
    std::vector<Arista*> buscarColaboracion(const std::string& codigoOrigen, const std::string& codigoDestino, const string& criterio);

    // Método para mostrar los resultados
    void mostrarResultados(const std::vector<Arista*>& camino, const string& criterio);

    std::vector<Arista*> getAristas(Vertice* vertice);
};

#endif // GRAFO_H
