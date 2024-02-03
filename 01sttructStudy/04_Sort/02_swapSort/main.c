//
// Created by WYR on 2024/2/2.
//
#include "bubbleSort.h"
#include "quickSort.h"
void test01(){
    int n = 10000;
    SortTable *table1 = generateLinearArray(n, 5);
    SortTable *table2 = copySortTable(table1);
    SortTable *table3 = copySortTable(table1);

    testSort("bubble SortV1: ", bubbleSortV1, table1);
    testSort("bubble SortV2: ", bubbleSortV2, table2);
    testSort("bubble SortV3: ", bubbleSortV3, table3);

    releaseSortTable(table1);
    releaseSortTable(table3);
    releaseSortTable(table2);
}

void test02(){

    int n = 100000;
    SortTable *table1 = generateRandomArray(n, 0, n);
    SortTable *table2 = copySortTable(table1);

    testSort("Quick SortV1: ", quickSortV1, table1);
    testSort("Quick SortV2: ", quickSortV2, table2);


    releaseSortTable(table1);
    releaseSortTable(table2);


}
int main(){
    test02();
    return 0;
}