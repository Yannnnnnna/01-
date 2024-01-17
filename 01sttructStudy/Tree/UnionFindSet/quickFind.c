//
// Created by WYR on 2023/12/13.
//
#include <stdlib.h>
#include "quickFind.h"

QuickFindSet *creatQuickFindSet(int capacity) {
    QuickFindSet *findSet = (QuickFindSet*)malloc(sizeof(QuickFindSet));
    findSet->data = (Element*) malloc(sizeof (Element) * capacity);
    findSet->groupID = (int * ) malloc(sizeof(int) * capacity);
    findSet->capacity = capacity;

    return findSet;
}

void releaseQuickFindSet(QuickFindSet *findSet) {
    if (findSet){
        free(findSet->data);
        free(findSet->groupID);
        free(findSet);
    }
}

void initQuickFindSet(QuickFindSet *findSet, const Element *data, int n) {
    if (findSet){
        for (int i = 0; i < n; ++i) {
            findSet->data[i] = data[i];
            findSet->groupID[i] = i;
        }
        findSet->n = n;
    }
}
static int findIndex(QuickFindSet *findSet, Element e){
    for (int i = 0; i < findSet->n; ++i) {
        if(findSet->data[i] == e){
            return i;
        }
    }
    return -1;
}
int isSameQuickFindSet(QuickFindSet *findSet, Element a, Element b) {
    //找到a，b的索引
    int aIndex = findIndex(findSet, a);
    int bIndex = findIndex(findSet, b);
    if(aIndex == -1 || bIndex == -1){
        return 0;
    }
    //根据索引，去ID空间里找两个元素的编号，判断是否相等
    return findSet->groupID[aIndex] == findSet->groupID[bIndex];
}

void unionQuickFindSet(QuickFindSet *findSet, Element a, Element b) {
    //找到对应的老大的信息
    int aIndex = findIndex(findSet, a);
    int bIndex = findIndex(findSet, b);

    int gID = findSet->groupID[bIndex];
    //把b的老大管的人都合并到a的老大
    for (int i = 0; i < findSet->n; ++i) {
        if (findSet->groupID[i] == gID){
            findSet->groupID[i] = findSet->groupID[aIndex];
        }
    }
}
