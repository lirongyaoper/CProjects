#include <stdio.h>
#include <stdlib.h>
// 定义双链表节点结构体
typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;

} Node;

//创建新节点
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Error: Memory allocation failed.");
        exit(EXIT_FAILURE);
    }
    newNode ->data = data;
    newNode ->prev = NULL;
    newNode ->next = NULL;
    return newNode;
}

//在链表头部插入节点
void insertAtHead(Node** head_ref, int data) {
    Node* newNode = createNode(data);
    
}