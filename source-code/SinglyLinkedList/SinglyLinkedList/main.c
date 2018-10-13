//
//  main.c
//  SinglyLinkedList
//
//  Created by zh on 2018/9/28.
//  Copyright © 2018 zh. All rights reserved.
//  单链表联系
//  1.建立单链表   2.求表长   3.查找操作   4.插入操作  5.删除操作

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

#define Head 1  //头插法
#define Tail 2  //尾插法

typedef int ElemeType;


//结点结构
typedef struct node{
    ElemeType data;
    struct node *next;
}LNode,*LinkList;

void Print_LinkList(LinkList);
LinkList Creat_LinkList(int);
int Length_LinkList(LinkList);
LNode* Get_LinkList(LinkList,int);  //位置索引
LNode* Locate_LinkList(LinkList,ElemeType);  //按值查找
bool Insert_LinkList(LinkList,int ,ElemeType);
bool Delete_LinkList(LinkList,int);  //删除索引位置的结点


int main(int argc, const char * argv[]) {
    LinkList L =  Creat_LinkList(Head);
    Print_LinkList(L);
    Delete_LinkList(L,2);
//    Insert_LinkList(L,10,999);
    Print_LinkList(L);
//    printf("长度为%d\n",Length_LinkList(L));
//    printf("查询结点元素为%d\n",Get_LinkList(L, 2)->data);
    return 0;
}

void Print_LinkList(LinkList L){
    LNode *p = L;
    while (p->next != NULL) {
        p = p->next;
        printf("%d ",p->data);
    }
    printf("\n");
}


LinkList Creat_LinkList(int type){
    //头插 & 尾插
    switch (type) {
        case Head:{
            LinkList H = (LinkList)malloc(sizeof(LNode));
            H->next = NULL;
            LNode *s;
            int x;
            scanf("%d",&x);
            while (x!=-1) {
                s = (LinkList)malloc(sizeof(LinkList));
                s->data = x;
                s->next = H->next;
                H->next = s;
                scanf("%d",&x);
            }
            return H;
        }
        case Tail:{
            LinkList H = (LinkList)malloc(sizeof(LNode));
            H->next = NULL;
            LNode *s,*r = H;
            int x;
            scanf("%d",&x);
            while (x!=-1) {
                s = (LinkList)malloc(sizeof(LinkList));
                s->data = x;
                
                s->next = r->next;
                r->next = s;
                r = s; //新尾结点
                scanf("%d",&x);
            }
            return H;
        }
        default:
            printf("输入类型错误。");
            exit(1);
            break;
    }
    return NULL;
}

int Length_LinkList(LinkList L){
    LNode * p = L;
    int i = 0;
    while (p->next != NULL) {
        p = p->next;
        i++;
    }
    return i;
}

LinkList Get_LinkList(LinkList L,int index){
    LNode * p = L;
    int i = 0;
    while (p->next != NULL && i<index) {
        p=p->next;i++;
    }
    if (i == index) {
        return p;
    }else{
        return NULL;
    }
}


LNode* Locate_LinkList(LinkList L,ElemeType E){
    LNode * p = L;
    int m;
    while (p->next != NULL) {
        p = p->next;
        m = p->data;
        
        if (m == E) {
            return p;
        }
    }
    return NULL;
}
/**
 插入到index结点上  即插入到index-1 与 index之间
 */
bool Insert_LinkList(LinkList L,int index,ElemeType E){
    LNode * p = L;
    int i = 0;
    while (p->next != NULL && i<index-1) {
        p = p->next;
        i++;
    }
    if (p->next == NULL) {
        printf("位置错误\n");
        return false;
    }
    LNode *s = (LinkList)malloc(sizeof(LNode));
    s->data = E;
    s->next = p->next;
    p->next = s;
    return true;
}

bool Delete_LinkList(LinkList L,int index){
    LNode * p = L;
    int i = 0;
    while (p->next != NULL && i< index-1) {
        p = p->next;
        i++;
    }
    
    if (p->next == NULL) {
        printf("位置错误\n");
        return false;
    }
    
    LNode * m = p->next ;
    p->next = m->next;
    free(m);
    
    return true;
}
