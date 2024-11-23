#include <stdio.h>
#include <stdlib.h>

int main(){
    int i=0;
    int n = 10;
    int sum = 0;
    while (i<n-1){
        printf("%d ",i);
        sum += 1;
        i++;
    }
    printf("\n");
    printf("%d\n",sum);
    return 0;
}