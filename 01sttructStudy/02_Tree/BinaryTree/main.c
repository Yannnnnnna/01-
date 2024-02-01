//
// Created by WYR on 2023/9/24.
//

#include "binaryTree.h"

// 初始化一棵树
binaryTree *initTree01() {
    binaryTree *tree = creatBinaryTree();

    treeNode *nodeA = creatTreeNode('A');
    treeNode *nodeB = creatTreeNode('B');
    treeNode *nodeC = creatTreeNode('C');
    treeNode *nodeD = creatTreeNode('D');
    treeNode *nodeE = creatTreeNode('E');
    treeNode *nodeF = creatTreeNode('F');
    treeNode *nodeG = creatTreeNode('G');
    treeNode *nodeH = creatTreeNode('H');
    treeNode *nodeK = creatTreeNode('K');

    initBinaryRoot(tree, nodeA);
    binaryTreeInsert(tree, nodeA, nodeB, nodeE);
    binaryTreeInsert(tree, nodeB, NULL, nodeC);
    binaryTreeInsert(tree, nodeE, NULL, nodeF);
    binaryTreeInsert(tree, nodeC, nodeD, NULL);
    binaryTreeInsert(tree, nodeF, nodeG, NULL);
    binaryTreeInsert(tree, nodeG, nodeH, nodeK);

    return tree;
}
void test01() {
    binaryTree *tree01 = initTree01();
//    printf("\npreOrder:\t");
//    preOrderBinaryTree(tree01);
//    printf("\ninOrder:\t");
//    inOrderBinaryTree(tree01);
    printf("\npostOrder:\t");
    postOrderBinaryTree(tree01);
//    printf("\nlevelOrder\t");
//    levelOrderBinaryTree(tree01);

//printf("\npredNoRecur:\t");
//    preOrderBTreeNoRecur(tree01);
//    printf("\ninNoRecur:\t");
//    inOrderBTreeNoRecur(tree01);
    printf("\npostNoRecur:\t");
    postOrderBTreeNoRecur(tree01);
    releaseBinaryTree(tree01);
}

int main() {
    test01();
}