#include<stdio.h>
int main()
{
    int A[] ={2,4, 5,8,1};
    int i;
    for(int  i =0; i < 5; i++){
        printf("Address of %p\n",&A[i]);
        printf("Address = %p\n", A+i);
        printf("Value = %d\n",A[i]);
        printf("Value = %d\n",*(A+i));
        
    }
}
//数组的变量名A返回数组首个元素地址的指针