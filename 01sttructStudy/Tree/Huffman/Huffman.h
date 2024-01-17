//
// Created by WYR on 2023/12/19.
//

#ifndef INC_01STRUCTSTUDY_HUFFMAN_H
#define INC_01STRUCTSTUDY_HUFFMAN_H
/* Huffman树的表示形式
 * 1. 采用顺序存储
 * 因为n个元素(叶子节点)，那么构造Huffman树所需要的总节点个数为2n-1个
 * 数组0号单元，不建议使用，需要用0号索引表示非法状态，代表没有左右孩子（叶子），没有父（根）
 * */
typedef struct {
    int weight;				// 节点的权值
    int lChild, rChild;		// 该节点的左右孩子编号
    int parent;				// 该节点的父节点编号
}HuffmanNode, *HuffmanTree;

// 传入权值，返回一个已经是Huffman的特性的树结构
HuffmanTree createHuffmanTree(const int *w, int n);
void releaseHuffmanTree(HuffmanTree tree);

// 有了这棵树，产生n个数据(叶子)的编码
// 用字符串来存储1和0的值（用bit来存储），方便打印，用字符串来存储
typedef char *HuffmanCode;
HuffmanCode *createHuffmanCode(HuffmanTree tree, int n);
void releaseHuffmanCode(HuffmanCode *codes, int n);

#endif //INC_01STRUCTSTUDY_HUFFMAN_H
