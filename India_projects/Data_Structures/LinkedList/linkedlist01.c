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
    // newNode->data = data;
    (*newNode).data = data;
    newNode->next = NULL;    
    return newNode;
} 


// 该函数功能是将一个新节点插入到链表的头部，但存在一个问题：`head`参数是以值传递的方式传入的，因此对`head`的修改不会影响调用者中的链表头指针。具体逻辑如下：  
// 1. 调用`createNewNode`函数创建一个新节点，并将其数据域设置为`data`。  
// 2. 将新节点的`next`指向当前链表头节点`head`。  
// 3. 更新`head`为新节点，但由于`head`是局部变量，外部链表头指针不会被更新。
// void insertAtBeginning(Node* head,int data ){
//     Node* newNode = createNewNode(data);
//     newNode->next = head;
//     head = newNode;
// }

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

//get the size of the linked list
int getListLength(Node* head){
    int length = 0;
    Node* temp = head;
    while(temp !=NULL){
        length++;
        temp = temp -> next;
    } 
    return length;
}

//reverse the linked list
void reverseList(Node** head){
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while(current != NULL){
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
} 

//merge two sorted linked list
Node* mergeSortedLists(Node* list1, Node* list2){
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    Node* dummy = (Node*)malloc(sizeof(Node));
    if(dummy == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    Node* current = dummy;
    dummy->next = NULL;

    // Node dummy;
    // Node* tail = &dummy;
    // dummy.next = NULL;

    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2 -> data){
            current -> next = list1;
            list1 = list1 -> next;
        }else{
            current -> next = list2;
            list2 = list2 ->next;
        }
        current = current -> next;

    }
    //  add remaining nodes
    current -> next = (list1 != NULL) ? list1 : list2;
    Node* mergedList = dummy -> next;
    free(dummy);
    return mergedList;
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
    Node* head2 = NULL;
    insertAtBeginning(&head2,60);
    insertAtBeginning(&head2,5);
    insertAtEnd(&head2,15);
    insertAtPositon(&head2,25,2);
    insertAtPositon(&head2,35,1);
    printList(head2);

    Node* mergeList= mergeSortedLists(head,head2);
    printList(mergeList);
}
