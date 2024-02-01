//
// Created by WYR on 2024/1/27.
//
#include "stdlib.h"
#include "stdio.h"
#include "shortPath.h"
/* Dijkstra算法概述：
 * 1. 初始化有向图，由于找最短路径，那么就要找最小值，没有路径的设置为INF(省略)
 * 2. 激活start编号，将这个start点的距离权重存入dist空间
 * 	 2.1 更新path，将start值存入path
 * 3. 寻找未激活节点中，dist距离最小的节点，将其激活
 * 	 3.1 更新dist信息，更新激活mark信息
 * 	 3.2 一旦发现新激活的点，能够发现比目前为止dist距离还要小的，更新dist，同步更新path
 * */

void DijkstraMGraph(const MGraph *graph, int start, int *dist, int *path) {
    int *mark;      //激活空间
    mark = (int *) malloc(sizeof (int ) * graph->nodeNum);
    // 1. 激活start后，节点距离表dist更新，
    //    path中start编号设置为-1， 作为后续打印路径的结束标志
    for (int i = 0; i < graph->nodeNum; ++i) {
        dist[i] = graph->edges[start][i];
        mark[i] = 0;
        if(dist[i] < INF){
            path[i] = start;
        }else{
            path[i] = -1;
        }
    }
    mark[start] = 1;
    path[start] = -1;
    dist[start] = 0;

    // 2. 从dist中查找最小值
    int mini;
    int tempIdx;
    for (int i = 0; i < graph->nodeNum - 1; ++i) {
        mini = INF;
        for (int j = 0; j < graph->nodeNum; ++j) {
            if(mark[j] == 0 && dist[j] < mini){
                mini = dist[j];
                tempIdx = j;
            }
        }
        mark[tempIdx] = 1;
        // 从刚刚激活的节点上更新到其他节点的距离同时更新path
        for (int j = 0; j < graph->nodeNum; ++j) {
            if(mark[j] == 0 && dist[tempIdx] + graph->edges[tempIdx][j] < dist[j]){
                // 到新激活的节点，比原来到的距离要短
                dist[j] = dist[tempIdx] + graph->edges[tempIdx][j];
                path[j] = tempIdx;
            }
        }
    }
    free(mark);
}

void showShortPath(const int *path, int num, int pos) {
    int *stack;
    int top = -1;
    stack = (int *) malloc(sizeof (int ) *num);

    //1.将状态压入栈中
    while (path[pos] != -1){
        //将当前pos编号入栈
        stack[++top] = pos;
        pos = path[pos];
    }
    stack[++top] = pos;
    //2.弹栈
    while (top != -1){
        printf("\t%d", stack[top--]);
    }
    printf("\n");
    free(stack);
}
