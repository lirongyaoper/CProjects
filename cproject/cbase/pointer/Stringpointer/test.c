/*
 * test.c
 *
 *  Created on: Oct 12, 2024
 *      Author: lirongyaoper
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
int main(){
	char ch = 'w';
	char* pc = &ch;
	printf("%c\n",*pc);
	return 0;
}
