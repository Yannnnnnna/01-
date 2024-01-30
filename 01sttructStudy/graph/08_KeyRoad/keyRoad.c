//
// Created by WYR on 2024/1/30.
//

#include "keyRoad.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

/* 算ETV: 通过拓扑排序计算出ETV，排序的结果返回
 * 1. stack ： 入度为0的节点放入栈区，弹
 * 2. topOut : 拓扑排序的输出结果，返回去计算LTV
 * */
static int topologicalOrder(AGraph *graph, int *ETV, int *LTV){
    int *stack;
    int top = -1;
    int *inDegree = (int *) malloc(sizeof (int ) * graph->nodeNum);
    memset(inDegree, 0, sizeof (int ) * graph->nodeNum);
    // 1. 初始化图中所有顶点的入度记录
    for (int i = 0; i < graph->nodeNum; ++i) {
        if(graph->nodes[i].firstEdge){
            arcEdge *edge = graph->nodes[i].firstEdge;
            while (edge){
                ++inDegree[edge->num];
                edge = edge->next;
            }
        }
    }
    // 2. 将入度为0的节点入栈，出栈的时候，更新各个顶点的最早时间
    stack = (int*) malloc(sizeof (int ) * graph->nodeNum);
    // 2.1 将初始化的入度为0的顶点压入栈
    //  只会有一个
    for (int i = 0; i < graph->nodeNum; ++i) {
        if(inDegree[i] == 0){
            stack[++top] = i;
            break;
        }
    }
    // 2.2 不断弹栈
    int *topOut = (int *) malloc(sizeof (int ) *graph->nodeNum);
    int index = 0;
    int temp;
    while (top != -1){
        temp = stack[top--];
        topOut [index++] = temp;
        arcEdge *edge = graph->nodes[temp].firstEdge;
        while (edge){
            --inDegree[edge->num];
            if(inDegree[edge->num] == 0){
                stack[++top] = edge->num;
            }
            // 看到这个边，ETV更新
            if(ETV[temp] + edge->weight > ETV[edge->num]){
                ETV[edge->num] = ETV[temp] +edge->weight;
            }
            edge = edge->next;
        }
    }
    free(inDegree);
    free(stack);
    if(index < graph->nodeNum){     //有环
        free(topOut);
        return -1;
    }
    //3. 更新LTV
    // 初始化LTV值，把汇点的最早发生时间， 不断遍历,减少各个边的权值
    topOut[index] = -1;
    for (int i = 0; i < graph->nodeNum; ++i) {
        LTV[i] = ETV[temp];
    }
    while (index){
        int getTopNode = topOut[--index];
        arcEdge *edge = graph->nodes[getTopNode].firstEdge;
        while (edge){
            //后一个节点LTV减去入度边的权值，和这个点的最晚发生时间比较
            if(LTV[edge->num] - edge->weight < LTV[getTopNode]){
                LTV[getTopNode] = LTV[edge->num] - edge->weight;
            }
            edge = edge->next;
        }
    }
    free(topOut);
    return 0;

}
// 显示
static void showTable(int *table, int n, const char *name){
    printf("%s ", name);
    for (int i = 0; i < n; ++i) {
        printf("\t%d", table[i]);

    }
    printf("\n");
}
void keyPath(AGraph *graph) {
    //1. 计算ETV和LTV
    int *ETV = (int *) malloc(sizeof (int ) * graph->nodeNum);
    int *LTV = (int *) malloc(sizeof (int ) * graph->nodeNum);

    memset(ETV, 0, sizeof (int ) * graph->nodeNum);
    memset(LTV, 0, sizeof (int ) * graph->nodeNum);
    printf("\nresult: %d\n", topologicalOrder(graph, ETV, LTV));

    showTable(ETV, graph->nodeNum, "ETV: ");
    showTable(LTV, graph->nodeNum, "LTV: ");
    //计算ETE和LTE
    for (int i = 0; i < graph->nodeNum; ++i) {
        arcEdge *edge = graph->nodes[i].firstEdge;
        while (edge){
            if(ETV[i] == LTV[edge->num] - edge->weight){
                printf("<%s> ----%d---- <%s>\n",
                       graph->nodes[i].detail, edge->weight, graph->nodes[edge->num].detail);

            }
            edge = edge->next;
        }
    }

}
