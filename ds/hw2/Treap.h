// https://www.geeksforgeeks.org/treap-set-2-implementation-of-search-insert-and-delete/
#include <stdlib.h>

struct node{
    int value;
    int priority;
    node* left;
    node* right;
    node(int val){
        value = val;
        priority = rand();
        left = NULL;
        right = NULL;
    }
};

typedef struct node Node;

class Treap{
public:
    // Constructor
    Treap();

    // Destructor
    ~Treap();

    // Insert a node
    void insert(int val);

    // Search a node
    int search(int val);

    // Get root node address
    Node* get_root();

    //Print the Treap
    void print(Node* node);

private:
    // Root of the Treap
    Node* root;

    // Insert a node recursively
    Node* insert_(int val, Node* node);

    // Search a node recursively
    Node* search_(int val, Node* node);

    // Delete nodes recursively
    void remove_(Node* node);

    //Left Rotation, return the new root
    Node* L_Rotation(Node* node);

    //Right Rotation, return the new root
    Node* R_Rotation(Node* node);
};