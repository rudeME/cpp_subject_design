#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include"class_student.h"
#include"functions.h"
using namespace std;

struct link_list
{
    student* head;
    student* end;
    int num;//the num of students that accord with condition
};

namespace data
{
    link_list stu_ls;
    student* seek_res[50005];
    int seek_num;
    int subject;
}
using namespace data;

bool cmp_by_total(student* pa, student* pb){return pa->get_total_score() >= pb->get_total_score();}
bool cmp_by_score(student* pa, student* pb){return pa->get_score(subject) >= pb->get_score(subject);}

void init()
{
    student* pnew;
    pnew = new student{"NULL", "NULL", 男, 计软院, -1};
    stu_ls.head = pnew;
    stu_ls.end = pnew;
    stu_ls.num = 0;
    fstream OpenFile;
    OpenFile.open("link_list.txt", ios::in);
    for(; !OpenFile.eof();)
    {
        char id[15];
        char name[20];
        int sex, school, class_num, score;
        OpenFile >> id >> name >> sex >> school >> class_num;
        pnew = new student{id, name, sex, school, class_num};
        for(int i = 0; i <= 19; i++)
        {
            OpenFile >> score;
            pnew->modify_score(i, score);
        }
    }
    OpenFile.close();
}

void save()
{
    fstream OpenFile;
    OpenFile.open("link_list.txt", ios::out);
    student* ptr;
    ptr = stu_ls.head->next;
    for(;;)
    {
        if(NULL == ptr)
            break;
        OpenFile << ptr->get_id() << " " << ptr->get_name() << " " << ptr->get_sex() << " " << ptr->get_school() << " " << ptr->get_class_num();
        for(int i = 0; i <= 19; i++)
            OpenFile << " " << ptr->get_score(i);
        OpenFile << endl;
        ptr = ptr->next;
    }
    OpenFile.close();
}

void seek(const char* id_or_name)
{
    seek_num = 0;
    student* ptr;
    ptr = stu_ls.head->next;
    for(;;)
    {
        if(NULL == ptr)
            break;
        if(!strcmp(ptr->get_id(), id_or_name) || !strcmp(ptr->get_name(), id_or_name))
            seek_res[seek_num++] = ptr;
        ptr = ptr->next;
    }
}

student* add(const char* id, const char* name, int sex, int school, int class_num)
{
    student* pnew, *ptr{stu_ls.head};
    pnew = new student{id, name, sex, school, class_num};
    for(;;ptr = ptr->next)
    {
        if(NULL == ptr->next)
        {
            ptr->next = pnew;
            stu_ls.end = pnew;
            break;
        }
        if(ptr == stu_ls.head)
            continue;
        if(strcmp(ptr->get_id(), id) < 0 && strcmp(ptr->next->get_id(), id) > 0)
        {
            pnew->next = ptr->next;
            ptr->next = pnew;
            break;
        }
    }
    ++stu_ls.num;
    return pnew;
}

void del(student* pdel)
{
    student* ptr{stu_ls.head};
    for(;;ptr = ptr->next)
        if(ptr->next == pdel)
        {
            ptr->next = pdel->next;
            delete(pdel);
            break;
        }
    --stu_ls.num;
}

void del_all()
{
    student* ptr{stu_ls.head->next}, *ptem;
    for(;;)
    {
        if(NULL == ptr)
            break;
        ptem = ptr->next;
        delete(ptr);
        ptr = ptem;
    }
    stu_ls.head->next = NULL;
    stu_ls.end = stu_ls.head;
    stu_ls.num = 0;
}

void sort_by_total_score(int school)
{
    seek_num = 0;
    student* ptr{stu_ls.head->next};
    for(; NULL != ptr; ptr = ptr->next)
        if(ptr->get_school() == school)
            seek_res[++seek_num] = ptr;
    if(seek_num == 0)
        return;
    sort(seek_res, seek_res + seek_num, cmp_by_total);
}

void sort_by_total_score(int school, int class_num)
{
    seek_num = 0;
    student* ptr{stu_ls.head->next};
    for(; NULL != ptr; ptr = ptr->next)
        if(ptr->get_school() == school && ptr->get_class_num() == class_num)
            seek_res[++seek_num] = ptr;
    if(seek_num == 0)
        return;
    sort(seek_res, seek_res + seek_num, cmp_by_total);
}

