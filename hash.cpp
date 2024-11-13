#include "hash.h"
#include <iostream>
#include <string>

using namespace std;


HashTable::HashTable(int size) : table(size) {}

int HashTable::hashFunction(const string& key) const {
    int hash = 0;
    for (char ch : key) {
        //hash = (31 * hash + ch) % table.size();
        hash += ch;
    }
    return hash;
}

bool HashTable::insert( Centro &key, int value) {
    int hash = hashFunction(key.getCodigo());
 
    table[hash].alta(key, value);
    return true;
}

bool HashTable::search( string key, int& value)  {
    int hash = hashFunction(key);
    int pos = table[hash].buscarPosicion(key);
    if (pos != -1) {
        value = pos;
        return true;
    }
    return false;
}

bool HashTable::remove( string key) {
    int hash = hashFunction(key);
    int pos = table[hash].buscarPosicion(key);
    if (pos != -1) {
        table[hash].baja(pos);
        return true;
    }
    return false;
}

void HashTable::print()  {
    for ( auto lista : table) {
        lista.mostrar();
    }
}
