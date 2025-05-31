#include<stdio.h>
#include<string.h>
int main (){
    char C[] = "JOIN"; // Initialize the string with a null terminator
    char C4[] = {'J', 'O', 'I', 'N', '\0'}; // Initialize the string with a null terminator
    printf("C = %s\n", C); // Print the string
    printf("Size in bytes = %d\n", sizeof(C));//Print the size of the array in bytes
    int len = strlen(C);// Get the length of the string
    printf("Length = %d\n",len);// Print the length of the string
    return 0;
}