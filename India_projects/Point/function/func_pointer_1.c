#include<stdio.h>
#include<stdlib.h>
//  function pointer can be passed as argument to another function 
 void A(){
    printf("Hello\n");
 }

 void B(void (*ptr)()){  // function pointer as argument
    ptr();  // call-back  function that is passed as argument
 }

 int main(){
    void (*p)() = A;
    B(p);
 }