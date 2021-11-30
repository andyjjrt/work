#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

int DFS(int table[500][500], int x, int y, int N){
    int l = 0, r = 0, u = 0, d = 0;
    table[x][y] = 2;
    if(table[x+1][y] == 1 && x+1 < N){
        l = DFS(table, x+1, y, N);
    }
    if(table[x-1][y] == 1 && x-1 >= 0){
        r = DFS(table, x-1, y, N);
    }
    if(table[x][y+1] == 1 && y+1 < N){
        u = DFS(table, x, y+1, N);
    }
    if(table[x][y-1] == 1 && y-1 >= 0){
        d = DFS(table, x, y-1, N);
    }
    return l + r + u + d + 1;
}

int main() {
    int N;
    scanf("%d", &N);
    int table[500][500];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &table[i][j]);
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(table[i][j] == 0){
                int ans_tmp = DFS(table, i, j, N);
                ans = MAX(ans_tmp , ans);
                //printf("%d %d %d\n", i, j, ans_tmp);
            }
        }
    }
    printf("%d\n", ans);
}
