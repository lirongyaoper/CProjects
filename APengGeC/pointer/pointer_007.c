#include <stdio.h>
void test(int(*p)[5],int r ,int c){
    int i = 0;
    int j  =0;
    for(i = 0;i < r ;i++){
        for (j = 0;j<c; j++){
            printf("%d ",*(*(p+i)+j));
        }
        printf("\n");
    }
}

int main(){
    int arr[3][5] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    test(arr,3,5);
    return 0;
}