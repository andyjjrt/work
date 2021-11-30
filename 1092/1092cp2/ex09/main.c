#include <stdio.h>
#include <stdlib.h>
#define MIN(a,b) (((a)<(b))?(a):(b))

int main() {
	int len, target;
	scanf("%d", &len);
	int *arr = calloc(len, sizeof(int));
	for(int i = 0; i < len; i++){
		scanf("%d", &arr[i]);
	}
	scanf("%d", &target);
	
	int step = 0,start = 0, end = 0;
	long long sum = 0;
	while(sum < target && end < len){
		sum += arr[end];
		end++;
	}
	if(sum < target){
		puts("0");
		return 0;
	}
	step = end-start;
	while(end <= len){
		//printf("%d %d %lld\n", step, end-start, sum);
		if(sum >= target){
			step = MIN(step, end-start);
			sum -= arr[start];
			start++;
		}else{
			sum += arr[end];
			end++;
		}
	}

	printf("%d\n", step);
	return 0;
}
