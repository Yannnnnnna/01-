//
// Created by WYR on 2023/9/12.
//

#ifndef INC_01STRUCTSTUDY_LINKLIST_H
#define INC_01STRUCTSTUDY_LINKLIST_H
#include <stdlib.h>
#include <stdio.h>
 typedef int Element;

 typedef struct linkNode{
     Element data;
     struct linkNode *next;
 }linkNode;

 //带头结点的结构
 typedef struct {
     linkNode header;
     int num;
 }linkHeader;

 //创建链表
linkHeader *creatLink();

//释放链表
void releaseLink(linkHeader  *header);

//带头节点的头插法
int headInsert_01(linkHeader *header, Element data);

//任意位置插入
int header_insert(linkHeader* header, int pos ,Element val);

//显示所有元素
void show_headLink(linkHeader* header);

//删除元素
int delete_headLink(linkHeader* header, Element data);

#endif //INC_01STRUCTSTUDY_LINKLIST_H




