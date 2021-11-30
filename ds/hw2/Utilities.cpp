#include "Utilities.h"
#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
using namespace std;

void Timer::start(){
    start_time = clock();
}

void Timer::stop(){
    stop_time = clock();
}

double Timer::get_time(){
    return (double(stop_time) - double(start_time)) / CLOCKS_PER_SEC;
}

int Random::generate(int from, int to){
    int range = to - from + 1;
    return (rand() % range) + from;
}

void Random::set(){
    srand(time(NULL));
}

CSV::CSV(string str){
    index = 0;
    file_name = str;
}

void CSV::insert(string str){
    fstream csv_file;
    if(index != 0){
        str = "," + str;
    }
    csv_file.open(file_name, ios_base::app);
    if(csv_file.is_open()){
        csv_file.write(str.data(), str.size());
    }
    csv_file.close();
    index++;
}

void CSV::newline(){
    index = 0;
    insert("\n");
    index--;
}