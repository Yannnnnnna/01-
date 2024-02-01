//
// Created by WYR on 2023/10/4.
//
#include "BinarySearchTree.h"

void test01() {
    Element array[] = {55,33,45,100,22,80,8,130,120};
    bsTree *tree = creatBSTree();
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
        insertBSTreeRecur(tree, array[i]);
    }
    printf("inOrder:");
    inOrderBSTree(tree);
    printf("\ndelete\n");
    deleteBSTreeRecur(tree,100);
    inOrderBSTree(tree);
    releaseBSTree(tree);
}
void test02(){
    Element array[] = {55,33,45,100,22,80,8,130,120,121,122};
    bsTree *tree = creatBSTree();
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
        insertBSTreeNoRecur(tree, array[i]);
    }
    printf("inOrder:");
    inOrderBSTree(tree);

    printf("\nheight  of  tree:\t");
    printf("%d\t", highOfNode(tree->root));

    releaseBSTree(tree);
}

void test03(){
    Element array[] = {55,33,45,100,22,80,8,130,120,121,122};
    bsTree *tree = creatBSTree();
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
        insertBSTreeNoRecur(tree, array[i]);
    }
    printf("inOrder:");
    inOrderBSTree(tree);

    printf("\ndelete  tree:\n");
    deleteBSTreeNoRecur(tree,100);

    printf("inOrder:");
    inOrderBSTree(tree);

    releaseBSTree(tree);
}

int main() {
    test03();
    return 0;
}
