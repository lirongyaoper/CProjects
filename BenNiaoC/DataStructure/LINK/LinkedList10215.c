#include <stdio.h>
#include <stdlib.h>
typedef struct doublyLinkedList{
    struct doublyLinkedList *prev;
    int data;
    struct doublyLinkedList *next;
}Dlinklist;


//create a node
Dlinklist* createNode(int data){
    Dlinklist* newNode = (Dlinklist*)malloc(sizeof(Dlinklist));
    newNode->data = data;
    newNode ->next = NULL;
    newNode ->prev = NULL;
    return newNode;
}



//insert at beginning
Dlinklist* insertAtBegin(Dlinklist* head, int data){
    Dlinklist *newNode = createNode(data);
    newNode->next = head;
    head -> prev = newNode;
    return newNode;
}


//insert at end
Dlinklist* insertAtEnd(Dlinklist *head,int data){
    Dlinklist *newNode = createNode(data);
    Dlinklist *temp = head;
    while(temp ->next != NULL){
        temp = temp ->next;
    }
    temp ->next = newNode;
    newNode ->prev = temp;
    return head;
}


Dlinklist* insertBetween(Dlinklist *head, int data, int pos){
    Dlinklist *newNode = createNode(data);
    Dlinklist *temp = head;
    int i = 0;
    while(i < pos-1){
        temp = temp->next;
        i++;
    }    
    temp->next->prev = newNode;
    newNode->next = temp->next;    
    temp->next = newNode;
    newNode->prev = temp;
    return head;

}

Dlinklist* deleteNode(Dlinklist *head, int pos){
    Dlinklist *temp = head;
    if(pos == 0){
        head = head->next;
        head ->prev = NULL;
        return head;
    }
    int i = 0;
    while(i < pos-1){
        temp = temp->next;
        if(temp->next == NULL){
            temp->next ->prev->next = NULL;
            temp->next ->prev = NULL;
            free(temp);
            return head;
        }
        i++;
    }
    temp->next = temp->next->next;
    temp->next->prev = temp;
    return head;
}



void printList(Dlinklist *head){
    Dlinklist *temp = head;
    while(temp != NULL){
        if (temp ->next ==NULL){
            printf("%d", temp->data);
            break;
        }
        else{
            printf("%d <-> ", temp->data);
            
        }
        temp = temp->next;
    }
    printf("\n");
}

void freeList(Dlinklist *head){
    Dlinklist *temp = head;
    while(temp != NULL){
        temp = temp->next;
        free(head);
        head = temp;
    }
}
int main(){
    Dlinklist *head = createNode(2);
    head = insertAtBegin(head, 1);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 5);
    head = insertBetween(head, 4, 3);
    printList(head);
    printf("After Deletion\n");
    head = deleteNode(head, 4);
    printList(head);
    return 0;
}