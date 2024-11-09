#include <iostream>
#include "centro.h"
#include "centro.cpp"
#include "proyecto.h"
#include "proyectos.cpp"
#include "lista.h"
#include "nodo.h"
#include "nodo.cpp"
#include "lista.cpp"
#include <vector>

using namespace std;

 void mostrarMenu() {
    cout << "Menu de opciones:\n";
    cout << "1. Consultar por un centro de investigacion en particular\n";
    cout << "2. Agregar un nuevo centro de investigacion\n";
    cout << "3. Eliminar un centro de investigacion\n";
    cout << "4. Mostrar todos los centros de investigacion\n";
    cout << "5. Ordenar centros\n";
    cout << "6. Salir\n";
    }

int main() {
    Lista centros2; // = new centros();
    Centro c;
    c.setDatos("CEN", "Centro de Energia Nuclear", "Chile", 100.0, 10, 5, 3);
    centros2.alta(c, 1);
    c.setDatos("CAN", "Centro de Astronomia", "Chile", 200.0, 20, 10, 6);
    centros2.alta(c, 2);
    
    //leerCentros(centros2, "../centros.txt");
    centros2.mostrar();
    //string codigo, nombre, pais;
    //float superficie;
    //int laboratorios, proyectosNacionales, proyectosInternacionales, pos, atributo, opcion;
    
    //cout << consultarCentro("CAN", centros) << endl;
    centros2.baja(2);
    centros2.mostrar();

   

    return 0;
}  