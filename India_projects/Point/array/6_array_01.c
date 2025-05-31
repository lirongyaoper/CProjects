#include<stdio.h>
int main()
{
	int A[5]={2,4,6,8,10};
	int *p = A;
	printf("%p\n",p);
	printf("%p\n",A+1);//(A+i) is same as &A[i]
    printf("%p\n",&A[1]);
	printf("%d\n",*(A+2));//*(A+i) is same as A[i]
    printf("%d\n",A[2]);
    
}