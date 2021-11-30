#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG puts("debug");
typedef struct Que Que;
struct Que{
    int x;
    int y;
    Que *next;
};

Que* new_node(int x, int y){
    Que* root = malloc(sizeof(Que));
    root -> x = x;
    root -> y = y;
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

void search(Que* point, Que* queue, int** table){
    int x = point -> x;
    int y = point -> y;
    if(table[x][y] == 1){
        return;
    }
    table[x][y] = 1;
    if(x+1 < 8 && y+2 < 8){
        if(table[x+1][y+2] == 0){
            push(queue, new_node(x+1, y+2));
        }
    }
    if(x+1 < 8 && y-2 >=0){
        if(table[x+1][y-2] == 0){
            push(queue, new_node(x+1, y-2));
        }
    }
    if(x-1 >= 0 && y+2 < 8){
        if(table[x-1][y+2] == 0){
            push(queue, new_node(x-1, y+2));
        }
    }
    if(x-1 >= 0 && y-2 >= 0){
        if(table[x-1][y-2] == 0){
            push(queue, new_node(x-1, y-2));
        }
    }
    if(x+2 < 8 && y+1 < 8){
        if(table[x+2][y+1] == 0){
            push(queue, new_node(x+2, y+1));
        }
    }
    if(x+2 < 8 && y-1 >= 0){
        if(table[x+2][y-1] == 0){
            push(queue, new_node(x+2, y-1));
        }
    }
    if(x-2 >= 0 && y+1 < 8){
        if(table[x-2][y+1] == 0){
            push(queue, new_node(x-2, y+1));
        }
    }
    if(x-2 >= 0 && y-1 >= 0){
        if(table[x-2][y-1] == 0){
            push(queue, new_node(x-2, y-1));
        }
    }
}

void print_queue(Que* queue){
    queue = queue -> next;
    while(queue != NULL){
        printf("(%d, %d) ", queue ->x, queue -> y);
        queue = queue -> next;
    }
    puts("");
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int** table = malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++){
        table[i] = calloc(m, sizeof(int));
        for(int j = 0; j < m; j++){
            scanf("%d", &table[i][j]);
        }
    }

    Que* queue = new_node(-1, -1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            push(queue, new_node(i, j));
            int step = 0;
            while(step <= 7){
                Que *tmp = new_node(-1, -1);
                while(queue -> next != NULL){
                    search(queue->next, tmp, table);
                    pop_first(queue);
                }
                //print_queue(tmp);
                if(table[x2][y2] == 1){
                    break;
                }
                step++;
                queue = tmp;
            }
            if(step <= 7){
                printf("%d\n", step);
            }else{
                puts("NO ANSWER");
            }
        }
    }
}
