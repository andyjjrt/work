#include <iostream>
#include <vector>
#include "SortedArray.h"
using namespace std;

SortedArray::SortedArray(int max_length){
    MAX_LENGTH = max_length;
    array = new int[MAX_LENGTH]();
    length = 0;
}

SortedArray::~SortedArray(){
    delete [] array;
}

void SortedArray::insert(int value){
    if(length >= MAX_LENGTH){
        return;
    }
    int i;
    for(i = length - 1; (i >= 0 && array[i] > value); i--){
        array[i+1] = array[i];
    }
    array[i+1] = value;
    length += 1;

}

void SortedArray::print(){
    for(int i = 0; i < length; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

int SortedArray::search(int key){
    return search_(0, length-1, key);
}

int SortedArray::search_(int low, int high, int key){
    if(high < low){
        return -1;
    }
    int mid = (low + high) / 2; /*low + (high - low)/2;*/
    if (key == array[mid])
        return mid;
    if (key > array[mid])
        return search_((mid + 1), high, key);
    return search_(low, (mid - 1), key);

}