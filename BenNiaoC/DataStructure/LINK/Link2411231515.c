#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
//https://blog.csdn.net/ffortunateoy/article/details/91359568


////双向链表结点结构体
typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;

}Node;

//创建双向链表结点
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
//双向链表结构体
typedef struct DoubleList{
    Node* head;
    Node* tail;
    size_t size;
}DoubleList;

//初始化双向链表
void init_DoubleList(DoubleList* link){
    link->head = NULL;
    link->tail = NULL;
    link ->size = 0;
    return;
}

//释放链表
void free_DoubleList(DoubleList* link){
    while(link->size){
        Node* temp = link->head;
        link->head = link->head->next;
        free(temp);
        temp = NULL;
        link->size--;
    }
    return;
}
//获取头结点获取头结点获取头结点获取头结点获取头结点
Node* get_head(DoubleList* link){

    return link->head;
}
//获取尾结点
Node* get_tail(DoubleList* link){
    return link->tail;
}

//获取链表长度
size_t get_size(DoubleList* link){
    return link->size;
}


//遍历链表打印链表中所有的元素
void print_DoubleList(DoubleList* link){
    Node* node =  link ->head;
    for (int i  = 0; i < link->size; i++){
        printf("%d ",node->data);
        node = node ->next;
    }
    printf("\n");

}


//插入头结点
    // 需要考虑两种情况：

    //     链表为空，那插入的结点既是头结点，也是尾结点；
    //     链表不为空，将新结点和链表通过前驱指针prev和后继指针next连接起来，并将头结点改为新插入的结点；

void insert_head(DoubleList* link,int data){
    Node* newNode = createNode(data);
    // 链表为空
    if(link->size == 0){
        link->head = newNode;
        link->tail = newNode;
    }
    // 链表不为空
    else{
        newNode->next = link->head;
        link->head->prev = newNode;
        link->head = newNode;
    }
    link->size++;

}

// 插入尾结点
//     和插入头结点一样，需要考虑两种情况：

//         链表为空，那插入的结点既是尾结点，也是头结点；
//         链表不为空，将新结点和链表通过前驱指针prev和后继指针next连接起来，并将尾结点改为新插入的结点；

void insert_tail(DoubleList* link, int data){
    Node* newNode = createNode(data);
    //link is empty
    if(link->size ==0){
        link->head = newNode;
        link->tail = newNode;
    } 
    //链表不为空
    else{
        link->tail->next = newNode;
        newNode ->prev = link->tail;
        link->tail = newNode;
    }
    link-> size++;
    
}

// 在任意位置插入一个结点
//     插入前判断插入的位置是否超出链表的范围，排除插入的位置小于0以及大于链表的长度；
//     插入的位置如果等于0，等同于插入头结点；
//     插入的位置如果等于链表的长度，等同于插入尾结点；
//     插入的位置如果小于等于中间位置，那插入的位置更靠近头结点，我们可以从头结点开始往后遍历到插入的前一个位置；
//     插入的位置如果大于中间位置，那插入的位置更靠近尾结点，我们可以从尾结点开始往前遍历到插入的前一个位置；

bool insertNode(DoubleList* link, int index, int data){
    if(index <0 || index > link->size){
        return false;        
    }
    if(index == 0){
        insert_head(link,data);
        return true;

    }
    else if(index == link->size){
        insert_tail(link,data);
        return true;
    }
    Node* temp = NULL;
    //插入的位置如果小于等于中间位置，那插入的位置更靠近头结点
    //从头结点开始往后遍历到插入的前一个位置
    if(index <= link->size/2){
        temp = link->head;
        for(int i = 0; i < index -1; i++){
            temp = temp -> next;
        }
    }else{
        temp = link->tail;
        for(int i =0; i< link->size - index; i++){
            temp = temp -> prev;
        }
    }
    Node* newNode= createNode(data);
    temp->next->prev  =newNode;
    newNode->next = temp->next;
    temp ->next = newNode;
    newNode->prev = temp;
    link->size++;
    return true;
}


// 删除头结点
//     需要考虑三种情况：

//     链表为空，不操作，直接返回；
//     链表只有一个结点，释放该结点的内存，并初始化链表，将链表长度改为0，头结点和尾结点置为NULL；
//     链表结点大于1，保存头结点，新头结点等于原头结点的下一个结点，然后释放保存的头结点的内存；
void delete_head(DoubleList *link){
    if(link->size == 0){
        return;
    }
    if(link->size == 1){
        free(link->head);//释放头结点的内存
        init_DoubleList(link);//初始化链表
        return;
    }
    Node*  temp = link->head;
    link->head = link->head -> next;
    //link->head = temp->next; 
    link->head->prev = NULL;
    free(temp);
    temp = NULL;
    link->size--;
}
// 删除尾结点
    // 和删除头结点类似

    // 链表为空，不操作，直接返回；
    // 链表只有一个结点，释放该结点的内存，并初始化链表，将链表长度改为0，头结点和尾结点置为NULL；
    // 链表结点大于1，保存尾结点，新尾结点等于原尾结点的上一个结点，然后释放保存的尾结点的内存；
void delete_tail(DoubleList * link){
    if(link ->size ==0){
        return;
    }
    if(link -> size ==1){
        free(link->tail);//释放尾结点的内存
        init_DoubleList(link);//初始化链表
        return;
    }
    Node* temp = link-> tail;
    link->tail = temp ->prev;
    link-> tail ->next = NULL;
    free(temp);
    temp = NULL;
    link->size--;
}


// 删除任意位置结点
//     与在任意位置插入结点类似，

