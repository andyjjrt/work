#include "IDFT.h"
#include <cmath>
#include <complex>
#include <iostream>
using namespace std;

IDFT::IDFT(int size_) : Points(size_) {
    omega = (2 * PI) / size;
    matrix = new complex<double>*[size];
    results = new complex<double>[size];
    for(int i = 0; i < size; ++i) {
        results[i] = complex<double>(0, 0);
        matrix[i] = new complex<double>[size];
        for(int j = 0; j < size; j++) {
            matrix[i][j].real(cos(omega * ((i * j) % size)));
            matrix[i][j].imag(sin(omega * ((i * j) % size)));
        }
    }
}

IDFT::~IDFT() {
    for(int i = 0; i < size; ++i) {
        delete [] matrix[i];
    }
    delete [] matrix;
    delete [] results;
}

void IDFT::process() {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            results[i].real(results[i].real() + matrix[i][j].real() * points[j]);
            results[i].imag(results[i].imag() + matrix[i][j].imag() * points[j]);
        }
        results[i] /= size;
    }
}

void IDFT::print() {
    for(int i = 0; i < size; i++) {
        cout << results[i] << endl;
    }
}