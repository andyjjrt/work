// https://www.youtube.com/watch?v=iaKu6jaKPFw
#include <iostream>

typedef struct skip_node{
    int value;
    skip_node* prev;
    skip_node* next;
    skip_node* above;
    skip_node* below;

    //Constructer
    skip_node(int val){
        value = val;
        prev = next = above = below = NULL;
    }
} Skip_Node;

class SkipList{
private:
    int MAX_FLOOR;
    double flip_prob;
    Skip_Node* List;

    // Initialize headers
    void init_headers();
public:
    // Constructer
    SkipList(double prob);

    // Destructer
    ~SkipList();

    // Insert a key
    bool insert(int key);

    // Search a key
    int search(int key);

    // Print
    void print();

};