//实现对有头结点链表的“增删查改”：

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct link{
    int elem;
    struct link* next;
}Link;

Link* initLink(){
    Link* temp = (Link*)malloc(sizeof(Link));
    temp->elem = 0;
    temp->next = NULL;
    Link* p = temp;
    for(int i = 1; i <5; i++){
        Link* a = (Link*)malloc(sizeof(Link));
        a->elem = i;
        a->next = NULL;
        temp -> next = a;
        temp  = temp ->next;
        
    }
return p;
}

//p为链表，elem为目标元素，add为要插入的位置
void insertElem(Link* p, int elem, int add){
    Link* temp = p;
    for (int i = 1; i< add; i++){
        temp = temp-> next;
        if(temp ==NULL){
            printf("error");
            return;
        }
    }

    Link* newNode = (Link*)malloc(sizeof(Link));
    newNode->elem = elem;
    newNode->next = temp->next;
    temp->next = newNode;
    
}

//p为原链表，elem 为要删除的目标元素
int delElem(Link* p, int elem){
    Link* temp = p;
    int find = 0;
    while(temp->next){
        if(temp->next->elem == elem){
            find = 1;
            break;
        }
        temp = temp->next; 
    }
    if(find == 0){
        printf("error");
        return -1;
    
    }else{
    Link* delNode = temp->next;
    temp->next = temp->next ->next;
    free(delNode);
    return 1;
    }
    
}

//p为原链表，elem表示被查找元素
int selectElem(Link* p ,int elem){
    int i  =1;
    p = p->next;
    while(p){
        if (p->elem == elem){
            return i;
        }
        p = p ->next;
        i++;
        
    }
    return -1;   
}

//p 为有头结点的链表，oldElem 为旧元素，newElem 为新元素
int amendElem(Link* p ,int oldElem, int newElem){
    p=p->next;
    while(p){
        if(p->elem == oldElem){
            p->elem  = newElem;
            return 1;
        }
        p = p -> next;
    }
    return -1;
}

//输出链表中各个结点的元素
void display(Link* p){
    p = p->next;
    while(p){
        printf("%d ",p->elem);
        p  = p ->next;
    }
    printf("\n");
}

//释放链表
void Link_free(Link* p){
    Link* fr = NULL;
    while(p->next){
        fr = p->next;
        p->next = p->next->next;
        free(fr);
    }
    free(p);
}

//迭代反转链表
Link* iteration_reverse(Link* p){
    if(p == NULL || p->next == NULL){
        return p;
    }else{
        Link* beg= NULL;
        Link* mid = p;
        Link* end = p->next;
        while(end){
            mid ->next = beg;
            beg = mid;
            mid  = end;
            end = end ->next;
        }
        Link* head = mid;
        return head;
    }
    
}
int main() {
    Link* p = initLink();
    printf("初始化链表为：\n");
    display(p);
    printf("反转链表：\n");
    Link* head  = iteration_reverse(p);
    display(head);
    printf("在第 3 的位置上添加元素 6：\n");
    insertElem(p, 6, 3);
    display(p);
    printf("删除元素4：\n");
    delElem(p, 4);
    display(p);
    printf("查找元素 2：\n");
    printf("元素 2 的位置为：%d\n", selectElem(p, 2));
    printf("更改元素 1 的值为 6：\n");
    amendElem(p, 1, 6);
    display(p);
    Link_free(p);
    return 0;
}