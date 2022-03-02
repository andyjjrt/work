#include "Treap.h"
#include <iostream>
using namespace std;


Treap::Treap(){
    root = NULL;
}

Treap::~Treap(){
    remove_(root);
}

Node* Treap::get_root(){
    return root;
}

bool Treap::insert(int val){
    try{
        root = insert_(val, root);
        return true;
    }
    catch(const bad_alloc& e){
        cout << e.what() << endl;
        return false;
    }
}

void Treap::print(){
    print_(root);
}

int Treap::search(int key){
    Node* result = search_(key, root);
    if(!result){
        return -1;
    }else{
        return result->value;
    }
}

Node* Treap::insert_(int val, Node* node){
    if(node == NULL){
        try{
            Node* newnode = new Node(val);
            return newnode;
        }
        catch(const bad_alloc& e){
            throw e;
        }
    }
    if(val < node->value){
        node->left = insert_(val, node->left);
        if(node->left->priority > node->priority){
            node = R_Rotation(node);
        }
    }else{
        node->right = insert_(val, node->right);
        if(node->right->priority > node->priority){
            node = L_Rotation(node);
        }
    }
    return node;
}

Node* Treap::search_(int val, Node* node){
    if(node == NULL) return NULL;
    else if(node->value == val) return node;
    else if(val < node->value){
        node = search_(val, node->left);
    }
    else if(val > node->value){
        node = search_(val, node->right);
    }
    return node;
}

void Treap::remove_(Node* node){
    if(node == NULL) return;
    if(node->left != NULL){
        remove_(node->left);
    }
    if(node->right != NULL){
        remove_(node->right);
    }
    delete node;
}

void Treap::print_(Node* node){
    if(node == NULL) return;
    if(node->left != NULL){
        print_(node->left);
    }
    cout << "(" << node->value << ", " << node->priority << ")" << endl;
    if(node->right != NULL){
        print_(node->right);
    }
}

Node* Treap::R_Rotation(Node* node){
    Node* tmp_node = node -> left;
    node -> left = tmp_node -> right;
    tmp_node -> right = node;
    return tmp_node;
}

Node* Treap::L_Rotation(Node* node){
    Node* tmp_node = node -> right;
    node -> right = tmp_node -> left;
    tmp_node -> left = node;
    return tmp_node;
}