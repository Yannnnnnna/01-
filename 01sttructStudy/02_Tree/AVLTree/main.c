//
// Created by WYR on 2023/11/25.
//
#include "AVLTree.h"

int main(){
    Element data[] = {10, 20, 30, 40, 50, 60, 68, 80, 25, 7, 55};
    AVL_Tree *tree = creatAVLTree();
    for (int i = 0; i < sizeof(data)/ sizeof(data[0]); ++i) {
        insertAVLTree(tree, data[i]);
    }
    printf("inOrder: ");
    inOrderAVLTree(tree);
    printf("Height: %d\n", heightOfAVLTree(tree->root));


    deleteAVLTree(tree, 40);
    printf("inOrder: ");
    inOrderAVLTree(tree);
    printf("Height: %d\n", heightOfAVLTree(tree->root));
    releaseAVLTree(tree);
    return 0;
}