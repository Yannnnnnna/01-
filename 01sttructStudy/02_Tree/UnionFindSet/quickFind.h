//
// Created by WYR on 2023/12/13.
//
/* QuickFind:
 * 每个元素都有一个编号，只要这个编号一样，就表示是一个集团的人
 * 合并时，就是把另外一个团伙的人的老大都改为这个团伙的老大
 * */
typedef char Element;
typedef struct {
    Element *data;  //存数据。默认用C语言索引建立和数据元素的关系
    int n;          //限制元素个数
    int capacity;
    int *groupID;   //存的是对应数据的编号
}QuickFindSet;

//产生capacity个容量元素quickfind的并查集，里面的数据是没有初始值，也没有有效个数据个数
QuickFindSet *creatQuickFindSet(int capacity);
void releaseQuickFindSet(QuickFindSet *findSet);

//初始化并查集
void initQuickFindSet(QuickFindSet *findSet, const Element *data, int n);
//查
int isSameQuickFindSet(QuickFindSet *findSet, Element a, Element b);
//合并
void unionQuickFindSet(QuickFindSet *findSet, Element a, Element b);

#ifndef INC_01STRUCTSTUDY_QUICKFIND_H
#define INC_01STRUCTSTUDY_QUICKFIND_H

#endif //INC_01STRUCTSTUDY_QUICKFIND_H
