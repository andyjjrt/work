#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void BS(vector<int> nums, int target, int left, int right){
    bool found = false;
    int times = 0, mid;
    while(right > left && found == false){
        mid = left + ((right-left)/2);
        if(nums[mid] == target){
            found = true;
        }else if(nums[mid] > target){
            right = mid;
        }else{
            left = mid+1;
        }
        times++;
    }
    if(found == false){
        printf("-1\n");
    }else{
        printf("%d\n%d\n", mid, times);
    }
}

int main(){
    int N;
    scanf("%d", &N);
    vector<int> nums;
    int m;
    while(scanf("%d", &m) != EOF){
        nums.push_back(m);
    }
    BS(nums, N, 0, nums.size());
}