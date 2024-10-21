#include <iostream>
#include "centro.h"
#include "centro.cpp"

using namespace std;

int main() {
    Centro c;
    c.setDatos("CEN", "Centro de Investigacion", "pais", 100.34, 10, 5, 3);
    cout << c.leerArchivo();
    cout << "Archivo leido." << endl;
    cout << c.leerLinea() << endl;
    cout << c.leerLineaNumero(3) << endl;
    c.agregarCentro();
    //cout << c.getDatos() << endl;
    //system("pause");
    return 0;
}
