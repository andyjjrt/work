#include <bits/stdc++.h>
using namespace std;

int main(){
    map<char, vector<int>> azmap;
    char c;
    for (c='a'; c<='z'; c++){
        int now = (int)c - 96;
        vector<int> vect;
        for(int i = 0; i < now; i++){
            //cout << i << " ";
            vect.push_back(i);
        }
        //cout << endl;
        azmap[c] = vect;
    }

    char token;
    int command, element;
    while(cin >> token >> command >> element){
        switch(command){
            case 0:
                cout << azmap[token][element] << " ";
                break;
            case 1:
                cout << azmap[token][azmap[token].size() - 1 - element] << " ";
                break;
            case 2:
                cout << ((element-1)*2 >= azmap[token].size() || element <= 0 ? 0 : azmap[token][(element-1)*2]) << " ";
                break;
        }
    }
}