#ifndef CLASS_H
#define CLASS_H
#include<iostream>
#include<cstdio>
using namespace std;

enum school {JI_RUAN, DIAN_XIN, SHU_TONG};
enum sex {MALE, FEMALE};
enum subject_name {GAO_SHU, XIAN_DAI, CHENG_XU, GAI_TONG, DIAN_ZI, JIN_SHI, CHANG_WEI_FEN, XIN_HAO, OS, NET};

class student
{
public:
    student(const char*, const char*, int, int, int);
    char* get_id();
    char* get_name();
    int get_sex();
    const char* get_sex_string();//
    int get_school();
    const char* get_school_string();//
    int get_class_num();
    int get_score(int);
    int get_score(const char*);//
    int get_total_score();
    bool modify_school(int);
    bool modify_school(const char*);
    bool modify_class_num(int);
    bool modify_score(int, int);
    bool modify_score(const char*, int);
    student* next;
protected:
    char id[15];
    char name[20];
    int stu_sex;
    int stu_school;
    int class_num;
    int score[20];//-1意思为未选课，-2意思为选课但是还没有考试，0~100意思为选课且有成绩
    int total_score;
};
#endif