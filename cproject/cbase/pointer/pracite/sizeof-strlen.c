/*
 * sizeof-strlen.c
 *
 *  Created on: Oct 25, 2024
 *      Author: lirongyaoper
 */


#include <stdio.h>
#include <string.h>
#include <assert.h>


//sizeof
//1. 是操作符，不是函数
//2. 是计算变量所占内存空间的大小，单位是字节。
//3. 不关注内存在存放的什么数据
//4. sizeof 括号中有表达式的话，表达式不参与计算的。


//strlen
//1. strlen是库函数，使用需要包含头文件，string.h
//2. 是求字符串的长度，统计的是\0之前字符的个数
//3. 关注的是内存中是否有\0，如果没有\0，就会持续往后找，可能会越届



//int main(){
//	int a = 0;
//	printf("%zd\n", sizeof(a));
//	printf("%zd\n",sizeof(int));
//	return 0;
//}

//*********************************************************
//strlen是c语言的库函数，功能是求字符串的长度

//int main(){
//	size_t len = strlen("abcdef");
//	printf("%zd\n",len);
//	return 0;
//}


//int main(){
//	char str[] = "abcdef";
//	printf("%zd\n",strlen(str));
//	return 0;
//}

//int main(){
//	char arr[] = {'a','b','c','d'};
//	printf("%zd\n",strlen(arr));
//	return 0;
//}



int main(){
	int a = 8;
	short s=4;
	printf("%d\n",sizeof(s = a +2));
	printf("%d\n",s);

	return 0;
}

//*************************************************************
