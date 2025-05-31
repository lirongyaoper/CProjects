#include<stdio.h>
int SumOfElements(int A[],int size){// "int A[]" or "int* A"   it's the same...
    int i, sum = 0;
    printf("SOE - size of A = %d, size of A[0] = %d\n",sizeof(A), sizeof(A[0]));
    for(i = 0; i <size; i++){
        sum += A[i];    // A[i] is same as *(A+i)
    }
    return sum; // Return the total sum of elements
}

int main(){
    int A[]={1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(A) / sizeof(A[0]);
    int total = SumOfElements(A,size);
    printf("Sum of elements in the array is: %d\n", total);
    printf("MAIN - size of A = %d, size of A[0] = %d\n",sizeof(A), sizeof(A[0]));
}