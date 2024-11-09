#include <iostream>
#include "centro.h"
#include "centro.cpp"
#include "proyecto.h"
#include "proyectos.cpp"
#include "lista.h"
#include "nodo.h"
#include "nodo.cpp"
#include "lista.cpp"

using namespace std;

int main() {
    Lista centros2; // = new centros();
    //Centro c;
    //c.setDatos("CEN", "Centro de Energia Nuclear", "Chile", 100.0, 10, 5, 3);
    //centros2.alta(c, 1);
    //c.setDatos("CAN", "Centro de Astronomia", "Chile", 200.0, 20, 10, 6);
    //centros2.alta(c, 2);
    
    leerCentros(centros2, "../centros.txt");
    leerCentros(centros2, "centros.txt");
    centros2.mostrar();
    //string codigo, nombre, pais;
    //float superficie;
    //int laboratorios, proyectosNacionales, proyectosInternacionales, pos, atributo, opcion;
    
    //cout << consultarCentro("CAN", centros) << endl;
    //centros2.baja(2);
    //centros2.mostrar();
    //centros2.ordenarCentros(1);
    //centros2.mostrar();
   

    return 0;
}  