//
// Created by WYR on 2023/9/20.
//

#include "link_stack.h"

LinkStack *createLinkStack() {
    LinkStack *head = (LinkStack*) malloc(sizeof(LinkStack) );
    if(head == NULL){
        printf("malloc failed\n");
        return NULL;
    }
    head->top = NULL;
    head->count = 0;
    return head;
}

void releaseLinkStack(LinkStack *stack) {
    if(stack){
        while (stack->top){
            stack_node *temp = stack->top;
            stack->top = temp->next;
            free(temp);
            --stack->count;
        }
        printf("finish\n");
    }
}

int pushLinkStack(LinkStack *stack, Element e) {
    stack_node  *new_node = (stack_node*) malloc(sizeof (stack_node));
    if(new_node == NULL){
        printf("malloc error\n");
        return -1;
    }
    new_node->data = e;
    new_node->next = stack->top;
    stack->top = new_node;
    ++stack->count;
    return 0;
}

int popLinkStack(LinkStack *stack, Element *e) {
    if (stack->top == NULL) {
        printf("No element!\n");
        return -1;
    }

    stack_node * temp = stack->top;
    *e = temp->data;
    stack->top = temp->next;
    free(temp);
    --stack->count;
    return 0;
}
