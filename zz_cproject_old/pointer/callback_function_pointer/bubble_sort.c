/*
 * bulluesort.c
 *
 *  Created on: Oct 23, 2024
 *      Author: lirongyaoper
 */


#include <stdio.h>
#include <string.h>
#include <assert.h>

//
//void bubble_sort(int arr[],int sz){
//	int i = 0;
//	for(i = 0;i< sz-1; i++){
//		int j = 0;
//		for(j = 0; j < sz -1-i; j++){
//			if(arr[j] > arr[j+1]){
//				int tmp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j+1] = tmp;
//			}
//		}
//	}
//}
//
//void print_arr(int arr[],int sz){
//	int i = 0;
//	for(i = 0; i < sz; i++){
//		printf("%d ",arr[i]);
//	}
//}
//
//int main(){
//	int arr[] ={9,8,7,6,4,3,2,1,0};
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	bubble_sort(arr,sz);
//	print_arr(arr,sz);
//	return 0;
//}
