//
// Created by WYR on 2024/2/6.
//

#ifndef INC_01DATASTRUCTURE_MERGESORT_H
#define INC_01DATASTRUCTURE_MERGESORT_H
#include "../sortHelper.h"
/* 归并排序
 * 包括“从上到下”和“从下到上”两个过程
 * 从上到下过程：
 * a. 分解 ---	将区间进行一分为二
 * b. 方法 ---	分区间a[low...mid] 和 b[mid+1 ... high]
 * 从下往上过程：
 * a. 将待排序的数列分成了若干长度为1的子数列，然后将这些数据进行两两合并
 * b. 直到合并成原始的区间范围
 * */
void mergeSort(SortTable *table);

#endif //INC_01DATASTRUCTURE_MERGESORT_H
