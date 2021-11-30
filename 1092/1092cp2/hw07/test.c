#include <stdio.h>
#include <stdlib.h>

int cmp (const void * a, const void * b){
   return *(double *)a > *(double *)b ? 1 : -1; 
}

int main(){
    double tmp[4] = {2.000000, 1.000000, 1.125000, 1.111111};
    for(int i = 0; i < 4; i++){
        printf("%lf ", tmp[i]);
    }
    puts("");
    qsort(tmp, 4, sizeof(double), cmp);
    for(int i = 0; i < 4; i++){
        printf("%lf ", tmp[i]);
    }
    puts("");
}