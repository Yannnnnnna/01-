//
// Created by WYR on 2023/10/3.
//

#ifndef INC_01STRUCTSTUDY_THREADBTREE_H
#define INC_01STRUCTSTUDY_THREADBTREE_H

#include <stdio.h>
#include <stdlib.h>
typedef int Element;
//线索二叉树的节点结构
typedef struct treeNode{
    Element data;
    struct treeNode *left;
    struct treeNode *right;
    int lTag;       //0表示left指向左节点，1表示left指向前驱
    int rTag;       //0表示right指向右节点，1表示right指向后继
}treeNode;

typedef struct {
    treeNode *root;
    int count;
    int tag;    //0：线索化未完成   2：线索化完成
}threadBTree;

threadBTree *creatThreadBTree(treeNode *root);
void releaseThreadBTree(threadBTree *tree);
 treeNode *creatThreadNode(Element e);

 void insertThreadBTree(threadBTree *tree, treeNode *parent,treeNode *left, treeNode *right);
 void visitThreadNode(treeNode *node);


 void inOrderThreadTree(threadBTree *tree);
 void inOrderTree(threadBTree *tree);
#endif //INC_01STRUCTSTUDY_THREADBTREE_H
