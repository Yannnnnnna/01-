//
// Created by WYR on 2024/1/29.
//

#include <stdio.h>
#include <stdlib.h>
#include "topologicalSort.h"

AGraph *setupAGraph() {
    char *names[] = {"0", "1", "2", "3",
                     "4", "5", "6"};
    int n = sizeof(names) / sizeof(names[0]);
    AGraph *graph = creatAGraph(n);
    if (graph == NULL) {
        return NULL;
    }
    initAGraph(graph, names, n, 1);
    addEdge(graph, 0, 1, 1);
    addEdge(graph, 0, 2, 1);
    addEdge(graph, 0, 3, 1);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 4, 1);
    addEdge(graph, 2, 4, 1);
    addEdge(graph, 2, 5, 1);
    addEdge(graph, 3, 5, 1);
    addEdge(graph, 4, 6, 1);
    addEdge(graph, 5, 4, 1);
    addEdge(graph, 5, 6, 1);
    return graph;
}

int main() {
    AGraph *graph = setupAGraph();

    int *result;
    int res_len;
    if (graph == NULL) {
        return -1;
    }
    int res = topologicalSortGraph(graph, &result, &res_len);
    for (int i = 0; i < res_len; ++i) {
        visitAGraphNode(&graph->nodes[result[i]]);
    }
    printf("\nresult = %d\n", res);
    free(result);

    return 0;
}

