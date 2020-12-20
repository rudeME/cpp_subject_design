#include<iostream>
#include<cstdio>
#include"class_student.h"
using namespace std;

void init();
void save();
void seek(const char*);
student* add(const char*, const char*, int, int, int);
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