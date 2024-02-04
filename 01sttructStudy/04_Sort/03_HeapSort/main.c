//
// Created by WYR on 2024/2/4.
//

#include "heapSort.h"
#include "miniHeap.h"

void test01() {
    int data[] = {9, 3, 7, 6,
                  5, 1, 10, 2};
    int n = 20;
    MiniHeap *miniHeap = creatMiniHeap(n);
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); ++i) {
        insertMiniHeap(miniHeap, data[i]);
    }
    printf("array: ");
    for (int i = 1; i <= miniHeap->len; ++i) {
        printf("\t%d", miniHeap->data[i]);
    }
    printf("\nextra:");
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); ++i) {
        printf("\t%d", extractMiniHeap(miniHeap));
    }
    releaseMiniHeap(miniHeap);
}

void test02() {
    int n = 10000;
    SortTable *table = generateRandomArray(n, 0, n);
    testSort("HeapSort: ", miniHeapSort, table);
    releaseSortTable(table);
}

int main() {
    test02();
    return 0;
}
