//
// Created by WYR on 2023/12/16.
//
#include <stdlib.h>
#include "quickUnion.h"

QuickUnionSet *createQuickUnion(int capacity) {
    QuickUnionSet *unionSet = (QuickUnionSet*) malloc(sizeof (QuickUnionSet));
   unionSet->data = (value_t*) malloc(sizeof(value_t) *capacity);
    unionSet->parent = (int*) malloc(sizeof (int ) * capacity);
    unionSet->size = (int*) malloc(sizeof (int )* capacity);
    unionSet->capacity = capacity;
    unionSet->n = 0;
    return unionSet;
}

void releaseQuickUnion(QuickUnionSet *unionSet) {
    if(unionSet){
        free(unionSet->data);
        free(unionSet->parent);
        free(unionSet->size);
        free(unionSet);
    }
}

void initQuickUnion(QuickUnionSet *unionSet, const value_t *data, int n) {
    for (int i = 0; i < n; ++i) {
        //初始化data的值
        unionSet->data[i] = data[i];
        //初始化每个集合的元素，目前就是他自己
        unionSet->size[i] = 1;
        //目前父亲也是他自己
        unionSet->parent[i] = i;
    }
    unionSet->n = n;
}
static int findIndex(QuickUnionSet *unionSet, value_t data){
    for (int i = 0; i < unionSet->n; ++i) {
        if(unionSet->data[i] == data){
            return i;
        }
    }
    return -1;
}
#define PATH_COMPRESS
#ifndef PATH_COMPRESS
/*采用普通方法查找根*/
static int findRootIndex(QuickUnionSet *unionSet, value_t e){
    //先找到目前e的索引
    int curIndex = findIndex(unionSet, e);
    if(curIndex == -1){
        return -1;
    }
    //不断向上递归直到找到,父节点就是自己
    while (unionSet->parent[curIndex] != curIndex){
        curIndex = unionSet->parent[curIndex];
    }
    return curIndex;
}
#else
static SetNode *pop(SetNode *top, int *index){
    SetNode *temp = top;
    *index = top->index;
    top = top->next;
    free(temp);
    return top;
}
static SetNode *push(SetNode *top, int index){
    SetNode *node = (SetNode*) malloc(sizeof (SetNode));
    node->index = index;
    node->next = top;
    return node;
}
static int findRootIndex(QuickUnionSet *unionSet, value_t e) {
    //先找到目前e的索引
    int curIndex = findIndex(unionSet, e);
    if (curIndex == -1) {
        return -1;
    }
    //创建一个临时栈
    SetNode  *path = NULL;
    //向上遍历，直到父节点就是自己
    while (unionSet->parent[curIndex] != curIndex){
        //将路径上的节点索引号压入到栈
        path = push(path, curIndex);
        curIndex = unionSet->parent[curIndex];
    }
    //出栈，将所有出栈的节点都指向根节点
    while (path){
        int pos;
        path = pop(path, &pos);
        unionSet->parent[pos] = curIndex;
    }
    return curIndex;
}
#endif

int isSameQuickUnion(QuickUnionSet *unionSet, value_t a, value_t b) {
    int aRoot = findRootIndex(unionSet, a);
    int bRoot = findRootIndex(unionSet, b);
    if(aRoot == -1 || bRoot == -1){
        return 0;
    }
    return aRoot == bRoot;
}
/* 1. 找a的根和b的根
 * 2. 根据size的情况，谁的元素多，谁就作为根（不变），元素少的集合的根就放弃根属性，变为指向父节点
 * */

void unionQuickUnion(QuickUnionSet *unionSet, value_t a, value_t b) {
    int aRoot = findRootIndex(unionSet, a);
    int bRoot = findRootIndex(unionSet, b);
    if(aRoot == -1 || bRoot == -1){
        return ;
    }
    if(aRoot != bRoot){
        int aSize = unionSet->size[aRoot];
        int bSize = unionSet->size[bRoot];

        if(aSize >= bSize){
            unionSet->parent[bRoot] = aRoot;
            unionSet->size[aRoot] += bSize;
        }else{
            unionSet->parent[aRoot] =bRoot;
            unionSet->size[bRoot] += aSize;
        }
    }
}
