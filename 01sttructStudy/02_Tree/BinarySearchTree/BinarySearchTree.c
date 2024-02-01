//
// Created by WYR on 2023/10/4.
//

#include "BinarySearchTree.h"

bsTree *creatBSTree() {
    bsTree  *tree = (bsTree*) malloc(sizeof (bsTree));
    if(tree == NULL){
        return NULL;
    }
    tree->root = NULL;
    tree->count = 0;
    return tree;
}
static void releaseBSTreeNode(bsNode *node){
    if(node){
        releaseBSTreeNode(node->left);
        releaseBSTreeNode(node->right);
        free(node);
    }
}
void releaseBSTree(bsTree *tree) {
    if(tree){
        releaseBSTreeNode(tree->root);
        printf("\nfree\n");
    }

}
static bsNode *creatBSTreeNode(Element e){
    bsNode *node = (bsNode*) malloc(sizeof(bsNode));
    if(node == NULL){
        printf("node malloc error\n");
        return NULL;
    }
    node->right = node->left = NULL;
    node->data = e;
    return node;
}

static bsNode *insertBSNodeRecur(bsTree *tree, bsNode *node, Element e){
    if(node == NULL){
        ++tree->count;
        return creatBSTreeNode(e);
    }
    if(e < node->data){
        node->left = insertBSNodeRecur(tree, node->left, e);
    } else if(e > node->data){
        node->right = insertBSNodeRecur(tree, node->right, e);
    }
    return node;
}

void insertBSTreeRecur(bsTree *tree, Element e) {
    if(tree){
        tree->root = insertBSNodeRecur(tree,tree->root, e);
    }

}
static void inOrderBSNode(bsNode *node){
    if(node){
        inOrderBSNode(node->left);
        visitBSTreeNode(node);
        inOrderBSNode(node->right);
    }
}
void inOrderBSTree(bsTree *tree) {
    if(tree){
        inOrderBSNode(tree->root);
    }
}

void visitBSTreeNode(bsNode *node) {
    if(node){
        printf("\t%d", node->data);
    }

}

bsNode *searchBSTree(bsTree *tree, Element e) {
    bsNode *node = tree->root;
    while (node){
        if(node->data < e){
            node = node->left;
        } else if(node->data > e){
            node = node->right;
        } else{
            return node;
        }
    }
    return NULL;
}
static bsNode * minValueBSNode(bsNode *node){
    while (node && node->left){
        node = node->left;
    }
    return node;
}
static bsNode * deleteBSNodeRecur(bsTree *tree, bsNode *node, Element e){
    if(node == NULL){
        return NULL;
    }
    if(e < node->data){
        node->left = deleteBSNodeRecur(tree, node->left, e);
    } else if(e > node->data){
        node->right = deleteBSNodeRecur(tree, node->right, e);
    } else{
        bsNode *temp;
        if(node->left == NULL){
            temp = node->right;
            free(node);
            --tree->count;
            return temp;
        }
        if(node->right == NULL){
            temp = node->left;
            free(node);
            --tree->count;
            return temp;
        }
        temp = minValueBSNode(node->right);
        node->data = temp->data;
        node->right = deleteBSNodeRecur(tree, node->right, temp->data);
    }
    return node;
}
void deleteBSTreeRecur(bsTree *tree, Element e) {
    if(tree){
        tree->root = deleteBSNodeRecur(tree,tree->root, e);
    }
}

void insertBSTreeNoRecur(bsTree *tree, Element e) {
    bsNode  *pre = NULL;
    bsNode *cur = tree->root;
    while (cur){
        pre = cur;
        if(e > cur->data){
            cur = cur->right;
        }else if(e < cur->data){
            cur = cur->left;
        } else{
            return;
        }
    }
    bsNode  *node = creatBSTreeNode(e);
    if( pre){

        if(e > pre->data){
            pre->right = node;
        } else{
            pre->left = node;
        }
    } else{
        tree->root = node;
    }
    ++tree->count;
}

int highOfNode(bsNode *node) {
    if(node ==  NULL){
        return 0;
    }
    int leftHeight = highOfNode(node->left);
    int rightHeight = highOfNode(node->right);
    return (leftHeight >rightHeight) ? (++leftHeight):(++rightHeight);
}

void deleteMiniNode(bsNode *node){
    bsNode *pre = node;
    bsNode *mini = node->right;
    //找最左边
    while (mini && mini->left){
        pre = mini;
        mini = mini->left;
    }
    //判断是否有最左边
    if(pre->data == node->data){
        //没有左边
        pre->right = mini->right;
    } else{
        //有左边
        pre->left = mini->right;
    }
    node->data = mini->data;
    free(mini);
}

void deleteBSTreeNoRecur(bsTree *tree, Element e) {
    //找要删除的节点
    bsNode  *node  = tree->root;
    bsNode  *pre = NULL;
    while (node){
        if(node->data > e){
            pre = node;
            node = node->left;
        } else if(node->data < e){
            pre = node;
            node = node->right;
        }else{
            break;
        }
    }

    //分类删除节点
    //非root
    bsNode *temp = NULL;
    if(node && pre){

        if(pre->left == NULL){
            temp = pre->right;
        } else if(pre->right == NULL){
            temp = pre->left;
        }else{
            //度为二的删除
            deleteMiniNode(node);
            --tree->count;
            return;
        }
        if(pre->right == NULL){
            pre->left = temp;
        } else if(pre->left == NULL){
            pre->right = temp;
        }
        free(node);
        --tree->count;
        return;
    }
    //root
    if(node && pre == NULL){
        if(node->left == NULL){
            temp = node->right;

        } else if(node->right == NULL){
            temp = node->left;

        }
        else{
            //度为二的删除
            deleteMiniNode(node);
            --tree->count;
            return;
        }
        tree->root = temp;
        free(node);
        --tree->count;
    }


}
