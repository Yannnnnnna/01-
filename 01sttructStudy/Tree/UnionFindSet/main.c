//
// Created by WYR on 2023/12/13.
//
#include "quickFind.h"
#include <stdio.h>
#include "quickUnion.h"

void test01() {
    QuickFindSet *findSet = creatQuickFindSet(16);
    Element data[9];
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); ++i) {
        data[i] = '0' + i;
    }
    initQuickFindSet(findSet, data, sizeof(data) / sizeof(data[0]));

    unionQuickFindSet(findSet, '3', '4');
    unionQuickFindSet(findSet, '8', '0');
    unionQuickFindSet(findSet, '2', '3');
    unionQuickFindSet(findSet, '5', '6');
    if (isSameQuickFindSet(findSet, '0', '2')) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    if (isSameQuickFindSet(findSet, '2', '4')) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    unionQuickFindSet(findSet, '5', '1');
    unionQuickFindSet(findSet, '7', '3');
    unionQuickFindSet(findSet, '1', '6');
    unionQuickFindSet(findSet, '4', '8');
    if (isSameQuickFindSet(findSet, '0', '2')) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    if (isSameQuickFindSet(findSet, '2', '4')) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    releaseQuickFindSet(findSet);
}

void test02(){
    QuickUnionSet *findSet = createQuickUnion(16);
    value_t data[9];
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); ++i) {
        data[i] = '0' + i;
    }
    initQuickUnion(findSet, data, sizeof(data) / sizeof(data[0]));

    unionQuickUnion(findSet, '3', '4');
    unionQuickUnion(findSet, '8', '0');
    unionQuickUnion(findSet, '2', '3');
    unionQuickUnion(findSet, '5', '6');
    if (isSameQuickUnion(findSet, '0', '2')) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    if (isSameQuickUnion(findSet, '2', '4')) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    unionQuickUnion(findSet, '5', '1');
    unionQuickUnion(findSet, '7', '3');
    unionQuickUnion(findSet, '1', '6');
    unionQuickUnion(findSet, '4', '8');
    if (isSameQuickUnion(findSet, '0', '2')) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    if (isSameQuickUnion(findSet, '2', '4')) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    releaseQuickUnion(findSet);

}
int main(){
    test02();
    return 0;
}