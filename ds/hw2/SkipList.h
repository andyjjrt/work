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
    int add_node_count;
    int insert_node_count;
    long long max_node_count;
    long long total_node_count;

    // Initialize headers
    void init_headers();
public:
    // Constructer
    SkipList(double prob, int MAX_GB_FOR_SKIPLIST);

    // Destructer
    ~SkipList();

    // Insert a key
    void insert(int key);

    // Search a key
    int search(int key);

    // Return average additional copy
    double avg_copy();

    // Return List count
    int list_count();

    // Print
    void print();

    // Determine if the skiplist is Mempry Limit Exceeded
    bool isMLE();
};