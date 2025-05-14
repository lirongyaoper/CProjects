#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// init stack
void initStack(Stack *s){
    s -> top = -1;
}

// check if stsack is empty
 bool isEmpty(Stack *s){
    return s -> top  == -1;
 }

 // check if stack is full
bool isFull(Stack *s){
    return s -> top == MAX_SIZE -1;

}

//  push element
bool push(Stack *s , int value){
    if(isFull(s)){
        printf("Stack Overflow");
        return false;
    }
    s ->data[++(s -> top)] = value;
    return true;
}

// pop element
bool pop(Stack *s, int *value){
    if(isEmpty(s)){
        printf("Error: Stack underflow\n");
        return false;
    }
    *value = s -> data[(s -> top)--];
    return true;
}

bool peek(Stack *s, int *value){
    if(isEmpty(s)){
        printf("Error: Stack underflow\n");
        return false;
    }
    *value = s -> data[s -> top];
    return true;
}

int size(Stack* s){
    return s -> top +1;
}

void clearStack(Stack *s){
    s -> top = -1;
}

void printStack(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for(int i = 0; i <= s -> top; i++){
        printf("%d ", s -> data[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initStack(&stack);
    int choice, value;

   push(&stack, 10);
   push(&stack, 20);
   push(&stack, 30);
   push(&stack, 40);
   push(&stack, 50);
   printStack(&stack);
   pop(&stack, &value);
   printf("Popped value: %d\n", value);
   printStack(&stack);
   peek(&stack, &value);
   printf("Stackdingelement: %d\n", value);

    return 0;
}
