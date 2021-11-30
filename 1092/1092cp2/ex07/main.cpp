#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int main(){
    int N, num;
    scanf("%d\n", &N);
    stringstream buffer;
    string array;
    map<int, int> table;

    getline(cin, array);
    cin.clear();
    buffer << array;
    while (getline(buffer, array, ' ')) {
        num = stoi(array);
        table[num] = 1;
    }
    buffer.clear();
    for(int i = 1; i < N; i++){
        map<int, int> tmp_table;
        getline(cin, array);
        cin.clear();
        buffer << array;
        while (getline(buffer, array, ' ')) {
            num = stoi(array);
            map<int, int>::iterator iter = table.find(num);
            if(iter != table.end()){
                tmp_table[num] = 1;
            }
        }
        buffer.clear();
        table.clear();
        for (auto j : tmp_table){
            table[j.first] = 1;
        }
    }

    for (auto i : table){
        cout << i.first << " ";
    }
    cout << endl;
    
}