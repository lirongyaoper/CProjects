#include <stdio.h>
#include <stdlib.h>
typedef struct link{
    int data;
    struct link * next;
}Link;

Link* CreateSlink(){
    Link* head = NULL;
    for(int i = 5;i >=1; i--){
        Link* newhead = (Link*)malloc(sizeof(Link));
        newhead->data = i;
        newhead ->next = head;
        head = newhead;
    }
    return head;
}

void print(Link* P){
    while(P!=NULL){
        printf("%d ",P->data);
        P = P->next;
    }
    printf("\n");
    return;
}

Link* reverse(Link* head){
    Link* temp = NULL;
    Link* Phead = NULL;
    while(head!=NULL){
        temp = head;
        head = head ->next;
        temp ->next = Phead;
        Phead = temp;
    }
    return Phead;
}
int main ()
{
	printf("原来的链表的数据:\n"); 
	Link* P=CreateSlink();
	print(P);
	printf("反转后链表的数据:\n"); 
	Link* head=reverse(P);
	print(head);		
	return 0;
}