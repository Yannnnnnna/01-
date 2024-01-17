//
// Created by WYR on 2023/9/24.
//

#include "binaryTree.h"
#include "array_queue.h"
#include "array_stack.h"

binaryTree *creatBinaryTree() {
    binaryTree  *tree = (binaryTree*) malloc(sizeof(binaryTree));
    if(tree == NULL){
        printf("malloc error\n");
        return NULL;
    }
    tree->root = NULL;
    tree->count = 0;
    return tree;
}
static void  freeTreeNode(treeNode *node){
    if(node){
        freeTreeNode(node->left);
        freeTreeNode(node->right);
        free(node);
    }
}
void releaseBinaryTree(binaryTree *tree){
    if(tree){
        freeTreeNode(tree->root);
    }

}

treeNode *creatTreeNode(Element e) {
    treeNode  *node = (treeNode*) malloc(sizeof(treeNode));
    if (node == NULL){
        printf("malloc error \n");
        return NULL;
    }
    node->data = e;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void binaryTreeInsert(binaryTree *tree, treeNode *parent, treeNode *left, treeNode *right) {
    if(tree && parent){
        parent->left = left;
        parent->right = right;

        if(left){
            ++tree->count;
        }
        if(right){
            ++tree->count;
        }
    }

}

void initBinaryRoot(binaryTree *tree, treeNode *root) {
    if(tree && root){
        tree->root = root;
        ++tree->count;
    }

}

static void preOrder(treeNode *node){
    if(node == NULL){
        return;
    }

    visitTreeNode(node);
    preOrder(node->left);
    preOrder(node->right);
}

void preOrderBinaryTree(binaryTree *tree) {
    preOrder(tree->root);

}

static void inOrder(treeNode *node){
    if(node == NULL){
        return;
    }
    inOrder(node->left);
    visitTreeNode(node);
    inOrder(node->right);
}

void inOrderBinaryTree(binaryTree *tree) {
    inOrder(tree->root);

}

static void postOrder(treeNode *node){
    if(node == NULL){
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    visitTreeNode(node);
}

void postOrderBinaryTree(binaryTree *tree) {
    postOrder(tree->root);

}

void visitTreeNode(treeNode *node) {
    printf("%c\t", node->data);
}

void levelOrderBinaryTree(binaryTree *tree) {
    Queue_t *queue = creat_array_queue();
    treeNode *node;
    enqueue_array(queue, tree->root);
    while (dequeue_array(queue,&node) != -1){
        visitTreeNode(node);
        if(node->left){
            enqueue_array(queue, node->left);
        }
        if(node->right){
            enqueue_array(queue, node->right);
        }
    }
    release_array_queue(queue);

}
/* 非递归的先序遍历，引入栈
 * 1. 先压入根节点到栈
 * 2. 出栈 出任务
 * 3. 打印任务，分配任务的机制，有右先压右，有左再压左 <先右后左>
 * 4. 取任务， 回到2
 * 5. 退出条件：栈空
 * */

void preOrderBTreeNoRecur(binaryTree *tree) {
    if(tree){
        ArrayStack  *stack =  createArrayStack();
        pushArrayStack(stack, tree->root);
        treeNode *node;
        while (popArrayStack(stack, &node) != -1){
            visitTreeNode(node);
            if(node->right){
                pushArrayStack(stack, node->right);
            }
            if(node->left){
                pushArrayStack(stack, node->left);
            }
        }

        releaseArrayStack(stack);
    }

}
/* 非递归的中序遍历
 * 1. 以根节点开始，把整条左边进栈
 * 2. 出栈
 * 3. 处理任务，打印，判断是否在这个任务上，还有新任务
 * 4. 以这个任务的右孩子为新节点，再次执行1
 * 5. 退出 栈为空
 * */
void inOrderBTreeNoRecur(binaryTree *tree){
    if(tree){
        ArrayStack  *stack =  createArrayStack();
        treeNode *node = tree->root;
        while(node || stack->top > 0){
            if(node){
                pushArrayStack(stack, node);
                node= node->left;
            } else {
                popArrayStack(stack, &node);
                visitTreeNode(node);
                node = node->right;
            }
        }

        releaseArrayStack(stack);
    }
}

/* 非递归后序遍历，需要两个栈，第一个栈为辅助栈，第二个栈才是输出栈
 * 第一个栈初始化头结点，弹出到第二个栈，根节点就最后出了
 * 辅助栈要先左后右压，弹出辅助栈的一个元素，放入第二个栈
 * 放入第二个栈的节点 先左后右放入辅助栈
 * 直到辅助栈为空
 * */

void  postOrderBTreeNoRecur(binaryTree *tree){
    if(tree){
        ArrayStack  *stack1 =  createArrayStack();
        ArrayStack *stack2 = createArrayStack();
        pushArrayStack(stack1, tree->root);
        treeNode *node;
        while (popArrayStack(stack1, &node) != -1){
            pushArrayStack(stack2, node);
            if(node->right){
                pushArrayStack(stack1, node->right);
            }
            if(node->left){
                pushArrayStack(stack1, node->left);
            }
        }
        while (popArrayStack(stack2, &node) != -1){
            visitTreeNode(node);
        }

        releaseArrayStack(stack1);
        releaseArrayStack(stack2);
    }
}