#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

int cmp (const void * a, const void * b){
   return *(long double *)a > *(long double *)b ? 1 : -1; 
}

int main() {
    int N, table[10000][2], ans = 1;
    long double tmp[10000];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d %d", &table[i][0], &table[i][1]);
    }

    for(int i = 0; i < N-1; ++i){
        for(int j = i+1; j < N; ++j){
            if(table[j][0] - table[i][0] == 0){
                tmp[j-i-1] = 100000;
            }else{
                tmp[j-i-1] = (table[j][1] - table[i][1])*1.0000/(table[j][0] - table[i][0])*1.0000;
            }
            
        }
        qsort(tmp, (N-i-1), sizeof(long double), cmp);
        long double temp = tmp[0];
        int continious = 1, sub_max = 1;
        for(int j = 0; j < N-i-1; ++j){
            //printf("%llf ", tmp[j]);
            if(tmp[j] != temp){
                sub_max = MAX(sub_max, continious);
                continious = 2;
                temp = tmp[j];
            }else{
                continious++;
            }
            //printf("%d\n", continious);
        }
        sub_max = MAX(sub_max, continious);
        /*
        for(int j = 0; j < N-i-1; j++){
            printf("%llf ", tmp[j]);
        }
        */
        //printf("\n%d\n", sub_max);
        
        ans = MAX(sub_max, ans);
    }
    printf("%d\n", ans);
    return 0;
}
