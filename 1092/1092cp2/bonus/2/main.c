#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

int main(){
    int *array = malloc(10000000 * sizeof(int));
    memset(array, 0, 1000000);
    int N;
    long max = 0, who = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        long tmp;
        scanf("%ld", &tmp);
        if(tmp < 0){
            continue;
        }
        array[tmp]++;
        if(array[tmp] * tmp > max * who){
            max = array[tmp];
            who = tmp;
        }
    }
    printf("%ld\n%ld\n", who, who*max*10000);
    free(array);
}