#include "IFFT.h"
#include <cmath>
#include <complex>
#include <iostream>
using namespace std;

IFFT::IFFT(int size_) : Points(size_) {
    omega = (2 * PI) / size;
}
IFFT::~IFFT() {
    delete [] results;
}

void IFFT::process() {
    results = process_(points, size);
}

complex<double>* IFFT::process_(double* arr_, int size_) {
    double omega_ = (2 * PI) / size_;
    if(size_ <= 2) {
        complex<double>* tmp = new complex<double>[2];
        tmp[0].real(arr_[0] + arr_[1]);
        tmp[0].imag(0);
        tmp[1].real(arr_[0] + cos(omega_) * arr_[1]);
        tmp[1].imag(sin(omega_) * arr_[1]);
        return tmp;
    }
    double* odd = new double[size_ / 2];
    double* even = new double[size_ / 2];
    for(int i = 0, j = 0; i < size_; i++) {
        i % 2 == 0 ? odd[j] = arr_[i] : even[j++] = arr_[i];
    }
    complex<double>* up = process_(odd, size_ / 2);
    complex<double>* down = process_(even, size_ / 2);
    complex<double>* combine = new complex<double>[size_];
    for(int i = 0; i < size_; i++) {
        int j = i % (size_ / 2);
        combine[i].real((up[j].real() + cos(i * omega_) * down[j].real() - sin(i * omega_) * down[j].imag()) / size_);
        combine[i].imag((up[j].imag() + sin(i * omega_) * down[j].real() + cos(i * omega_) * down[j].imag()) / size_);
    }

    delete [] odd;
    delete [] even;
    delete [] up;
    delete [] down;
    return combine;
}

void IFFT::print() {
    for(int i = 0; i < size; i++) {
        cout << results[i] << endl;
    }
}