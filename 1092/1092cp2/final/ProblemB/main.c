#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

int main(){
    long long xa1, ya1, xa2, ya2, xb1, yb1, xb2, yb2, xc1, yc1, xc2, yc2;
    scanf("(%lld, %lld, %lld, %lld)\n(%lld, %lld, %lld, %lld)\n(%lld, %lld, %lld, %lld)", &xa1, &ya1, &xa2, &ya2, &xb1, &yb1, &xb2, &yb2, &xc1, &yc1, &xc2, &yc2);
    //printf("%d %d %d %d\n%d %d %d %d\n%d %d %d %d\n", xa1, ya1, xa2, ya2, xb1, yb1, xb2, yb2, xc1, yc1, xc2, yc2);
    long long A = (xa2 - xa1) * (ya2 - ya1);
    long long B = (xb2 - xb1) * (yb2 - yb1);
    long long C = (xc2 - xc1) * (yc2 - yc1);
    long long xab1 = MAX(xa1,xb1), yab1 = MAX(ya1,yb1), xab2 = MIN(xa2,xb2), yab2 = MIN(ya2,yb2);
    long long A_B = 0, check_A_B = 0;
    if(xab2 > xab1 && yab2 > yab1){
        check_A_B = 1;
        A_B = (xab2 - xab1) * (yab2 - yab1);
    }
    long long xbc1 = MAX(xc1,xb1), ybc1 = MAX(yc1,yb1), xbc2 = MIN(xc2,xb2), ybc2 = MIN(yc2,yb2);
    long long B_C = 0, check_B_C = 0;
    if(xbc2 > xbc1 && ybc2 > ybc1){
        check_B_C = 1;
        B_C = (xbc2 - xbc1) * (ybc2 - ybc1);
    }
    long long xac1 = MAX(xa1,xc1), yac1 = MAX(ya1,yc1), xac2 = MIN(xa2,xc2), yac2 = MIN(ya2,yc2);
    long long A_C = 0, check_A_C = 0;
    if(xac2 > xac1 && yac2 > yac1){
        check_A_C = 1;
        A_C = (xac2 - xac1) * (yac2 - yac1);
    }
    long long xabc1 = MAX(xab1,xc1), yabc1 = MAX(yab1,yc1), xabc2 = MIN(xab2,xc2), yabc2 = MIN(yab2,yc2);
    long long A_B_C = 0, check_A_B_C = 0;
    if(check_A_B && check_A_C && check_B_C){
        check_A_B_C = 1;
        A_B_C = (xabc2 - xabc1) * (yabc2 - yabc1);
    }
    long long ans = A + B + C - A_B - A_C - B_C + A_B_C;
    printf("%lld\n", ans);
}