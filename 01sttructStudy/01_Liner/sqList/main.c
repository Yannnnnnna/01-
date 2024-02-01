//
// Created by WYR on 2023/9/9.
//
#include "sqList.h"
int main(){
    sqList * head = creatSqList(5);
    for (int i = 0; i < 5; ++i) {
        push_backSq(head, 10 + i);

    }
    showSqList(head);

    push_backSq(head,70);
    showSqList(head);

    insertSq(head,2, 1000);
    showSqList(head);

    releaseSqList(head);
    return 0;
}