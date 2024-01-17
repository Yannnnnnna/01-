//
// Created by WYR on 2023/12/19.
//
#include <stdio.h>
#include "Huffman.h"

int main() {
    int w[] = {5, 29, 7, 8, 14, 23, 3, 11};
    char show[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int len = sizeof(w) / sizeof(w[0]);
    HuffmanTree tree = createHuffmanTree(w, sizeof(w) / sizeof(w[0]));
     for (int i = 0; i <= 2*len - 1; ++i) {
     	printf("%d, %d, %d, %d\n", tree[i].weight, tree[i].parent, tree[i].lChild, tree[i].rChild);
     }
//     打印编码
//    HuffmanCode *code = createHuffmanCode(tree, len);
//    for (int i = 0; i < len; ++i) {
//        printf("%c : %s\n", show[i], code[i]);
//    }
//    releaseHuffmanCode(code, len);
    releaseHuffmanTree(tree);

    return 0;
}

