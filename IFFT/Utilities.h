#ifndef UTILITIES_H_
#define UTILITIES_H_
#include <ctime>
const double PI = 3.141592653589793;

class Points {
public:
    Points(int size_);
    ~Points();
    int size;
    double* points;
};

class Timer{
private:
    clock_t start_time;
    clock_t stop_time;
public:
    Timer() {
        start_time = 0;
        stop_time = 0;
    }
    // Start the timer
    void start();

    // Stop the timer
    void stop();

    // Get time
    double get_time();
};
#endif