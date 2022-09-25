#include "Vector.h"
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

Vector::Vector(int dim){
    dimention = dim;
    data = new double[dimention]();
}

Vector::Vector(int dim, const double* data_){
    dimention = dim;
    data = new double[dimention]();
    for(int i = 0; i < dimention; i++){
        data[i] = data_[i];
    }
}

Vector::Vector(const Vector& vector){
    dimention = vector.dimention;
    data = new double[dimention]();
    for(int i = 0; i < dimention; i++){
        data[i] = vector.data[i];
    }
}

Vector::~Vector(){
    delete [] data;
}

Vector &Vector::operator=(const Vector rhs){
    dimention = rhs.dimention;
    delete [] data;
    data = new double[dimention]();
    for(int i = 0; i < dimention; i++){
        data[i] = rhs.data[i];
    }
    return *this;
}

double Vector::operator[](int slot){
    if(slot >= 0 && slot < dimention){
        return data[slot];
    }
    cout << "Can't access out-of-bound index." << endl;
    return 0;
}

Vector Vector::operator-() const {
    Vector vec(dimention);
    for(int i = 0; i < dimention; i++){
        vec.data[i] = -(data[i]);
    }
    return vec;
}

Vector Vector::operator+(const Vector rhs){
    if(rhs.dimention == dimention){
        Vector vec(dimention);
        for(int i = 0; i < dimention; i++){
            vec.data[i] = data[i] + rhs.data[i];
        }
        return vec;
    }
    cout << "Two dimensions are not the same." << endl;
    return *this;
}

Vector Vector::operator-(const Vector rhs){
    if(rhs.dimention == dimention){
        Vector vec(dimention);
        for(int i = 0; i < dimention; i++){
            vec.data[i] = data[i] - rhs.data[i];
        }
        return vec;
    }
    cout << "Two dimensions are not the same." << endl;
    return *this;
}

Vector &Vector::operator+=(const Vector rhs){
    if(rhs.dimention == dimention){
        for(int i = 0; i < dimention; i++){
            data[i] += rhs.data[i];
        }
    }else{
        cout << "Two dimensions are not the same." << endl;
    }
    return *this;
}

Vector &Vector::operator-=(Vector rhs){
    if(rhs.dimention == dimention){
        for(int i = 0; i < dimention; i++){
            data[i] -= rhs.data[i];
        }
    }else{
        cout << "Two dimensions are not the same." << endl;
    }
    return *this;
}

Vector Vector::operator*(const double volume){
    Vector vec(dimention);
    for(int i = 0; i < dimention; i++){
        vec.data[i] = data[i] * volume;
    }
    return vec;
}

Vector &Vector::operator*=(const double volume){
    for(int i = 0; i < dimention; i++){
        data[i] *= volume;
    }
    return *this;
}

Vector operator*(const double lfs, Vector rhs){
    return rhs.operator*(lfs);
}

bool Vector::operator==(const Vector rhs) const {
    if(dimention == rhs.dimention){
        bool is_equal = true;
        for(int i = 0; i < dimention; i++){
            if(data[i] != rhs.data[i]){
                is_equal = false;
                break;
            }
        }
        return is_equal;
    }
    cout << "Two dimensions are not the same." << endl;
    return false;
}

bool Vector::operator!=(const Vector rhs) const {
    if(dimention == rhs.dimention){
        bool is_equal = true;
        for(int i = 0; i < dimention; i++){
            if(data[i] != rhs.data[i]){
                is_equal = false;
                break;
            }
        }
        return !is_equal;
    }
    cout << "Two dimensions are not the same." << endl;
    return false;
}

int Vector::getDimension(){
    return dimention;
}

void Vector::setDimension(int new_dim){
    double* new_data = new double[new_dim]();
    for(int i = 0; i < dimention && i < new_dim; i++){
        new_data[i] = data[i];
    }
    delete [] data;
    dimention = new_dim;
    data = new_data;
}

double Vector::length(){
    double power_sum = 0;
    for(int i = 0; i < dimention; i++){
        power_sum += (data[i] * data[i]);
    }
    return sqrt(power_sum);
}

ostream& operator<<(ostream& out, const Vector& vector){
    out << "(";
    for(int i = 0; i < vector.dimention; i++){
        if(i != 0){
            out << ", ";
        }
        out << vector.data[i];
    }
    out << ")";
    return out;
}