//     删除前判断插入的位置是否超出链表的范围，排除删除的位置小于0以及大于链表的长度；
//     删除的位置如果等于0，等同于删除头结点；
//     删除的位置如果等于链表的长度，等同于删除尾结点；
//     删除的位置如果小于中间位置，那删除的位置更靠近头结点，我们可以从头结点开始往后遍历到删除的结点；
//     删除的位置如果大于等于中间位置，那删除的位置更靠近尾结点，我们可以从尾结点开始往前遍历到删除的结点；
bool deleteNode(DoubleList* link, int index){
    //判断插入的位置是否超出链表的范围
    if(index < 0 || index > link->size){
        return false;
    }
    //删除的位置如果等于0，等同于删除头结点
    if(index ==0){
        delete_head(link);
        return true;
    }
    //删除的位置如果等于链表的长度，等同于删除尾结点
    if(index ==link->size){
        delete_tail(link);
        return true;
    }

    Node* temp = NULL;
    //删除的位置如果小于中间位置
    if(index <= link->size/2){
         //从头结点开始往后遍历到删除的的结点
        temp = link->head;
        for(int i = 0; i < index; ++i){
            temp = temp -> next;
        }

    }
    //删除的位置如果大于等于中间位置
    else{
        //从尾结点开始往前遍历到删除的结点
        temp = link->tail;
        for(int i = 0; i < link->size - index-1; i++){
            temp = temp -> prev;
        }
    }

    temp ->prev -> next = temp->next;
    temp -> next ->prev = temp ->prev;
    free(temp);
    temp = NULL;
    link->size--;
    return true;
}



// 获取任意节点位置
//     遍历前判断插入的位置是否超出链表的范围，排除删除的位置小于0以及大于链表的长度；
//     目标结点的位置如果小于中间位置，那目标结点的位置更靠近头结点，我们可以从头结点开始往后遍历到目标结点；
//     目标结点的位置如果大于等于中间位置，那目标结点的位置更靠近尾结点，我们可以从尾结点开始往前遍历到目标结点；

Node* getNode(DoubleList* link, int index){
    //判断插入的位置是否超出链表的范围
    if(index < 0 || index > link->size){
        return NULL;
    }
    Node* node = NULL;
    //目标结点的位置如果小于中间位置
    if(index <= link->size/2){
        //从头结点开始往后遍历到目标结点
        node = link->head;
        for(int i = 0; i <index; i++){
            node  = node ->next;
        }
    //目标结点的位置如果大于等于中间位置
    }else if (index >= link->size/2){
         //从尾结点开始往前遍历到目标结点
         node = link->tail;
         for(int i = 0; i <link->size -index-1; i++){
            node =  node ->prev;
         }
    }
    return node;
}


//获取链表中指定数据所在的第一个结点
Node* getNodeByData(DoubleList* link, int data){
    if(link->size ==0){
        return NULL;

    }
    Node* node = link->head;
    while(node ){
        if(node->data == data){
            return node;
        }
        node = node ->next;
    }
    return NULL;
}


// 修改链表中指定结点的值
//     先获取到目标位置的结点，再修改目标结点的值

bool ModifyNode(DoubleList* link, int index, int data){
    Node* node = getNode(link, index);
    if(node){
        node->data = data;
        return true;
    }
    return false;
}


// 修改链表中指定的第一个数据
//     先获取目标数据所在的第一个结点，再修改改结点的值
bool ModifyNodeByData(DoubleList* link, int data, int newData){
    Node* node = getNodeByData(link, data);
    if(node){
        node->data = newData;
        return true;
    }
    return false;
}

void test_insert_del_node(){
    DoubleList* dlink = (DoubleList*)malloc(sizeof(DoubleList));
    init_DoubleList(dlink);
    printf("insert head and insert tail--------------\n");
    insert_head(dlink,5);
    insert_tail(dlink,15);
    print_DoubleList(dlink);
    printf("list length : %zd\n", get_size(dlink));
    printf("insert nodes at any location-----------------\n");
    insertNode(dlink,0,1);
    insertNode(dlink,2,10);
    insertNode(dlink,4,20);
    print_DoubleList(dlink);
    printf("list length : %zd\n", get_size(dlink));  
    printf("delete head and tail-----------------\n");
    delete_head(dlink);
    delete_tail(dlink);
    print_DoubleList(dlink);
    printf("list length : %zd\n", get_size(dlink));
    printf("delete nodes at any location-----------------\n");
    deleteNode(dlink,1);
    print_DoubleList(dlink);
    printf("list length : %zd\n", get_size(dlink));
}


void test_find_node(){
    DoubleList* dlink = (DoubleList*)malloc(sizeof(DoubleList));
    init_DoubleList(dlink);
    printf("create a test double link-------------------");
    for (int i =0; i <=10;i++){
        insert_tail(dlink,i);
    }
    print_DoubleList(dlink);
    printf("list length: %zd\n",get_size(dlink));
    printf("get the node through the index---------------\n");
    Node* node = getNode(dlink,7);
    if(node){
        printf("success,data:%d\n",node->data);
    }else{
        printf("index out of the range\n");
    }
    Node* node1 = getNode(dlink,12);
    if(node1){
        printf("success,data:%d\n",node->data);
    }else{
        printf("index out of the range\n");
    }

    printf("get the node through the data---------------\n");
    Node* node2 = getNodeByData(dlink,7);
    if(node2){
        printf("success,data:%d\n",node->data);
    }else{
        printf("data not found\n");
    }
    Node* tmp = getNodeByData(dlink,12);
    if(tmp){
        printf("success,data:%d\n",tmp->data);
    }else{
        printf("data not found\n");
    }

}
int main(){
    //test_insert_del_node();
    test_find_node();
}