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



int main(int argc, const char * argv[]) {
    // insert code here...
    
    return 0;
}

LinkList Creat_LinkList(int type){
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
                s->next = NULL;
                H->next = s;
                scanf("%d",&x);
            }
            
            return H;
        }
        case Tail:{
            LinkList R = (LinkList)malloc(sizeof(LNode));
            R->next = NULL;
            LNode *s;
            int x;
            scanf("%d",&x);
            while (x!=-1) {
                s = (LinkList)malloc(sizeof(LinkList));
                s->data = x;
                
                R->next = s;
                s->next = NULL;
                R = s; //新尾结点
                scanf("%d",&x);
            }
            return R;
        }
        default:
            printf("输入类型错误。");
            exit(1);
            break;
    }
    return NULL;
}
