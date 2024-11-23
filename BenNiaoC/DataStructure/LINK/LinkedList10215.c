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
    int i = 1;
    while(i < pos){
        temp = temp->next;
        i++;
    }    
    temp->next->prev = newNode;
    newNode->next = temp->next;    
    temp->next = newNode;
    newNode->prev = temp;
    return head;

}

// Dlinklist* deleteNode(Dlinklist *head, int pos){
//     Dlinklist *temp = head;
//     if(pos == 1){
//         head = head->next;
//         head ->prev = NULL;
//         return head;
//     }
//     int i = 1;
//     while(i < pos){
//         //temp = temp->next;
//         if(temp->next == NULL){
//             temp->prev->next = NULL;
//             temp->prev = NULL;
//             free(temp);
//             return head;
//         }
//         temp = temp->next;
//         i++;
//     }
//     temp->next = temp->next->next;
//     temp->next->prev = temp;
//     return head;
// }

Dlinklist* deleteNode(Dlinklist *head, int data){
    Dlinklist* temp = head;
    while(temp){
        if(temp ->data == data){
            // 删除表头结点的实现过程是：
            // 新建一个指针指向表头结点；
            // 断开表头结点和其直接后续结点之间的关联，更改 head 头指针的指向，同时将其直接后续结点的 prior 指针指向 NULL；
            // 释放表头结点占用的内存空间。
            if(temp->prev ==NULL){
                head = head->next;
                if(head ){
                    head->prev = NULL;
                    temp->next = NULL;

                }
                free(temp);
                return head;
            }
            // 删除中间结点的实现过程是：
            // 新建一个指针指向待删除结点；
            // 将其直接后续结点的 prior 指针指向其直接前驱结点，同时将其直接前驱结点的 next 指针指向其直接后续结点；
            // 释放待删除结点的内存空间。
            if(temp ->prev &&temp->next){
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                free(temp);
                return head;
            }
            // 删除表尾结点的实现过程是：
            // 新建一个指针指向待删除结点；
            // 将其直接前驱结点的 next 指针指向 NULL，同时将其 prior 指针指向其直接后续结点；
            // 释放待删除结点的内存空间。
            if(temp->next ==NULL){
                temp->prev->next = NULL;
                temp->prev = NULL;
                free(temp);
                 return head;
            }
        }
        temp = temp->next;
    }
    printf("Node not found. failed to delete.\n");
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
    head = deleteNode(head, 5);
    printList(head);
    return 0;
}