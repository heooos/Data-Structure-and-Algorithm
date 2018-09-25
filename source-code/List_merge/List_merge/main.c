//
//  main.c
//  List_merge
//
//  Created by zh on 2018/9/24.
//  Copyright © 2018年 zh. All rights reserved.
//  两个顺序表(有序)合并操作 按从小到大的升序

#include <stdio.h>
#define MAXSIZE 100

typedef struct {
    int m[MAXSIZE];
    int size;
}SeqList;

void init_SeqList(SeqList *list);
void print_SeqList(SeqList *s);
void merge(SeqList *A,SeqList *B,SeqList *C);

int main(int argc, const char * argv[]) {
    SeqList alist;
    SeqList blist;
    SeqList clist;
    
    init_SeqList(&alist);
    init_SeqList(&blist);
    print_SeqList(&alist);
    print_SeqList(&blist);
    printf("合并后：:\n");
    merge(&alist, &blist, &clist);
    print_SeqList(&clist);
    
    return 0;
}

void init_SeqList(SeqList *list){
    int n, len;
    printf("输入顺序表的长度：");
    scanf("%d", &len);
    list->size = len;
    printf("输入顺序表的元素：");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &n);
        list->m[i] = n;
    }
}

//输出
void print_SeqList(SeqList *s){
    for (int i = 0; i < s->size; i++)
        printf("%d ", s->m[i]);
    printf("\n");
}


void merge(SeqList *A,SeqList *B,SeqList *C){
    int i,j,k;
    i =0;j=0;k=0;
    while (i<A->size && j< B->size) {
        if (A->m[i] <= B->m[j]) {
            C->m[k] = A->m[i];
            i++;k++;
        }else{
            C->m[k] = B->m[j];
            j++;k++;
        }
    }
    //A扫描完毕  B接到C之后
    if (i == A->size) {
        for (; j<B->size; j++) {
            C->m[k] = B->m[j];
            k++;
        }
    }
    if (j == B->size) {
        for (; i<A->size; i++) {
            C->m[k] = A->m[i];
            k++;
        }
    }
    C->size = k;
}
