#include <iostream>
using namespace std;

class Complex {
public:
    friend ostream& operator<<(ostream&, const Complex&);
    friend istream& operator>>(istream&, Complex&);
    Complex(){};
    Complex(double _Real, double _imaginary){Real = _Real; Imaginary = _imaginary;};

    Complex operator+=(Complex c);
    Complex operator+(Complex c);
    Complex operator-(Complex c);
    Complex operator*(Complex c);

    Complex operator++();
    Complex operator++(int);
    Complex operator--();
    Complex operator--(int);

    bool operator>(Complex c);
    bool operator<(Complex c);
    bool operator==(Complex c);
private:
    double Real;
    double Imaginary;
};

istream& operator>>( istream& in, Complex& c)
{
    in >> c.Real >> c.Imaginary;
    return in;
}
ostream& operator<<(ostream& out, const Complex& c)
{
    if(c.Imaginary<0){
        out << c.Real << c.Imaginary << "i";
        return out;
    }else{
        out << c.Real << "+" << c.Imaginary << "i";
        return out;
    }

}
Complex Complex::operator+=(Complex c) {
    Real += c.Real;
    Imaginary += c.Imaginary;
    return *this;
}
Complex Complex::operator+(Complex c) {
    Complex result(Real + c.Real, Imaginary + c.Imaginary);
    return result;
}
Complex Complex::operator-(Complex c) {
    Complex result(Real - c.Real, Imaginary - c.Imaginary);
    return result;
}
Complex Complex::operator*(Complex c) {
    Complex result(Real * c.Real - Imaginary * c.Imaginary, Real * c.Imaginary + Imaginary * c.Real);
    return result;
}

Complex Complex::operator++() {
    Real += 1;
    Imaginary += 1;
    return *this;
}
Complex Complex::operator++(int) {
    Complex result = *this;
    Real += 1;
    Imaginary += 1;
    return result;
}
Complex Complex::operator--() {
    Real -= 1;
    Imaginary -= 1;
    return *this;
}
Complex Complex::operator--(int) {
    Complex result = *this;
    Real -= 1;
    Imaginary -= 1;
    return result;
}
bool Complex::operator>(Complex c){
    if(Real == c.Real){
        return Imaginary > c.Imaginary;
    }
    return Real > c.Real;
}

bool Complex::operator<(Complex c){
    if(Real == c.Real){
        return Imaginary < c.Imaginary;
    }
    return Real < c.Real;
}
bool Complex::operator==(Complex c){
    return (Real == c.Real && Imaginary == c.Imaginary) ? true : false;
}
int main() {
    Complex C1, C2;
    while( cin >> C1 >> C2 ) {
        cout << "C1 = " << C1 << endl;
        cout << "C2 = " << C2 << endl;

        cout << "C1==C2? " << ((C1==C2)?"true":"false") << endl;
        cout << "C1<C2?  " << ((C1<C2)?"true":"false") << endl;
        cout << "C1>C2?  " << ((C1>C2)?"true":"false") << endl;

        cout << "C1+C2 = " << C1+C2 << endl;
        cout << "C1-C2 = " << C1-C2 << endl;
        cout << "C1*C2 = " << C1*C2 << endl;
        cout << "C1++  = " << C1++ << endl;
        cout << "C1++  = " << C1++ << endl;
        cout << "++C1  = " << ++C1 << endl;
        cout << "++C1  = " << ++C1 << endl;
        cout << "C2--  = " << C2-- << endl;
        cout << "C2--  = " << C2-- << endl;
        cout << "--C2  = " << --C2 << endl;
        cout << "--C2  = " << --C2 << endl;

        C1+=C2;
        cout << "C1+=C2  " << C1 << endl;
        cout << "==============" << endl;
    }
    return 0;
}