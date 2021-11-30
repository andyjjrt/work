#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        int n, k;
        scanf("%d %d", &n, &k);
        n = n % 1007;
        int ans[33];
        int b = 0, ba = k, sub = 1, counter = 0;
        while(1){
            int check = ba % 2;
            if(counter == 0){
                sub = n;
            }else{
                sub *= sub;
            }
            sub %= 1007;
            if(check == 1){
                ans[b] = sub;
                b++;
            }
            counter++;
            ba /= 2;
            if(ba < 1){
                break;
            }
        }
        long long a = 1;
        for(int j = 0; j < b; j++){
            a *= ans[j];
            a %= 1007;
        }
        printf("%lld\n", a);
    }
}