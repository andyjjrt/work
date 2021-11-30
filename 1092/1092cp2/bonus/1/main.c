#include <stdio.h>

int main(){
    int N, array[100010];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", &array[i]);
    }
    int j = N-1;
    int a = 0, b = 0, ans = 0;
    for(int i = 0; i < N; i++){
        a += array[i];
        while(b < a){
            b += array[j];
            j--;
            //printf("a=%d, b=%d\n", a, b);
        }
        if(a == b){
            //printf("equal, a=%d, b=%d\n", a, b);
            ans++;
        }
    }
    printf("%d\n", ans);
}