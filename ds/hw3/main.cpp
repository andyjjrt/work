#include <bits/stdc++.h>
#include <string>
#include "Treap.h"
#include "SkipList.h"
#include "SortedArray.h"
#include "Hashtable.h"
#include "HashTable+.h"
#include "Utilities.h"
using namespace std;

int main(int argc, char **argv){

    if(argc != 4){
        cout << "Usage: hw3 [MIN_POWER] [MAX_POWER] [MAX_TIME]" << endl;
        return 0;
    }

    int MIN_POWER = atoi(argv[1]);
    int MAX_POWER = atoi(argv[2]);
    double MAX_TIME = atof(argv[3]);

    if(MIN_POWER < 10){
        cout << "Error: MIN_POWER < 10" << endl;
        return 0;
    }
    if(MAX_POWER < 10){
        cout << "Error: MAX_POWER < 10" << endl;
        return 0;
    }
    if(MAX_POWER < MIN_POWER){
        cout << "Error: MAX_POWER < MIN_POWER" << endl;
        return 0;
    }
    
    Timer timer;
    Random random;
    random.set();
    CSV insert("insert.csv"), search("search.csv");
    insert.insert("#,Treap,SkipList(0.5),SortedArray,HashTable,HashTable+");
    insert.newline();
    search.insert("#,Treap,SkipList(0.5),SortedArray,HashTable,HashTable+");
    search.newline();

    double last_run_time[5] = {0, 0, 0, 0};

    for(int i = MIN_POWER; i <= MAX_POWER; i++){
        cout << i << endl;
        int last_run_index = 0;
        Treap* T;
        SkipList* SK;
        SortedArray* SA;
        HashTable* HS;
        HashTablePlus* HSP;
        insert.insert(to_string(i));
        search.insert(to_string(i));

        /****************
         * Treap
         * **************/
        
        if(last_run_time[last_run_index] < MAX_TIME && i < 30){
            T = new Treap();
            bool insert_success = false;
            timer.start();
            for(int j = 0; j < (1 << i); j++){
                insert_success = T -> insert(random.generate(1, 1 << 30));
                if(!insert_success){
                    break;
                }
            }
            timer.stop();

            if(insert_success){
                insert.insert(to_string(timer.get_time()));
                cout << "Treap insert: " << timer.get_time() << endl;
                last_run_time[last_run_index] = timer.get_time();
            }else{
                insert.insert("");
                cout << "Treap insert failure" << endl;
                last_run_time[last_run_index] = MAX_TIME;
            }

            timer.start();
            for(int j = 0; j < 100000; j++){
                T -> search(random.generate(1, 1 << 30));
            }
            timer.stop();
            search.insert(to_string(timer.get_time()));
            cout << "Treap search: " << timer.get_time() << endl;
            delete T;
        }else{
            insert.insert("");
            cout << "Treap insert: TLE"<< endl;
            search.insert("");
            cout << "Treap search: TLE"<< endl;
        }
        last_run_index++;

        /**************
         * SkipList
         * ************/

        if(last_run_time[last_run_index] < MAX_TIME && i < 29){
            SK = new SkipList(0.5);
            bool insert_success = false;
            timer.start();
            for(int j = 0; j < (1 << i); j++){
                insert_success = SK -> insert(random.generate(1, 1 << 30));
                if(!insert_success){
                    break;
                }
            }
            timer.stop();

            if(insert_success){
                insert.insert(to_string(timer.get_time()));
                cout << "SkipList insert: " << timer.get_time() << endl;
                last_run_time[last_run_index] = timer.get_time();
            }else{
                insert.insert("");
                cout << "SkipList insert failure" << endl;
                last_run_time[last_run_index] = MAX_TIME;
            }
            
            timer.start();
            for(int j = 0; j < 100000; j++){
                SK -> search(random.generate(1, 1 << 30));
            }
            timer.stop();
            search.insert(to_string(timer.get_time()));
            cout << "SkipList search: " << timer.get_time() << endl;
            delete SK;
        }else{
            insert.insert("");
            cout << "SkipList insert: TLE"<< endl;
            search.insert("");
            cout << "SkipList search: TLE"<< endl;
        }
        last_run_index++;
        
        /*************
         * Sorted Array
         * ***********/
        if(last_run_time[last_run_index] < MAX_TIME){
            SA = new SortedArray((1 << i) + 100);
            timer.start();
            for(int j = 0; j < (1 << i); j++){
                SA -> insert(random.generate(1, 1 << 30));
            }
            timer.stop();
            insert.insert(to_string(timer.get_time()));
            cout << "SortedArray insert: " << timer.get_time() << endl;

            last_run_time[last_run_index] = timer.get_time();

            timer.start();
            for(int j = 0; j < 100000; j++){
                SA -> search(random.generate(1, 1 << 30));
            }
            timer.stop();
            search.insert(to_string(timer.get_time()));
            cout << "SortedArray search: " << timer.get_time() << endl;
            delete SA;
        }else{
            insert.insert("");
            cout << "SortedArray insert: TLE"<< endl;
            search.insert("");
            cout << "SortedArray search: TLE"<< endl;
        }
        last_run_index++;

        /*************
         * Hash Table
         *************/
        if(last_run_time[last_run_index] < MAX_TIME && i < 28){
            HS = new HashTable((int)((1 << i) * 1.3));
            timer.start();
            for(int j = 0; j < (1 << i); j++){
                HS -> insert(random.generate(1, 1 << 30));
            }
            timer.stop();
            insert.insert(to_string(timer.get_time()));
            cout << "HashTable insert: " << timer.get_time() << endl;

            last_run_time[last_run_index] = timer.get_time();

            timer.start();
            for(int j = 0; j < 100000; j++){
                HS -> search(random.generate(1, 1 << 30));
            }
            timer.stop();
            search.insert(to_string(timer.get_time()));
            cout << "HashTable search: " << timer.get_time() << endl;
            last_run_time[last_run_index] = timer.get_time();
            delete HS;
        }else{
            insert.insert("");
            cout << "HashTable insert: TLE"<< endl;
            search.insert("");
            cout << "HashTable search: TLE"<< endl;
        }
        last_run_index++;

        /*************
         * Hash Table with dynamic array reallocation
         *************/
        if(last_run_time[last_run_index] < MAX_TIME){
            HSP = new HashTablePlus((int)((1 << i) * 1.3));
            timer.start();
            for(int j = 0; j < (1 << i); j++){
                HSP -> insert(random.generate(1, 1 << 30));
            }
            timer.stop();
            insert.insert(to_string(timer.get_time()));
            cout << "HashTable+ insert: " << timer.get_time() << endl;

            last_run_time[last_run_index] = timer.get_time();

            timer.start();
            for(int j = 0; j < 100000; j++){
                HSP -> search(random.generate(1, 1 << 30));
            }
            timer.stop();
            search.insert(to_string(timer.get_time()));
            cout << "HashTable+ search: " << timer.get_time() << endl;
            last_run_time[last_run_index] = timer.get_time();
            delete HSP;
        }else{
            insert.insert("");
            cout << "HashTable+ insert: TLE"<< endl;
            search.insert("");
            cout << "HashTable+ search: TLE"<< endl;
        }
        last_run_index++;

        insert.newline();
        search.newline();

        for(int j = 0; j < 5; j++){
            cout << last_run_time[j] << " ";
        }
        cout << endl;
    }
}