#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct linknode{
    int elem;
    struct linknode *next;
}linkNode;

// 创建无头结点的链表
linkNode* initLinkNode(){
    //1、创建头指针
    linkNode* p = NULL;
    //2.2、创建首元结点
    linkNode* temp  = (linkNode*)malloc(sizeof(linkNode));
    temp -> elem = 1;
     temp ->next = NULL;
     p = temp;
     //3、每创建一个结点，都令其直接前驱结点的指针指向它
     for(int i = 2;i <5; i++){
        //创建一个结点
        linkNode* newNode = (linkNode*)malloc(sizeof(linkNode));
        newNode->elem =  i;
        newNode->next = NULL;
          //每次 temp 指向的结点就是 a 的直接前驱结点
        temp ->next = newNode;
        //temp指向下一个结点（也就是a),为下次添加结点做准备
        temp = temp ->next;
     }
    return p;
}


//输出链表
void display(linkNode* p){
    linkNode* temp = p;
    while(temp){
        printf("%d ",temp -> elem);
        temp =  temp -> next;
        
    }
    printf("\n");
}

//销毁链表
void destroy(linkNode* p){
    while(p){
         linkNode* free_node = p;
         p = p->next;
         free(free_node);
    }
}


// 删除链表的倒数第 N 个节点
linkNode* removeNthFromEnd(linkNode* head, int N){
    int length = 0;
    // 为链表添加头结点
    linkNode* temp = (linkNode*)malloc(sizeof(linkNode));
    temp -> next = head;
    head = temp;
    // ① 第一次遍历链表以确定其长度
    linkNode* current = temp;
    while(current != NULL){
        length++;
        current = current ->next;
    }
    if (N+1 >length){
        return NULL;
    }
    current = head;
     // ② 第二次遍历链表，直到第 L-N 个节点(算上头结点)
     for(int i = 1; i <length -N; i++){
        current = current ->next;
     }
     linkNode* target = current->next;
     current -> next = current ->next ->next;
     free(target);
     head = temp ->next;
     free(temp);
     return head;
}

