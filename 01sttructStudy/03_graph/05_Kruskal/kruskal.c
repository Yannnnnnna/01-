//
// Created by WYR on 2024/1/23.
//
#include "string.h"
#include "kruskal.h"
#include "stdlib.h"

int initEdgeSet(MGraph *graph, EdgeSet *edges) {
    int k = 0;
    for (int i = 0; i < graph->nodeNum; ++i) {
        for (int j = i + 1; j < graph->nodeNum ; ++j) {
            if(graph->edges[i][j] > 0){
                edges[k].begin = i;
                edges[k].end = j;
                edges[k].weight = graph->edges[i][j];
                ++k;
            }
        }
    }
    return k;
}


static int getRoot(const int *uSet, int a){
    while (a != uSet[a]){
        a = uSet[a];
    }
    return a;
}
int kruskalMGraph(MGraph *graph, const EdgeSet *edges, int num, EdgeSet *result) {
    int *uSet;
    int a, b;
    int count = 0;
    int sum = 0;
    //1.初始化并查集
    uSet = (int*) malloc(sizeof (int ) * graph->nodeNum);
    for (int i = 0; i < graph->nodeNum; ++i) {
        uSet[i] = i;
    }
    //2.从已经排序好的边集中，找最小的边，当这个边加入后不构成闭环
    for (int i = 0; i < num; ++i) {
        a = getRoot(uSet, edges[i].begin);
        b = getRoot(uSet,edges[i].end);
        if(a != b){         //不构成闭环
            uSet[a] = b;       //a指向了b
            result[count].begin = edges[i].begin;
            result[count].end = edges[i].end;
            result[count].weight = edges[i].weight;
            ++count;
            sum += edges[i].weight;
        }
    }
    free(uSet);
    return sum;
}
//冒泡排序
void sortEdgeSet(EdgeSet *edges, int n) {
    EdgeSet temp;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if(edges[j].weight < edges[i].weight){
                memcpy(&temp, &edges[i], sizeof (EdgeSet));
                memcpy(&edges[i], &edges[j], sizeof (EdgeSet));
                memcpy(&edges[j], &temp, sizeof (EdgeSet));

            }
        }
    }
}
