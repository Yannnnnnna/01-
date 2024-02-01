//
// Created by WYR on 2024/1/21.
//

#include "CrossLinkGraph.h"
#include "stdlib.h"
#include "stdio.h"

CrossGraph *creatCrossGraph(int n) {
    CrossGraph *graph = (CrossGraph*) malloc(sizeof (CrossGraph));
    graph->nodes = (CrossVertex*) malloc(sizeof (CrossVertex) * n);
    graph->numEdge = 0;
    graph->numVertex = n;
    return graph;
}

void initCrossGraph(CrossGraph *graph, char **names, int num) {
    for (int i = 0; i < num; ++i) {
        graph->nodes[i].node = i;
        graph->nodes[i].show = names[i];
        graph->nodes[i].firstIn = graph->nodes[i].firstOut = NULL;
    }
}

/* 添加边的逻辑
 * 1. 创造边
 * 2. 修正链表和这个边next的关系（头插法）
 * */

void addCrossArc(CrossGraph *graph, int tail, int head, int weight) {
    ArcBox *box = (ArcBox*) malloc(sizeof (ArcBox));
    box->weight = weight;
    // 使用头插法处理出度的关系
    box->tailVertex = tail;
    box->tailNext = graph->nodes[tail].firstOut;
    graph->nodes[tail].firstOut = box;
    // 使用头插法处理入度的关系
    box->headVertex = head;
    box->headNext = graph->nodes[head].firstIn;
    graph->nodes[head].firstIn = box;

    ++graph->numEdge;

}

int outDegreeCrossGraph(CrossGraph *graph, int node) {
    int count = 0;
    ArcBox *box = graph->nodes[node].firstOut;
    while (box){
        ++count;
        box = box->tailNext;
    }
    return count;
}

int inDegreeCrossGraph(CrossGraph *graph, int node) {
    int count = 0;
    ArcBox *box = graph->nodes[node].firstIn;
    while (box){
        ++count;
        box = box->headNext;
    }
    return count;
}

void releaseCrossGraph(CrossGraph *graph) {
    if(graph){
        if(graph->nodes){
            for (int i = 0; i < graph->numVertex; ++i) {
                ArcBox *box = graph->nodes[i].firstOut;
                ArcBox *temp;
                while (box){
                    temp = box;
                    box = box->tailNext;
                    free(temp);
                }

            }
        }
        free(graph->nodes);
    }
    free(graph);
}
