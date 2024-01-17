//
// Created by WYR on 2023/9/9.
//


#include "sqList.h"

static int enlargerSq(sqList *head){
    Element *temp = (Element*) malloc(sizeof (Element) * head->capacity * 2);
    if(temp == NULL){
        return -1;
    }
    for (int i = 0; i < head->capacity; ++i) {
        temp[i] = head->data[i];
    }
    head->capacity *= 2;
    free(head->data);
    head->data = temp;
    printf("enlarger\n");
    return 0;
}
sqList *creatSqList(int n){
    sqList *head = (sqList*) malloc(sizeof(sqList));
    if(head == NULL){
        fprintf(stderr,"malloc header failed\n");
        return NULL;
    }

    //初始化表头里的所有数据成员
    head->data = (Element*) malloc(n * sizeof (Element));
    if(head->data == NULL){
        fprintf(stderr, "malloc data failed\n");
        free(head);
        return NULL;

    }
    head->capacity = n;
    head->len= 0;

}

void releaseSqList(sqList *head) {
    free(head->data);
    free(head);
}

int push_backSq(sqList *head, Element val) {
    if((head->len >= head->capacity) && enlargerSq(head)){
        return -1;
    }
    head->data[head->len] = val;
    ++head->len;
    return 0;
}

void showSqList(const sqList *head) {
    for (int i = 0; i < head->len; ++i) {
        printf("%d\t", head->data[i]);
    }
    printf("\n");
}

int insertSq(sqList *head, int pos, Element val) {
    //1.判断插入的位置是否合法
    if(pos < 0 || pos > head->len){
        printf("invalid insert\n");
        return -1;
    }
    //2.判断是否需要扩容
    if((head->len >= head->capacity) && enlargerSq(head)){
        return -1;
    }
    //3.将插入位置之后的元素后移
    for (int i = head->len - 1; i >= pos ; --i) {
        head->data[i+ 1] = head->data[i];

    }
    //4.插入元素
    head->data[pos] = val;
    ++head->len;
    return 0;
}

int findSq(sqList *head, Element val){
    for (int i = 0; i < head->len; ++i) {
        if(head->data[i] == val){
            return i;
        }
    }
    return -1;
}

int deleteSq(sqList *head, Element val) {
    int target = findSq(head, val);
    if(target <0){
        printf("Not Find\n");
        return -1;
    }

    for (int i = target + 1; i <head->len ; ++i) {
        head->data[i -1] = head->data[i];
    }
    --head->len;
    return 0;
}
