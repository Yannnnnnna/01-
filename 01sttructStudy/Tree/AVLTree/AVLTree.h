//
// Created by WYR on 2023/11/25.
//

#ifndef INC_01STRUCTSTUDY_AVLTREE_H
#define INC_01STRUCTSTUDY_AVLTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int Element;
//树节点
 typedef struct AVL_Node{
     Element e;
     struct AVL_Node *left;
     struct AVL_Node *right;
     int height;    //引入高度属性来计算平衡因子
 }AVL_Node;

 //树头节点
 typedef struct {
     AVL_Node *root;
     int count;
 }AVL_Tree;

 AVL_Tree *creatAVLTree();
 void  releaseAVLTree(AVL_Tree *tree);
 void inOrderAVLTree(AVL_Tree *tree);
 int heightOfAVLTree(AVL_Node *node);

 //插入元素到树
 void insertAVLTree(AVL_Tree *tree, Element e);
 void deleteAVLTree(AVL_Tree *tree, Element e);
#endif //INC_01STRUCTSTUDY_AVLTREE_H
