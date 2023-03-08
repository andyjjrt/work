#include "Goat.h"
#include <bits/stdc++.h>
using namespace std;

Goat::Goat(int pass) : Creature(pass){
    food_points = 20;
}

ACTION Goat::act(Creature** neighbor){
    // This function is called when neighbor is valid, so we can simply determine who is neighbor.
    if((*neighbor) == NULL){
        if(time_to_breed()){
            (*neighbor)= new Goat(get_pass());
            return BREED;
        }else{
            (*neighbor) = this;
            walk();
            return WALK;
        }
    }else if((*neighbor)->type() == GRASS){
        delete (*neighbor);
        (*neighbor) = NULL;
        (*neighbor) = this;
        comsume_food();
        walk();
        return WALK_AND_EAT_GRASS;
    }else if((*neighbor)->type() == GOAT){
        return NONE;
    }
    return NONE;
}