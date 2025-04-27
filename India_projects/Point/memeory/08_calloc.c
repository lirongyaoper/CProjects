#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int *ptr = (int*)calloc(n,sizeof(int));
    // for(int i = 0; i < n; i++){
    //     *(ptr+ i) = i+1;
    // }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",*(ptr+i));
    }
    
}