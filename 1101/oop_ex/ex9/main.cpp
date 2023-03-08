#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<long, string>a, pair<long, string>b) {
    return a.first < b.first;
}

int main(){
    /*
    ifstream input_file;
    input_file.open("source.txt");
    
    vector<pair<long, string>> data;
    if(input_file.is_open()){
        pair<long, string> tmp;
        while(input_file >> tmp.first >> tmp.second){
            data.push_back(tmp);
        }
    }
    input_file.close();
    */
    
    vector<pair<long, string>> data;
    string name;
    long id;
    while(cin >> id >> name){
        pair<long, string> tmp;
        tmp.first = id;
        tmp.second = name;
        data.push_back(tmp);
    }
    

    sort(data.begin(), data.end(), cmp);

    /*
    ofstream output_file;
    output_file.open("result.txt", ios::app);
    */

    for(pair<long, string> i : data){
        cout << left << setw(10) << i.first << "    " << left << setw(10) << i.second << "*" << endl;
        //output_file << left << setw(10) << i.first << "    " << setw(10) << i.second << "*" << endl;
    }

    //output_file.close();
}