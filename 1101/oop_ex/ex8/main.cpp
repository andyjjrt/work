#include <bits/stdc++.h>
using namespace std;

template<typename T>
void avg(){
    T a, b;
    cin >> a >> b;
    cout << "Mean: " << (a + b) / 2 << endl;
}

int main(){
    string type;
    while(cin >> type){
        if(type == "-1") break;
        if(type == "int"){
            avg<int>();
        }else if(type == "float"){
            avg<float>();
        }else if(type == "char"){
            avg<char>();
        }
    }
}