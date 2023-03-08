#include <bits/stdc++.h>
#include <string>
#include "Treap.h"
#include "SkipList.h"
#include "SortedArray.h"
#include "Utilities.h"
using namespace std;

int main(int argc, char **argv){

    if(argc != 5){
        cout << "Usage: hw2 [MIN_POWER] [MAX_POWER] [MAX_GB_FOR_SKIPLIST] [MAX_TIME]" << endl;
        return 0;
    }

    int MIN_POWER = atoi(argv[1]);
    int MAX_POWER = atoi(argv[2]);
    int MAX_GB_FOR_SKIPLIST = atoi(argv[3]);
    double MAX_TIME = atof(argv[4]);

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
    if(MAX_GB_FOR_SKIPLIST > (1 << 12)){
        cout << "Error: MAX_GB_FOR_SKIPLIST <= 4096" << endl;
        return 0;
    }
    
    Timer timer;
    Random random;
    random.set();
    CSV insert("insert.csv"), search("search.csv"), copy("additional_copy.csv"), list_count("list_count.csv");
    insert.insert("#,Treap,SkipList(0.5),SkipList(0.1),SkipList(0.9),SortedArray");
    insert.newline();
    search.insert("#,Treap,SkipList(0.5),SkipList(0.1),SkipList(0.9),SortedArray");
    search.newline();
    copy.insert("#,SkipList(0.5),SkipList(0.1),SkipList(0.9)");
    copy.newline();
    list_count.insert("#,SkipList(0.5),SkipList(0.1),SkipList(0.9)");
    list_count.newline();

    double last_run_time[5] = {0, 0, 0, 0, 0};

    double skip_prob[3] = {0.5, 0.1, 0.9};

    for(int i = MIN_POWER; i <= MAX_POWER; i++){
        cout << i << endl;
        int last_run_index = 0;
        Treap* T;
        SkipList* SK;
        SortedArray* SA;
        insert.insert(to_string(i));
        search.insert(to_string(i));
        copy.insert(to_string(i));
        list_count.insert(to_string(i));

        /****************
         * Treap
         * **************/
        
        if(last_run_time[last_run_index] < MAX_TIME){
            T = new Treap();
            timer.start();
            for(int j = 0; j < (1 << i); j++){
                T -> insert(random.generate(1, 1 << 30));
            }
            timer.stop();
            insert.insert(to_string(timer.get_time()));
            cout << "Treap insert: " << timer.get_time() << endl;

            last_run_time[last_run_index] = timer.get_time();

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

        for(int k = 0; k < 3; k++){
            if(last_run_time[last_run_index] < MAX_TIME){
                SK = new SkipList(skip_prob[k], MAX_GB_FOR_SKIPLIST);
                timer.start();
                for(int j = 0; j < (1 << i); j++){
                    SK -> insert(random.generate(1, 1 << 30));
                    if(SK -> isMLE()) break;
                }
                timer.stop();
                if(SK->isMLE()){
                    insert.insert("");
                    cout << "SkipList(" << skip_prob[k] << ") insert: MLE" << endl;
                }else{
                    insert.insert(to_string(timer.get_time()));
                    cout << "SkipList(" << skip_prob[k] << ") insert: " << timer.get_time() << endl;
                }

                last_run_time[last_run_index] = timer.get_time();

                timer.start();
                for(int j = 0; j < 100000; j++){
                    SK -> search(random.generate(1, 1 << 30));
                }
                timer.stop();
                if(SK->isMLE()){
                    search.insert("");
                    cout << "SkipList(" << skip_prob[k] << ") search: " << timer.get_time() << " (MLE)" << endl;
                }else{
                    search.insert(to_string(timer.get_time()));
                    cout << "SkipList(" << skip_prob[k] << ") search: " << timer.get_time() << endl;
                }
                copy.insert(to_string(SK->avg_copy()));
                list_count.insert(to_string(SK->list_count()));
                delete SK;
            }else{
                insert.insert("");
                cout << "SkipList(" << skip_prob[k] << ") insert: TLE"<< endl;
                search.insert("");
                cout << "SkipList(" << skip_prob[k] << ") search: TLE"<< endl;
                copy.insert("");
                list_count.insert("");
            }
            last_run_index++;
        }
        
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

        insert.newline();
        search.newline();
        copy.newline();
        list_count.newline();

        for(int j = 0; j < 5; j++){
            cout << last_run_time[j] << " ";
        }
        cout << endl;
    }
}