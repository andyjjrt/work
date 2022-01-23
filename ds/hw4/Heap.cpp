#include "Heap.h"
#include <bits/stdc++.h>
using namespace std;

void Heap::MinHeapify(int node, int length){
    int left = 2*node;
    int right = 2*node + 1;
    int smallest;

    if (left <= length && heap[left].second < heap[node].second)
        smallest = left;
    else
        smallest = node;

    if (right <= length && heap[right].second < heap[smallest].second)
        smallest = right;

    if (smallest != node) {
        swap(heap[smallest], heap[node]);
        MinHeapify(smallest, length);
    }
}

void Heap::BuildMinHeap(vector<double> array){
    int array_size = array.size();
    int heap_size = heap.size();
    for (int i = 0; i < array_size; i++) {
        heap[i + 1].first = i;
        heap[i + 1].second = array[i];
    }
    for (int i = heap_size / 2; i >= 1 ; i--) {
        MinHeapify(i, heap_size - 1);
    }
}

double Heap::ExtractMin(){
    if(IsHeapEmpty()) return -1;
    int heap_size = heap.size();
    int min = heap[1].first;
    heap[1] = heap[heap_size - 1];
    heap.erase(heap.begin() + heap_size - 1);
    MinHeapify(1, heap_size - 1);
    return min;
}

void Heap::DecreaseKey(int index, double newKey){

    int node_index = FindPosition(index);
    heap[node_index].second = newKey;
    while (node_index > 1 && heap[node_index / 2].second > heap[node_index].second) {
        swap(heap[node_index], heap[node_index / 2]);
        node_index = node_index / 2;
    }
}

void Heap::swap(pair<int, double> &p1, pair<int, double> &p2){
    pair<int, double> tmp = p1;
    p1 = p2;
    p2 = tmp;
}

int Heap::FindPosition(int node){
    int idx = 0;
    int heap_size = heap.size();
    for (int i = 1; i < heap_size; i++) {
        if (heap[i].first == node) {
            idx = i;
        }
    }
    return idx;
}