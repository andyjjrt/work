#include <bits/stdc++.h>
using namespace std;

template <typename T>
T input() {
    string type;
    if (type == "-1") break;
    if (type == "int") {
        auto a = input<int>();
    } else if (type == "float") {
        avg<float>();
    } else if (type == "char") {
        avg<char>();
    }
    T a;
    cin >> a return a;
}

int main() {
    string type;
    while (cin >> type) {
        if (type == "-1") break;
        if (type == "int") {
            auto a = input<int>();
        } else if (type == "float") {
            avg<float>();
        } else if (type == "char") {
            avg<char>();
        }
    }
}