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
