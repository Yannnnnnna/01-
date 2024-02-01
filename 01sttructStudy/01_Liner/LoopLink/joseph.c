//
// Created by WYR on 2024/1/19.
//
#include "stdio.h"
#include "stdlib.h"

//��ͷָ��ĵ�ѭ������
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
    //����ѭ��
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
    Node *pre = NULL;       // ���ڵ���ɾ���ڵ��ǰ���ϵ��Ҫ��ǰ�ýڵ�
    Node *cur = game->head;
    //ѭ��ɾ���ڵ㣬ֱ��������ֻʣ��һ����
    while (cur->next != cur){
        //����
        for (int i = 1; i < m; ++i) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        printf("\t%d", cur->data);
        free(cur);
        cur = pre->next;
    }
    printf("\n���ʣ�µ��ˣ�%d\n", cur->data);
}
/*
 * �����Ǽ���Լɪ�򻷵Ĳ��Դ𰸣�����ÿ����ɱ�ߵ�˳���ź������Ҵ���:
 * ��n=5��k=2ʱ����ɱ�ߵ�˳����Ϊ2, 4, 1, 5�������Ҵ�����3��
 * ��n=10��k=3ʱ����ɱ�ߵ�˳����Ϊ3, 6, 9, 2, 7, 1, 8, 5, 10�������Ҵ�����4��
 * ��n=7��k=2ʱ����ɱ�ߵ�˳����Ϊ2, 4, 6, 1, 5, 3�������Ҵ�����7��
 * ��n=10��k=17ʱ�������Ҵ�����3��
 * */
int main(){
    josephHead game = {NULL, NULL};
    initJosephGame(&game, 10);
    showTable(&game);
    printf("\n��Ϸ��ʼ: ");
    startGame(&game, 3);
    return 0;
}