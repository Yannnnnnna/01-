//
// Created by WYR on 2023/9/21.
//

#include "array_queue.h"
#include <string.h>

Queue_t *creat_array_queue() {
    Queue_t  *queue = (Queue_t*) malloc(sizeof (Queue_t));
    if(queue == NULL){
        printf("malloc error\n");
        return NULL;
    }
    memset(queue, 0, sizeof (Queue_t));
    queue->rear = queue->front = 0;
    return queue;

}

void release_array_queue(Queue_t *queue) {
    if(queue){
        free(queue);
    }

}

int enqueue_array(Queue_t *queue, treeNode *data) {
    if((queue->rear + 1) % MAX_QUEUE_SIZE == queue->front){
        printf("overflow\n");
        return -1;
    }
    queue->data[queue->rear] = data;
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    return 0;
}

int dequeue_array(Queue_t *queue, treeNode **data) {
    if(queue->rear == queue->front){
        printf("under flow\n");
        return -1;
    }
    if(data){
        *data =  queue->data[queue->front];
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;

    }
    return 0;
}
