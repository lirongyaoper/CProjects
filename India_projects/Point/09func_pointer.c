#include<stdio.h>
int Add(int a, int b){
    return  a+b ;
}
int main(){
    int c;
    int (*p)(int ,int);
    p  = &Add;            
    c = (*p)(20,30);
    printf("%d",c);
}