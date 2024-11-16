#include <stdio.h>
int main(){
    int arr[10] = {0};
    int i = 0;
    int sz = sizeof(arr)/sizeof(arr[0]);
    int* p = arr;
    for (i = 0; i < sz; i++){
        scanf("%d", p);
        p++;
    }
    for  (i = 0; i <sz; i++){
        printf("第%d个元素的值为：%d\n", i+1, *(arr+i));
        
    }
    return 0;
    
}