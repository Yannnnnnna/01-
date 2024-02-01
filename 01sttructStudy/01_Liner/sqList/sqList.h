//
// Created by WYR on 2023/9/9.
//

#ifndef INC_01STRUCTSTUDY_SQLIST_H
#define INC_01STRUCTSTUDY_SQLIST_H
#include <stdlib.h>
#include <stdio.h>

typedef int Element;    //不同数据只需修改此处

typedef struct{
    Element *data;      //指向该表的数据区域
    int capacity;   //该表的边界条件
    int len;        //长度，也是插入位置的索引
}sqList;
//维护表的结构
sqList *creatSqList(int n);         //创建表头，并将表头元素初始化为 n个
void releaseSqList(sqList* head);   //释放表头

//表里数据的行为
//1.插入（尾插法）
int push_backSq(sqList *head, Element val);
//  插入（任意位置）
int insertSq(sqList *head, int pos, Element val);


//2.打印数据表
void showSqList(const sqList *head);

//3.删除数据元素
int deleteSq(sqList *head, Element val);

#endif //INC_01STRUCTSTUDY_SQLIST_H
