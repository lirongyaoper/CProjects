#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    struct 
    {
        char *name;
        int num;
        int age;
        char group;
        float score;
    }stu1;
    stu1.name = "John";
    stu1.num = 1001;
    stu1.age = 20;
    stu1.group = 'A';
    stu1.score = 80.5;
    printf("%s的学号是%d，年龄是%d，在%c组，今年的成绩是%.1f！\n", stu1.name, stu1.num, stu1.age, stu1.group, stu1.score);
    
    return 0;
    
    
}