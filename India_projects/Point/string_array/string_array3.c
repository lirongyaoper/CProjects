#include<stdio.h>
#include<string.h>
int main(){
    char C1[6] = "Hello"; // Initialize the string with a null terminator
    char* C2 ;
    C2 = C1; // Point C2 to the string in C1
    printf("char_1 = %c\n",C2[1]); // Print the second character of the string
    C2[1] = 'l';
    printf("C1 = %s\n", C1); // Print the modified string
    return 0;
}