#include "Utilities.h"
#include <complex>

class IDFT : private Points{
public:
    IDFT(int size_);
    ~IDFT();
    void process();
    void print();
private:
    std::complex<double>** matrix;
    std::complex<double>* results;
    double omega;
};