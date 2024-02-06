//
// Created by WYR on 2024/2/6.
//

#include "mergeSort.h"
#include "stdlib.h"
//左右已经有序了，如何合并到原空间
static void merge(SortTable *table, int left, int mid, int right){
    //计算左右空间的大小
    int n1 = mid - left + 1;
    int n2 = right - mid;
    //分配临时的空间来中转
    Element *aux1 = (Element *) malloc(sizeof (Element) * n1);
    Element *aux2 = (Element *) malloc(sizeof (Element) * n2);
    if(aux1 == NULL || aux2 == NULL){
        fprintf(stderr, "tmp malloc failed!\n");
        return;
    }
    //拷贝
    for (int i = 0; i < n1; ++i) {
        aux1[i] = table->data[left + i];
    }
    for (int i = 0; i < n2; ++i) {
        aux2[i] = table->data[mid + 1 + i];
    }
    //对已经有序的空间进行合并
    int i = 0;      //标记aux1的辅助索引
    int j = 0;      //标记aux2 的辅助索引
    int k = left;   //标记结果空间的辅助索引（table）
    //遍历2个有序的辅助空间，只要其中有一个遍历完，后面进行收尾处理
    while (i < n1 && j < n2){
        // 将两个空间较小的值放入原空间
        if(aux1[i].key <= aux2[j].key){
            table->data[k] = aux1[i++];
        } else{
            table->data[k] = aux2[j++];
        }
        ++k;

    }
    // 收尾，k指向待填充的位置，判断是那个空间遍历完
    while (i < n1){
        table->data[k++] = aux1[i++];
    }
    while (j < n2){
        table->data[k++] = aux2[j++];
    }
    //释放临时空间
    free(aux1);
    free(aux2);
}
//递归分解table【左···右】区域
static void mergeLoop(SortTable *table, int left, int right){
    if(left >= right){
        return;
    }
    int mid = (left + right) / 2;
    mergeLoop(table, left, mid);
    mergeLoop(table, mid + 1, right);
    //拆的任务结束，开始合并
    merge(table, left, mid, right);
}
void mergeSort(SortTable *table) {
    mergeLoop(table, 0, table->length - 1);
}
