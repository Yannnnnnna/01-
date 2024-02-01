//
// Created by WYR on 2023/9/12.
//

#include "LinkList.h"

linkHeader *creatLink() {
    linkHeader *head;
    head = (linkHeader *) malloc(sizeof (linkHeader));
    if(head == NULL){
        return NULL;
    }
    head->num = 0;
    head->header.next = NULL;
    head->header.data = 0;
    return head;
}

void releaseLink(linkHeader *header) {
    if(header){
        if(header->header.next){
            linkNode *p = header->header.next;
            while (p){
                linkNode *q = p->next;
                free(p);
                p = q;
                --header->num;
            }

        }
        free(header);
    }

}

int headInsert_01(linkHeader *head, Element data) {
    linkNode  *p = &head->header;
    linkNode *new_node = (linkNode*) malloc(sizeof (linkNode));
    if(new_node == NULL){
        printf("空间分配出错\n");
        return -1;
    }
    new_node->data = data;
    new_node->next = p->next;
    p->next = new_node;
    ++head->num;

    return 0;
}

void show_headLink(linkHeader *header) {
    linkNode *p = header->header.next;
    while (p){
        printf("%d\t", p->data);
        p = p->next;

    }
    printf("\n显示完成\n");

}

int delete_headLink(linkHeader *header, Element data) {
    linkNode  *p = &header->header;

    while (p->next){
        if(p->next->data == data){
            break;
        }
        p = p->next;
    }
    if(p->next){
        linkNode  * q =p->next;
        p->next = q->next;
        free(q);
        --header->num;
    }else{
        printf("没有找到\n");
        return -1;
    }

    return 0;
}

int header_insert(linkHeader *header, int pos, Element val) {
    //判断位置是否合法
    if(pos < 0 || pos > header->num){
        printf("插入位置不合法\n");
        return -1;
    }
    //查找插入位置
    int index = -1;
    linkNode  *p = &header->header;
    while (p && index < pos -1){

        p = p->next;
        ++index;

    }

    if(p == NULL){
        printf("出错！\n");
        return -1;
    }

    //插入元素
    linkNode *newNode = (linkNode*) malloc(sizeof (linkNode));
    if(newNode == NULL){
        printf("分配空间出错\n");
        return -1;
    }
    newNode->data = val;
    newNode->next = p->next;
    p->next = newNode;
    ++header->num;

    return 0;
}
