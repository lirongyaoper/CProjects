/*
 * array_pointer.c
 *
 *  Created on: Oct 15, 2024
 *      Author: lirongyaoper
 */


#include <stdio.h>
#include <string.h>
#include <assert.h>

//***************************************************************
//int main(){
//	int j = 0;
//	int i = 0;
//	int arr1[5] = {1,2,3,4,5};
//	int arr2[5] = {2,3,4,5,6};
//	int arr3[5] = {3,4,5,6,23};
//	int* parr[5] = {arr1,arr2,arr3};
//	for(i = 0; i<3;i++){
//		for(j = 0; j < 5;j ++){
//			printf("%d ",*(parr[i] +j));
//		}
//		printf("\n");
//	}
//	return 0;
//}
//***************************************************************

//int main(){
//	int arr[10] ={1,2,3,4,5,6,7,8,9,10};
//	int (*p)[10] = &arr;
//	//int * p = &arr;
//	return 0;
//
//}
//***************************************************************

//int main(){
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	int(*p)[10] = &arr;  //p == &arr;
//	int i = 0;
//	for(i =0; i <10; i++){
//		printf("%d ",(*p)[i]);
//		printf("%d ",*(*p +i));
//		printf("%d ",*&arr[i]);
//	}
//	return 0;
//}
//***************************************************************
//int main(){
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	printf("&arr[0] = %p\n",&arr[0]);
//	printf("arr   = %p\n", arr);
//	return 0;
//}
//***************************************************************
//int main(){
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	printf("%d ",sizeof(arr));
//	return 0;
//}

//***************************************************************
//int main(){
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	printf("&arr[0] = %p\n",&arr[0]);
//	printf("arr     = %p\n",arr);
//	printf("&arr    =%p\n",&arr);
//	return 0;
//}


//***************************************************************
//int main(){
//	int arr[10] = {0};
//	int i = 0;
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	int *p = arr;
//	for(i = 0 ;i < sz; i++){
//		scanf("%d",p+i);
//	}
//	for(i = 0; i < sz; i++){
//		printf("%d ",*(p+i));
//
//	}
//	return 0;
//}
//***************************************************************
//int main(){
//	int arr1[] = {1,2,3,4,5};
//	int arr2[] = {2,3,4,5,6};
//	int arr3[] = {3,4,5,6,7};
//	int* arr[3] = {arr1,arr2,arr3};
//	int i = 0;
//	for(i = 0; i < 3; i++){
//		int j = 0;
//		for(j = 0; j < 5; j++){
//			printf("%d ",*(arr[i]+j));
//		}
//		printf("\n");
//	}
//
//	return 0;
//}
//

//***************************************************************

//
//int main(){
//
//	char* pstr = "hello bit.";
//	printf("%s\n", pstr);
//	return 0;
//}
