//
// Created by WYR on 2024/1/17.
//
#include "adjacencyList.h"
#include "stdio.h"
void creatGraph(AGraph *graph){
    char *nodes[] = {"A(1)", "B(2)", "C(3)", "D(4)", "E(5)"};
    initAGraph(graph, nodes, 5, 1);

    addEdge(graph, 0, 4, 1);
    addEdge(graph, 0, 3, 1);
    addEdge(graph, 0, 1, 1);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 4, 1);
    addEdge(graph, 2, 0, 1);
    addEdge(graph, 3, 2, 1);
}
int main(){
    int n = 5;
    AGraph *graph = creatAGraph(n);
    creatGraph(graph);
    printf("图中边的数量为 %d\n", graph->edgeNum);
    printf("DFS:\n");
    DFSAGraphTravel(graph, 0);
    printf("\n");
}