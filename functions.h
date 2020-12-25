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
    inline link_list stu_ls;
    inline student* seek_res[50005];
    inline int seek_num;
    inline int subject;
}

bool sex_correctness(int);
bool school_correctness(int);
bool subject_correctness(int);
int modify_to_int(const char*);
void init();
void save();
void seek(const char*);
student* add(const char*, const char*, int, int, int);
student* add(const char*, const char*, const char*, const char*, int);
bool del(student*);
void del_all();
void sort_by_total_score(int);
void sort_by_total_score(const char*);
void sort_by_total_score(int, int);
void sort_by_total_score(const char*, int);
void sort_by_subject_score(int, int);
void sort_by_subject_score(const char*, const char*);
void sort_by_subject_score(int, int, int);
void sort_by_subject_score(const char*, int, const char*);
void sort_by_id();
void sort_by_id(int);
void sort_by_id(const char*);
void sort_by_id(int, int);
void sort_by_id(const char*, int);
double subject_pass_rate(int);
double subject_pass_rate(const char*);
double subject_pass_rate(int, int);
double subject_pass_rate(const char*, const char*);
double subject_pass_rate(int, int, int);
double subject_pass_rate(const char*, int, const char*);
double subject_average(int);
double subject_average(const char*);
double subject_average(int, int);
double subject_average(const char*, const char*);
double subject_average(int, int, int);
double subject_average(const char*, int, const char*);
#endif