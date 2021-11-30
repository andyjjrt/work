#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node;
struct node{
	int value;
	node* next;
	node* base;
};

void piler(int a, int b, node** base, node** prev){
	node* ptrb = base[b] -> base;
	while(ptrb -> next != NULL ){
		ptrb = ptrb -> next;
	}
	node* ptra = base[a] -> base;
	ptrb -> next = base[a] -> base;
	if(prev[a] == NULL){
		base[a] -> next = NULL;
	}else{
		prev[a] -> next = NULL;
	}
	prev[a] = ptrb;
}

void move(node* ptr, node** base, node** prev){
	node* tmp2 = ptr -> next;
	ptr -> next = NULL;
	ptr = tmp2;
	while(ptr != NULL){
		node* tmp = ptr -> next;
		ptr -> next = NULL;
		base[ptr -> value] -> next = ptr;
		prev[ptr -> value] = NULL;
		ptr = tmp;
	}
}

int main() {
	int N;
	while(scanf("%d", &N) != EOF){
		node* base[27];
		node* prev[27];
		int a, b;
		char cmd[20], cmd2[20];
		for(int i = 0; i < N; i++){
			base[i] = malloc(sizeof(node));
			node* tmp = malloc(sizeof(node));
			base[i] -> base = tmp;
			base[i] -> next = tmp;
			base[i] -> value = -1;
			tmp -> value = i;
			tmp -> next = NULL;
			tmp -> base = NULL;
			prev[i] = NULL;
		}
		while(1){
			scanf(" %s", cmd);
			if(strcmp(cmd, "quit") == 0){
				break;
			}
			scanf(" %d %s %d", &a, cmd2, &b);
			if(a == b){
				continue;
			}
			node* tmp = base[a] -> base;
			int samerow = -1;
			while(tmp != NULL){
				if(tmp -> value == b){
					samerow = 0;
					break;
				}
				tmp = tmp -> next;
			}
			if(samerow == 0){
				continue;
			}
			tmp = base[b] -> base;
			samerow = -1;
			while(tmp != NULL){
				if(tmp -> value == a){
					samerow = 0;
					break;
				}
				tmp = tmp -> next;
			}
			if(samerow == 0){
				continue;
			}
			if(strcmp(cmd, "move") == 0){
				if(strcmp(cmd2, "onto") == 0){
					move(base[a] -> base, base, prev);
					move(base[b] -> base, base, prev);
					piler(a, b, base, prev);
				}else if(strcmp(cmd2, "over") == 0){
					move(base[a] -> base, base, prev);
					piler(a, b, base, prev);
				}
			}else if(strcmp(cmd, "pile") == 0){
				if(strcmp(cmd2, "onto") == 0){
					move(base[b] -> base, base, prev);
					piler(a, b, base, prev);
				}else{
					piler(a, b, base, prev);
				}
			}
		}
		
		for(int i = 0; i < N; i++){
			printf("%d: ", i);
			node *ptr = base[i] -> next;
			while(ptr != NULL){
				printf("%d ", ptr -> value);
				ptr = ptr -> next;
			}
			puts("");
		}
	}
	return 0;
}
