//
// Created by WYR on 2024/1/27.
//
#include "shortPath.h"
#include "stdio.h"
#include "stdlib.h"
void setupMGraph1(MGraph *graph) {
    char *names[] = {"0", "1", "2", "3",
                     "4", "5", "6"};
    initMGraph(graph,names,sizeof(names)/ sizeof(names[0]),1,INF);
    addMGraphEdge(graph, 0, 1, 4);
    addMGraphEdge(graph, 0, 2, 6);
    addMGraphEdge(graph, 0, 3, 6);
    addMGraphEdge(graph, 1, 4, 7);
    addMGraphEdge(graph, 1, 2, 1);
    addMGraphEdge(graph, 2, 4, 6);
    addMGraphEdge(graph, 2, 5, 4);
    addMGraphEdge(graph, 3, 2, 2);
    addMGraphEdge(graph, 3, 5, 5);
    addMGraphEdge(graph, 4, 6, 6);
    addMGraphEdge(graph, 5, 4, 1);
    addMGraphEdge(graph, 5, 6, 8);
}

int main(){
    MGraph graph;
    setupMGraph1(&graph);

    int *dist;
    int *path;

    dist = (int *) malloc(sizeof (int ) *graph.nodeNum);
    path = (int *) malloc(sizeof (int ) *graph.nodeNum);

    DijkstraMGraph(&graph, 0, dist, path);
    for (int i = 0; i < graph.nodeNum; ++i) {
        printf("%d\t", dist[i]);

    }
    printf("\n");
    for (int i = 0; i < graph.nodeNum; ++i) {
        printf("%d\t", path[i]);
    }
    printf("\n");
    showShortPath(path, 0, 5);
    printf("\n");
    showShortPath(path, 0, 6);
    printf("\n");
    free(dist);
    free(path);
    return 0;
}