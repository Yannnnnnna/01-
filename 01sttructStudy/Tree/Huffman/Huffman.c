//
// Created by WYR on 2023/12/19.
//

#include "Huffman.h"
#include <stdlib.h>
//在1 - n-1 的范围中，找父节点为0的最小的两个节点
static void selectNode(HuffmanTree tree, int n, int *s1, int* s2){
    int min1 = 0, min2 = 0;
    // 找到第一个父节点为0的编号，假设他为最小值
    for (int i = 1; i <= n; ++i) {
        if (tree[i].parent == 0) {
            min1 = i;
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (tree[i].parent == 0 && i != min1) {
            min2 = i;
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if(tree[i].parent == 0){

            if(tree[i].weight < tree[min1].weight){
                min1 = i;
            }else if(tree[i].weight < tree[min2].weight){
                min2 = i;
            }
        }
    }
    *s1 = min1;
    *s2 = min2;
}
HuffmanTree createHuffmanTree(const int *w, int n) {
    HuffmanTree tree;
    //1.根据总节点数 = 2*n - 1来申请空间
    int m = 2 * n - 1;
    tree = (HuffmanTree) malloc(sizeof (HuffmanNode) * (m + 1));
    //2.初始化1~2n - 1个节点
    for (int i = 0; i <= m; ++i){
        tree[i].parent = tree[i].lChild = tree[i].rChild = 0;
        tree[i].weight = 0;
    }
    //填入初始化的权值
    for (int i = 1; i <= n; ++i) {
        tree[i].weight = w[i - 1];
    }
    //------------------初始化完成，开始构建Huffman树------------------------
    //填充n + 1下标到m下标的空间
    int s1, s2;
    for (int i = n + 1; i <= m; ++i) {
        //找出两个最小的权值节点的索引
        selectNode(tree, i - 1, &s1, &s2);
        //将返回的这两个节点的parent····更新
        tree[s1].parent = tree[s2].parent = i;
        tree[i].lChild = s1;
        tree[i].rChild = s2;
        tree[i].weight = tree[s1].weight + tree[s2].weight;
    }
    return tree;
}

void releaseHuffmanTree(HuffmanTree tree) {
    if(tree)
    free(tree);
}
