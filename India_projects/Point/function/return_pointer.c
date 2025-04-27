#include<stdio.h>
#include<stdlib.h>
void PrintHelloWorld(){
    printf("Hello World\n");
}

int *Add(int*a ,int *b){
    int c = *a + *b;
    return &c;
}

int main(){
    int a =2,b = 4;
    int *ptr = Add(&a,&b);
    PrintHelloWorld();
    printf("%d\n",*ptr); //error here  :Add函数接受两个int指针参数a和b，然后计算它们的和c。这里返回的是局部变量c的地址。问题来了，因为c是在Add函数中定义的局部变量，当Add函数执行完毕后，c的内存空间会被释放，也就是栈上的内存可能被其他数据覆盖。这时候返回指向c的指针会导致悬垂指针的问题，即ptr指向的内存区域已经不再有效。这种情况下，访问*ptr会导致未定义行为，可能输出错误的值，或者程序崩溃。
}