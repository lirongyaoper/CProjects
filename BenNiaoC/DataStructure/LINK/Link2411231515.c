#include <stdio.h>
#include <stdlib.h>

//https://blog.csdn.net/ffortunateoy/article/details/91359568


////双向链表结点结构体
typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;

}Node;

//创建双向链表结点
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
//双向链表结构体
typedef struct DoubleList{
    Node* head;
    Node* tail;
    size_t size;
}DoubleList;

//初始化双向链表
void init_DoubleList(DoubleList* link){
    link->head = NULL;
    link->tail = NULL;
    link ->size = 0;
    return;
}

//释放链表
void free_DoubleList(DoubleList* link){
    while(link->size){
        Node* temp = link->head;
        link->head = link->head->next;
        free(temp);
        temp = NULL;
        link->size--;
    }
    return;
}
//获取头结点获取头结点获取头结点获取头结点获取头结点
Node* get_head(DoubleList* link){

    return link->head;
}
//获取尾结点
Node* get_tail(DoubleList* link){
    return link->tail;
}

//获取链表长度
size_t get_size(DoubleList* link){
    return link->size;
}


//遍历链表打印链表中所有的元素
void print_DoubleList(DoubleList* link){
    Node* node =  link ->head;
    for (int i  = 0; i < link->size; i++){
        printf("%d ",node->data);
        node = node ->next;
    }
    printf("\n");

}


//插入头结点
    // 需要考虑两种情况：

    //     链表为空，那插入的结点既是头结点，也是尾结点；
    //     链表不为空，将新结点和链表通过前驱指针prev和后继指针next连接起来，并将头结点改为新插入的结点；

void insert_head(DoubleList* link,int data){
    Node* newNode = createNode(data);
    // 链表为空
    if(link->size == 0){
        link->head = newNode;
        link->tail = newNode;
    }
    // 链表不为空
    else{
        newNode->next = link->head;
        link->head->prev = newNode;
        link->head = newNode;
    }
    link->size++;

}