#include "hash.h"
#include <iostream>
#include <string>

using namespace std;


HashTable::HashTable() {
    // Constructor por defecto
    //codigo = " ";
    //nombre = " ";
    //pais = " ";
    //superficie = 0.0;
    //laboratorios = 0;
    //proyectos_nacionales = 0;
    //proyectos_internacionales = 0;
}
 

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

    bool guardar(Centro centro, Lista table)
    {
      int hash = hashFunction(centro.getCodigo(), table.obtener_largo()) + 1;
      if (!table.pos_ocupada(hash))
      {
        table.alta(centro, hash);
      }
      else
      {
        cout << "Colision en la posicion " << hash << endl;
        int j = 1;
        do
        {
          int colision = quadraticProbing(hash, j, table.obtener_largo());
          if (!table.pos_ocupada(colision))
          {
            table.alta(centro, colision);
            break;
          }
          cout << "Colision en la posicion " << colision << endl;
          j++;
        } while (j <= table.obtener_largo());
      }
      return true;
    }