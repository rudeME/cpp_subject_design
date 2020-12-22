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
        score[i] = -2;
    total_score = 0;
    next = NULL;
}

char* student::get_id(){return id;}

char* student::get_name(){return name;}

int student::get_sex(){return stu_sex;}

int student::get_school(){return stu_school;}

int student::get_class_num(){return class_num;}

int student::get_score(int sub){return score[sub];}

int student::get_total_score(){return total_score;}

bool student::modify_school(int stu_school)
{
    if(stu_school == 0 || stu_school == 1 || stu_school == 2)
    {
        student::stu_school = stu_school;
        return true;
    }
    return false;
}

bool student::modify_school(const char* stu_school)
{
    int a;
    if(strcmp(stu_school, "计软") == 0 || strcmp(stu_school, "JI_RUAN") == 0)
        a = JI_RUAN;
    else if(strcmp(stu_school, "电信") == 0 || strcmp(stu_school, "DIAN_XIN") == 0)
        a = DIAN_XIN;
    else if(strcmp(stu_school, "数统") == 0 || strcmp(stu_school, "SHU_TONG") == 0)
        a = SHU_TONG;
    else
        return false;
    return this->modify_school(a);
}

bool student::modify_class_num(int class_num)
{
    if(class_num > 0)
    {
        student::class_num = class_num;
        return true;
    }
}

bool student::modify_score(int sub, int score)
{
    if(sub < 0 || sub > 19 || score < -2 || score > 100)
        return false;
    int origin = student::score[sub];
    student::score[sub] = score;
    if(origin == -1 || origin == -2)
        total_score += score;
    else 
        total_score += score - origin;
    return true;
}

bool student::modify_score(const char* sub, int score)
{
    int sub_int;
    if(strcmp(sub, "高数") == 0)
        sub_int = GAO_SHU;
    else if(strcmp(sub, "程序") == 0)
        sub_int = CHENG_XU;
    else if(strcmp(sub, "电子") == 0)
        sub_int = DIAN_ZI;
    else if(strcmp(sub, "常微分") == 0)
        sub_int = CHANG_WEI_FEN;
    else if(strcmp(sub, "操作系统") == 0)
        sub_int = OS;
    else if(strcmp(sub, "线代") == 0)
        sub_int = XIAN_DAI;
    else if(strcmp(sub, "概统") == 0)
        sub_int = GAI_TONG;
    else if(strcmp(sub, "近世") == 0)
        sub_int = JIN_SHI;
    else if(strcmp(sub, "信号") == 0)
        sub_int = XIN_HAO;
    else if(strcmp(sub, "网络") == 0)
        sub_int = NET;
    else 
        return false;
    return this->modify_score(sub_int, score);
}