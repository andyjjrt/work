#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b;
    scanf("%d", &a);
    int *A = malloc(a * sizeof(int));
    for(int i = 0; i < a; i++){
        scanf("%d", &A[i]);
    }
    scanf("%d", &b);
    int *B = malloc(b * sizeof(int));
    for(int i = 0; i < b; i++){
        scanf("%d", &B[i]);
    }
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        int l_a, r_a, l_b, r_b;
        scanf("%d %d %d %d", &l_a, &r_a, &l_b, &r_b);
        int total = r_a + r_b - l_a - l_b;
        if(total % 2 == 1){
            int tmp, a_p = l_a, b_p = l_b, j = 0;
            while(j < total / 2 + 1 && a_p < r_a && b_p < r_b){
                if(A[a_p] < B[b_p]){
                    tmp = A[a_p];
                    a_p++;
                }else{
                    tmp = B[b_p];
                    b_p++;
                }
                j++;
            }
            while(j < total / 2 + 1 && a_p < r_a){
                tmp = A[a_p];
                a_p++;
                j++;
            }
            while(j < total / 2 + 1 && b_p < r_b){
                tmp = B[b_p];
                b_p++;
                j++;
            }
            printf("%d\n", tmp);
        }else{
            int tmp, a_p = l_a, b_p = l_b, j = 0;
            while(j < total / 2 && a_p < r_a && b_p < r_b){
                if(A[a_p] < B[b_p]){
                    tmp = A[a_p++];
                }else{
                    tmp = B[b_p++];
                }
                j++;
            }
            while(j < total / 2 && a_p < r_a){
                tmp = A[a_p++];
                j++;
            }
            while(j < total / 2 && b_p < r_b){
                tmp = B[b_p++];
                j++;
            }
            printf("%d ", tmp);
            if(a_p < r_a && b_p < r_b){
                if(A[a_p] < B[b_p]){
                    tmp = A[a_p++];
                }else{
                    tmp = B[b_p++];
                }
            }else if(a_p < r_a){
                tmp = A[a_p++];
            }else if(b_p < r_b){
                tmp = B[b_p++];
            }
            printf("%d\n", tmp);
        }
    }
}