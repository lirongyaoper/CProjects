/*
 * paratra.c
 *
 *  Created on: Oct 14, 2024
 *      Author: lirongyaoper
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>

//******************************************************************************************************
//void test(int a[3][5],int r,int c){
//	int i = 0;
//	int j = 0;
//	for(i = 0;i < r; i++){
//		for(j = 0; j < c; j++){
//			printf("%d ",a[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//
//int main(){
//	int arr[3][5] = {{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7}};
//	test(arr, 3, 5);
//
//	return 0;
//}
//******************************************************************************************************
//void test(int (*p)[5],int r,int c){
//	int i = 0;
//	int j = 0;
//	for(i = 0;i < r; i++){
//		for(j = 0; j < c; j++){
//			printf("%d ",(*(p)+i)[j]);
//			//printf("%d ",*(*(p+i)+j));
//		}
//		printf("\n");
//	}
//}
//
//
//int main(){
//	int arr[3][5] = {{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7}};
//	test(arr, 3, 5);
//
//	return 0;
//}
