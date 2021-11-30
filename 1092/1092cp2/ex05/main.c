#include <stdio.h>

int main() {
	int A[1000010], station[1000010];
	int N;
	while(scanf("%d", &N) != EOF){
		int _A = 0, _S = 0;
		_A = N;
		for(int i = N, ii = 0; i > 0; --i, ii++){
			A[ii] = i;
		}
		int found = -1;
		for(int i = 0; i < N; i++){
			int target;
			scanf("%d", &target);
			if(found == -2){
				continue;
			}
			found = -1;
			if(station[_S-1] == target && _S != 0){
				_S -= 1;
				found = 0;
			}else if(target < A[_A-1]){
				found = -1;
			}else{
				for(int j = _A-1, k = 0; j >= 0; j--, k++){
					if(A[j] == target){
						_S = _S + k;
						_A = j;
						found = 0;
						break;
					}
					station[_S+k] = A[j];
				}
			}
			if(found == -1){
				found = -2;
			}
			/*
			printf("A: ");
			for(int j = _A - 1; j >= 0; j--){
				printf("%d ", A[j]);
			}
			puts("");
			printf("S: ");
			for(int j = _S - 1; j >= 0; j--){
				printf("%d ", station[j]);
			}
			puts("");
			*/
		}
		if(found == 0){
			puts("TAK");
		}else{
			puts("NIE");
		}
	}
	return 0;
}

