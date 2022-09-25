#ifndef GRASS_H
#define GRASS_H

#include "Creature.h"

class Grass : public Creature{
public:
    // Construnctor, pass "pass" to Creature to initialize.
    Grass(int);

    // Destructor, no exact using
    ~Grass(){}

    // Return Grass's type
    inline TYPE type() { return GRASS; }

    // Return Grass's icon
    inline char icon() { return 'I'; }

    // Check if the grass is ready to die
    inline bool time_to_die() { return age >= 6; }

    // Check if the grass is ready to breed
    inline bool time_to_breed() { return age >= 3 && age <= 5; }
    ACTION act(Creature** neighbor);
};

#endif