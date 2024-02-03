//
// Created by WYR on 2024/2/2.
//

#include "bubbleSort.h"

/* 冒泡法，遍历n轮，每轮发现最大值，第一次[0...n-1)，第二次[0...n-2)
 * 找最大值行为，当前位置和后一个位置进行比较交换
 * */
void bubbleSortV1(SortTable *table) {
    for (int i = 0; i < table->length; ++i) {

        for (int j = 0; j < table->length - i - 1; ++j) {

            if(table->data[j].key > table->data[j + 1].key){
                swapElement(&table->data[j], &table->data[j + 1]);
            }
        }
    }
}

void bubbleSortV2(SortTable *table) {
    for (int i = 0; i < table->length; ++i) {
        int flags = 1;
        for (int j = 0; j < table->length - i - 1; ++j) {

            if(table->data[j].key > table->data[j + 1].key){
                swapElement(&table->data[j], &table->data[j + 1]);
                flags = 0;
            }
        }
        if(flags == 1){
            break;
        }
    }

}
/* 冒泡排序，引入newIndex标记交换的索引位置，下次冒泡的时候结束标志就是newIndex */
void bubbleSortV3(SortTable *table) {
    int newIndex;
    int len = table->length;
    do {
        newIndex = 0;
        for (int i = 0; i < len - 1; ++i) {
            if (table->data[i].key > table->data[i + 1].key) {
                swapElement(&table->data[i], &table->data[i + 1]);
                newIndex = i + 1;
            }
        }
        len = newIndex;
    } while (newIndex > 0);

}
