//
// Created by WYR on 2024/1/21.
//
#include "CrossLinkGraph.h"
#include "stdlib.h"
#include "stdio.h"

void setupGraph(CrossGraph *graph) {
    char *nodes[] = {"V0", "V1", "V2", "v3"};
    initCrossGraph(graph, nodes, sizeof(nodes) / sizeof(nodes[0]));
    addCrossArc(graph, 0, 3, 1);
    addCrossArc(graph, 1, 0, 1);
    addCrossArc(graph, 1, 2, 1);
    addCrossArc(graph, 2, 1, 1);
    addCrossArc(graph, 2, 0, 1);
}


int main() {
    int n = 4;
    CrossGraph *graph = creatCrossGraph(n);
    setupGraph(graph);
    printf("V0 inDegree: %d\n", inDegreeCrossGraph(graph, 0));
    printf("V0 outDegree: %d\n", outDegreeCrossGraph(graph, 0));
   releaseCrossGraph(graph);
    return 0;
}
