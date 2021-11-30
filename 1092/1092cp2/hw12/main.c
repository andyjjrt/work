#include <stdio.h>
#include <stdlib.h>

int* bit(int n){
    int* tmp = calloc(32, sizeof(int));
    for(int i = n, j = 0; i > 0; i /= 2, j++){
        tmp[j] = i % 2;
    }
    return tmp;
}

int dec(int* bit){
    int tmp = bit[0];
    for(int i = 1; i < 31; i++){
        tmp += bit[i] * (2 << i-1);
    }
    return tmp;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int* A = bit(a);
    int* B = bit(b);
    int* tmp = calloc(32, sizeof(int));
    for(int i = 31; i >= 0; i--){
        if(A[i] != B[i]){
            break;
        }else{
            tmp[i] = A[i];
        }
    }
    printf("%d\n", dec(tmp));
    return 0;
}
