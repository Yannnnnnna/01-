//
// Created by WYR on 2024/1/21.
//

#ifndef INC_01STRUCTSTUDY_CROSSLINKGRAPH_H
#define INC_01STRUCTSTUDY_CROSSLINKGRAPH_H
/*十字链表*/

//边节点——定义弧
typedef struct arcBox{
    int tailVertex;             //弧尾的编号，为出度服务
    struct arcBox* tailNext;    //下一个弧尾
    int headVertex;             //弧头的编号，为入度服务
    struct arcBox *headNext;    //下一个弧头
    int weight;                 //权重
}ArcBox;

//顶点集合
typedef struct {
    int node;           //节点的编号
    const char *show;   //用于打印
    ArcBox *firstIn;    //存节点的入度
    ArcBox *firstOut;   //存节点的出度
}CrossVertex;

//图的结构
typedef struct {
    CrossVertex *nodes;
    int numVertex;
    int numEdge;
}CrossGraph;

//产生n个节点的十字链表图
CrossGraph *creatCrossGraph(int n);
void releaseCrossGraph(CrossGraph *graph);

//初始化图，设置顶点信息
void initCrossGraph(CrossGraph *graph, char *names[], int num);

//添加边
void addCrossArc(CrossGraph *graph, int tail, int head, int weight);

//计算出度和入度
int inDegreeCrossGraph(CrossGraph *graph, int node);
int outDegreeCrossGraph(CrossGraph *graph, int node);
#endif //INC_01STRUCTSTUDY_CROSSLINKGRAPH_H
