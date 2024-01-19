//
// Created by WYR on 2024/1/17.
//

#ifndef INC_01_STRUCT_STUDY_ADJACENCY_LIST_H
#define INC_01_STRUCT_STUDY_ADJACENCY_LIST_H
//边的结构
typedef struct arcEdge{
    int num;                //入的节点编号
    int weight;             //边的权重
    struct arcEdge *next;   //下一个节点
}arcEdge;

//顶点结构
typedef struct {
    int idx;        //顶点的索引号
    char *detail;   //用于打印的信息
    arcEdge *firstEdge; //指向第一个出的弧
}arcNode;

//邻接表
typedef struct {
    arcNode *nodes;     //图中顶点的集合
    int *visited;       //用于遍历中标记节点是否看过
    int nodeNum;        //图中顶点的数量
    int edgeNum;        //边的个数
    int directed;       //是否有向
}AGraph;

//产生n个节点的邻接表
AGraph *creatAGraph(int n);
//释放邻接表
void releaseAGraph(AGraph *graph);

//初始化表
void initAGraph(AGraph *graph, char *detail[], int num, int directed);
//建立边的关系
void addEdge(AGraph *graph, int x, int y, int weight);

//遍历
//深度遍历
void DFSAGraphTravel(AGraph *graph, int idx);
//广度遍历
#endif //INC_01_STRUCT_STUDY_ADJACENCY_LIST_H
