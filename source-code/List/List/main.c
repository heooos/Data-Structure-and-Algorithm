//
//  main.c
//  List
//
//  Created by zh on 2018/9/17.
//  Copyright © 2018年 zh. All rights reserved.
//有bug  如果宏定义各Tag值等于表值 ....


//  线性表基本运算：
//  1.初始化  2.求表长
//  3.取线性表的第i个节点(1<=i<=ListLength(L))
//  4.查找值为x的结点 返回位置
//  5.第i个位置插入  6.删除第i个结点
//  拓展： 1.倒置
//

#include <stdio.h>
#include "stdlib.h"
#include "stdbool.h"

#define MAXSIZE 100
#define OVERFLOW -1  //表满tag
#define ERR -2     //错误tag
#define TRUE -4      //成功tag

typedef int ElemType;
typedef struct {
    ElemType elem[MAXSIZE];
    int length;    //线性表长度
}seqList;

  //定义一个顺序表

void init_SeqList(seqList*);
void print_SeqList(seqList*);
int insert_SeqList(seqList *,int,ElemType);
int delete_SeqList(seqList *,int);
void reverse_SeqList(seqList *);
int location_SeqList(seqList*,int);
int get_SeqList(seqList*,int);

int main(int argc, const char * argv[]) {
    
    seqList *L = NULL;
    init_SeqList(L);
    insert_SeqList(L, 1, 11);
    insert_SeqList(L, 2, 22);
    insert_SeqList(L, 3, 33);
    insert_SeqList(L, 4, 48);
    insert_SeqList(L, 4, 41);
    insert_SeqList(L, 4, 42);
    insert_SeqList(L, 4, 43);
    insert_SeqList(L, 4, 555);
    print_SeqList(L);
    delete_SeqList(L, 5);
    printf("删除后：\n");
    print_SeqList(L);
    printf("倒置：\n");
    reverse_SeqList(L);
    print_SeqList(L);
//    return 0;
    printf("\n");
    int m,n,index,sul;
    scanf("%d",&m);
    index = location_SeqList(L,m);
    if (index == ERR) {
        printf("表中不含有此数。\n");
    }else{
        printf("查询结果：第%d个\n",index);
    }
    printf("输入要获取的节点位置:\n");
    scanf("%d",&n);
    sul = get_SeqList(L, n);
    if(sul == ERR){
        
    }else{
        printf("该结点的值为：%d\n",sul);
    }

}


//顺序表的初始化
void init_SeqList(seqList *L){
    L = (seqList*)malloc(sizeof(seqList));
    L->length = 0;
}
//打印
void print_SeqList(seqList *L){
    int i;
    if (L == NULL || L->length <=0) {
        printf("表不存在或为空\n");
    }
    for (i=0; i<L->length; i++) {
        printf("%d ",L->elem[i]);
    }
}

//顺序表的插入
/**
 *一、判断表是否已满
 *二、判断插入位置是否合法
 *三、对表插入位置之后的数据进行后移
 *四、将传入数据放到插入的位置
 *五、表长+1
 **/
int insert_SeqList(seqList * L,int index,ElemType Elem){
    int j;
    if (L->length >= MAXSIZE -1) {
        printf("表满\n");
        return OVERFLOW;
    }
    if (index<1 || index>L->length+1) {
        printf("位置错误\n");
        return ERR;
    }
    for (j=L->length; j>=index-1; j--){
        L->elem[j+1] = L->elem[j];
    }
    L->elem[index-1] = Elem;
    L->length++;
    return TRUE;
}

//顺序表的删除(删除指定位置的元素，若表空或不存在指定元素，则返回ERROR)
/**
 *一、判断表是否为空或是否存在
 *二、判断插入位置是否合法
 *三、对表插入位置之后的数据进行前移
 *四、表长-1
 **/
int delete_SeqList(seqList *L,int index){
    int j;
    if (L == NULL || L->length <=0) {
        printf("表不存在或为空\n");
        return ERR;
    }
    if (index<1 || index>L->length) {
        printf("位置非法\n");
        return ERR;
    }
    for (j = index-1; j<=L->length-1; j++) {
        L->elem[j] = L->elem[j+1];
    }
    L->length--;
    return TRUE;
}

//顺序表的倒置(将表的顺序逆置)
/**
 *一、判断表是否异常
 *二、将表前后位置对调
 **/
void reverse_SeqList(seqList *L){
    ElemType tep; //临时中间值
    int i;
    if (L == NULL || L->length <=0) {
        printf("表不存在或为空\n");
    }
    for (i=0; i<L->length/2; i++) {
        tep =L->elem[i];
        L->elem[i] = L->elem[L->length-i-1];
        L->elem[L->length-i-1] = tep;
    }
}

//顺序表的查询
int location_SeqList(seqList *L,int elem){
    
    int i;
    if (L == NULL || L->length <=0) {
        printf("表不存在或为空\n");
    }
    
    for (i = 0; i<L->length; i++) {
        if (elem == L->elem[i]) {
            return i+1;
        }
    }
    return ERR;
}

//顺序表获取第i个结点
int get_SeqList(seqList *L,int index){
    
    if (L == NULL || L->length <=0) {
        printf("表不存在或为空\n");
        return ERR;
    }
    
    if (index<1 || index>L->length+1) {
        printf("位置错误\n");
        return ERR;
    }
    
    return L->elem[index-1];
}


