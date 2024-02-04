//
// Created by WYR on 2024/2/4.
//

#ifndef INC_01DATASTRUCTURE_MINIHEAP_H
#define INC_01DATASTRUCTURE_MINIHEAP_H
#include "../sortHelper.h"
//堆排序
// 定义小顶堆的结构
typedef struct {
    keyType *data;
    int len;            //用于约束data的长度
    int capacity;       //最大容量
}MiniHeap;

MiniHeap *creatMiniHeap(int n);     // 产生n个元素
void releaseMiniHeap(MiniHeap *heap);

// 插入
void insertMiniHeap(MiniHeap *heap, keyType e);
//提取
keyType extractMiniHeap(MiniHeap *heap);
#endif //INC_01DATASTRUCTURE_MINIHEAP_H
