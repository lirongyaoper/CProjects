/*
 * test.c
 *
 *  Created on: Oct 12, 2024
 *      Author: lirongyaoper
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
//*********************************************************************************

//		char arr[] = "hello world";
//		char* p = arr;
//*********************************************************************************
//int main(){
//	char ch = 'w';
//	char* pc = &ch;
//	printf("%c\n",*pc);
//	return 0;
//}
//*********************************************************************************
//int main(){
//	const char* p = "hello world";//常量字符串，不允许修改；
//	printf("%c\n",*p);
//
//	return 0;
//}
//*********************************************************************************
//int main(){
//	const char* p  = "hello world";
//	printf("%s\n",p);//printf("%s\n","hello world");
//	return 0;
//}

//*********************************************************************************
//int  main(){
//	const char* p ="hello world";
//	int len = strlen(p);
//	int i = 0;
//	for(i = 0 ;i <len; i++){
//		printf("%c",p[i]);
//		//printf("%c",*(p+i));
//	}
//	printf("\n");
//	return 0;
//}
//*********************************************************************************
//int main(){
//	char arr[] = "abcdefg";
//	char* p = arr;
//	printf("%s\n",arr);
//	printf("%s\n",p);
//	return 0 ;
//}
//***********************************剑指offcer**********************************************
//int main(){
//	char str1[] = "hello bit.";
//	char str2[] = "hello bit.";
//	const char* str3 = "hello bit.";
//	const char* str4 = "hello bit.";
//	if(str1 == str2){
//		printf("str1 and str2 are same\n");
//	}else{
//		printf("str1 and str2 are not same\n");
//	}
//	if(str3 == str4){
//		printf("str3 and str4 are same\n");
//	}else{
//		printf("str3 and str4 are not same\n");
//	}
//	return 0;
//}
//***********************************数组指针的写法**********************************************
//int main(){
//	int arr[10] = {0};
//	int (*p)[10] = &arr;//&arr 取出的是数组的地址   p元素的类型是  int(*)[10]
//	//p是数组指针，既然是指针，p的前面肯定是要和"*"连在一起，p指向的是数组，数组有10个元素，每个月元素的类型是int
//	return 0;
//
//}
//***********************************数组指针的写法(练习1)**********************************************
//int main(){
//	char arr[5];
//	char (*p)[5] = &arr;  //p元素的类型是char (*)[5]
//	return 0;
//}
//***********************************数组指针的写法(练习2)**********************************************
//int main(){
//	char* arr[5];
//	char* (*p)[5] = &arr; //p元素的类型是 char* (*)[5]
//	return 0;
//}

////***********************************数组指针的写法(练习2)**********************************************

								//int (*p) [10] = &arr;
								// |    |    |
								// |    |    |
								// |    |    p指向数组的元素个数
								// |    p是数组指针变量名
								// p指向的数组的元素类型
