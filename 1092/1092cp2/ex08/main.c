#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        long long n, k, m;
        scanf("%lld %lld %lld", &n, &k, &m);
        n = n % m;
        long long ans[33] = {0};
        long long b = 0, ba = k, sub = 1, counter = 0;
        while(1){
            int check = ba % 2;
            if(counter == 0){
                sub = n;
            }else{
                sub *= sub;
            }
            sub %= m;
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
        for(long long j = 0; j < b; j++){
            printf("%lld ", ans[j]);
            a *= ans[j];
            a %= m;
        }
        printf("\n%lld\n", a);
    }
}