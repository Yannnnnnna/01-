//
// Created by WYR on 2023/9/12.
//
#include "LinkList.h"
int main(){
    linkHeader *head = creatLink();
    if(head == NULL){
        return -1;
    }

    for (int i = 0; i < 5; ++i) {
        headInsert_01(head, 100+ i);
    }

    show_headLink(head);

    delete_headLink(head,103);
    show_headLink(head);

    header_insert(head,1,300);
    show_headLink(head);

    releaseLink(head);


    return 0;
}