#ifndef GOAT_H
#define GOAT_H

#include "Creature.h"

class Goat : public Creature{
public:
    // Construnctor, pass "pass" to Creature to initialize.
    Goat(int);

    // Destructor, no exact using
    ~Goat(){}

    // Return Goat's type
    inline TYPE type() { return GOAT; }

    // Return Goat's icon
    inline char icon() { return 'X'; }

    // Check if the goat is ready to die
    inline bool time_to_die() { return age >= 70 || food_points <= 0; }

    // Check if the goat is ready to breed
    inline bool time_to_breed() { return age >= 50 && age <= 55; }

    // Let the Goat act in specific position (neighbor), returns what this goat do this round
    ACTION act(Creature** neighbor);

    // Comsume food (food point + 5)
    inline void comsume_food() { food_points += 5; }

    //walk(food point - 1)
    inline void walk() { food_points -= 1;}
private:
    int food_points;
};

#endif