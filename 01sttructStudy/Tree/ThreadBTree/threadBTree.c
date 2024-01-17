//
// Created by WYR on 2023/10/3.
//

#include "threadBTree.h"
static treeNode *pre = NULL;
static void inOrderThreading(treeNode *node){
    if(node){
        inOrderThreading(node->left);
        //visitThreadNode(node);
        if(node->left == NULL){
            node->left = pre;
            node->lTag = 1;
        }
        if(pre && pre->right == NULL){
            pre->right = node;
            pre->rTag = 1;
        }
        pre = node;
        inOrderThreading(node->right);
    }
}
void inOrderThreadTree(threadBTree *tree) {
    if(tree){
        inOrderThreading(tree->root);
        tree->tag = 2;
    }
}

void inOrderTree(threadBTree *tree) {
    if(tree->tag == 2){
        treeNode  *node = tree->root;
        while (node){
            while (node->lTag  == 0){
                node = node->left;
            }
            visitThreadNode(node);
            while (node->rTag && node->right){
                node = node->right;
                visitThreadNode(node);
            }
            node = node->right;
        }

    }

}

static void freeTreeNode(threadBTree  *tree,treeNode *node){
    if(node){
        if(node->lTag == 0){
            freeTreeNode(tree, node->left);
        }
        if(node->rTag == 0){
            freeTreeNode(tree, node->right);
        }
        free(node);
        --tree->count;
    }
}
void releaseThreadBTree(threadBTree *tree) {
    if(tree){
        freeTreeNode(tree->root);
    }

}
