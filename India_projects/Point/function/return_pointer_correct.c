#include<stdio.h>
#include<stdlib.h>
void PrintHelloworld(){
    printf("Hello World\n");
}

int *Add(int *a, int *b){
    int *c = (int *)malloc(sizeof(int)); //  allocate memory
    *c = *a + *b; // addition
    return c;
}

int main(){
    int a = 10;
    int b = 20;
    int *c = Add(&a, &b); 
    printf("%d\n", *c);
    free(c);
    return 0;
}