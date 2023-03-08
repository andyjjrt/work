#include "Utilities.h"
#include <complex>

class IFFT : private Points{
public:
    IFFT(int size_);
    ~IFFT();
    void process();
    void print();
private:
    std::complex<double>* process_(double* arr_, int size_);
    std::complex<double>* results;
    double omega;
};