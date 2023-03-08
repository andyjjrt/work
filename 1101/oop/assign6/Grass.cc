#include "Grass.h"
#include <bits/stdc++.h>
using namespace std;

Grass::Grass(int pass) : Creature(pass){}

ACTION Grass::act(Creature** neighbor){
    // This function is called when neighbor is valid, so we can simply determine who is neighbor.
    if((*neighbor) == NULL){
        if(time_to_breed()){
            (*neighbor)= new Grass(get_pass());
            return BREED;
        }
    }
    return NONE;
}