//
// Created by WYR on 2023/9/22.
//

#ifndef INC_01STRUCTSTUDY_LINK_QUEUE_H
#define INC_01STRUCTSTUDY_LINK_QUEUE_H

typedef int Element;

#include <stdio.h>
#include <stdlib.h>

typedef struct queue_node{
    Element data;
    struct queue_node *next;
}queue_node;

typedef struct {
    queue_node *front;
    queue_node *rear;
    int num;
}linkQueue;

linkQueue *creatQueue();
void releaseQueue(linkQueue *queue);

int enLinkQueue(linkQueue* queue, Element val);
int deLinkQueue(linkQueue*queue, Element* val);


#endif //INC_01STRUCTSTUDY_LINK_QUEUE_H
