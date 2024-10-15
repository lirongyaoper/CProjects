/*
 * array_pointer.c
 *
 *  Created on: Oct 15, 2024
 *      Author: lirongyaoper
 */


#include <stdio.h>
#include <string.h>
#include <assert.h>

int main(){
	int j = 0;
	int i = 0;
	int arr1[5] = {1,2,3,4,5};
	int arr2[5] = {2,3,4,5,6};
	int arr3[5] = {3,4,5,6,23};
	int* parr[5] = {arr1,arr2,arr3};
	for(i = 0; i<3;i++){
		for(j = 0; j < 5;j ++){
			printf("%d ",*(parr[i] +j));
		}
		printf("\n");
	}
	return 0;
}
