#include <stdio.h>
#include <stdlib.h>

// 头结点、头指针和首元结点
// 图 4 所示的链表并不完整，一个完整的链表应该由以下几部分构成：
// 头指针：一个和结点类型相同的指针，它的特点是：永远指向链表中的第一个结点。上文提到过，我们需要记录链表中第一个元素的存储位置，就是用头指针实现。
// 结点：链表中的节点又细分为头结点、首元结点和其它结点：
// 头结点：某些场景中，为了方便解决问题，会故意在链表的开头放置一个空结点，这样的结点就称为头结点。  也就是说，头结点是位于链表开头、数据域为空（不利用）的结点。
// 首元结点：指的是链表开头第一个存有数据的结点。
// 其他节点：链表中其他的节点。

// 也就是说，一个完整的链表是由头指针和诸多个结点构成的。每个链表都必须有头指针，但头结点不是必须的。


typedef struct linkNode {
    int elem;
    struct linkNode* next;
}Link;
Link* initLink(){
    int i ;
    //1、创建头指针    
    Link *p = NULL;
    //2、创建头结点
    Link *temp = (Link*)malloc(sizeof(Link));
    temp ->elem = 0;
    temp->next = NULL;
    //头指针指向头结点
    p = temp;
    for (i = 1;i <5; i++){
        Link* a = (Link*)malloc(sizeof(Link));
        a->elem = i;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
        
    } 
    return p;   
}

void display(Link *p){
    Link* temp = p;

//只要temp指向结点的next值不是NULL，就执行输出语句。
    while(temp){
        Link* f = temp;
        printf("%d ",temp->elem);
        temp = temp->next;
        free(f);
    }
    printf("\n");
}

int main(){
    Link* p = NULL;

    p = initLink();
    display(p);
    return 0;
    
}