void sort_by_subject_score(int school, int subject)
{
    seek_num = 0;
    student* ptr{stu_ls.head->next};
    for(; NULL != ptr; ptr = ptr->next)
        if(ptr->get_school() == school)
            seek_res[++seek_num] = ptr;
    if(seek_num == 0)
        return;
    data::subject = subject;
    sort(seek_res, seek_res + seek_num, cmp_by_score);
}

void sort_by_subject_score(int school, int class_num, int subject)
{
    seek_num = 0;
    student* ptr{stu_ls.head->next};
    for(; NULL != ptr; ptr = ptr->next)
        if(ptr->get_school() == school && ptr->get_class_num() == class_num)
            seek_res[++seek_num] = ptr;
    if(seek_num == 0)
        return;
    data::subject = subject;
    sort(seek_res, seek_res + seek_num, cmp_by_score);
}

void sort_by_id()
{
    seek_num = 0;
    student* ptr{stu_ls.head->next};
    for(; NULL != ptr; ptr = ptr->next)
        seek_res[++seek_num] = ptr;
}

void sort_by_id(int school)
{
    seek_num = 0;
    student* ptr{stu_ls.head->next};
    for(; NULL != ptr; ptr = ptr->next)
        if(ptr->get_school() == school)
            seek_res[++seek_num] = ptr;
}

void sort_by_id(int school, int class_num)
{
    seek_num = 0;
    student* ptr = stu_ls.head->next;
    for(; NULL != ptr; ptr = ptr->next)
        if(ptr->get_school() == school && ptr->get_class_num() == class_num)
            seek_res[++seek_num] = ptr;
}

double subject_pass_rate(int subject)
{
    int total{0}, acc{0};
    student* ptr{stu_ls.head->next};
    for(; NULL != ptr; ptr = ptr->next)
        if(ptr->get_score(subject) >= 0)
        {
            ++total;
            if(ptr->get_score(subject) >= 60)
                ++acc;
        }
    return double(acc) / double(total);
}

double subject_pass_rate(int school, int subject)
{
    int total{0}, acc{0};
    student* ptr{stu_ls.head->next};
    for(; NULL != ptr; ptr = ptr->next)
        if(ptr->get_school() == school && ptr->get_score(subject) >= 0)
        {
            ++total;
            if(ptr->get_score(subject) >= 60)
                ++acc;
        }
    return double(acc) / double(total);
}

double subject_pass_rate(int school, int class_num, int subject)
{
    int total{0}, acc{0};
    student* ptr{stu_ls.head->next};
    for(; NULL != ptr; ptr = ptr->next)
        if(ptr->get_school() == school && ptr->get_class_num() == class_num && ptr->get_score(subject) >= 0)
        {
            ++total;
            if(ptr->get_score(subject) >= 60)
                ++acc;
        }
    return double(acc) / double(total);
}

double subject_average(int subject)
{
    int total_score{0}, total{0};
    student* ptr{stu_ls.head->next};
    for(; NULL != ptr; ptr = ptr->next)
        if(ptr->get_score(subject) >= 0)
        {
            ++total;
            total_score += ptr->get_score(subject);
        }
    return double(total_score) / double(total);
}

double subject_average(int school, int subject)
{
    int total_score{0}, total{0};
    student* ptr{stu_ls.head->next};
    for(; NULL != ptr; ptr = ptr->next)
        if(ptr->get_school() == school && ptr->get_score(subject) >= 0)
        {
            ++total;
            total_score += ptr->get_score(subject);
        }
    return double(total_score) / double(total);
}

double subject_average(int school, int class_num, int subject)
{
    int total_score{0}, total{0};
    student* ptr{stu_ls.head->next};
    for(; NULL != ptr; ptr = ptr->next)
        if(ptr->get_school() == school && ptr->get_class_num() == class_num && ptr->get_score(subject) >= 0)
        {
            ++total;
            total_score += ptr->get_score(subject);
        }
    return double(total_score) / double(total);
}