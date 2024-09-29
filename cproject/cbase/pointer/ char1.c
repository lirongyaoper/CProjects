/*
 * char.c
 *
 *  Created on: Sep 24, 2024
 *      Author: lirongyaoper
 */
#include <stdio.h>

int main(){
	int a= 0x11223344;
	int* pa = &a;
	*pa = 0;
	return 0;
}

