#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
// type of creature
enum TYPE {GOAT, GRASS};
// type of action
enum ACTION {BREED, WALK, WALK_AND_EAT_GRASS, NONE};

class Creature {
public:
    // Contructor, initialize with world's pass
    Creature(int pass);

    // Virtual destructor, no exact using
    virtual ~Creature(){}

    // Operrator "<<" overloading, this let cout display creature's icon
    friend std::ostream& operator<<(std::ostream& out, Creature* creature);

    // Return Creature's type
    virtual TYPE type() = 0;

    // Return Creature's icon
    virtual char icon() = 0;

    // Let the Creature act in specific position (neighbor), returns what this creature do this round
    virtual ACTION act(Creature** neighbor) = 0;

    // Check if the creature is ready to die
    virtual bool time_to_die() = 0;

    // Check if the creature is ready to breed
    virtual bool time_to_breed() = 0;

    // Sync pass simply add 1 to current pass
    inline void syncpass() { pass++; }

    // Return current pass
    inline int get_pass() { return pass; }

    // Age process
    inline void become_older() { age++; }

    // Return current age
    inline int get_age() { return age; }

protected:
    int age;
    int pass;
};

#endif