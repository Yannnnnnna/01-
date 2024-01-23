//
// Created by WYR on 2024/1/22.
//

#ifndef INC_01STRUCTSTUDY_ADJACENCYMULTILIST_H
#define INC_01STRUCTSTUDY_ADJACENCYMULTILIST_H

//邻接多重表——适用于无向图
//边的节点
typedef struct amlEdge{
    int iVex;
    struct amlEdge *iNext;
    int jVex;
    struct amlEdge *jNext;
    int weight;
}MultiListEdge;

//顶点结构
typedef struct {
    int node;
    char *show;
    MultiListEdge *firstEdge;
}MultiListVertex;

//邻接多重表的图头
typedef struct {
    MultiListVertex *nodes;
    int vexNum;
    int edgeNum;
}AdjacencyMultiList;

AdjacencyMultiList *creatMultiList(int n);
void releaseMultiList(AdjacencyMultiList *graph);
void initMultiList(AdjacencyMultiList *graph, char *name[], int n);

//插入边
void insertMultiListEdge(AdjacencyMultiList *graph, int a, int b, int weight);

//删除边
int deleteMultiListEdge(AdjacencyMultiList *graph, int a, int b, int weight);
#endif //INC_01STRUCTSTUDY_ADJACENCYMULTILIST_H
