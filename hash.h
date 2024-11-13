#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <vector>
#include <string>
#include <iostream>
#include "lista.h"
#include "centro.h"
//#include "centro.cpp"

using namespace std;

class HashTable {
public:
    HashTable(int size);
    bool insert( Centro& key, int value);
    bool search( string key, int& value) ;
    bool remove( string key);
    void print() ;

private:
    struct Entry {
        Centro key;
        int value;


        Entry() : key(key), value(1) {}
        Entry(const Centro& k, int v) : key(k), value(v) {}
    };

    vector<Lista> table;
    int hashFunction(const string& key) const;
};

#endif // HASH_TABLE_H

