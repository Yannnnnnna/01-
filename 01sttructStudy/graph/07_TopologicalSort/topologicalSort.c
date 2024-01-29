//
// Created by WYR on 2024/1/29.
//

#include "topologicalSort.h"
#include "string.h"
/* 拓扑排序的算法过程：
 * 1. 从有向图中选择一个没有前驱（入度为0）的顶点，输出
 * 2. 删除上一步输出的顶点，从这个顶点出发，遍历他的出度边，每发现一个边，就把inDegree数组对应下标进行减1
 * 3. 重复上面2步
 * 拓扑排序的算法，需要引入一个入度数组
 * */

int topologicalSortGraph(AGraph *graph, int **res, int *len) {
    int *inDegree;
    int count = 0;
    int *result;
    int res_len;

    inDegree = (int*) malloc(sizeof (int ) * graph->nodeNum);
    result = (int *) malloc(sizeof(int ) * graph->nodeNum);

    if(inDegree == NULL){
        return -1;
    }
    memset(inDegree, 0, sizeof (int ) * graph->nodeNum);

    // 1. 更新入度表
    for (int i = 0; i < graph->nodeNum; ++i) {
        if(graph->nodes[i].firstEdge){
            // 引入辅助节点指针
            arcEdge *edge = graph->nodes[i].firstEdge;
            while (edge){
                ++inDegree[edge->num];
                edge = edge->next;
            }
        }
    }

    // 2. 查找入度表里不为0的点
    int *stack;
    int top = -1;
    stack = (int *) malloc(sizeof (int ) * graph->nodeNum);
    if(stack == NULL){
        return -1;
    }

    for (int i = 0; i < graph->nodeNum; ++i) {
        if(inDegree[i] == 0){
            stack[++top] = i;
        }
    }

    //根据栈的数据来弹出节点，弹出节点，就删除对应的边，更新indegree，直到栈空
    int idx;
    while (top != -1){
        idx = stack[top--];
        result[count] = idx;
        ++count;
        //访问
        //visitAGraphNode(&graph->nodes[idx]);
        //更新入度
        arcEdge *edge = graph->nodes[idx].firstEdge;
        while (edge){
            --inDegree[edge->num];
            if(inDegree[edge->num] == 0){
                stack[++top] = edge->num;
            }
            edge = edge->next;
        }
    }

    free(stack);
    free(inDegree);

    *res = result;
    *len = count;

    // 判断是否为有环图
    if(count == graph->nodeNum){
        return 0;
    } else{
        return 1;
    }

}
