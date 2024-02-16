//
// Created by WYR on 2024/2/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Element;
//左闭右开区间
int binarySearch02(Element *arr, int n, Element target){
    int left = 0;
    int right = n;
    int mid;
    while (left < right){
        mid = left + (right - left ) / 2;
        if(arr[mid] == target){
            return mid;
        } else if(arr[mid] < target){
            left = mid + 1;
        } else{
            right = mid;
        }
    }
    return -1;
}

//二分查找，闭区间
int binarySearch01(Element *arr, int n, Element target){
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right){
        mid = left + (right - left) / 2;
        if(arr[mid] == target){
            return mid;
        } else if(arr[mid] < target){
            left = mid + 1;
        } else{
            right = mid - 1;
        }
    }
    return -1;
}


// 产生有序元素的数组
Element *generateOrderArray(int n){
    Element *arr = (Element *) malloc(sizeof (Element) * n);
    if(arr == NULL){
        return NULL;
    }
    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }
    return arr;
}


int main(){
    int n = 10000;
    int pos;
    Element *arr = generateOrderArray(n);

    for (int i = 0; i < n; ++i) {
        pos = binarySearch01(arr, n, arr[i]);
        if(arr[pos] != arr[i]){
            printf("Not Find\n");
        }
    }
    pos = binarySearch01(arr, n, n + 10);
    if(pos == -1){
        printf("n + 10 Not find\n");
    }
    return 0;

}