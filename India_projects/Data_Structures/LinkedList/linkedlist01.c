#include<stdio.h>
#include<stdlib.h>
// linked list
struct Node{
    int data;
    struct Node *next;

}; //struct Node 
struct Node *head; //head node pointer //global variable,can be accessed from anywhere in the program
int main(){
    head = NULL;
    printf("How many numbers?\n");
    int n, i;
    scanf("%d\n",&n);
    for (i = 0; i < n; i++){
        
    }
}
