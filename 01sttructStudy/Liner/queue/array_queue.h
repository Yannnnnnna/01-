//
// Created by WYR on 2023/9/21.
//

#ifndef INC_01STRUCTSTUDY_ARRAY_QUEUE_H
#define INC_01STRUCTSTUDY_ARRAY_QUEUE_H

#include <stdio.h>
#include <stdlib.h>


#define MAX_QUEUE_SIZE 5

typedef int Element;

typedef struct {
    Element data[MAX_QUEUE_SIZE];
    int front;
    int rear;
}Queue_t;

Queue_t *creat_array_queue();
void release_array_queue(Queue_t *queue);

int enqueue_array(Queue_t *queue, Element data);
int dequeue_array(Queue_t *queue,Element* data);
#endif //INC_01STRUCTSTUDY_ARRAY_QUEUE_H
