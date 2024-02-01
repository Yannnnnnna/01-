//
// Created by WYR on 2024/2/1.
//
#include "insertSort.h"

int main(){
    int n = 10000;
    SortTable *table1 = generateRandomArray(n, 0, n);
    SortTable *table2 = generateLinearArray(n, 5);

    testSort("Random insertSort: ", insertSortV1, table1);
    testSort("Random insertSort: ", insertSortV1, table2);


    releaseSortTable(table1);

    return 0;
}