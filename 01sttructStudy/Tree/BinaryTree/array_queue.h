//
// Created by WYR on 2023/9/21.
//

#ifndef INC_01STRUCTSTUDY_ARRAY_QUEUE_H
#define INC_01STRUCTSTUDY_ARRAY_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

#define MAX_QUEUE_SIZE 10



typedef struct {
    treeNode *data[MAX_QUEUE_SIZE];
    int front;
    int rear;
}Queue_t;

Queue_t *creat_array_queue();
void release_array_queue(Queue_t *queue);

int enqueue_array(Queue_t *queue, treeNode *data);
int dequeue_array(Queue_t *queue,treeNode  **data);
#endif //INC_01STRUCTSTUDY_ARRAY_QUEUE_H
