#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>  
#include <assert.h>

int main(){
    char *target = calloc(100, sizeof(char)), pattern[40];
    scanf("%s\n%s", target, pattern);
    regex_t preg;
    int success = regcomp(&preg, pattern, REG_EXTENDED|REG_ICASE);
    assert(success==0);

    regmatch_t matchptr[1];
    const size_t nmatch = 1;
    int status = regexec(&preg, target, nmatch, matchptr, 0);
    if (status == REG_NOMATCH){
        printf("false\n");
    }
    else if (status == 0){
        if(strlen(target) == matchptr[0].rm_eo - matchptr[0].rm_so){
            printf("true\n");
        }else{
            printf("false\n");
        }
    }
    else {
        char msgbuf[256];
        regerror(status, &preg, msgbuf, sizeof(msgbuf)); 
        printf("error: %s\n", msgbuf);
    }

    regfree(&preg); 
    return 0;
}