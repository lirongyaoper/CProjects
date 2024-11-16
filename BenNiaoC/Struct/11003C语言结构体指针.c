#include <stdio.h>
#include <string.h>
//下面是一个定义结构体指针的实例：
// //结构体
// struct stu{
//     char *name;  //姓名
//     int num;  //学号
//     int age;  //年龄
//     char group;  //所在小组
//     float score;  //成绩
// } stu1 = { "Tom", 12, 18, 'A', 136.5 };
// //结构体指针
// struct stu *pstu = &stu1;


//也可以在定义结构体的同时定义结构体指针：
// struct stu{
//     char *name;  //姓名
//     int num;  //学号
//     int age;  //年龄
//     char group;  //所在小组
//     float score;  //成绩
// } stu1 = { "Tom", 12, 18, 'A', 136.5 }, *pstu = &stu1;

int main(){
    struct{
        char *name;  //姓名
        int num;  //学号
        int age;  //年龄
        char group;  //所在小组
        float score;  //成绩
    } stu1 = { "Tom", 12, 18, 'A', 136.5 }, *pstu = &stu1;
    //读取结构体成员的值
    printf("%s的学号是%d，年龄是%d，在%c组，今年的成绩是%.1f！\n", (*pstu).name, (*pstu).num, (*pstu).age, (*pstu).group, (*pstu).score);
    printf("%s的学号是%d，年龄是%d，在%c组，今年的成绩是%.1f！\n", pstu->name, pstu->num, pstu->age, pstu->group, pstu->score);
    return 0;
}