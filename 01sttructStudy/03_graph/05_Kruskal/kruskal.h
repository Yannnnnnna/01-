//
// Created by WYR on 2024/1/23.
//

#ifndef INC_01STRUCTSTUDY_KRUSKAL_H
#define INC_01STRUCTSTUDY_KRUSKAL_H
#include "matrixGraph.h"        //用邻接矩阵来存储信息
#include "commom.h"
// 从邻接矩阵图中初始化边集数组
int initEdgeSet(MGraph *graph, EdgeSet *edges);
// 排序边集数组
void sortEdgeSet(EdgeSet *edges, int n);
// kruskal算法
int kruskalMGraph(MGraph *graph, const EdgeSet *edges, int num, EdgeSet *result);
#endif //INC_01STRUCTSTUDY_KRUSKAL_H
