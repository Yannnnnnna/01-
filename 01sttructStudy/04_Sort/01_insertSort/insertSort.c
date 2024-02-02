//
// Created by WYR on 2024/2/1.
//
#include "insertSort.h"

void insertSortV1(SortTable *table) {
    for (int i = 0; i < table->length; ++i) {
        Element e = table->data[i];
        int j;
        for (j = i; j > 0 && e.key < table->data[j - 1].key; --j) {
            //swapElement(&table->data[j], &table->data[j - 1]);
            table->data[j] = table->data[j - 1];    //覆盖

        }
        table->data[j] = e;
    }
}

void shellSort(SortTable *table) {
    //按照gap进行分类
    for (int gap = table->length / 2; gap > 0 ; gap /= 2) {
        //每组都进行插入排序
        for (int i = gap; i < table->length; ++i) {
            Element temp = table->data[i];
            int j;
            for (j = i; j >= gap
                && (table->data[j - gap].key > temp.key); j -= gap) {
                swapElement(&table->data[j], &table->data[j - gap]);
            }
            table->data[j] = temp;
        }
    }
}

