#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

int main(){
    int T;
    scanf("%d", &T);
    int* arr = calloc(T, sizeof(int));
    for(int i = 0; i < T; i++){
        scanf("%d", &arr[i]);
    }
    int** table = malloc(T * sizeof(int*));
    for(int i = 0; i < T; i++){
        table[i] = calloc(T, sizeof(int));
        for(int j = 0; j <= arr[i] && j < T; j++){
            table[i][j+i] = 1;
        }
    }
    int ans = -1;
    for(int i = 0; i < T; i++){
        if(table[i][T-1]){
            ans = i + 1;
            break;
        }
    }
    printf("%d\n", ans);
}