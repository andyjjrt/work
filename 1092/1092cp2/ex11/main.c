#include <stdio.h>
#include <stdlib.h>
#define DEBUG puts("DEBUG");

typedef struct queue que;
struct queue{
    int val;
    que* next;
};


//=========QUEUE DATA FUNCTIONS=========//

que* new_node(int val){
    que* node = malloc(sizeof(que));
    node -> val = val;
    node -> next = NULL;
    return node;
}

que* first(que* root){
    return root -> next;
}

void push(que* root, que* node){
    while(root -> next != NULL){
        root = root -> next;
    }
    root -> next = node;
}

void pop(que* root){
    que* first = root -> next;
    if(first != NULL){
        que* tmp = first -> next;
        free(first);
        root -> next = tmp;
    }
}

void print_queue(que* root){
    root = first(root);
    while(root != NULL){
        printf("%d ", root -> val);
        root = root -> next;
    }
    puts("");
}

//=========QUEUE DATA FUNCTIONS=========//



int main() {
    que** station = malloc(1000000 * sizeof(que*));
    for(int i = 0; i < 1000000; i++){
        station[i] = new_node(-1);
    }
    int start, end, n;
    scanf("%d %d %d", &start, &end, &n);
    que** bus = malloc(n * sizeof(que*));
    for(int i = 0; i < n; i++){
        bus[i] = new_node(-1);
    }
    for(int i = 0; i < n; i++){
        bus[i] = new_node(-1);
        int k;
        scanf("%d", &k);
        for(int j = 0; j < k; j++){
            int tmp;
            scanf("%d", &tmp);
            push(bus[i], new_node(tmp));
            push(station[tmp], new_node(i));
        }
    }
    que* queue = new_node(-1);
    int* station_status = calloc(1000000, sizeof(int));
    int step = 1;
    push(queue, new_node(start));
    while(first(queue) != NULL){
        que* tmp = new_node(-1);
        while(first(queue) != NULL){
            int station_number = first(queue) -> val;
            while(first(station[station_number]) != NULL){
                int bus_number = first(station[station_number]) -> val;
                while(first(bus[bus_number]) != NULL){
                    if(first(bus[bus_number]) -> val != station_number){
                        push(tmp, new_node(first(bus[bus_number]) -> val));
                        station_status[first(bus[bus_number]) -> val] = 1;
                    }
                    pop(bus[bus_number]);
                }
                pop(station[station_number]);
            }
            pop(queue);
        }
        //print_queue(tmp);
        free(queue);
        queue = tmp;
        if(station_status[end] == 1){
            break;
        }
        step++;
    }
    if(station_status[end] == 1){
        printf("%d\n", step);
    }
    else{
        puts("-1");
    }

    //free data
    for(int i = 0; i < 1000000; i++){
        free(station[i]);
    }
    free(station);
    for(int i = 0; i < n; i++){
        free(bus[i]);
    }
    free(bus);
    free(station_status);
    free(queue);
}
