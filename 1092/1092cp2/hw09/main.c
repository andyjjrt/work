#include <stdio.h>
#include <stdlib.h>

int nums[5000000000];

void BS(int* nums, int target, int left, int right){
    int found = 0;
    int times = 0, mid;
    while(right > left && found == 0){
        mid = left + ((right-left)/2);
        if(nums[mid] == target){
            found = 1;
        }else if(nums[mid] > target){
            right = mid;
        }else{
            left = mid+1;
        }
        times++;
    }
    if(found == 0){
        printf("-1\n");
    }else{
        printf("%d\n%d\n", mid, times);
    }
}

int main(){
    int N;
    scanf("%d", &N);
    int m, i=0;
    while(scanf("%d", &m) != EOF){
        nums[i] = m;
        i++;
    }
    BS(nums, N, 0, i);
}