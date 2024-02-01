//
// Created by WYR on 2023/9/20.
//

#include "array_stack.h"

ArrayStack *createArrayStack() {
    ArrayStack *arrayStack = (ArrayStack*) malloc(sizeof (ArrayStack));
    arrayStack->top = 0;

    return arrayStack;
}

void releaseArrayStack(ArrayStack *stack) {
    if(stack)
    free(stack);

}

int pushArrayStack(ArrayStack *stack, treeNode *e) {
    if(stack->top + 1 >= MaxStackSize){
        printf("over flow\n");
        return -1;
    }
    stack->data[stack->top++] = e;
    return 0;
}

int popArrayStack(ArrayStack *stack, treeNode **e) {
    if(stack->top <=  0){
        printf("under flow\n");
        return -1;
    }
    *e = stack->data[--stack->top];

    return 0;
}


