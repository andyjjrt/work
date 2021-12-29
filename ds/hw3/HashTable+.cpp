#include "HashTable+.h"
#include <bits/stdc++.h>
using namespace std;

Array::Array(){
    capacity = 1;
    size = 0;
    arr = new int[capacity]();
}

Array::~Array(){
    delete [] arr;
}

void Array::insert(int val){
    if(size >= capacity - 1){
        // Reallocation
        capacity *= 2;
        int* tmp = new int[capacity]();
        for(int i = 0; i < size; i++){
            tmp[i] = arr[i];
        }
        delete [] arr;
        arr = tmp;
    }
    arr[size++] = val;
}

int Array::search(int val){
    for(int i = 0; i < size; i++){
        if(val == arr[i]){
            return arr[i];
        }
    }
    return -1;
}

HashTablePlus::HashTablePlus(int n){
    hashtable = new Array*[n];
    size = n;
    for(int i = 0; i < size; i++){
        hashtable[i] = new Array;
    }
}

HashTablePlus::~HashTablePlus(){
    for(int i = 0; i < size; i++){
        delete hashtable[i];
    }
    delete [] hashtable;
}

void HashTablePlus::insert(int val){
    int pos = hash(val);
    hashtable[pos]->insert(val);
}

int HashTablePlus::search(int val){
    int pos = hash(val);
    return hashtable[pos]->search(val);
}

int HashTablePlus::hash(int val){
    //h(k) = floor (m * frac (k * c))
    return val % size;
}