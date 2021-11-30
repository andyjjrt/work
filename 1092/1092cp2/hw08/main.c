#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_stack(char stack[100][15], int* stack_height){
    printf("=h:%d=\n", *stack_height);
    for(int i = *stack_height-1; i >= 0; i--){
        printf("%s\n", stack[i]);
    }
    puts("=======");
}
void push_stack(char stack[100][15], int* stack_height, char inputs[15]){
    strcpy(stack[*stack_height], inputs);
    *stack_height += 1;
    //print_stack(stack, stack_height);
}
char* pop_stack(char stack[100][15], int* stack_height){
    *stack_height -= 1;
    //print_stack(stack, stack_height);
    return stack[*stack_height];
}
int priority(char* a){
    if(strcmp(a, "*") == 0 || strcmp(a, "/") == 0){
        return 2;
    }else if(strcmp(a, "+") == 0 || strcmp(a, "-") == 0){
        return 1;
    }
    return -1;
}
int my_atoi(char* str){
    int a;
    if(str[0] = '-'){
        a = atoi(str+1);
    }else{
        a = atoi(str);
    }
    printf("=%d=\n", a);
    return a;
}

int main() {
    char input[200];
    char pre_oper[100][15];
    char postfix[100][15];
    char post_stack[100][15];
    int ans[100];

    int pre_position = 0;
    int tmp_position = 0;
    int post_position = 0;
    int stack_position = 0;
    int ans_position = 0;

    scanf("%s", input);
    for(int i = 0; input[i] != '\0'; i++){
        if(input[i] == '+' || input[i] == '*' || input[i] == '/' || input[i] == '(' || input[i] == ')' || (input[i] == '-' && (i != 0 && input[i-1] != '('))){
            if(tmp_position != 0){
                pre_oper[pre_position][tmp_position] = '\0';
                tmp_position = 0;
                pre_position++;
            }
            pre_oper[pre_position][0] = input[i];
            pre_oper[pre_position][1] = '\0';
            pre_position++;
        }else{
            pre_oper[pre_position][tmp_position] = input[i];
            tmp_position++;
        }
    }
    if(tmp_position != 0){
        pre_oper[pre_position][tmp_position] = '\0';
        tmp_position = 0;
        pre_position++;
    }

    for(int i = 0; i < pre_position; i++){
        //printf("current: %s\n", pre_oper[i]);
        if(strcmp(pre_oper[i],"(") == 0){
            push_stack(post_stack, &stack_position, "(");
        }else if(strcmp(pre_oper[i],")") == 0){
            while(1){
                char* tmp;
                tmp = pop_stack(post_stack, &stack_position);
                if(tmp[0] == '('){
                    //puts("break");
                    break;
                }
                //printf("%s\n", tmp);
                strcpy(postfix[post_position],tmp);
                post_position++;
            }
        }else if(strcmp(pre_oper[i],"+") == 0 || strcmp(pre_oper[i],"-") == 0 || strcmp(pre_oper[i],"*") == 0 || strcmp(pre_oper[i],"/") == 0){
            if(stack_position == 0){
                push_stack(post_stack, &stack_position, pre_oper[i]);
            }else{
                if(priority(pre_oper[i]) > priority(post_stack[stack_position])){
                    push_stack(post_stack, &stack_position, pre_oper[i]);
                }else{
                    char* tmp;
                    while(priority(pre_oper[i]) <= priority(post_stack[stack_position]) && stack_position > 0){
                        tmp = pop_stack(post_stack, &stack_position);
                        strcpy(postfix[post_position],tmp);
                        post_position++;
                    }
                }
            }
        }else{
            strcpy(postfix[post_position],pre_oper[i]);
            post_position++;
        }
    }
    char* tmp;
    while(stack_position >= 0){
        tmp = pop_stack(post_stack, &stack_position);
        strcpy(postfix[post_position],tmp);
        post_position++;
    }

    for(int i = 0; i < post_position; i++){
        printf("%s ", postfix[i]);
    }
    puts("");
}
 