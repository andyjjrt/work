#include <iostream>
using namespace std;

int main(){
    string str;
    while(cin >> str){
        int balance = 0, ans = 0;
        for(int i = 0; i < str.length(); i++){
            str[i] == 'L' ? balance-- : balance++;
            if(balance == 0){
                ans++;
            }
        }
        cout << ans << endl;
    }
    
}