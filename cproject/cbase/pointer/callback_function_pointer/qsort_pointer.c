/*
 * qsort_pointer.c
 *
 *  Created on: Oct 23, 2024
 *      Author: lirongyaoper
 */


#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>


//void qsort(void* base, //指针，指向的是待排序数组的第一个元素。
//			  size_t num, //待排序数组的元素个数
//			  size_t size,//指向待排数组的元素的大小
//			  int(*compar)(const void*, const void*)//void* 类型的指针是无具体类型的指针，这种类型的指针不能直接解引用，也不能进行+-整数的运算。
//
//);


void print_arr(int arr[],int sz){
	int i = 0;
	for(i = 0; i < sz; i++){
		printf("%d ",arr[i]);
	}
}

//int cmp_int(const void* p1,const void* p2){
//	if(*(int*)p1 > *(int*)p2)
//		return 1;
//	else if(*(int*)p1 == *(int*)p2)
//		return 0;
//	else
//		return -1;
//}

//*************************************整型数组比较start**************************************
int cmp_int(const void* p1,const void* p2){
	return *(int*)p1 -*(int*)p2;
}
void test1(){
	int arr[] = {9,8,7,6,11,5,4,3,2,19,1,0};
	int sz = sizeof(arr)/sizeof(arr[0]);
	qsort(arr,sz,sizeof(arr[0]),cmp_int);
	print_arr(arr,sz);
}
//*************************************整型数组比较end**************************************

//*************************************结构体比较start**************************************
struct Stu{
	char name[20];
	int age;
};
//这里的两个结构体元素如何比较大小？
//1. 按照名字比较，比较字符串
int cmp_stu_by_name(const void* p1, const void* p2){
	return strcmp(((struct Stu*)p1) ->name,((struct Stu*)p2)->name);
}
//2. 按照年龄比较，比较整型


void test2(){
	struct Stu arr[3] = {{"zhangsan",20},{"lishi",26},{"wangjun",18}};
	int sz = sizeof(arr)/sizeof(arr[0]);
	qsort(arr,sz,sizeof(arr[0]),);
}


int main(){
//	test1();
	test2();

	return 0;

}
