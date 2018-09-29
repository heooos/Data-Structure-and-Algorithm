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

#define Head 1  //头插法
#define Tail 2  //尾插法

typedef int ElemeType;


//结点结构
typedef struct node{
    ElemeType data;
    struct node *next;
}LNode,*LinkList;

LinkList Creat_LinkList(int);
int Length_LinkList(LinkList);
LinkList Get_LinkList(LinkList,int);
LNode* Locate_LinkList(LinkList,ElemeType);


int main(int argc, const char * argv[]) {
    LinkList L =  Creat_LinkList(Tail);
    printf("长度为%d\n",Length_LinkList(L));
    printf("查询结点元素为%d\n",Get_LinkList(L, 2)->data);
    return 0;
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
