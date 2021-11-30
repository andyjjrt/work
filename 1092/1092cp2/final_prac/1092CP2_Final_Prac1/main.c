#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

int main(){
    int n;
    scanf("%d", &n);
    int* arr = malloc(n * sizeof(int));
    int* tmp = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        tmp[i] = arr[i];
    }
    long long ans = arr[0];
    for(int i = 0; i < n; i++){
        long long tmp2 = arr[i];
        long long mul = arr[i];
        for(int j = i-1 ; j >= 0; j--){
            tmp2 *= arr[j];
            mul = MAX(tmp2, mul);
        }
        ans = MAX(ans, mul);
    }
    printf("%lld\n", ans);
}