#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *accurate = calloc(100, sizeof(char)), test[40];
    scanf("%s\n%s", accurate, test);
    int ac_counter = 0, test_counter = 0, ac_length = strlen(accurate), test_length = strlen(test);

    while(test_counter < test_length){
        if(test[test_counter] == '.'){
            ac_counter++;
            test_counter++;
        }else if(test_counter + 1 < test_length && test[test_counter+1] == '*'){
            for(; accurate[ac_counter] == test[test_counter]; ac_counter++);
            test_counter += 2;
        }else{
            if(test[test_counter] == accurate[ac_counter]){
                test_counter++;
                ac_counter++;
            }else{
                puts("false");
                return 0;
            }
        }
    }
    if(ac_counter < ac_length){
        puts("false");
    }else{
        puts("true");
    }
    return 0;
}