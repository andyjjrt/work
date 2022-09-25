#ifndef _QUEUE_H
#define _QUEUE_H

#include "AnsiPrint.h"
template <class T>
struct node{
    T data;
    node<T>* next;
    node<T>* prev;
    // Dertermine weather this node is end node or not
    bool is_end_point;
};

template <class T>
class Queue{
public:
    // Constructor
    Queue();

    // Destructor
    ~Queue();

    // Copy constructor
    Queue(const Queue &queue);

    // Assignment operator overloading
    Queue<T> &operator=(const Queue rhs);

    // Enqueue a data
    void enqueue(T data);

    // Dequeue a dara
    void dequeue();

    // Print the Queue
    void print();

private:
    // Create a new node
    node<T>* create_node(bool end_point, T val = 0);

    // Bind two node together
    void bind(node<T>* node1, node<T>* node2);

    node<T>* front;
    node<T>* end;
};

#endif