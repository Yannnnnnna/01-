//
// Created by WYR on 2023/9/22.
//

#include "link_queue.h"

linkQueue *creatQueue() {
    linkQueue *queue = (linkQueue*) malloc(sizeof(linkQueue));
    queue->rear = queue->front = NULL;
    queue->num = 0;
    return  queue;
}

int enLinkQueue(linkQueue *queue, Element val) {
    queue_node *node = (queue_node*) malloc(sizeof(queue_node));
    if(node == NULL){
        printf("malloc error\n");
        return -1;
    }
    node->data = val;
    node->next = NULL;

    if( queue->front){
        queue->rear->next = node;
    } else{
        queue->front = node;
    }

    queue->rear = node;

    ++queue->num;

    return 0;
}

int deLinkQueue(linkQueue *queue, Element *val) {
    if(queue->front == NULL){
        printf("empty queue\n");
        return -1;
    }
    queue_node *p = queue->front;
    *val = p->data;
    queue->front = p->next;
    free(p);
    --queue->num;

    if(queue->front == NULL){
        queue->rear = NULL;
    }
    return 0;
}

void releaseQueue(linkQueue *queue) {
    if(queue){
        queue_node *temp;
        while (queue->front){
            temp = queue->front;
            queue->front = temp->next;
            free(temp);
            --queue->num;
        }
        printf("finish\n");
    }
    free(queue);

}
