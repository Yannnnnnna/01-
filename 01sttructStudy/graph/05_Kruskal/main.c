//
// Created by WYR on 2024/1/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "Kruskal.h"

void setupMGraph(MGraph *graph, int initValue) {
    char *names[] = {
            "A", "B", "C", "D",
            "E", "F", "G",
    };
    initMGraph(graph, names, sizeof(names) / sizeof(names[0]),
               0, initValue);
    addMGraphEdge(graph, 0, 1, 12);
    addMGraphEdge(graph, 0, 5, 16);
    addMGraphEdge(graph, 0, 6, 14);
    addMGraphEdge(graph, 1, 2, 10);
    addMGraphEdge(graph, 1, 5, 7);
    addMGraphEdge(graph, 2, 3, 3);
    addMGraphEdge(graph, 2, 4, 5);
    addMGraphEdge(graph, 2, 5, 6);
    addMGraphEdge(graph, 3, 4, 4);
    addMGraphEdge(graph, 4, 5, 2);
    addMGraphEdge(graph, 4, 6, 8);
    addMGraphEdge(graph, 5, 6, 9);
}

void test01() {
    MGraph graph;
    EdgeSet *edges;
    int num;
    EdgeSet *result;
    int sum;
    setupMGraph(&graph, 0);
    // 构建边集数组，先申请好空间
    edges = (EdgeSet *) malloc(sizeof(EdgeSet) * graph.edgeNum);
    num = initEdgeSet(&graph, edges);
    printf("edge set num: %d\n", num);
    sortEdgeSet(edges, num);

    result = malloc(sizeof(EdgeSet) * (graph.nodeNum - 1));
    sum = kruskalMGraph(&graph, edges, num, result);
    printf("sum = %d\n", sum);
    for (int i = 0; i < graph.nodeNum - 1; ++i) {
        printf("edge %d: [%s] --- <%d> --- [%s]\n", i + 1,
               graph.vex[result[i].begin].show, result[i].weight, graph.vex[result[i].end].show);
    }
    free(edges);
    free(result);
}

int main() {
    test01();
}
