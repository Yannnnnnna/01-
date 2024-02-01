//
// Created by WYR on 2023/11/25.
//

#include "AVLTree.h"
//====================旋转操作==================
//获取树的高度
static  int h(AVL_Node* node){
    if(node == NULL){
        return 0;
    }
    return node->height;
}
//返回两数中的最大值
static int maxNum(int a, int b){
    return a > b ? a : b;
}
/* 左旋操作
 *     px
 *     |
 *     x
 *   /  \
 * lx    y
 *      / \
 *     ly ry
 * */
static AVL_Node *leftRotate(AVL_Node *x){
    AVL_Node *y = x->right;
    x->right = y->left;
    y->left = x;
    //更新x y的高度
    x->height = maxNum(h(x->left), h(x->right)) + 1;
    y->height = maxNum(h(y->left), h(y->right)) + 1;

    return y;
}

/* 右旋操作
 *       py
 *       |
 *       y
 *     /  \
 *    x   ry
 *   / \
 * lx  rx
 * */
static AVL_Node *rightRotate(AVL_Node *y){
    AVL_Node *x = y->left;
    y->left = x->right;
    x->right = y;
    //更新x y的高度(那个在下面先更新哪个)
    y->height = maxNum(h(y->left), h(y->right)) + 1;
    x->height = maxNum(h(x->left), h(x->right)) + 1;


}
//====================旋转操作==================


//***********插入操作***************
//获取平衡因子
static int getBalance(AVL_Node *node){
    if(node == NULL){
        return 0;
    }
    //高度一定为左减右
    return h(node->left) - h(node->right);
}
//创建新节点
static AVL_Node *creatAVLNode(Element e){
    AVL_Node *node = (AVL_Node*) malloc(sizeof(AVL_Node));
    if(node == NULL){
        printf("malloc failed\n");
        return NULL;

    }
    node->e = e;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}
/* 向平衡二叉树插入元素e:
 * 1. 按照二叉搜索树的规则，递进去到空位置，创建新节点，归回来
 * 2. 在归的过程中，更新节点的高度，计算平衡因子
 * 3. 一旦发现失衡节点，判断类型进行旋转
 * */
static AVL_Node *insertAVLNode(AVL_Tree *tree, AVL_Node*node, Element e){
    //1.判断归的条件，是否触发归的过程
    if(node == NULL){
        ++tree->count;
        return creatAVLNode(e);
    }
    //递任务（任务拆分，左小右大）
    if(e < node->e){
        node->left = insertAVLNode(tree,node->left,e);
    }else if(e > node->e){
        node->right = insertAVLNode(tree, node->right, e);
    }else{
        return node;
    }
    //2.更新归中每个节点的高度
    node->height = maxNum(h(node->left), h(node->right)) + 1;
    //3.计算当前节点的平衡因子
    int balance = getBalance(node);
    if(balance > 1){       //左边高度大
        //L? ---->LL ---->右旋
        if(e > node->left->e){     //LR
            node->left = leftRotate(node->left);
        }
        return rightRotate(node);
    }else if(balance < -1){
        //R?
        if(e < node->right->e){
            //RL
            node->right = rightRotate(node->right);
        }
        return leftRotate(node);
    }
    return node;
}

void insertAVLTree(AVL_Tree *tree, Element e){
    if(tree){
        tree->root = insertAVLNode(tree, tree->root, e);
    }
}
//***********插入操作***************
//***********创建和释放树***********
AVL_Tree *creatAVLTree() {
    AVL_Tree *tree = (AVL_Tree*) malloc(sizeof (AVL_Tree));
    tree->root = NULL;
    tree->count = 0;
    return tree;
}
static void  freeNode(AVL_Tree *tree, AVL_Node *node){
    if(node){
        freeNode(tree, node->right);
        freeNode(tree, node->left);
        free(node);
        --tree->count;
    }

}
void releaseAVLTree(AVL_Tree *tree) {
    if(tree){
        freeNode(tree, tree->root);
        printf("AVL 02_Tree have %d node\n", tree->count);
    }

}
//***********创建和释放树***********
//***********中序遍历树*************
static void visitAVLNode(AVL_Node *node){
    if(node){
        printf("\t<%d:%d>", node->e, node->height);
    }
}
static void inOrderAVLNode(AVL_Node *node){
    if(node){
        inOrderAVLNode(node->left);
        visitAVLNode(node);
        inOrderAVLNode(node->right);
    }

}
void inOrderAVLTree(AVL_Tree *tree) {
    if(tree){
        inOrderAVLNode(tree->root);
        printf("\n");
    }
}
//***********中序遍历树*************
//***********获取树的高度*************
int heightOfAVLTree(AVL_Node *node) {
    if(node == NULL){
        return 0;
    }
    int leftHeight = heightOfAVLTree(node->left);
    int rightHeight = heightOfAVLTree(node->right);
    if(leftHeight > rightHeight){
        return ++leftHeight;
    }else{
        return ++rightHeight;
    }
}
//***********获取树的高度*************
//***********删除节点*****************
/* - 归
 * 	边界条件：
 * 		找不到，
 * 		找到了（度为0或1），才能归，
 * 		度为2，矛盾转移
 * */

static AVL_Node *deleteAVLNode(AVL_Tree *tree, AVL_Node  *node, Element  e){
    //设置归的条件，当找不到e时，返回空
    if(node == NULL){
        return NULL;
    }
    AVL_Node *temp;
    //1.寻找e
    if(e < node->e){
        node->left = deleteAVLNode(tree, node->left, e);
    }else if(e > node->e){
        node->right = deleteAVLNode(tree, node->right, e);
    } else{
        //找到e节点，根据度的情况，进行删除或转移矛盾
        if(node->left == NULL || node->right == NULL){
            temp = node->left ? node->left : node->right;
            if(temp == NULL){   //度为0
                free(node);
                --tree->count;
                return NULL;
             }else{     //度为1
                free(node);
                --tree->count;
                return temp;
            }

        }else{      //度为2   找前驱节点，左边的最右边
            temp = node->left;
            while (temp->right){
                temp = temp ->right;
            }
            node->e = temp->e;
            node->left = deleteAVLNode(tree, node->left, temp->e);
        }
        //更新node的高度
        node->height = maxNum(h(node->left), h(node->right)) + 1;
        int balance = getBalance(node);
        if(balance > 1){
            if(getBalance(node->left) > 0){
                node->left = leftRotate(node->left);
            }
            return rightRotate(node);
        } else if(getBalance(node->right) > 0){
            node->right = rightRotate(node->right);
        }
        return leftRotate(node);
    }
    return node;
}
/* 1. 按照二分搜索树的规则，递归找到元素e节点（拆分问题的过程终止条件）
 * 2. 判断节点是否度为0或1，删除节点（递的过程，拆分问题的过程终止条件处理完成）如果度为2，替换节点，转移矛盾
 * 3. 一旦节点删除完成，开始归的过程，计算归过程中每个节点的平衡因子，进行调整
 * */
void deleteAVLTree(AVL_Tree *tree, Element e) {
    if(tree){
       tree->root = deleteAVLNode(tree,tree->root, e);
    }
}
//***********删除节点************