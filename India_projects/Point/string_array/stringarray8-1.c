#include<stdio.h>
#include<string.h>
int main(){
    char C[5];
    C[0] = 'J';
    C[1] = 'O';
    C[2] = 'H';
    C[3] = 'N';
    C[4] = '\0'; // Null-terminate the string to avoid undefined behavior
    printf("%s\n", C); // Print the string stored in C
    return 0;
}