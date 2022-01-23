#include <string>
#include <ctime>
using namespace std;

class Timer{
private:
    clock_t start_time;
    clock_t stop_time;
public:

    // Start the timer
    void start();

    // Stop the timer
    void stop();

    // Get time
    double get_time();
};

class Random{
public:
    int rand_num(int from, int to);
    void set();
};

class CSV{
public:
    CSV(string name);
    void insert(string str);
    void newline();
private:
    string file_name;
    int index;
};