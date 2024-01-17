//
// Created by WYR on 2023/12/20.
//

#include "matrixGraph.h"
#include <string.h>
#include <stdio.h>
//定义无穷大为IE4
#define INF 1E4
//判断是否为有边 有边返回1 没有边返回0
int isEdge(int weight){
    if(weight > 0 && weight < INF){
        return 1;
    }
    return 0;
}
//初始化地图
void initMGraph(MGraph *g, char **names, int num, int directed, int initEdgeValue) {
    g->directed = directed;     //是否有向
    g->edgeNum = 0;
    g->nodeNum = num;
    memset(g->vex, 0, sizeof (g->vex));     //将节点全部清零
    memset(g->edges, 0 , sizeof (MatrixEdge) * MaxNodeNum * MaxNodeNum);    //将邻接表全部清零
    //初始化邻接表
    for (int i = 0; i < num; ++i) {
        //根据name来初始化节点信息
        g->vex[i].node = i;
        g->vex[i].show = names[i];
        //对边的矩阵进行初始化
        for (int j = 0; j < num; ++j) {
            g->edges[i][j] = initEdgeValue;
        }
    }

}
//x 和 y 为下标
void addMGraphEdge(MGraph *g, int x, int y, int w) {
    //保护，防止越界
    if(x < 0 || x > g->nodeNum){
        return;
    }
    if(y < 0 || y > g->nodeNum){
        return;
    }
    //没有自环边， 重复边， 没有边就自行添加
    if(!isEdge(g->edges[x][y])){
        g->edges[x][y] = w;
        if(g->directed == 0){
            g->edges[y][x] = w;
        }

        ++g->edgeNum;
    }
}
/*邻接矩阵的深度遍历：
 * 1.访问第v的节点，通过第v个节点去找他的未被访问的所有节点
 * 2.发现有一个满足条件的新节点，就把这个节点当作任务，继续调用这个接口
 * 3.只有某个节点，他都没有满足条件的任务，就返回*/
static int MGraphVisit[MaxNodeNum];     //储存节点是否访问的信息
void DFSMGraphTravel(MGraph *graph, int v) {
    visitMGraphNode(&graph->vex[v]);
    MGraphVisit[v] = 1;
    for (int i = 0; i < graph->nodeNum; ++i) {
        if(isEdge(graph->edges[v][i]) && MGraphVisit[i] == 0){
            DFSMGraphTravel(graph, i);
        }
    }

}

void visitMGraphNode(MatrixVertex *node) {
    printf("\t%s", node->show);
}
/* 邻接矩阵的广度遍历
 * 初始化
 * 	1. v放入队列
 * 	2. visited标记
 * 循环出任务
 *  1. 出队，访问
 *  2. 一旦有满足条件的这个节点，依次入队
 *  3. 入队过程中，标记visited
 *  4. 循环
 * */

void BFSMGraphTravel(MGraph *graph, int v) {
    int queue[MaxNodeNum + 1];  //定义一个队列存索引
    int rear = 0, front = 0;
    int cur;

    rear = (rear + 1) % MaxNodeNum;
    cleanVisited();     //先清空再用
    queue[rear] = v;
    MGraphVisit[v] = 1;
    while(front != rear){
        //先把队首取出来，然后进行访问
        front = (front + 1) % MaxNodeNum;
        cur = queue[front];
        visitMGraphNode(&graph->vex[cur]);
        //对取出的节点进行搜索，判断和其他节点是否有连接
        for (int i = 0; i < graph->nodeNum; ++i) {
            //有边连接，同时没有被访问过，就入队并将当前节点的访问状态设置为已经访问过
            if(isEdge(graph->edges[cur][i]) && MGraphVisit[i] == 0){
                rear = (rear + 1) % MaxNodeNum;
                queue[rear] = i;
                MGraphVisit[i] = 1;
            }
        }
    }
}

void cleanVisited() {
    memset(MGraphVisit, 0 ,sizeof (MGraphVisit));
}
