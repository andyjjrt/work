#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node{
    char type;
    int value;
    char str[20];
    Node* next;
};

void push(Node* root, Node* node){
    while(root->next != NULL){
        root = root->next;
    }
    root->next = node;
}
void pop(Node* root){
    Node* pre = root;
    Node* cur = root->next;
    if(cur == NULL){
        return;
    }
    while(cur->next != NULL){
        pre = cur;
        cur = cur->next;
    }
    free(cur);
    pre->next = NULL;
}
Node* top(Node* root){
    while(root->next != NULL){
        root = root->next;
    }
    return root;
}
void clear(Node* root){
    while(root != NULL){
        Node* tmp = root->next;
        free(root);
        root = tmp;
    }
}
Node* new_char(char *str){
    Node* newchar = malloc(sizeof(Node));
    newchar->type = 'S';
    strcpy(newchar->str, str);
    newchar->next = NULL;
    return newchar;
}
Node* new_int(int num){
    Node* newint = malloc(sizeof(Node));
    newint->type = 'N';
    newint->value = num;
    newint->next = NULL;
    return newint;
}
Node* new_root(){
    Node* newroot = malloc(sizeof(Node));
    newroot->type = 'R';
    newroot->next = NULL;
    return newroot;
}
void print(Node* root){
    while(root != NULL){
        if(root->type == 'S'){
            printf("%s ", root->str);
        }else if(root->type == 'N'){
            printf("%d ", root->value);
        }
        root = root->next;
    }
    puts("");
}
int priority(char* a){
    if(strcmp(a, "*") == 0 || strcmp(a, "/") == 0){
        return 2;
    }else if(strcmp(a, "+") == 0 || strcmp(a, "-") == 0){
        return 1;
    }
    return -1;
}
int get_ans(int a, int b, char* oper){
    if(strcmp(oper, "+") == 0){
        return a+b;
    }else if(strcmp(oper, "-") == 0){
        return a-b;
    }else if(strcmp(oper, "*") == 0){
        return a*b;
    }else if(strcmp(oper, "/") == 0){
        return a/b;
    }
}

int main(){
    char input[200];
    Node* infix = new_root();

    scanf("%s", input);
    char tmp[200];
    int tmp_position = 0;
    for(int i = 0; input[i] != '\0'; i++){
        if(input[i] == '+' || input[i] == '*' || input[i] == '/' || input[i] == '(' || input[i] == ')' || (input[i] == '-' && (i != 0 && input[i-1] != '('))){
            if(tmp_position != 0){
                tmp[tmp_position] = '\0';
                Node* tmp_node = new_int(atoi(tmp));
                push(infix, tmp_node);
            }
            tmp[0] = input[i];
            tmp[1] = '\0';
            Node* tmp_node = new_char(tmp);
            push(infix, tmp_node);
            tmp_position = 0;
        }else{
            tmp[tmp_position] = input[i];
            tmp_position++;
        }
    }
    if(tmp_position != 0){
        tmp[tmp_position] = '\0';
        Node* tmp_node = new_int(atoi(tmp));
        push(infix, tmp_node);
    }
    
    Node* postfix = new_root();
    Node* transfer = new_root();
    for(Node* i = infix->next;i != NULL; i = i->next){
        if(i->type == 'N'){
            Node* tmp = new_int(i->value);
            push(postfix, tmp);
        }else if(i->type == 'S'){
            if(strcmp(i->str, "(") == 0){
                Node* tmp = new_char(i->str);
                push(transfer, tmp);
            }else if(strcmp(i->str, ")") == 0){
                while(strcmp(top(transfer)->str,"(") != 0){
                    Node* tmp = new_char(top(transfer)->str);
                    push(postfix, tmp);
                    pop(transfer);
                }
                pop(transfer);
            }else{
                if(top(transfer) == transfer){
                    Node* tmp = new_char(i->str);
                    push(transfer, tmp);
                }else{
                    if(priority(i->str) > priority(top(transfer)->str)){
                        Node* tmp = new_char(i->str);
                        push(transfer, tmp);
                    }else{
                        while(top(transfer) != transfer && priority(i->str) <= priority(top(transfer)->str)){
                            Node* tmp = new_char(top(transfer)->str);
                            push(postfix, tmp);
                            pop(transfer);
                        }
                        Node* tmp = new_char(i->str);
                        push(transfer, tmp);
                    }
                }
            }
        }
    }
    while(top(transfer) != transfer){
        Node* tmp = new_char(top(transfer)->str);
        push(postfix, tmp);
        pop(transfer);
    }

    Node* calculater = new_root();
    for(Node* i = postfix->next;i != NULL; i = i->next){
        if(i->type == 'N'){
            Node* tmp = new_int(i->value);
            push(calculater, tmp);
        }else if(i->type == 'S'){
            int a = top(calculater)->value;
            pop(calculater);
            int b = top(calculater)->value;
            pop(calculater);
            Node* tmp = new_int(get_ans(b,a,i->str));
            push(calculater, tmp);
        }
    }
    print(calculater);
    clear(postfix);
}