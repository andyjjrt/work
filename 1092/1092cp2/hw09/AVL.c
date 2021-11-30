#include <stdio.h>
#include <stdlib.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

typedef struct AVL AVL;
struct AVL{
    int key;
    int height;
    AVL* left;
    AVL* right;
};
int height(AVL* node){
    if(node){
        return node->height;
    }
    return 0;
}
AVL* L_L(AVL* node){  //LL旋轉
    AVL* tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    tmp->height = max(height(tmp->left), height(tmp->right)) + 1;
    return tmp;
}
AVL* R_R(AVL* node){  //RR旋轉
    AVL* tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    tmp->height = max(height(tmp->left), height(tmp->right)) + 1;
    return tmp;
}
AVL* R_L(AVL* node){  //RL旋轉
    node->right = L_L(node->right);
    return R_R(node);
}
AVL* L_R(AVL* node){  //LR旋轉
    node->left = R_R(node->left);
    return L_L(node);
}

void output(AVL* this_node){
    if(this_node == NULL){
        return;
    }
    output(this_node->left);
    printf("%d ",this_node->key);
    output(this_node->right);
}

AVL* push_AVL(AVL *curr, int num){
    if(curr == NULL){
        AVL* new_node = malloc(sizeof(AVL));
        new_node->key = num;
        new_node->height = 1;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }else if(num > curr->key){
        curr->right = push_AVL(curr->right, num);
        if(height(curr->left) - height(curr->right) == 2){
            if(height(curr->left->left) > height(curr->left->right)){
                curr = L_L(curr);
            }else{
                curr = L_R(curr);
            }
        }
    }else if(num < curr->key){
        curr->left = push_AVL(curr->left, num);
        if(height(curr->right) - height(curr->left) == 2){
            if(height(curr->right->left) > height(curr->right->right)){
                curr = R_L(curr);
            }else{
                curr = R_R(curr);
            }
        }
    }
    return curr;
}
int findAVL(AVL *curr, int target){
    if(curr == NULL){
        return -2147483647;
    }
    if(curr->key > target){
        return findAVL(curr->right, target) + 1;
    }else if(curr->key < target){
        return findAVL(curr->left, target) + 1;
    }else{
        return 1;
    }
}

int main() {
    int N, M;
    scanf("%d", &N);
    AVL* AVLTree = NULL;
    while(scanf("%d", &M) != EOF){
        AVLTree = push_AVL(AVLTree, M);
    }
    int steps;
}
