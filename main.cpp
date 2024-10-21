#include <iostream>
#include "centro.h"
#include "centro.cpp"

using namespace std;

int main() {
    Centro c;
    c.leerArchivo();
    cout << "Archivo leido." << endl;
    system("pause");
    return 0;
}
