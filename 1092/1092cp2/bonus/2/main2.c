#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

int cmp (const void * a, const void * b){
   return *(long *)a > *(long *)b ? 1 : -1; 
}

int main(){
    long array[1000010];
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%ld", &array[i]);
    }
    qsort(array, N, sizeof(long), cmp);
    long temp = array[0], sub_max = 0, sub = 0, who = 0;
    for(int j = 0; j < N; ++j){
        //printf("%ld ", array[j]);
        if(array[j] != temp){
            if(sub > sub_max){
                sub_max = sub;
                who = temp;
            }
            sub = array[j];
            temp = array[j];
        }else{
            sub += array[j];
        }
    }
    if(sub > sub_max){
        sub_max = sub;
        who = temp;
    }
    printf("%ld\n%ld\n", who, sub_max*10000);
}