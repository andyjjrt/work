#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

int check_valid(char* arr, int* bin, int N){
    int valid = 1;
    for(int i = 0, j = N; i <= j; i++, j--){
        for(; bin[i] == 0; i++);
        for(; bin[j] == 0; j--);
        if(arr[i] != arr[j]){
            valid = 0;
            break;
        }
    }
    return valid;
}

int main(){
    char arr[30];
    scanf("%s", arr);
    int* ans = calloc(30, sizeof(int));
    int max_length = 0;
    int arrlen = strlen(arr);

    for(int i = 0; i < (1 << arrlen);i++){
        int b = 0,binary[20] = {0}, a = i,* const bptr = binary, count = 0;
        while(1){
            int check = a % 2;
            count += check;
            *(bptr+b) = check;
            b++;
            a /= 2;
            if(a < 1)
                break;
        }
        if(check_valid(arr, binary, arrlen) == 1){
            if(count > max_length){
                max_length = count;
                free(ans);
                ans = calloc(30, sizeof(int));
                memcpy(ans, binary, sizeof(binary));
            }
        }
    }
    for(int i = 0; i < arrlen; i++){
        if(ans[i]){
            printf("%c", arr[i]);
        }
    }
    puts("");
}