#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include <iostream>
#include "lista.h"
#include "centro.h"


using namespace std;

class HashTable {
private:

public:
    HashTable();

    int hashFunction(string key, int table);
    int quadraticProbing(int hash, int i, int table);
    bool guardar( Centro centro, Lista table);
    bool buscar( string key, int& value) ;
    bool borrar( string key);
    void imprimir() ;



};
#endif // HASH_TABLE_H

