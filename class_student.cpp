#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include"class_student.h"
using namespace std;

student::student(const char* id, const char* name, int stu_sex, int stu_school, int class_num): 
            stu_sex(stu_sex), stu_school(stu_school), class_num(class_num)
{
    strcpy(student::id, id);
    strcpy(student::name, name);
    for(int i = 0; i<= 19; i++)
        score[i] = -1;
    total_score = 0;
}
char* student::get_id()
{
    return id;
}
char* student::get_name()
{
    return name;
}
int student::get_sex()
{
    return stu_sex;
}
int student::get_school()
{
    return stu_school;
}
int student::get_class_num()
{
    return class_num;
}
int student::get_score(int sub)
{
    return score[sub];
}
void student::modify_school(int stu_school)
{
    student::stu_school = stu_school;
}
void student::modify_score(int sub, int score)
{
    int origin = student::score[sub];
    student::score[sub] = score;
    if(origin == -1 || origin == -2)
        total_score += score;
    else 
        total_score += score - origin;
}