//
// Created by WYR on 2024/2/2.
//

#ifndef INC_01DATASTRUCTURE_QUICKSORT_H
#define INC_01DATASTRUCTURE_QUICKSORT_H
/* 快速排序
 * 1. 在每一轮挑选一个基点，把比这个基点大的元素，放到一边，比它小的放到另外一边
 * 2. 元素就分为两个部分
 * */
#include "../sortHelper.h"
//双边循环法
void quickSortV1(SortTable *table);

// 单边循环法
void quickSortV2(SortTable *table);
#endif //INC_01DATASTRUCTURE_QUICKSORT_H

