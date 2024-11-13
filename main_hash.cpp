#include "hash.h"
#include "hash.cpp"
#include <iostream>
#include "centro.h"
#include "centro.cpp"
#include "lista.h"
#include "lista.cpp"
#include "nodo.h"
#include "nodo.cpp"

using namespace std;

int main() {
    HashTable hashTable(5);
    Centro c = Centro();
    Centro c1 = Centro(); 
    Centro c2 = Centro();
    c.setDatos("CSI", "Centro Cientifico de Innovacion", "España", 12.5, 15, 23, 12);
    c1.setDatos("2", "Centro 2", "Brasil", 200.0, 20, 10, 6);
    c2.setDatos("3", "Centro 3", "Argentina", 300.0, 30, 15, 9);

    hashTable.insert(c, 1);
   // hashTable.insert("dos", 2);
   // hashTable.insert("tres", 3);
   // hashTable.insert("juan", 343);
   // hashTable.insert("uno", 1);
   // hashTable.insert("dos", 2);
   // hashTable.insert("tres", 3);
   // hashTable.insert("juan", 343);

    int value;
    if (hashTable.search("CSI", value)) {
        cout << "Valor encontrado: " << value << endl;
    } else {
        cout << "Valor no encontrado" << endl;
    }

    hashTable.print();

    hashTable.remove("CSI");

    if (hashTable.search("CSI", value)) {
        cout << "Valor encontrado: " << value << endl;
    } else {
        cout << "Valor no encontrado" << endl;
    }

    hashTable.print();

    return 0;
}
