//
// Created by WYR on 2024/1/19.
//
#include <stdio.h>
#include "stdlib.h"

/*带头节点的单项循环链表*/
typedef int Element;
typedef struct node{
    Element value;
    struct node *next;
}node;

//单向循环链表的头节点，对链表的结构进行了隐藏
typedef struct {
    node header;    // 含有头节点，插入、删除，有前置节点，算法设计较为容易
    node *rear;     // 指向尾节点，提高了尾插法效率
    int num;        // 牺牲了空间，节约了遍历计数的时间开销
}circularList;

void initTable(circularList *list){
    list->num = 0;
    list->rear = NULL;
    list->header.value = 0x99;
    list->header.next = &list->header;      //循环指向头
}
void insertHead(circularList *list, Element e){
    node *node1 = (node*) malloc(sizeof (node));
    node1->value = e;
    node1->next = list->header.next;
    list->header.next = node1;
    ++list->num;
    if(list->rear == NULL){
        list->rear = node1;
    }
}

void showTable(const circularList *list){
    node *node1 = list->header.next;
    while (node1 != &list->header){
        printf("\t%d", node1->value);
        node1 = node1->next;

    }
}

void releaseTable(circularList *list){
    node *node1 = list->header.next;
    node *temp;
    while (node1 != &list->header){
        temp = node1;
        node1 = node1->next;
        free(temp);
        --list->num;
    }

}

int main(){
    circularList list;
    initTable(&list);

    for (int i = 0; i < 10; ++i) {
        insertHead(&list, i + 100);
    }
    showTable(&list);
    return 0;
}