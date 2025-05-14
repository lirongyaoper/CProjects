#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//定义链表节点结构体
typedef struct  Node{
    int data;
    struct Node* next;
}Node;

typedef struct Stack{
    Node* top;
    int size;
}Stack;

//创建新阶段
Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("内存分配失败！");
        exit(EXIT_FAILURE);
    }
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}

//初始化栈
void initStack(Stack* s){
    s -> top = NULL;
    s -> size = 0;
}

//判断栈是否为空
bool isEmpty(Stack* s){
    return s -> top == NULL;
}

//获取栈的大小
int size(Stack* s){
    return s -> size;
}

//入栈
void push(Stack* s, int value){
    Node* newNode = createNode(value);
    newNode -> next = s ->top;
    s -> top = newNode;
    s -> size ++;
}

//出栈
bool pop(Stack* s,int* value){
    if(isEmpty(s)){
        printf("Error: stack underflow\n");
        return false;
    }
    Node* temp = s -> top;

    *value = temp -> data;
    s -> top = temp -> next;
    free(temp);
    s->size --;
    return true;
}

//获取栈顶元素
bool peek(Stack* s, int* value){
    if(isEmpty(s)){
        printf("Error: stack underflow \n");
        return false;
    }
    *value = s -> top -> data;
    return true;
}

//清空栈
void clear(Stack *s){
    int temp;
    while (!isEmpty(s))
    {
        pop(s,&temp);
    }   
}

//打印栈中的元素
void printStack(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return;
    }
    printf("stack elememts (from top to bottom)\n");
    Node* current = s ->top;
    while(current != NULL){
        printf("%d ",current -> data);
        current = current -> next;
    }
    printf("\n");
}

int main(){
    Stack stack;
    initStack(&stack);
    
}