#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct info info;
struct info{
    char name[10];
    int from;
    int to;
    int time;
};

int main(){
    info** info_list = malloc(125 * sizeof(info*));
    int* info_list_check = calloc(125, sizeof(int));
    int** info_list_info = malloc(125 * sizeof(int*));
    for(int i = 0; i < 125; i++) info_list_info[i] = calloc(1000, sizeof(int));
    while(1){
        char command;
        scanf("%c", &command);
        if(command == 'E')
            break;
        if(command == 'Q'){
            int q_from, q_to, total_stations = 0;
            scanf("%d %d", &q_from, &q_to);
            for(int i = 0; i < 125; i++){
                if(info_list_check[i] > 0){
                    total_stations += info_list_check[i];
                }
            }
            printf("%d\n", total_stations);
        }else if(command == 'L'){
            char car_name[10];
            int S;
            scanf("%s %d", car_name, &S);
            int car_index = atoi(car_name) == 0 ? car_name[0]+35 : atoi(car_name);
            info_list_check[car_index] = S+1;
            info_list[car_index] = malloc(S * sizeof(info));
            for(int i = 0; i < S; i++){
                scanf("%d %d %d", &info_list[car_index][i].from, &info_list[car_index][i].to, &info_list[car_index][i].time);
                info_list_info[car_index][info_list[car_index][i].from] = 1;
                info_list_info[car_index][info_list[car_index][i].to] = 1;
                strcpy(info_list[car_index][i].name, car_name);
            }
        }
    }
}