#include <iostream>
using namespace std;

class Vector{
public:
    friend ostream& operator<<(ostream& out, const Vector& vector);   // ostream operator overloading
    Vector(int dimention=2);                           // creates a n-d vector: (0, 0, 0, ... (*n))
    Vector(int dimention, const double* data);         // creates a n-d vector with data initialized
    Vector(const Vector& vector);                      // copy constructor
    ~Vector();                                         // destructor
    Vector &operator=(const Vector rhs);               // assignment operator overloading
    double operator[](int slot);                       // accesses the coordinates of a Vector
    Vector operator-() const;                          // unary negation
    Vector operator+(const Vector rhs);                // add two Vectors
    Vector operator-(const Vector rhs);                // subtract two Vectors
    Vector &operator+=(Vector rhs);                    // add two Vectors and assign the value back to the lhs
    Vector &operator-=(Vector rhs);                    // subtract two Vectors and assign the value back to the lhs
    Vector operator*(const double volume);             // vector multiple with a doouble
    Vector &operator*=(const double volume);           // vector multiple with a doouble and assign the value back to the lhs
    bool operator==(const Vector rhs) const;           // determine whether two vectors are the same
    bool operator!=(const Vector rhs) const;           // determine whether two vectors are not the same

    int getDimension();                // returns the dimensionality of a Vector
    void setDimension(int new_dim);    // change the dimensionality of a Vector 
    double length();                   // compute and return a double containing the length of a Vector
private:
    int dimention;
    double* data;
};

Vector operator*(const double lfs, const Vector rhs);    // a double multiple with vector