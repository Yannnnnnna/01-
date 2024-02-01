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

