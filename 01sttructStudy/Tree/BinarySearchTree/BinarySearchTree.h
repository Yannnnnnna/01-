//
// Created by WYR on 2023/10/4.
//

#ifndef INC_01STRUCTSTUDY_BINARYSEARCHTREE_H
#define INC_01STRUCTSTUDY_BINARYSEARCHTREE_H
#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct bsNode{
    Element data;
    struct bsNode *left;
    struct bsNode *right;
}bsNode;

typedef struct {
    bsNode *root;
    int count;
}bsTree;

bsTree *creatBSTree();
void releaseBSTree(bsTree* tree);
//递归插入节点
void insertBSTreeRecur(bsTree *tree, Element e);
//查找节点
bsNode *searchBSTree(bsTree *tree, Element e);

//中序遍历
void inOrderBSTree(bsTree *tree);

void visitBSTreeNode(bsNode *node) ;

//删除节点，递归
void deleteBSTreeRecur(bsTree *tree, Element e);

//非递归插入节点
void insertBSTreeNoRecur(bsTree *tree, Element e);
//非递归删除节点
void deleteBSTreeNoRecur(bsTree *tree, Element e);


//计算树的高度
int highOfNode(bsNode *node );

#endif //INC_01STRUCTSTUDY_BINARYSEARCHTREE_H
