/*
 * test.c
 *
 *  Created on: Oct 19, 2024
 *      Author: lirongyaoper
 */


 #include <stdio.h>
#include <string.h>
#include <assert.h>

//***********************************函数指针即函数指针数组***************************************************
int add(int x, int y){
	int ret = x +y;
	return ret;
}
int main(){
	printf("%p\n",add);
	printf("%p\n",&add);
	return 0;
}
