#include <bits/stdc++.h>
using namespace std;

struct node{
    int left;         //left index
    int right;        //right index
    double priority;  //random priority
    int val;          //value of the node
};
typedef struct node node;

class Treap{
private:
    int length;
    int index;
    node* data;
    void R_rotation(int &current_index);
    void L_rotation(int &current_index);
public:
    Treap(int length);           //constructer
    ~Treap();                    //destructer
    int root;
    void insert(int &current_index, int value);
    void remove(int &cirrent_index, int value);
    void print(int current_index);
};

Treap::Treap(int length_){
    length = length_;
    index = 0;
    root = -1;
    data = new node[length];
}

Treap::~Treap(){
    delete [] data;
}

void Treap::L_rotation(int &current_index){
    int new_index = data[current_index].right;
    data[current_index].right = data[new_index].left;
    data[new_index].left = current_index;
    current_index = new_index;
}

void Treap::R_rotation(int &current_index){
    int new_index = data[current_index].left;
    data[current_index].left = data[new_index].right;
    data[new_index].right = current_index;
    current_index = new_index;
}

void Treap::insert(int &current_index, int value){
    if(current_index == -1){
        data[index].left = -1;
        data[index].right = -1;
        data[index].priority = rand();
        data[index].val = value;
        current_index = index;
        index++;
        return;
    }
    if(value >= data[current_index].val){
        insert(data[current_index].right, value);
        if(data[data[current_index].right].priority > data[current_index].priority){
            L_rotation(current_index);
        }
    }else{
        insert(data[current_index].left, value);
        if(data[data[current_index].left].priority > data[current_index].priority){
            R_rotation(current_index);
        }
    }
}

void Treap::remove(int &current_index, int value){
    if(current_index == -1) return;
    if(value > data[current_index].val){
        remove(data[current_index].right, value);
    }else if(value < data[current_index].left){
        remove(data[current_index].left, value);
    }else{
        
    }
}

void Treap::print(int current_index){
	if (current_index == -1) return ;
	if (data[current_index].left != -1){
        print(data[current_index].left);
    }
	cout << data[current_index].val << " : " << data[current_index].priority << endl;
	if (data[current_index].right != -1){
        print(data[current_index].right);
    }
}

int main(){
    Treap T(1 << 28);
    for(int i = 0; i < (1 << 28); i++){
        T.insert(T.root, i);
    }
    cout << T.root << endl;
    T.print(T.root);

}
