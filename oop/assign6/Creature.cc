#include <bits/stdc++.h>
#include "Creature.h"
using namespace std;

Creature::Creature(int pass_){
    // initialize a creature with age 0, and sync pass with world's current pass.
    age = 0;
    pass = pass_;
}

