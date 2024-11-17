
// C语言中，结构体是一种复杂的数据类型，它可以将不同类型的多个变量组合在一起形成新的数据类型。而结构体指针则是指向结构体变量的指针，它允许我们通过地址操作结构体中的元素，从而提高程序的效率和灵活性。下面通过一个具体的实例来详细阐述结构体指针的使用。
#include <stdio.h>
struct Student{
    char name[50];
    int age;
    float score;
    
};
struct Student* pStudent;

int main(){
    struct Student s1;
    
    strcpy(s1.name,"Tom");
    s1.age = 20;
    s1.score = 90.5;
    pStudent = &s1;
    
    printf("Student's Name: %s\n",pStudent->name);
    printf("Student's Age: %d\n",pStudent->age);
    printf("Student's Score: %.2f\n",pStudent->score);

    (*pStudent).age = 21;
    pStudent-> score = 97.3;
    printf("\nAfter modification:\n");
    printf("Student's age: %d\n", pStudent->age);
    printf("Student's score: %.1f\n", pStudent->score);
 
    return 0;  
}