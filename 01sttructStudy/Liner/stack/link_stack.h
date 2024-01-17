//
// Created by WYR on 2023/9/20.
//

#ifndef INC_01STRUCTSTUDY_LINK_STACK_H
#define INC_01STRUCTSTUDY_LINK_STACK_H

#include <stdlib.h>
#include <stdio.h>

/* 链式栈 */
typedef int Element;
// 定义节点
typedef struct _stack_node {
    Element data;
    struct _stack_node* next;
}stack_node;

// 定义链式栈头
typedef struct {
    stack_node *top;			// 链式栈，只需要保存栈顶指针
    int count;					// 统计栈压入了多少个元素
}LinkStack;

LinkStack *createLinkStack();
void releaseLinkStack(LinkStack *stack);

int pushLinkStack(LinkStack *stack, Element e);
int popLinkStack(LinkStack *stack, Element *e);



#endif //INC_01STRUCTSTUDY_LINK_STACK_H
