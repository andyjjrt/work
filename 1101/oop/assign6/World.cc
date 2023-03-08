#include <bits/stdc++.h>
#include "World.h"

using namespace std;

World::World(int pass, int seed) : RandomNum(seed) {
    srand(seed);
    pass_to_run = pass;
    current_pass = 0;

    // Initialize the map with NULL pointer
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 35; j++){
            map[i][j] = NULL;
        }
    }

    //Generate Goats
    for(int i = 0; i < 5;){
        int tmp_random_num = getRandomNum(0, 699);
        int y_pos = tmp_random_num / 35;
        int x_pos = tmp_random_num % 35;
        if(map[y_pos][x_pos] == NULL){
            map[y_pos][x_pos] = new Goat(current_pass);
            i++;
        }
    }

    //Generate Grass
    for(int i = 0; i < 10;){
        int tmp_random_num = getRandomNum(0, 699);
        int y_pos = tmp_random_num / 35;
        int x_pos = tmp_random_num % 35;
        if(map[y_pos][x_pos] == NULL){
            map[y_pos][x_pos] = new Grass(current_pass);
            i++;
        }
    }
}

World::~World(){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 35; j++){
            if(map[i][j] != NULL){
                delete map[i][j];
            }
        }
    }
}

void World::mainLoop(int display_interval){
    while(current_pass <= pass_to_run){
        scan();
        if(current_pass % display_interval == 0){
            print();
        }
    }
}

void World::scan(){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 35; j++){
            // I use pass to record whether this creature has acted or not, new creature won't
            // act because of syncpass()
            if(map[i][j] != NULL && map[i][j]->get_pass() == current_pass){
                map[i][j]->syncpass();
                // Determine whether it's time to die
                if(map[i][j]->time_to_die()){
                    delete map[i][j];
                    map[i][j] = NULL;
                    continue;
                }
                map[i][j]->become_older();
                // By generate a random number from 0~3, means choosing a direction. First the program
                // check whether the neighbor cell is legal or not, and tell the creature to act there
                // (breed, walk, etc...) and get what it has done. If the creature has WALK event,
                // the program will set self cell to NULL to avoid duplicated pointer.
                int direction = getRandomNum(0, 3);
                if(check_neighbor(i, j, direction)){
                    Creature** neighbor = get_neighbor(i, j, direction);
                    ACTION response = map[i][j]->act(neighbor);

                    /****** DEEBUG ******/
                    //debug(j, i, response);
                    /****** DEEBUG ******/
                    
                    if(response == WALK || response == WALK_AND_EAT_GRASS){
                        map[i][j] = NULL;
                    }
                }
            }
        }
    }
    // Last, sync the world's pass to end scan.
    current_pass++;
}

bool World::check_neighbor(int y, int x, int direction){
    int neighbor_x = x + neighbor_amplifier[direction][0];
    int neighbor_y = y + neighbor_amplifier[direction][1];
    return (neighbor_x >= 0 && neighbor_x < 35 && neighbor_y >= 0 && neighbor_y < 20) ? true : false;
}

Creature** World::get_neighbor(int y, int x, int direction){
    return &(map[y + neighbor_amplifier[direction][1]][x + neighbor_amplifier[direction][0]]);
}


void World::print(){
    for(int i = -1; i< 20; i++){
        for(int j = -1; j < 35; j++){
            if(i == -1){
                cout << " ";
                if(j != -1) cout << (j % 10);
            }else{
                if(j == -1){
                    cout << (i % 10);
                }else{
                    cout << " " << map[i][j];
                }
            }
        }
        cout << endl;
    }
    for(int i = -1; i < 35; i++){
        cout << "--";
    }
    cout << endl;
}

void World::debug(int x, int y, ACTION res){
    // NULL pointer exception
    if(map[y][x] == NULL){
        cout << "NULL" << endl;
        return;
    }
    cout << "(" <<setw(2) << x << "," << setw(2) << y << ") ";
    if(map[y][x]->type() == GOAT) cout << setw(6) << "GOAT";
    if(map[y][x]->type() == GRASS) cout << setw(6) << "GRASS";
    cout << left << setw(20);
    switch(res){
        case WALK:
            cout << "walk";
            break;
        case WALK_AND_EAT_GRASS:
            cout << "walk and eat grass";
            break;
        case BREED:
            cout << "breed";
            break;
        case NONE:
            cout << "none";
            break;
    }
    cout << endl;
}

ostream& operator<<(std::ostream& out, Creature* creature){
    if(creature == NULL){
        out << " ";
    }else{
        out << creature->icon();
    }
    return out;
}