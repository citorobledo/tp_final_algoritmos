#include <iostream>
#include <fstream>
#include "centro.h"

using namespace std;

Centro::Centro() {
    // Constructor por defecto
}

void Centro::leerArchivo() {
    cout << "Leyendo archivo..." << endl;
    ifstream archivo("../centros.txt");

    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo centros.txt" << endl;
    }
}
