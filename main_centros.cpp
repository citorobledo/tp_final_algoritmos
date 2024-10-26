#include <iostream>
#include "centro.h"
#include "centro.cpp"
#include "proyecto.h"
#include "proyectos.cpp"

using namespace std;

int main() {
    Centro c;
    Centro a;
    c.setDatos("CEN", "Centro de Investigacion", "pais", 100.34, 10, 5, 3);
    cout << c.leerArchivo();
    cout << "Archivo leido." << endl;
    cout << c.leerLinea() << endl;
    cout << c.leerLineaNumero(3) << endl;
    a = leerCentro(c.leerLineaNumero(1));
    cout << c.getDatos() << endl;
    cout << a.getDatos() << endl;
    //c.agregarCentro("AST", "Centro de paradise", "argelia", 10.334, 15, 15, 13);
    //cout << c.getDatos() << endl;
    //system("pause");

  return 0;
}