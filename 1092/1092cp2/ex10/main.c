#include <stdio.h>
#include <stdlib.h>
/*
typedef struct Array Array;
struct Array{
    int value;
    Array* next;
};

Array* init(int N){
    Array* root = malloc(sizeof(Array));
    root->next = NULL;
    root->value = 0;
    Array* tmp = root;
    for(int i = 1; i <= N; i++){
        Array* new_node = malloc(sizeof(Array));
        tmp -> next = new_node;
        new_node -> value = i;
        new_node -> next = NULL;
        tmp = new_node;
    }
}

Array* remove(Array* root, Array* remove_node){
    while(root->next != remove_node){
        root = root -> next;
    }
    root -> next = remove_node -> next;
    free(remove_node);
}
*/

int counter = 0;
int ans = -1;

void rec(int N, int depth, int *arr, int *chosen, int* k){
    if(depth == N){
        counter++;
    }else{
        for(int i = 0; i < N && counter < *k; i++){
            if(chosen[i]){
                continue;
            }
            chosen[i] = 1;
            arr[depth] = i+1;
            rec(N, depth+1, arr, chosen, k);
            if(counter < *k){
                chosen[i] = 0;
                arr[depth] = 0;
            }
        }
    }
}

int main() {
    int N, k;
    scanf("%d %d", &N, &k);
    int ans = -1;
    int* arr = calloc(N, sizeof(int));
    int* chosen = calloc(N, sizeof(int));
    rec(N, 0, arr, chosen, &k);
    for(int i = 0; i < N; i++){
        printf("%d", arr[i]);
    }
    puts("");
    return 0;
}
