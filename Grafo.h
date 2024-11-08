#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <string>
#include "Centro.h"    
#include "Arista.h"   

class Grafo {
private:
    // Vectores para almacenar nodos (centros) y aristas
    std::vector<Centro*> nodos;
    std::vector<Arista*> aristas;

public:
    // Constructor
    Grafo() = default;


    // Métodos para agregar nodos y aristas
    void agregarNodo(Centro* centro);  // Agregar un nodo (centro)
    void agregarArista(Arista* arista);  // Agregar una arista

    // Métodos para buscar nodos
    bool hayNodo(const std::string& codigo);  // Comprobar existencia de un nodo
    Centro* encontrarNodo(const std::string& codigo);  // Buscar un nodo y devolverlo

    // Métodos para mostrar nodos y aristas
    void mostrarNodos();  // Mostrar todos los nodos
    void mostrarAristas();  // Mostrar todas las aristas

    // Obtener las aristas de un nodo específico
    std::vector<Arista*> getAristas(Centro* centro);  // Obtener aristas de un nodo
};

#endif // GRAFO_H
