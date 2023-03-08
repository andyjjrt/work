#include "Utilities.h"
#include <iostream>
using namespace std;

Points::Points(int size_) {
    size = size_;
    points = new double[size];
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        points[i] = (double)rand() / (double)RAND_MAX;
        //cout << points[i] << endl;
    }
}

Points::~Points() {
    delete [] points;
}

void Timer::start(){
    start_time = clock();
}

void Timer::stop(){
    stop_time = clock();
}

double Timer::get_time(){
    return (double(stop_time) - double(start_time)) / CLOCKS_PER_SEC;
}

