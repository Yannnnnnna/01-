//
// Created by WYR on 2023/9/24.
//

#include <stdio.h>
#include <stdlib.h>

#ifndef INC_01STRUCTSTUDY_BINARYTREE_H
#define INC_01STRUCTSTUDY_BINARYTREE_H

typedef int Element;

//节点结构
typedef struct treeNode{
    Element data;
    struct treeNode *left;
    struct treeNode *right;

}treeNode;

//树头
typedef struct {
    //二叉树头节点
    treeNode *root;
    //二叉树的节点个数
    int count;
}binaryTree;

binaryTree *creatBinaryTree();
void initBinaryRoot(binaryTree *tree, treeNode *root);
void releaseBinaryTree(binaryTree *tree);
treeNode *creatTreeNode(Element e);
void binaryTreeInsert(binaryTree *tree, treeNode *parent, treeNode * left, treeNode* right);
void visitTreeNode(treeNode *node);

//递归深度遍历
//先序
void preOrderBinaryTree(binaryTree *tree);
//中序
void inOrderBinaryTree(binaryTree *tree);
//末序
void postOrderBinaryTree(binaryTree *tree);


//广度遍历
void levelOrderBinaryTree(binaryTree *tree);

//非递归深度遍历
//先序
void preOrderBTreeNoRecur(binaryTree *tree);
//中序
void inOrderBTreeNoRecur(binaryTree *tree);
//后序
void  postOrderBTreeNoRecur(binaryTree *tree);

#endif //INC_01STRUCTSTUDY_BINARYTREE_H
