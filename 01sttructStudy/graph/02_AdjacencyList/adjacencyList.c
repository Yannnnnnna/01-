//
// Created by WYR on 2024/1/17.
//
#include <stdlib.h>
#include "adjacencyList.h"
#include <string.h>
#include <stdio.h>

AGraph *creatAGraph(int n) {
    //先有图的头,初始化图头的信息
    AGraph *graph = (AGraph*) malloc(sizeof (AGraph));
    graph->nodeNum = n;
    graph->edgeNum = 0;
    //给图中数组申请空间
    graph->nodes = (arcNode*) malloc(sizeof(arcNode) * n);
    graph->visited = (int*) malloc(sizeof (int ) * n);
    //清空图中数组的信息
    memset(graph->nodes, 0, sizeof(arcNode) * n);
    memset(graph->visited, 0, sizeof (int ) * n);

    return graph;

}

void initAGraph(AGraph *graph, char **detail, int num, int directed) {
    graph->directed = directed;
    for (int i = 0; i < num; ++i) {
        graph->nodes[i].detail = detail[i];
        graph->nodes[i].idx = i;
        graph->nodes[i].firstEdge = NULL;

    }
}
//创建一个边
static arcEdge *creatArcEdge(int idx, int weight){
    arcEdge *edge = (arcEdge*) malloc(sizeof (arcEdge));
    edge->num = idx;
    edge->weight = weight;
    edge->next = NULL;

    return edge;
}
void addEdge(AGraph *graph, int x, int y, int weight) {
    if(x < 0 || x >graph->nodeNum || y < 0 || y > graph->nodeNum || x == y){
        return;
    }
    //利用头插法插入边的关系，从当前节点指向哪个节点
    arcEdge *edge = creatArcEdge(y, weight);
    edge->next = graph->nodes[x].firstEdge;
    graph->nodes[x].firstEdge = edge;
    ++graph->edgeNum;
    //如果是有向，方向也建立边
    if(graph->directed == 0){
        edge = creatArcEdge(x, weight);
        edge->next = graph->nodes[y].firstEdge;
        graph->nodes[y].firstEdge = edge;
        ++graph->edgeNum;
    }
}
//看节点的信息
void visitAGraphNode(arcNode *node){
    printf("\t%s", node->detail);
}
void DFSAGraphTravel(AGraph *graph, int idx) {
    graph->visited[idx] = 1;
    visitAGraphNode(&graph->nodes[idx]);
    //定义一个辅助指针来访问节点
    arcEdge *p = graph->nodes[idx].firstEdge;
    while (p != NULL){
        if(graph->visited[p->num] == 0){
            DFSAGraphTravel(graph, p->num);
        }
        p = p->next;
    }
}
