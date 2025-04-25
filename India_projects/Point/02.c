#include<stdio.h>
int main(){
    int a = 1024;
    int *p ;
    p = &a;
    printf("size of integer is %d  bytes\n",sizeof(int));
    printf("Address = %d, value = %d\n",p,*p);
    printf("Address = %d, value = %d\n",p+1,*(p+1));
    char *P_0;
    P_0 = (char*)p;
    printf("size of char is %d\n",sizeof(char));
    printf("Address = %d, value = %d\n",P_0,*P_0);
    printf("Address = %d, value = %d\n",P_0+1,*(P_0+1));    

}