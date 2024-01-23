//
// Created by WYR on 2024/1/22.
//

#include "adjacencyMultiList.h"
#include "stdio.h"
#include "stdlib.h"

AdjacencyMultiList *creatMultiList(int n) {
    AdjacencyMultiList *graph = (AdjacencyMultiList *) malloc(sizeof (AdjacencyMultiList));
    graph->nodes = (MultiListVertex *) malloc(sizeof (MultiListVertex) * n);
    graph->edgeNum = 0;
    graph->vexNum = n;
    return graph;
}

void initMultiList(AdjacencyMultiList *graph, char **name, int n) {
    for (int i = 0; i < n; ++i) {
        graph->nodes[i].show = name[i];
        graph->nodes[i].node = i;
        graph->nodes[i].firstEdge = NULL;
    }
}

void insertMultiListEdge(AdjacencyMultiList *graph, int a, int b, int weight) {
    //1.产生边
    MultiListEdge *edge = (MultiListEdge *) malloc(sizeof (MultiListEdge));
    edge->weight = weight;
    //2.处理a的关系
    edge->iVex = a;
    edge->iNext = graph->nodes[a].firstEdge;
    graph->nodes[a].firstEdge = edge;
    //3.处理b的关系
    edge->jVex = b;
    edge->jNext = graph->nodes[b].firstEdge;
    graph->nodes[b].firstEdge = edge;

    ++graph->edgeNum;

}
//删除一个边，要用两个辅助指针，一个指向a节点的前置节点，一个指向b节点的前置节点
int deleteMultiListEdge(AdjacencyMultiList *graph, int a, int b, int weight) {
    //找到a节点的前置节点
    MultiListEdge *aPreEdge = NULL;
    MultiListEdge *aCurEdge = graph->nodes[a].firstEdge;
    while (aCurEdge &&
        !((aCurEdge->iVex == a && aCurEdge->jVex == b)
        || (aCurEdge->iVex == b && aCurEdge->jVex == a))){
        aPreEdge = aCurEdge;
        if(aCurEdge->iVex == a){
            aCurEdge = aCurEdge->iNext;
        } else {
            aCurEdge = aCurEdge->jNext;
        }
    }
    if(aCurEdge == NULL){
        return -1;
    }
    //找到b编号的前置节点
    MultiListEdge *bPreEdge = NULL;
    MultiListEdge *bCurEdge = graph->nodes[b].firstEdge;
    while (bCurEdge &&
           !((bCurEdge->iVex == a && bCurEdge->jVex == b)
             || (bCurEdge->iVex == b && bCurEdge->jVex == a))){
        bPreEdge = bCurEdge;
        if(bCurEdge->iVex == a){
            bCurEdge = bCurEdge->iNext;
        } else {
            bCurEdge = bCurEdge->jNext;
        }
    }
    if(bCurEdge == NULL){
        return -1;
    }
    //删除a节点的边的关系
    if(aPreEdge == NULL){
        if(aCurEdge->iVex == a){
            graph->nodes[a].firstEdge = aCurEdge->iNext;
        } else {
            graph->nodes[a].firstEdge = aCurEdge->jNext;
        }
    } else{
        if(aPreEdge->iVex == a && aCurEdge->iVex == a){
            aPreEdge->iNext = aCurEdge->iNext;
        }else if(aPreEdge->iVex == a && aCurEdge->jVex == a){
            aPreEdge->iNext = aCurEdge->jNext;
        }else if(aPreEdge->jVex == a && aCurEdge->iVex == a){
            aPreEdge->jNext = aCurEdge->iNext;
        }else{
            aPreEdge->jNext = aCurEdge->jNext;
        }
    }
    //删除b节点的边的关系
    if(bPreEdge == NULL){
        if(bCurEdge->iVex == a){
            graph->nodes[b].firstEdge = bCurEdge->iNext;
        } else {
            graph->nodes[b].firstEdge = bCurEdge->jNext;
        }
    } else{
        if(bPreEdge->iVex == b && bCurEdge->iVex == b){
            bPreEdge->iNext = bCurEdge->iNext;
        }else if(bPreEdge->iVex == b && bCurEdge->jVex == b){
            bPreEdge->iNext = bCurEdge->jNext;
        }else if(bPreEdge->jVex == b && bCurEdge->iVex == b){
            bPreEdge->jNext = bCurEdge->iNext;
        }else{
            bPreEdge->jNext = bCurEdge->jNext;
        }
    }
    free(aCurEdge);
    --graph->edgeNum;
    return 0;
}


