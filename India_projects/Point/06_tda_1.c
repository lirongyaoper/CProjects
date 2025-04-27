#include<stdio.h>
int main(){
    int B[2][3];
    int (*p)[3] = B;
    printf("%d\n",sizeof(B));
    printf("%d\n",sizeof(p));
    printf("%d\n",sizeof(*p));
    printf("%p\n",B);
    printf("%p\n",&B[0]);
    printf("#########################\n");
    printf("%p\n",*B);
    printf("%p\n",B[0]);

}