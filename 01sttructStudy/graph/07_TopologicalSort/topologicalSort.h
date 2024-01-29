//
// Created by WYR on 2024/1/29.
//

#ifndef INC_01STRUCTSTUDY_TOPOLOGICALSORT_H
#define INC_01STRUCTSTUDY_TOPOLOGICALSORT_H

#include "adjacencyList.h"
#include "stdlib.h"

//拓扑排序：
//      通过返回值来判断有向图是否有环
//          0 表示无环
//          1 表示有环
//          -1 表示错误
int topologicalSortGraph(AGraph *graph, int **res, int *len) ;

#endif //INC_01STRUCTSTUDY_TOPOLOGICALSORT_H
