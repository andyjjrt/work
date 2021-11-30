#include <stdio.h>

int main() {
    char array[30] = {'#'};
    int cnt = 0, length = 0;
    scanf("%s", array);
    for(int i = 0; array[i] != '\0'; length++, i++){
        if(array[i] == '('){
            cnt++;
        }else if(array[i] == ')'){
            if(cnt != 0){
                cnt--;
            }else{
                array[i] = '#';
            }
        }
    }
    //printf("%s\n", array);
    cnt = 0;
    for(int i = length; i >= 0; i--){
        if(array[i] == ')'){
            cnt++;
        }else if(array[i] == '('){
            if(cnt != 0){
                cnt--;
            }else{
                array[i] = '#';
            }
        }
    }
    //printf("%s\n", array);
    for(int i = 0; array[i] != '\0'; i++){
        if(array[i] != '#'){
            printf("%c", array[i]);
        }
    }
    puts("");
    return 0;
}
