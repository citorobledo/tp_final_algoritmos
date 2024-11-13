#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include <iostream>
#include "lista.h"
#include "centro.h"

using namespace std;

class HashTable
{

private:
public:
    HashTable();
    int hashFunction(string cod, int table);
    int quadraticProbing(int hash, int i, int table);
    bool guardar_centro(Centro centro, Lista &table);
    string buscar_centro(string cod, Lista &table);
    ;
    void borrar_centro(string cod, Lista &table);
};
#endif // HASH_TABLE_H
