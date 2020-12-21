#ifndef CLASS_F
#define CLASS_F
#include<iostream>
#include<cstdio>
#include"class_student.h"
using namespace std;

struct link_list
{
    student* head;
    student* end;
    int num;//the num of students that accord with condition
};

namespace back_end_data
{
    static link_list stu_ls;
    static student* seek_res[50005];
    static int seek_num;
    static int subject;
}

void init();
void save();
void seek(const char*);
student* add(const char*, const char*, int, int, int);
student* add(const char*, const char*, const char*, const char*, int);
void del(student*);
void del_all();
void sort_by_total_score(int);
void sort_by_total_score(int, int);
void sort_by_subject_score(int, int);
void sort_by_subject_score(int, int, int);
void sort_by_id();
void sort_by_id(int);
void sort_by_id(int, int);
double subject_pass_rate(int);
double subject_pass_rate(int, int);
double subject_pass_rate(int, int, int);
double subject_average(int);
double subject_average(int, int);
double subject_average(int, int, int);
#endif