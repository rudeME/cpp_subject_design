#include<iostream>
#include<cstdio>
#include"class_student.h"
using namespace std;

void init();
void save();
student* seek(student*);
student* add(char*, char*, sex, school, int);
void del(student*);
void del_all();
void sort_by_total_score(school, int);
void sort_by_total_score(school, int, int);
void sort_by_subject_score(school, subject_name, int);
void sort_by_subject_score(school, subject_name, int, int);
void sort_by_id(school, int);
void sort_by_id(school, int, int);
double subject_pass_rate(subject_name);
double subject_pass_rate(school, subject_name);
double subject_pass_rate(school, int, subject_name);
double subject_average(subject_name);
double subject_average(school, subject_name);
double subject_average(school, int, subject_name);