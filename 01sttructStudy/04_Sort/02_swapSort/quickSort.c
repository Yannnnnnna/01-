//
// Created by WYR on 2024/2/2.
//
#include <time.h>
#include "quickSort.h"
static int partitionDouble(SortTable *table, int startIndex, int endIndex){
    int pivot = startIndex;
    srand(time(NULL) + 1);
    swapElement(&table->data[startIndex], &table->data[rand() % (endIndex - startIndex) + startIndex]);
    int left = startIndex;
    int right = endIndex;
    while (left !=right){
        while (left < right && table->data[right].key > table->data[pivot].key)  right--;
        while (left < right && table->data[left].key <= table->data[pivot].key)  left++;
        if(left < right){
            swapElement(&table->data[left], &table->data[right]);
        }
    }
    //将基点放入left 或者 right
    swapElement(&table->data[pivot], & table->data[left]);
    return left;
}
static void quickSort1(SortTable *table, int startIndex, int endIndex){
    if(startIndex >= endIndex){
        return;
    }
    int pivot = partitionDouble(table, startIndex, endIndex);
    quickSort1(table, startIndex, pivot - 1);
    quickSort1(table, pivot + 1, endIndex);
}
void quickSortV1(SortTable *table) {
    quickSort1(table, 0,table->length - 1);

}
/* 单边循环法
 * 1. 从基准元素的下一个位置开始遍历数组
 * 2. 如果遍历过程中，发现大于基准点，就继续
 * 3. 如果遍历过程中，发现小于基准点
 * 		3.1 把mark标记的点++
 * 		3.2 交换
 * 4. 把mark和基准点交换
 * */
static int partitionSingle(SortTable *table, int startIndex, int endIndex){
    keyType value = table->data[startIndex].key;
    int mark = startIndex;
    for (int i = startIndex + 1; i <= endIndex; ++i) {
        if(table->data[i].key < value){
            ++mark;
            swapElement(&table->data[mark], &table->data[i]);
        }
    }
    swapElement(&table->data[mark], &table->data[startIndex]);
    return mark;
}
static void quickSort2(SortTable *table, int startIndex, int endIndex){
    if(startIndex >= endIndex){
        return;
    }
    int pivot = partitionSingle(table, startIndex, endIndex);
    quickSort2(table, startIndex, pivot - 1);
    quickSort2(table, pivot + 1, endIndex);
}
void quickSortV2(SortTable *table) {
    quickSort2(table, 0, table->length - 1);
}
