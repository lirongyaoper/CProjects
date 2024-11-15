/*
 * assert.c
 *
 *  Created on: Sep 25, 2024
 *      Author: lirongyaoper
 */

#include <stdio.h>
#include <assert.h>

//**************************************************************************************************

int main(){
	int a = 10;
	int* pa = &a;
	assert(pa != NULL);
	*pa = 20;
	printf("%d\n",a);
	return 0;
}


//*************************************************************************************************
//int main(){
//	int a = 0;
//	scanf("%d",&a);
//	assert(a != 0);
//	printf("%d",a);
//	return 0;
//}
