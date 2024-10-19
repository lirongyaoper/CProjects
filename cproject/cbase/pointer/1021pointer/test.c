/*
 * test.c
 *
 *  Created on: Oct 19, 2024
 *      Author: lirongyaoper
 */


 #include <stdio.h>
#include <string.h>
#include <assert.h>

//***********************************函数指针***************************************************
//int add(int x, int y){
//	int ret = x +y;
//	return ret;
//}
//int main(){
//	//说明：&函数名和函数名都是函数的地址
//	printf("%p\n",add);
//	printf("%p\n",&add);
//	return 0;
//}
//如果我要把函数的地址保存到一个变量里边去，那么就应该是一个指针变量,，我们思考一下那么这个指针变量的类型应该是什么样的呢？
//	1)首先应该是一个指针 （*p）
//	2)这个指针的类型应该是函数指针类型；就应该是函数类型，函数类型应该有参数和返回值。
//	int (*p)(int,int) = &add;//p先和*结合，说明其为一个指针，指向一个函数，返回类型为int，有两个参数

//***********************************函数指针应用***************************************************
//int add(int x,int y){
//	int ret = x +y;
//	return ret;
//}
//
//int main(){
//	int (*p)(int,int) = &add;
//	printf("%d\n",(*p)(3,5));
//	return 0;
//}
//***********************************函数指针数组***************************************************
//int Add(int x,int y){
//	return x+y;
//}
//
//int Sub(int x, int y){
//	return x -y;
//}
//
//int Mul(int x, int y){
//	return x*y;
//}
//
//int Div(int x, int y){
//	return x / y;
//}
//
////int(*)(int,int) 为上述四个函数的指针地址类型
//
////	int(*pf1)(int,int)  = Add;
////	int(*pf2)(int,int)  = Sub;
////	int(*pf3)(int,int)  =  Mul;
////	int(*pf4)(int,int)  = Div;
//int main(){
//	int (*pfarr[4])(int, int) = {Add,Sub,Mul,Div};
//	return 0;
//}
//***********************************函数指针数组的使用***************************************************

//
//int Add(int x,int y){
//	return x+y;
//}
//
//int Sub(int x, int y){
//	return x -y;
//}
//
//int Mul(int x, int y){
//	return x*y;
//}
//
//int Div(int x, int y){
//	return x / y;
//}
//
//void menu()
//{
//	printf("************************\n");
//	printf("****1.add  2.sub********\n");
//	printf("****3.mul  4.div********\n");
//	printf("****0.exit  ************\n");
//	printf("************************\n");
//}
//
//int main(){
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	int (*pfarr[5])(int ,int) = {NULL,Add,Sub,Mul,Div};
//	do{
//		menu();
//		printf("请选择： \n");
//		scanf("%d",&input);
//		if(input >=1 && input <=4){
//			printf("请输入两个操作数： \n");
//			scanf("%d %d",&x,&y);
//			ret = pfarr[input](x,y);
//			printf("ret = %d \n",ret);
//		}else if(input ==0){
//			printf("退出计算器\n");
//		}else{
//			printf("选择错误，重新选择\n");
//		}
//
//	}while(input);
//	return 0;
//}

