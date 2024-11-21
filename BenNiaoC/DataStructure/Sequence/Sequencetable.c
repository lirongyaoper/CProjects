#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct {
    int* head;//定义一个名为head的长度不确定的数组，也叫“动态数组”
    int length; //记899,录当前顺序表的长度
    int size;//记录顺序表的存储容量
}Table;


//创建顺序表
void initTable(Table* T){
    //构造一个空的顺序表，动态申请存储空间
    T->head = (int*)malloc(MAXSIZE*sizeof(int));
    //如果申请失败，作出提示并直接退出程序
    if(!T->head){
        printf("存储分配失败！");
        exit(0);
    }
    //空表的长度初始化为0
    T->length = 0;
    //空表的初始存储空间为Size
    T->size = MAXSIZE;
    
}

//插入函数，其中，elem为插入的元素，insert_local为插入到顺序表的位置,位置标号从零开始
void insertTable(Table* T,int elem,int insert_local){
    int i;
    //如果插入元素位置比整张表的长度+1还大（如果相等，是尾随的情况），或者插入的位置本身不存在，程序作为提示并自动退出
    if (insert_local > T->length +1 || insert_local < 1){
        printf("插入位置不合法！");
        exit(0);
    }
        
    //判断是否需要扩容
    if(T->length == T->size){
        //动态申请存储空间
        T->head = (int*)realloc(T->head,2*T->size*sizeof(int));
        //如果申请失败，作出提示并直接退出程序
        if(!T->head){
            printf("存储分配失败！");
            exit(0);
        } 
        
        T->size *= 2;
        //插入操作，需要将自插入位置之后的所有元素全部后移一位
        //插入操作，需要将自插入位置之后的所有元素全部后移一位
        for (i = T ->length-1;i >=insert_local-1;i--){
            T->head[i+1] = T->head[i];
        }
        //后移完成后，直接插入元素
        T->head[insert_local - 1] = elem;
        T->length++;
        
    }
}

//删除函数 (依据位置删除)
void deleteTable(Table* T,int delete_local){
    int i;
    //如果删除位置不合法，则提示并退出程序
    if(delete_local > T->length || delete_local < 1){
        printf("删除位置不合法！");
        exit(0);
    }
    //删除操作，需要将自删除位置之后的所有元素全部前移一位
    for(i=delete_local;i<T->length;i++){
        T->head[i -1]  = T->head[i];

    }
    T ->length--;
    
}


//查找函数
int searchTable(Table *T,int elem){
    int i;
    for (i = 0; i< T->length; i++){
        if (T->head[i] ==elem)
        {
            return i + 1;
        }
        
    }
    return -1;
}

//更改函数
void amendTable(Table* T, int elem, int newElem) {
    int add = searchTable(T, elem);
    if (add == -1) {
        printf("顺序表中没有找到目标元素\n");
        return;
    }
    T->head[add - 1] = newElem;
}

//输出顺序表中元素的函数
void displayTable(Table* T){
    printf("顺序表元素为：");
    for(int i=0;i<T->length;i++){
        printf("%d ",T->head[i]);
    }
    printf("\n");
    return;
    
}

// int main(){
//     int i;
//     Table T = {NULL,0,0};
//     initTable(&T);
//     for(i=1;i<MAXSIZE;i++){
//         T.head[i -1] = i;
//         T.length++;
//     }
//     printf("顺序表中存储的元素分别是：\n");
//     displayTable(&T);
//     free(T.head);
//     return 0;
// }

int main(){
    int i, add;
    Table T = {NULL,0,0};
    initTable(&T);
    for(i=1;i<=MAXSIZE;i++){
        insertTable(&T,i,i);
        T.head[i - 1] = i;
        T.length++;
    }
    printf("原顺序表：\n");
    displayTable(&T);
    printf("删除元素1:\n");
    deleteTable(&T, 1);
    displayTable(&T);    
    printf("在第2的位置插入元素5:\n");
    insertTable(&T, 5, 2);
    displayTable(&T);
    printf("查找元素3的位置:\n");
    add = searchTable(&T, 3);
    printf("%d\n", add);

    printf("将元素3改为6:\n");
    amendTable(&T, 3, 6);
    displayTable(&T);    
    return 0;
}