//
// Created by WYR on 2023/9/21.
//

#include "array_queue.h"
#include "link_queue.h"
void test01(){
    Queue_t *queue = creat_array_queue();
    Element e;
    for (int i = 0; i < 5; ++i) {
        enqueue_array(queue, i+100);
    }
    enqueue_array(queue, 10000);
    while (dequeue_array(queue, &e) != -1){
        printf("%d\t", e);
    }
    printf("\n");
}

void test02(){
     linkQueue *queue = creatQueue();
    Element e;
    for (int i = 0; i < 6; ++i) {
        enLinkQueue(queue,i+100);
    }
    printf("=======================================\n");

    while (deLinkQueue(queue, &e) != -1){
        printf("%d\t", e);
    }
    printf("\n");
    releaseQueue(queue);
}

int main(){
    test02();
    return 0;
}