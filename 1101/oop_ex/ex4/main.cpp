#include <bits/stdc++.h>
using namespace std;

class superman{
private:
    string name;
    vector<int> score;
public:
    superman(string);
    double get_avg();
    void add_score(int a_score);
    void sort_score();
    void to_string();
};

superman::superman(string my_name){
    name = my_name;
}

double superman::get_avg(){
    double sum = 0;
    int size = score.size();
    for(int i = 0; i < size; i++){
        sum += score[i];
    }
    return (sum / size);
}

void superman::add_score(int a_score){
    score.push_back(a_score);
}

void superman::sort_score(){
    sort(score.begin(), score.end(), greater<int>());
}

void superman::to_string(){
    cout << name << ":";
    for(int i = 0; i < score.size(); i++){
        cout << score[i] << " ";
    }
    cout << this->get_avg() << endl;
}

bool mycompare(superman s1, superman s2){
   return s1.get_avg() > s2.get_avg();
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int s1, s2;
        cin >> s1 >> s2;
        vector<superman> superclass;
        for(int j = 0; j < s1; j++){
            string superman_name;
            cin >> superman_name;
            superman man(superman_name);
            for(int k = 0; k < s2; k++){
                int tmp;
                cin >> tmp;
                man.add_score(tmp);
            } 
            man.sort_score();
            superclass.push_back(man);
        }

        sort(superclass.begin(), superclass.end(), mycompare);

        for(int j = 0; j < s1; j++){
            superclass[j].to_string();
        }

        cout << "==========" << endl;
    }
}