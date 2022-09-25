#include "Queue.h"
#include <bits/stdc++.h>
#include <typeinfo>
using namespace std;

/******************
 * In my Queue, I create two dummy node at front and end, which only handle pointers.
 * When the Queue is empty, front and end node is connected, so if the user is trying to 
 * dequeue an empty queue, pointers will never be NULL. My Queue is a two-way linklist, 
 * so it is easy to hadle forward and backward.
*******************/

template <class T>
Queue<T>::Queue(){
    // Create two dummy nodes
    front = create_node(true);
    end = create_node(true);
    bind(front, end);
}

template <class T>
Queue<T>::~Queue(){
    // Traversal through the queue and delete them
    for(node<T>* n = front->next; n != end;){
        n = n->next;
        delete n->prev;
    }
    // Delete dummy nodes
    delete front;
    delete end;
}

template <class T>
Queue<T>::Queue(const Queue<T>& queue){
    front = create_node(true);
    end = create_node(true);
    bind(front, end);
    for(node<T>* n = queue.front->next; n != queue.end;n = n->next){
        enqueue(n->data);
    }
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T> rhs){
    for(node<T>* n = rhs.front->next; n != rhs.end;n = n->next){
        enqueue(n->data);
    }
    return *this;
};

template <class T>
void Queue<T>::enqueue(T val){
    // This NULL try-catch will never happpen, LOL
    try{
        if(front == NULL || end == NULL){
            throw "Queue pointer error.";
        }
    }
    catch(const char* err){
        AnsiPrint(err, red, yellow);
        cout << endl;
    }
    node<T>* end_prev = end->prev;
    node<T>* new_node;
    // Catch memory allocation error, though this error might be catch by OS.
    try{
        new_node = create_node(false, val);
    }
    catch(bad_alloc &err){
        AnsiPrint("Bad Memory Allocation", black, white, true);
        cout << endl;
        return;
    }
    bind(end_prev, new_node);
    bind(new_node, end);
}

template <class T>
void Queue<T>::dequeue(){
    try{
        node<T>* delete_node = front->next;
        // Catch if you try to delete end point.
        if(delete_node == end){
            throw "Attempt to dequeue empty queue";
        }
        node<T>* delete_node_next = delete_node->next;
        delete delete_node;
        bind(front, delete_node_next);
    }
    catch(const char* err){
        AnsiPrint(err, red, yellow);
        cout << endl;
    }
}

template <class T>
void Queue<T>::print(){
    if(typeid(T) == typeid(int)) AnsiPrint("Integer Queue:", yellow, black);
    if(typeid(T) == typeid(char)) AnsiPrint("Character Queue:", yellow, black);
    cout << endl;
    for(node<T>* n = front->next; n != end;n = n->next){
        cout << n->data << endl;
    }
    if(front->next == end){
        cout << "This queue is empty." << endl;
    }
}

template <class T>
node<T>* Queue<T>::create_node(bool end_point, T val){
    node<T>* tmp;
    try{
        tmp = new node<T>;
    }
    catch(bad_alloc &err){
        throw err;
    }
    tmp->data = val;
    tmp->prev = NULL;
    tmp->next = NULL;
    tmp->is_end_point = end_point;
    return tmp;
}

template <class T>
void Queue<T>::bind(node<T>* node1, node<T>* node2){
    node1->next = node2;
    node2->prev = node1;
}

template struct node<int>;
template struct node<char>;
template class Queue<int>;
template class Queue<char>;
