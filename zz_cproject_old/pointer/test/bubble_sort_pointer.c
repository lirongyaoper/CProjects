/*
 * bubble_sort_pointer.c
 *
 *  Created on: Oct 12, 2024
 *      Author: lirongyaoper
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
//*****************************************************************************************
//void bubble_sort (int arr[],int sz){
//	int i = 0;
//	for(i = 0;i < sz -1; i++){
//		int flag = 1;
//		int j = 0;
//		for(j = 0; j < sz-i-1;j++){
//			if(arr[j]>arr[j+1]){
//				flag = 0;
//				int tmp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j+1] = tmp;
//			}
//		}
//		if(flag ==1){
//			break;
//		}
//	}
//}
//
int main(){
	int arr[] = {3,1,7,5,8,9,0,2,4,6};
	int sz = sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr,sz);
	int i = 0;
	for (i =0;i < sz;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}

