//
// Created by WYR on 2024/2/4.
//

#include "miniHeap.h"
#include "stdlib.h"
#include "string.h"
MiniHeap *creatMiniHeap(int n) {

    MiniHeap *heap = (MiniHeap*) malloc(sizeof(MiniHeap));
    heap->capacity = n;
    heap->data = (keyType*) malloc(sizeof (keyType) * (n + 1));
    memset(heap->data, 0, sizeof (keyType) * (n + 1));
    heap->len = 0;
    return heap;
}

void releaseMiniHeap(MiniHeap *heap) {
    if(heap){
        if(heap->data){
            free(heap->data);
        }
        free(heap);
    }
}
static void shiftUp(MiniHeap *heap, int k){
    keyType temp;
    while (k > 1 && heap->data[k /2] > heap->data[k]){

        temp = heap->data[k /2];
        heap->data[k /2] = heap->data[k];
        heap->data[k] = temp;
        k /= 2;


    }
}
void insertMiniHeap(MiniHeap *heap, keyType e) {
    //判断空间是否满
    if(heap->len + 1 >heap->capacity){
        return;
    }
    // 1. len的位置插入
    heap->data[++heap->len] = e;
    // 2. 上移操作
    shiftUp(heap, heap->len);
}
static void shiftDown(MiniHeap *heap, int k){
    keyType temp;
    while (k * 2 <= heap->len){
        //有左孩子
        int index = 2 * k;
        // 判断是否有右孩子同时是否小于当前值
        if(index + 1 <= heap->len && heap->data[index + 1] < heap->data[index]){
            index += 1;
        }
        // 如果当前值已经小于左右孩子的最小值，退出
        if(heap->data[k] <= heap->data[index]){
            break;
        }
        temp = heap->data[index];
        heap->data[index] = heap->data[k];
        heap->data[k] = temp;

        k = index;


    }
}
keyType extractMiniHeap(MiniHeap *heap) {
    //1.取出最小元素
    keyType temp = heap->data[1];
    // 2.将最后一个元素替换到根元素
    heap->data[1] = heap->data[heap->len];
    --heap->len;
    //3.下沉
    shiftDown(heap, 1);

    return temp;
}
