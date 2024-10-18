/*
 * test.c
 *
 *  Created on: Oct 18, 2024
 *      Author: lirongyaoper
 */


#include <stdio.h>
#include <string.h>
#include <assert.h>

//**************************************************************************************

int main(){
	const char * p = "hello world";
	printf("%s\n",p);
	printf("%s\n","hello world");
	int lenstr = strlen(p);
	int i = 0;
	for(i = 0; i < lenstr; i++){
		printf("%c" ,*(p+i));
	}

	return 0;
}
