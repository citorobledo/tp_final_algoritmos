#include <iostream>
#include <vector>
//#include <list>
#include "lista.h"
#include "lista.cpp"
#include "centro.h"
#include "centro.cpp"
#include "nodo.h"
#include "nodo.cpp"
//#include "hash.h"

using namespace std;

int hashFunction(string key, int table) {
    int hash = 0;
    for (char ch : key) {
        //hash = (31 * hash + ch) % table.size();
        hash += ch;
    }
    return (hash % table);
}

int quadraticProbing(int hash, int i, int table) { 
    if ((hash + i * i) % table == 0) {
        return 1;
    }
    
    return ((hash + i * i) % table);
    }
int main() {

    Lista centros; // = new centros();

    //leerCentros(centros, "../centros.txt");
    leerCentros(centros, "centros.txt");

    double loadFactor = 0.7;
    int capacity = centros.obtener_largo() / loadFactor;//implementar el proximo primo para calcular la capacidad
   


    Lista table ;
    for (int i = 1; i <= capacity; i++) {
        Centro *c = new Centro();
        table.alta(*c, i);
    }
    


    for (int i = 1; i <= centros.obtener_largo(); i++) {
        int hash = hashFunction(centros.consulta(i).getCodigo(), table.obtener_largo()) +1;
        if(!table.pos_ocupada(hash)){
            table.alta(centros.consulta(i), hash);
        }
        else
        {
            cout << "Colision en la posicion " << hash << endl;
            int j = 1;
            do {
                int colision = quadraticProbing(hash, j, table.obtener_largo());
                if(!table.pos_ocupada(colision)){
                    table.alta(centros.consulta(i), colision);
                    break;
                }
                cout << "Colision en la posicion " << colision << endl;
                j++;
            }
            while (j <= table.obtener_largo());
        }
    }

   // Centro c = Centro();
   // Centro c1 = Centro(); 
   // Centro c2 = Centro();
   // Centro c3 = Centro();
   // c.setDatos("CSI", "Centro Cientifico de Innovacion", "España", 12.5, 15, 23, 12);
   // c1.setDatos("2", "Centro 2", "Brasil", 200.0, 20, 10, 6);
   // c2.setDatos("3", "Centro 3", "Argentina", 300.0, 30, 15, 9);
   // c3.setDatos("LAT", "Laboratorio Avanzado de Tecnologia", "Brasil", 8.7, 8, 12, 18);
//
//
   //
   // // Insertar elementos de ejemplo
   // int hash2 = hashFunction(c.getCodigo(), table.obtener_largo());
   // table.alta(c, quadraticProbing(hash2, 0, table.obtener_largo())); // inserta el centro c en la posicion 1 de la lista l
   // table.alta(c1, 2);
   // table.alta(c2, 4);
   // int hash = hashFunction(c3.getCodigo(), table.obtener_largo());
   // table.alta(c3, quadraticProbing(hash, 1, table.obtener_largo()));
//
   // table.obtener_largo();
   // int pos = 1;
    table.mostrar();


    return 0;
}