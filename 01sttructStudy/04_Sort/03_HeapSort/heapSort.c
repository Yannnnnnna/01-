//
// Created by WYR on 2024/2/4.
//

#include "heapSort.h"
#include "miniHeap.h"

void miniHeapSort(SortTable *table) {
    // 申请一个临时的空间
    MiniHeap *heap = creatMiniHeap(table->length);

    //1.从原始表中，将数据填入到堆空间，形成小顶堆
    for (int i = 0; i < table->length; ++i) {
        insertMiniHeap(heap, table->data[i].key);
    }
    // 2.将上述空间逐个提取到原始表中
    for (int i = 0; i < table->length; ++i) {
        table->data[i].key = extractMiniHeap(heap);
    }

    releaseMiniHeap(heap);

}
