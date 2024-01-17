//
// Created by WYR on 2023/9/20.
//

#ifndef INC_01STRUCTSTUDY_ARRAY_STACK_H
#define INC_01STRUCTSTUDY_ARRAY_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"


#define MaxStackSize 	10
// 顺序栈的栈头，一般顺序栈都是固定大小的，不建议扩容
typedef struct {
    treeNode* data[MaxStackSize];				// 栈空间
    int top;								// 栈顶索引，下标
}ArrayStack;

ArrayStack *createArrayStack();
void releaseArrayStack(ArrayStack *stack);

int pushArrayStack(ArrayStack *stack, treeNode *e);
// Element getArrayStack(ArrayStack *stack);				// 只是获取栈顶的元素，栈不变化
// int popArrayStack(ArrayStack *stack);					// 只改变栈，栈顶元素不返回
int popArrayStack(ArrayStack *stack, treeNode **e);			// 栈顶的元素拷贝给上层空间


#endif //INC_01STRUCTSTUDY_ARRAY_STACK_H
