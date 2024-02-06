//
// Created by WYR on 2024/2/6.
//
#include "mergeSort.h"

int main() {
    int n = 10000;
    SortTable *table = generateRandomArray(n, 0, n);
    testSort("MergeSort: ", mergeSort, table);
    releaseSortTable(table);
}
