#include<stdio.h>
int main()
{
    int tda[2][3];
    //int *p =tda;  //error , tda will return a pointer to One-dimensional array of 3 integers 
    int (*p)[3]=tda;

    //print tda or &tda[0]
    //print *tda or tda[0] or &tda[0][0]
    //print *(tda+1)  or tda[1] 
    //print *(tda+1)+2 or tda[1]+2 or tda[1][2]
    //important
    //tda[i][j] == *(tda[i]+j) == *(*(tda+i)+j)
    printf("Size of tda is %d\n",sizeof(tda));
    printf("%p\n",p);
    printf("%p\n",tda);

    printf("%p\n",&tda[0]);
    printf("%p\n",tda+1);    
    printf("%p\n",&tda[1]);
    

}