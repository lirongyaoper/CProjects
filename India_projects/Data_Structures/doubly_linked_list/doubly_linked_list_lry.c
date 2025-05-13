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
        current -> prev = NULL;
    }
    else{
        //如果链表只有一个节点，则删除该节点并更新头指针
        *head_ref = NULL;
    }
    free(current);
}

//删除指定位置的节点(position)
void deleteAtPosition(Node** head_ref, int position){
    if(*head_ref == NULL) return;
    Node* current = *head_ref;
    if (position == 0){
        deleteAtHead(head_ref);
        return;
    }
    for (int i = 0; current != NULL && i < position; i++){
        current = current -> next;
    }
    if(current == NULL){
        printf("Error: Invalid position.");
        return;
    }
    if(current -> prev != NULL){
        current -> prev ->next = current -> next;
    }
    if(current -> next != NULL){
        current ->next ->prev = current -> prev;
    }
    free(current);
}


// 查找节点
Node* findNode(Node* head, int data){
    Node* current = head;
    while(current != NULL){
        if(current -> data == data){
            return current;
            
        }
        current = current -> next;
    }
    return NULL;
}

// 正向遍历链表
void printForward(Node* head){
    Node* current = head;
    while(current != NULL){
        printf("%d ->",current -> data);
        current = current -> next;
    }
    printf("NULL\n");
}


// 反向遍历链表
void printBackward(Node* head){
    Node* current  = head;
    if(current == NULL) return;
    while(current -> next != NULL){
        current = current -> next;
    }

    printf("反向遍历： ");
    while(current != NULL){
        printf("%d ->",current -> data);
        current = current -> prev;

    }
    printf("NULL\n");
}

//  释放链表
void freeList(Node** head){
    Node* temp;
    while((*head) != NULL){
        temp = *head;
        (*head) = (*head) -> next;
        free(temp);
    }
}

// 示例用法
int main() {
    Node* head = NULL;

    // 插入节点
    insertAtHead(&head, 10);
    insertAtTail(&head, 30);
    insertAtPosition(&head, 20, 1);
    insertAtHead(&head, 5);
    insertAtTail(&head, 40);

    // 打印链表
    printForward(head);  // 输出: 5 10 20 30 40
    printBackward(head); // 输出: 40 30 20 10 5

    // // 删除节点
    deleteAtHead(&head);
    deleteAtTail(&head);
    deleteAtPosition(&head, 1);

    // 打印链表
    printForward(head);  // 输出: 10 30

    // // 查找节点
    Node* node = findNode(head, 30);
    if (node != NULL) {
        printf("找到节点: %d\n", node->data);
    } else {
        printf("未找到节点\n");
    }

    // // 释放内存
    freeList(&head);

    return 0;
}    