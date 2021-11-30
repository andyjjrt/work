#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int priority(string str){
    if(str == "*" || str == "/"){
        return 2;
    }else if(str == "+" || str == "-"){
        return 1;
    }
    return -1;
}
int get_ans(int a, int b, string oper){
    if(oper == "+"){
        return a+b;
    }else if(oper == "-"){
        return a-b;
    }else if(oper == "*"){
        return a*b;
    }else if(oper == "/"){
        return a/b;
    }
}

int main(){
    vector<string> pre;
    stack<string> post_tmp;
    string input;
    cin >> input;

    string tmp;
    for(int i = 0; i < input.size(); i++){
        if(input[i] == '+' || input[i] == '*' || input[i] == '/' || input[i] == '(' || input[i] == ')' || (input[i] == '-' && (i != 0 && input[i-1] != '('))){
            if(tmp.size() != 0){
                pre.push_back(tmp);
                tmp.clear();
            }
            tmp += input[i];
            pre.push_back(tmp);
            tmp.clear();
        }else{
            tmp += input[i];
        }
    }
    if(tmp.size() != 0){
        pre.push_back(tmp);
        tmp.clear();
    }

    vector<string> postfix;

    for(int i = 0; i < pre.size(); i++){
        if(pre[i] == "("){
            post_tmp.push(pre[i]);
        }else if(pre[i] == ")"){
            while(post_tmp.top() != "("){
                postfix.push_back(post_tmp.top());
                post_tmp.pop();
            }
            post_tmp.pop();
        }else if(pre[i] == "+" || pre[i] == "-" || pre[i] == "*" || pre[i] == "/"){
            if(post_tmp.empty()){
                post_tmp.push(pre[i]);
            }else{
                if(priority(pre[i]) > priority(post_tmp.top())){
                    post_tmp.push(pre[i]);
                }else{
                    while(!post_tmp.empty() && priority(pre[i]) <= priority(post_tmp.top())){
                        postfix.push_back(post_tmp.top());
                        post_tmp.pop();
                    }
                    post_tmp.push(pre[i]);
                }
            }
        }else{
            postfix.push_back(pre[i]);
        }
    }
    while(!post_tmp.empty()){
        postfix.push_back(post_tmp.top());
        post_tmp.pop();
    }

    stack<int> ans;

    for(int i = 0; i < postfix.size(); i++){
        if(postfix[i] == "+" || postfix[i] == "-" || postfix[i] == "*" || postfix[i] == "/"){
            int a = ans.top();
            ans.pop();
            int b = ans.top();
            ans.pop();
            int c = get_ans(b,a,postfix[i]);
            //cout << "a: " << a << " b: " << b << " c: " << c << endl;
            ans.push(c);
        }else{
            int a = stoi(postfix[i]);
            ans.push(a);
        }
    }
    cout << ans.top() << endl;

}