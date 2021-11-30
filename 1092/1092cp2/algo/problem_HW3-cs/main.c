#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

int table[1100][1100], copy_table[1100][1100];

int DFS( int x, int y, int target, int N, int M){
    copy_table[x][y] = -1;
    int l = 0, r = 0, u = 0, d = 0;
    if(copy_table[x+1][y] == target && x+1 < N){
        r = DFS(x+1, y, target, N, M);
    }
    if(copy_table[x-1][y] == target && x-1 >= 0){
        l = DFS(x-1, y, target, N, M);
    }
    if(copy_table[x][y+1] == target && y+1 < M){
        u = DFS(x, y+1, target, N, M);
    }
    if(copy_table[x][y-1] == target && y-1 >= 0){
        d = DFS(x, y-1, target, N, M);
    }
    //printf("%d %d\n", target, l + r + u + d);
    return l + r + u + d + 1;
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d", &table[i][j]);
        }
    }
    int ans = -1;
    memcpy(copy_table, table, sizeof(table));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(copy_table[i][j] != -1){
                int des = DFS(i, j, table[i][j], N, M);
                ans = MAX(ans, des);
            }
        }
    }
    printf("%d\n", ans);
}