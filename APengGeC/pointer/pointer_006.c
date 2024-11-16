#include <stdio.h>
int main(){
    int arr[10]  ={0};
    int (*parr)[10] = &arr;
    return 0;
}