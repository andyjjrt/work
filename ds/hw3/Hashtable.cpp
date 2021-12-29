#include "Hashtable.h"
#include <bits/stdc++.h>
using namespace std;

HashTable::HashTable(int n){
    hashtable = new list<int>[n];
    size = n;
}

HashTable::~HashTable(){
    for(int i = 0; i < size; i++){
        hashtable[i].clear();
    }
    delete [] hashtable;
}

int HashTable::hash(int val){
    //h(k) = floor (m * frac (k * c))
    return val % size;
}

void HashTable::insert(int val){
    int pos = hash(val);
    hashtable[pos].push_back(val);
}

int HashTable::search(int val){
    int pos = hash(val);
    for(list<int>::iterator it = hashtable[pos].begin(); it != hashtable[pos].end(); it++){
        if((*it) == val){
            return (*it);
            break;
        }
    }
    return -1;
}