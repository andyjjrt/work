#include <iostream>
using namespace std;

class superman {
public:
    superman(string category, string name, int hp, float atk, float def);
    ~superman();

    void doAtk();
    void beAtked(int be_atk_value);
    void showHP();

private:
    string category;
    string name;
    int hp;
    float atk;
    float def;

};

// Initialization function
superman::superman(string i_category, string i_name, int i_hp, float i_atk, float i_def) {
    category = i_category;
    name = i_name;
    hp = i_hp < 0 ? 0 : i_hp;
    atk = i_atk < 0 ? 0 : i_atk;
    def = i_def < 0 ? 0 : i_def;
}

// Finalization function
superman::~superman() {

}

void superman::doAtk() {
    cout << category << " " << name << " caused " << (atk + hp) / 2 << " points damage" << endl;
}

void superman::beAtked(int be_atk_value) {
    cout << category << " " << name << " is damaged by " << (def <= 0 ? 0 : (2 * be_atk_value / def)) << " points" << endl;
}

void superman::showHP(){
    cout << category << " " << name << " currently has " << hp << " points of HP" << endl;
}

int main(){
    while(!cin.eof()){
        string category, name;
        int hp;
        float atk, def;
        cin >> category >> name >> hp >> atk >> def;
        superman man(category, name, hp, atk, def);

        string event;
        cin >> event;
        
        if(event.compare("A") == 0){
            man.doAtk();
        }else if(event.compare("B") == 0){
            int tmp;
            cin >> tmp;
            man.beAtked(tmp);
        }else if(event.compare("C") == 0){
            man.showHP();
        }
        
    }
}