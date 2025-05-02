#include<stdio.h>
#include<stdlib.h>
//define the node structure
typedef struct Node{
    int data;
    struct Node* next;
} Node;

//create a new node with given data
Node* createNewNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    (*newNode).data = data;
    newNode->next = NULL;    
    return newNode;
} 

// insert a node at the first of the linked list
void insertAtBeginning(Node** head , int data){
    Node* newNode = createNewNode(data);
    newNode->next = *head;
    *head = newNode;
}

//insert a node at the end of the linked list
void insertAtEnd(Node** head ,int data){
    Node* newNode = createNewNode(data);
    // if the list is empty, insert the new node at the beginning
    if (*head == NULL){
        *head = newNode;
        printf("Inserted %d at the end\n",data);
        return;
    }
    Node* temp = *head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    printf("Inserted %d at the end\n",data);
}

// insert a node at the middle of the linked list
void insertAtPositon(Node** head , int data, int position){
    if(position == 0){
        insertAtBeginning(head,data);
        return;
    }
    Node* newNode = createNewNode(data);
    Node* temp = *head;
    for(int i = 0; i < position - 1 && temp != NULL; i++){
        temp = temp -> next;
    }
    if(temp ==NULL){
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    newNode -> next = temp -> next;
    temp ->next = newNode;
}

// delete the first node for the linked list
void deleteAtBeginning(Node** head){
    if(*head ==NULL){
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    *head = (*head) -> next;
    free(temp);
}

// delete the last node for the linked list
void deleteAtEnd(Node** head){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    if((*head) -> next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    while(temp ->next -> next != NULL){
        temp = temp -> next;
    }
    free(temp -> next);
    temp ->next = NULL;
}

// delete the node at the given position
void deleteAtPosition(Node** head, int position){ 
    if(*head == NULL){
        printf("List is empty\n");       
        return;
    }
    if(position == 0){
        deleteAtBeginning(head);
        return;
    }
    Node* temp = *head;
    for(int i = 0; i < position -1 && temp != NULL; i++){
        temp = temp -> next;
    }
    if(temp == NULL || temp -> next ==NULL){
        printf("Invalid position\n");
        return;
    }
    Node* toDelete = temp -> next;
    temp -> next = toDelete -> next;
    free(toDelete);
}

//find the node of the linked list
Node* searchNode(Node* head ,int data){
    Node* temp = head;
    while(temp != NULL){
        if(temp -> data == data){
            return temp;
        }
        temp = temp -> next;
    }
    return NULL;
}

//print  the linked list
void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d ",temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

void freeList(Node** head){
    Node* temp;
    while(* head != NULL){
        temp = *head;
        *head = (*head)-> next;
        free(temp);
    }
}

// 获取链表长度
int getListLength(Node* head) {
    int length = 0;
    Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

// 反转链表
void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// 合并两个有序链表
Node* mergeSortedLists(Node* list1, Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return dummy.next;
}

// 删除链表中所有值为指定值的节点
void deleteNodesWithValue(Node** head, int value) {
    while (*head != NULL && (*head)->data == value) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    Node* current = *head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

int main(){
    Node* head = NULL;
    //insert at the beginning
    insertAtBeginning(&head,10);
    insertAtBeginning(&head,20);
    //insert at the end
    insertAtEnd(&head,30);
    //insert at the middle
    insertAtPositon(&head,40,2);
    insertAtPositon(&head,50,1);
    printList(head);

    // 获取链表长度
    int length = getListLength(head);
    printf("List length: %d\n", length);

    // 反转链表
    reverseList(&head);
    printf("Reversed list: ");
    printList(head);

    // 创建另一个有序链表
    Node* head2 = NULL;
    insertAtBeginning(&head2, 15);
    insertAtBeginning(&head2, 25);
    insertAtBeginning(&head2, 35);
    printf("List 2: ");
    printList(head2);

    // 合并两个有序链表
    Node* mergedList = mergeSortedLists(head, head2);
    printf("Merged list: ");
    printList(mergedList);

    // 删除链表中所有值为指定值的节点
    deleteNodesWithValue(&mergedList, 25);
    printf("List after deleting nodes with value 25: ");
    printList(mergedList);

    // 释放链表内存
    freeList(&mergedList);

    return 0;
}
