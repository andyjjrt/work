#include <stdio.h>
#include <stdlib.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int cmpfunc (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}
int compare ( const void *pa, const void *pb ) {
    int a = **(int**)pa;
    int b = **(int**) pb;
    return a - b;
}

int main(){
    int **data;
    int M, N;
    scanf("%d %d", &M, &N);
    data = calloc(M, sizeof(int*));
    for(int i = 0; i < M; i++){
        data[i] = calloc(N, sizeof(int));
        for(int j = 0; j < N; j++){
            scanf("%d", &data[i][j]);
        }
        qsort(data[i], N, sizeof(int), cmpfunc);
    }
    qsort(data, M, sizeof(int*), compare);
    int ans = 0;

    int solution[10000];
    for (int i = 0; i < M; ++i) {
        solution[i] = 1;
        for (int j = 0; j < i; ++j){
            int check = 1;
            for(int k = 0; k < N; k++){
                if(data[j][k] >= data[i][k]){
                    check = -1;
                    break;
                }
            }
            if (check == 1 && solution[j] + 1 > solution[i]){
                solution[i] = solution[j] + 1;
            }
        }
        ans = MAX(ans, solution[i]);
    }
    /*
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", data[i][j]);
        }
        puts("");
    }
    */
    printf("%d\n", ans);
}