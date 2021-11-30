#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}


int* full_atoi(int* ptr, int* length){
    char* del = " ";
    char* pch = strtok((char*)ptr,del);
    int* int_array = malloc(5000 * sizeof(int));
    while (pch != NULL){
        int tmp = atoi(pch);
        int_array[*length] = tmp;
        *length += 1;
        pch = strtok (NULL, del);
    }
    free(ptr);
    qsort(int_array, *length, sizeof(int), cmp);
    int* final_array = malloc(5000 * sizeof(int));
    int final_size = 1;
    int checker = int_array[0];
    final_array[0] = int_array[0];
    for(int i = 1; i < *length; i++){
        if(checker != int_array[i]){
            final_array[final_size] = int_array[i];
            final_size ++;
            checker = int_array[i];
        }
    }
    free(int_array);
    *length = final_size;
    return final_array;
}

int main() {
    int N;
    scanf("%d\n", &N);
    int *array_ptr, *tmp_ptr;
    int *ans, ans_length = 0;
    for(int i = 0; i < N; i++){
        int tmp_length = 0;
        tmp_ptr = malloc(60000 * sizeof(char));
        gets(tmp_ptr);
        tmp_ptr = full_atoi(tmp_ptr, &tmp_length);
        if(i == 0){
            ans = tmp_ptr;
            ans_length = tmp_length;
        }else{
            int *tmp2 = malloc(5000 * sizeof(int));
            int tmp2_lenght = 0;
            for(int j=0, k = 0; j < ans_length && k < tmp_length;){
                //printf("%d %d\n", ans[j], tmp_ptr[k]);
                if(ans[j] > tmp_ptr[k]){
                    k++;
                }else if(ans[j] < tmp_ptr[k]){
                    j++;
                }else{
                    tmp2[tmp2_lenght] = ans[j];
                    tmp2_lenght ++;
                    j++;
                    k++;
                }
            }
            free(ans);
            ans = tmp2;
            ans_length = tmp2_lenght;
        }
    }

    for(int i = 0; i < ans_length; i++){
        printf("%d ", ans[i]);
    }
    puts("");

    return 0;
}
