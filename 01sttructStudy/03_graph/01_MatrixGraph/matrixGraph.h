//
// Created by WYR on 2023/12/20.
//

#ifndef INC_01STRUCTSTUDY_MATRIXGRAPH_H
#define INC_01STRUCTSTUDY_MATRIXGRAPH_H

/* 邻接矩阵
 * - 描述顶点的集合  用一维数组
 * - 描述边的集合	   用二维数组
 * */
#define MaxNodeNum 20
//节点结构
typedef struct {
    int node;       //顶点编号
    char *show;     //方便打印，显示字符串 "v1" "v2"
}MatrixVertex;
//定义边结构
typedef int MatrixEdge;
//节点，边封装为一个类
typedef struct {
    MatrixVertex vex[MaxNodeNum];   //储存顶点空间
    int nodeNum;                    //约束顶点的数量，记录现在顶点有多少个节点
    MatrixEdge edges[MaxNodeNum][MaxNodeNum];   //邻接矩阵边的关系
    int edgeNum;
    int directed;   //是否为有向图
}MGraph;

// 初始化了一定的空间容量，顶点的值由names的指针数组来决定信息
void initMGraph(MGraph *g, char *names[], int num, int directed, int initEdgeValue);
// 添加边的关系, 将x向y添加边，如果是无向图，也需要y向x添加边，w是这个边的权重
void addMGraphEdge(MGraph *g, int x, int y, int w);
// 一个连通子图的深度遍历
void DFSMGraphTravel(MGraph *graph, int v);
// 一个连通子图的广度遍历
void BFSMGraphTravel(MGraph *graph, int v);
// 访问节点
void visitMGraphNode(MatrixVertex *node);
//清空节点的访问信息
void cleanVisited();

#endif //INC_01STRUCTSTUDY_MATRIXGRAPH_H
