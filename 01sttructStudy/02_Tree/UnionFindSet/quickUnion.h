//
// Created by WYR on 2023/12/16.
//

#ifndef INC_01STRUCTSTUDY_QUICKUNION_H
#define INC_01STRUCTSTUDY_QUICKUNION_H
/* 基于size的QuickUnion
 * 存储每个元素的关系，就存父的关系
 * 父关系   根关系O(logN)*/
typedef char value_t;
typedef struct {
    value_t *data;				// 数据区的首地址
    int n;						// 限制元素个数的
    int capacity;
    int *parent;				// 存的是对应数据的父节点号
    int *size;					// 如果对应索引位置是根节点，那么就存放这个根为集合的元素个数
}QuickUnionSet;

/* 定义一个链式栈的节点结构，进行路径压缩 */
typedef struct _setNode{
    int index;					// 只保存索引
    struct _setNode *next;
}SetNode;

QuickUnionSet *createQuickUnion(int capacity);
void releaseQuickUnion(QuickUnionSet *unionSet);
// 初始化过程
void initQuickUnion(QuickUnionSet *unionSet, const value_t *data, int n);
// 查
int isSameQuickUnion(QuickUnionSet *unionSet, value_t a, value_t b);
// 并
void unionQuickUnion(QuickUnionSet *unionSet, value_t a, value_t b);

#endif //INC_01STRUCTSTUDY_QUICKUNION_H
