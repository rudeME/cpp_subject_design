#include<iostream>
#include<cstdio>
using namespace std;

enum school {计软院, 电信院, 数统院};
enum sex {男, 女};
enum subject_name {高等数学, 线性代数, 程序设计基础, 概率统计, 电子技术基础, 近世代数, 常微分方程, 信号与系统, 操作系统, 计算机网络};

class student
{
public:
    student(const char*, const char*, int, int, int);
    char* get_id();
    char* get_name();
    int get_sex();
    int get_school();
    int get_class_num();
    int get_score(int);
    void modify_school(int);
    void modify_class_num();
    void modify_score(int, int);
protected:
    char id[15];
    char name[20];
    int stu_sex;
    int stu_school;
    int class_num;
    int score[20];//-1意思为未选课，-2意思为选课但是还没有考试，0~100意思为选课且有成绩
    int total_score;
};