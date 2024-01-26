//
// Created by WYR on 2024/1/26.
//

#ifndef INC_01STRUCTSTUDY_COMMOM_H
#define INC_01STRUCTSTUDY_COMMOM_H
#define INF 1E4
//边集结构如何定义，用这个定义开始操作内存
typedef struct {
    int begin;      //都是顶点集合的索引号
    int end;
    int weight;
}EdgeSet;


#endif //INC_01STRUCTSTUDY_COMMOM_H
