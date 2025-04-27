#include<stdio.h>
#include<stdlib.h>

int compare(int a,int b){
     if (a > b)  return 1;
     else return -1;
     
}
void BubbleSort(int A[],int n,int (*compare)(int, int)){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(compare(A[j],A[j+1])> 0 ){ //compare function is used to compare two elements
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int main(){
    int A[] = {3,2,1,5,6,4};
    int n = sizeof(A)/sizeof(A[0]);
    BubbleSort(A,n,compare);
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}