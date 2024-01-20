//
// Created by WYR on 2024/1/19.
//
#include "stdio.h"
#include "stdlib.h"

//带头指针的单循环链表
typedef struct node{
    int data;
    struct node* next;
}Node;

typedef struct {
    Node *tail;
    Node *head;
}josephHead;

void initJosephGame(josephHead *game, int n){
    Node *node;
    for (int i = 1; i <= n; ++i) {
        node = (Node*) malloc(sizeof (Node));
        node->data = i;
        node->next = NULL;
        if(game->head == NULL){
            game->head = node;
            game->tail = node;
        }else{
            game->tail->next = node;
            game->tail = node;
        }
    }
    //构建循环
    game->tail->next = game->head;
}

void showTable(josephHead *game){
    Node *node = game->head;
    do {
        printf("\t%d", node->data);
        node = node->next;
    } while (node != game->head);
}
void startGame(josephHead *game, int m){
    Node *pre = NULL;       // 便于调整删除节点的前后关系，要有前置节点
    Node *cur = game->head;
    //循环删除节点，直到链表里只剩下一个人
    while (cur->next != cur){
        //计数
        for (int i = 1; i < m; ++i) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        printf("\t%d", cur->data);
        free(cur);
        cur = pre->next;
    }
    printf("\n最后剩下的人：%d\n", cur->data);
}
/*
 * 以下是几组约瑟夫环的测试答案，包括每个被杀者的顺序编号和最后的幸存者:
 * 当n=5，k=2时，被杀者的顺序编号为2, 4, 1, 5，最后的幸存者是3。
 * 当n=10，k=3时，被杀者的顺序编号为3, 6, 9, 2, 7, 1, 8, 5, 10，最后的幸存者是4。
 * 当n=7，k=2时，被杀者的顺序编号为2, 4, 6, 1, 5, 3，最后的幸存者是7。
 * 当n=10，k=17时，最后的幸存者是3。
 * */
int main(){
    josephHead game = {NULL, NULL};
    initJosephGame(&game, 10);
    showTable(&game);
    printf("\n游戏开始: ");
    startGame(&game, 3);
    return 0;
}