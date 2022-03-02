#include <bits/stdc++.h>
#include "SkipList.h"
using namespace std;

SkipList::SkipList(double prob, int MAX_GB_FOR_SKIPLIST){
    MAX_FLOOR = 0;
    add_node_count = 0;
    insert_node_count = 0;
    max_node_count = ((long)MAX_GB_FOR_SKIPLIST) * (1 << 30) / sizeof(Skip_Node);
    total_node_count = 0;
    flip_prob = (prob <= 1 || prob >= 0) ? prob : 0.5; // prob of skiplist is stored in the object
    init_headers();
}

SkipList::~SkipList(){
    Skip_Node* node = List;
    while(node != NULL){
        Skip_Node* tmp_node = node;
        Skip_Node* tmp_node2 = node -> below;
        while(tmp_node != NULL){
            Skip_Node* del_node = tmp_node;
            tmp_node = tmp_node->next;
            delete del_node;
        }
        node = tmp_node2;
    }
}

void SkipList::init_headers(){
    Skip_Node* first_node = new Skip_Node(-1);
    Skip_Node* last_node = new Skip_Node(INT32_MAX);
    first_node->next = last_node;
    last_node->prev = first_node;

    total_node_count+=2;

    List = first_node;
}

void SkipList::insert(int key){
    Skip_Node* insert_pos = List;
    insert_node_count++;

    // Find where to insert this value at floor 0
    while(insert_pos->below != NULL){
        insert_pos = insert_pos->below;
        while(insert_pos->next->value <= key){
            insert_pos = insert_pos->next;
        }
    }

    // Create a node and insert it
    Skip_Node* new_node = new Skip_Node(key);
    total_node_count++;
    new_node->next = insert_pos->next;
    new_node->next->prev = new_node;
    new_node->prev = insert_pos;
    new_node->prev->next = new_node;

    // Start build up
    int current_floor = 0;
    while(((double) rand() / (RAND_MAX)) <= flip_prob && !isMLE()){
        current_floor++;
        if(current_floor >= MAX_FLOOR){
            MAX_FLOOR++;
            Skip_Node* first_node = List;
            Skip_Node* last_node = List;
            while(last_node->next){
                last_node = last_node->next;
            }

            Skip_Node* above_first_node = new Skip_Node(-1);
            Skip_Node* above_last_node = new Skip_Node(INT32_MAX);
            total_node_count += 2;

            above_first_node->next = above_last_node;
            above_last_node->prev = above_first_node;

            above_first_node->below = first_node;
            first_node->above = above_first_node;
            above_last_node->below = last_node;
            last_node->above = above_last_node;

            List = above_first_node;
        }
        while(insert_pos->above == NULL){
            insert_pos = insert_pos->prev;
        }
        insert_pos = insert_pos->above;

        Skip_Node* tmp_node = new Skip_Node(key);
        total_node_count++;
        tmp_node->below = new_node;
        tmp_node->below->above = tmp_node;
        tmp_node->next = insert_pos->next;
        tmp_node->next->prev = tmp_node;
        tmp_node->prev = insert_pos;
        tmp_node->prev->next = tmp_node;

        new_node = tmp_node;

        add_node_count++;
    }
    //cout << total_node_count << "/" << max_node_count << endl;
}

int SkipList::search(int key){
    Skip_Node* insert_pos = List;
    while(insert_pos->below != NULL){
        insert_pos = insert_pos->below;
        while(insert_pos->value <= key){
            if(insert_pos -> value == key){
                return insert_pos -> value;
            }
            insert_pos = insert_pos->next;
        }
    }
    return -1;
}

void SkipList::print(){
    Skip_Node* node = List;
    while(node){
        Skip_Node* tmp_node = node->next;
        if(tmp_node->next){
            while(tmp_node->next){
                cout << tmp_node->value << " ";
                tmp_node = tmp_node->next;
            }
            cout << endl;
        }
        node = node->below;
    }
}

double SkipList::avg_copy(){
    return double(add_node_count + insert_node_count) / insert_node_count;
}

int SkipList::list_count(){
    return MAX_FLOOR;
}

bool SkipList::isMLE(){
    return total_node_count >= max_node_count;
}