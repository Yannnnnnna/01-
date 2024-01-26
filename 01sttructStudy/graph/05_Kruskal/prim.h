//
// Created by WYR on 2024/1/26.
//

#ifndef INC_01STRUCTSTUDY_PRIM_H
#define INC_01STRUCTSTUDY_PRIM_H

#include "matrixGraph.h"
#include "commom.h"
/* graph 邻接矩阵存储的图
 * result 边集数组，最小生成树的边结果
 * startV 随机选择的第一个激活顶点编号
 * return 最小生成树的权值
 * */
int PrimMGraph(MGraph *graph,int startV,  EdgeSet *result);

#endif //INC_01STRUCTSTUDY_PRIM_H
