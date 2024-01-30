//
// Created by WYR on 2024/1/30.
//
#include "keyRoad.h"
#include "stdio.h"

AGraph *setupAGraph() {
    char *names[] = {"V0", "V1", "V2", "V3",
                     "V4", "V5", "V6", "V7",
                     "V8",};
    int n = sizeof(names) / sizeof(names[0]);
    AGraph *graph =creatAGraph(n);

    initAGraph(graph, names, n, 1);
    addEdge(graph, 0, 1, 6);
    addEdge(graph, 0, 2, 4);
    addEdge(graph, 0, 3, 5);
    addEdge(graph, 1, 4, 1);
    addEdge(graph, 2, 4, 1);
    addEdge(graph, 3, 5, 2);
    addEdge(graph, 4, 6, 9);
    addEdge(graph, 4, 7, 7);
    addEdge(graph, 5, 7, 4);
    addEdge(graph, 6, 8, 2);
    addEdge(graph, 7, 8, 4);

    return graph;
}

int main() {
    AGraph *graph = setupAGraph();

    keyPath(graph);
    return 0;
}

