#include<stdio.h>
#include<string.h>
void print(char *c){
    while(*c != '\0'){
        printf("%c",*c);
        c++;
    }
    printf("\n");
}

int main(){
    //char C[20] = "Hello";// string gets stored in the space for array
    char *C = "Hello";//string gets stored as complie time costant   
    print(C);
}