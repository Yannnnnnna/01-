//
// Created by WYR on 2023/12/23.
//
#include <stdio.h>
#include "matrixGraph.h"

void initMatrixGraph(MGraph *graph) {
    char *nodeNames[] = {"V1", "V2", "V3", "V4",
                         "V5", "V6", "V7", "V8"};
    // 构造顶点集
    initMGraph(graph, nodeNames, sizeof(nodeNames) / sizeof(nodeNames[0]), 0, 0);
    // 构造边的逻辑
    addMGraphEdge(graph, 0, 1, 1);
    addMGraphEdge(graph, 0, 2, 1);
    addMGraphEdge(graph, 1, 3, 1);
    addMGraphEdge(graph, 1, 4, 1);
    addMGraphEdge(graph, 2, 5, 1);
    addMGraphEdge(graph, 2, 6, 1);
    addMGraphEdge(graph, 3, 7, 1);
    addMGraphEdge(graph, 4, 7, 1);
    addMGraphEdge(graph, 5, 6, 1);
}

int main() {
    MGraph g1;		// 如果很大，栈溢出，需要使用malloc申请这个MGraph
    initMatrixGraph(&g1);

    printf("MatrixGraph edge num: %d\n", g1.edgeNum);
    printf("DFS: ");
    DFSMGraphTravel(&g1, 0);

    cleanVisited();
    printf("\nBFS: ");
    BFSMGraphTravel(&g1, 0);
    return 0;
}

