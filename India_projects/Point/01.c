#include<stdio.h>
int main(){
    int a ;
    int *p;
    a = 10;
    p = &a;  //&a = address of a
    printf("%d\n",a);
    *p = 12;

    int b = 20;
    *p = b;
    
    printf("%d\n",p);
    printf("%d\n",*p);
    printf("%d\n",&a);
}