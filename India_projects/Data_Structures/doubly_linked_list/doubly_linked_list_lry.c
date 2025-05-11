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
    newNode->next = *head_ref;
    if (*head_ref != NULL) {
        (*head_ref) -> prev = newNode;
    }
    *head_ref =  newNode;

}

//在链表尾部插入节点
void insertAtTail(Node** head_ref, int data){
    Node* newNode = createNode(data);
    if(*head_ref == NULL){
        *head_ref = newNode;
        return;
    }
    Node* current = *head_ref;
    while(current->next != NULL){
        current = current ->next;
    }
    current -> next = newNode;
    newNode -> prev = current;

}

//在链表中间插入节点（指定位置）
void insertAtPosition(Node** head_ref, int data, int position){
    //如何position =1 ,则在头部插入
    if(position == 0){
        insertAtHead(head_ref, data);
        return;
    }
    Node* newNode = createNode(data);
    Node* current = *head_ref;
    for(int i = 0; i < position -1  && current != NULL; i++){
        current = current ->next;
    }
    if(current == NULL){
        printf("Error: Invalid position.");
        free(newNode);
        return;
    }
    newNode -> next = current ->next;
    newNode -> prev = current;
    if(current -> next != NULL){
        current -> next -> prev = newNode;
    }
    current -> next = newNode;
}

//删除头部节点
void deleteAtHead(Node** head_ref){
    if(*head_ref == NULL){
        printf("Error: List is empty.");
        return;
    }
    Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    if(*head_ref != NULL){
        (*head_ref)-> prev = NULL;
    }
    free(temp);
}

//删除尾部节点
void deleteAtTail(Node** head_ref){
    if(*head_ref == NULL){
        printf("Error: List is empty.");
        return;
    }
    Node* current = *head_ref;
    while(current -> next != NULL){
        current = current -> next;
    }
    if(current -> prev != NULL){
        //
        current -> prev -> next = NULL;
    }
    else{
        //如果链表只有一个节点，则删除该节点并更新头指针
        *head_ref = NULL;
    }
    free(current);
}

//删除指定位置的节点