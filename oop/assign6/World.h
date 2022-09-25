#ifndef WORLD_H
#define WORLD_H

#include "Goat.h"
#include "Grass.h"
#include "Creature.h"
#include "RandomNum.h"

// four direction's amplifier, so i only need to get random number from 0~3
const int neighbor_amplifier[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

class World : public RandomNum {
public:
    // Constructor, init with how many pass to run and random seed
    World(int, int);

    // Destructor
    ~World();

    // Print the whole map
    void print();

    // mainloop of world event
    void mainLoop(int display_interval);

private:
    // Debugger. This function should be called right after a creature's act.
    void debug(int x, int y, ACTION res);

    // Scan through the map
    void scan();

    // Check if the given coords on the map is legal
    bool check_neighbor(int x, int y, int direction);

    // Return the address of a cell
    Creature** get_neighbor(int y, int x, int direction);

    int pass_to_run;
    int current_pass;
    Creature* map[20][35];
};

#endif