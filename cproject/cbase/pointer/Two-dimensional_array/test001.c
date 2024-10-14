/*
 * test001.c
 *
 *  Created on: Oct 14, 2024
 *      Author: lirongyaoper
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>

//**************************************************经典写法************************************************************
//int main(){
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	int *p  = arr;
//	int i = 0;
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	for(i = 0 ; i < sz; i++){
//		printf("%d ",*(p+i));
//	}
//	return 0;
//}


//**************************************************数组指针写法*************************************************************

//int main(){
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	int (*p)[10]  = &arr;
//	int i = 0;
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	for(i = 0 ; i < sz; i++){
//		printf("%d ",(*p)[i]);//(*p)[i] 而非*p[i],因为[]的结合性更强
//	}
//	return 0;
//}



