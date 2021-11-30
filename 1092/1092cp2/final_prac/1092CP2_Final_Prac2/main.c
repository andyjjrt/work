#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Que Que;
struct Que{
    int val;
    Que *next;
};

Que* new_node(int val){
    Que* root = malloc(sizeof(Que));
    root -> val = val;
    root -> next = NULL;
    return root;
}

void push(Que *root, Que* node){
    while(root -> next != NULL){
        root = root -> next;
    }
    root -> next = node;
}

void pop_first(Que* root){
    if(root -> next != NULL){
        Que* tmp = root -> next -> next;
        free(root -> next);
        root -> next = tmp;
    }
}

int transfer(int val){

}

void search(Que* point, Que* queue, int* table){
    int val = point -> val;
    if(table[val] == 1){
        return;
    }
    if(val < 10){
        if(val == 9){
            push(queue, new_node(0));
        }else{
            push(queue, new_node(val+1));
        }
        if(val == 0){
            push(queue, new_node(9));
        }else{
            push(queue, new_node(val-1));
        }
    }
}

void print_queue(Que* queue){
    queue = queue -> next;
    while(queue != NULL){
        printf("(%d) ", queue -> val);
        queue = queue -> next;
    }
    puts("");
}

int main(){
    int *table = calloc(10000, sizeof(int));

    Que* queue = new_node(-1);

    int final;
    scanf("%d", &final);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        table[tmp] = 1;
    }
    push(queue, new_node(0));
    int step = 0;
    while(1){
        Que *tmp = new_node(-1);
        while(queue -> next != NULL){
            search(queue->next, tmp, table);
            pop_first(queue);
        }
        //print_queue(tmp);
        if(table[final] == 1){
            break;
        }
        step++;
        queue = tmp;
        break;
    }
    printf("%d\n", step);
}