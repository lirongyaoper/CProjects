/*
 * pointer_operation.c
 *
 *  Created on: Sep 24, 2024
 *      Author: lirongyaoper
 */

#include <stdio.h>
int main(){

	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int arrsize = sizeof(arr)/sizeof(arr[0]);
	for( int i = 0; i < arrsize; i++){
		printf("%d ",arr[i]);
	}
	return 0;

}

//***************************************************************


//int main(){
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	int i = 0;
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	int* p = &arr[0];
//	for(i = 0; i< sz; i++){
//		printf("%d ",*p);
//		p++;
//	}
//
//
//	return 0;
//}
//***************************************************************

//
//int main(){
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	int i = 0;
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	int* p = &arr[0];
//	for(i = 0; i< sz; i++){
//		printf("%d ",*(p+i));
//
//	}
//
//
//	return 0;
//}

//***************************************************************

//
//int main(){
//	int arr[10] = {0};
//	printf("%d\n", &arr[9]- &arr[0]);
//	return 0;
//}

//***************************************************************
//int my_strlen(char* s){
//	char* p =s;
//	while(*p != '\0'){
//		p++;
//	}
//	return p-s;
//}
//int main(){
//	char arr[] = "aqzswxdecvfrbgt";
//	printf("%d\n",my_strlen(arr));
//	return 0;
//}
//***************************************************************
//***************************************************************
//**********************指针的关系元算******************************
//int main(){
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	int *p =&arr[0];
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	while(p < arr + sz){
//		printf("%d ",*p);
//		p ++;
//
//	}
//	return 0;
//}
//***************************************************************

