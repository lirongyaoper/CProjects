#include <stdio.h>
#include <string.h>
int main()
{
    int a[] = {1,2,3,4};
    printf("%d\n",sizeof(a));
    printf("%d\n",sizeof(a+0));
    printf("%d\n",sizeof(*a));
    printf("%d\n",sizeof(a+1));
    printf("%d\n",sizeof(a[1]));
    printf("%d\n",sizeof(&a));
    printf("%d\n",sizeof(*&a));
    printf("%d\n",sizeof(&a+1));
    return 0;
}