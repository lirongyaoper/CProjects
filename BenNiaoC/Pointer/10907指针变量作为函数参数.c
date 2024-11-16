/*
 * 1097指针变量作为函数参数.c
 *
 *  Created on: Nov 4, 2024
 *      Author: lirongyaoper
 */


/*
*在C语言中，函数的参数不仅可以是整数、小数、字符等具体的数据，还可以是指向它们的指针。用指针变量作函数参数可以将函数外部的地址传递到函数内部，使得在函数内部可以操作函数外部的数据，并且这些数据不会随着函数的结束而被销毁。
*
*像数组、字符串、动态分配的内存等都是一系列数据的集合，没有办法通过一个参数全部传入函数内部，只能传递它们的指针，在函数内部通过指针来影响这些数据集合。
*有的时候，对于整数、小数、字符等基本类型数据的操作也必须要借助指针，一个典型的例子就是交换两个变量的值。
*/


/*#include <stdio.h>
void swap(int *p1, int *p2){
    int temp;  //临时变量
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
int main(){
    int a = 66, b = 99;
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}*/




/*
#include <stdio.h>
int max(int *intArr,int len){
	int i,maxValue = intArr[0];
	for(i =1; i < len; i++){
		if (maxValue < intArr[i]){
			maxValue = intArr[i];
		}
	}
	return maxValue;
}


int main(){
	int nums[6], i;
	int len = sizeof(nums)/sizeof(int);
	for (i = 0; i < len; i++){
		scanf("%d", nums+i);
	}
	printf("Max value id %d!\n",max(nums,len));
	return 0;
}
*/
