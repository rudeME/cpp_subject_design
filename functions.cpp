#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include"class_student.h"
#include"functions.h"
using namespace std;
using namespace back_end_data;

bool cmp_by_total(student* pa, student* pb) {return pa->get_total_score() >= pb->get_total_score();}
bool cmp_by_score(student* pa, student* pb) {return pa->get_score(subject) >= pb->get_score(subject);}

bool sex_correctness(int sex)
{
    if(sex == 0 || sex == 1)
        return true;
    return false;
}

bool school_correctness(int school)
{
    if(school == 0 || school == 1 || school == 2)
        return true;
    return false;
}

bool subject_correctness(int subject)
{
    if(subject < 0 || subject > 19)
        return false;
    return true;
}

int modify_to_int(const char* str)
{
    int a;
    if(strcmp(str, "男") == 0 || strcmp(str, "MALE") == 0)
        a = MALE;
    else if(strcmp(str, "女") == 0 || strcmp(str, "FEMALE") == 0)
        a = FEMALE;
    else if(strcmp(str, "计软") == 0 || strcmp(str, "JI_RUAN") == 0)
        a = JI_RUAN;
    else if(strcmp(str, "电信") == 0 || strcmp(str, "DIAN_XIN") == 0)
        a = DIAN_XIN;
    else if(strcmp(str, "数统") == 0 || strcmp(str, "SHU_TONG") == 0)
        a = SHU_TONG;
    else if(strcmp(str, "高数") == 0)
        a = GAO_SHU;
    else if(strcmp(str, "程序") == 0)
        a = CHENG_XU;
    else if(strcmp(str, "电子") == 0)
        a = DIAN_ZI;
    else if(strcmp(str, "常微分") == 0)
        a = CHANG_WEI_FEN;
    else if(strcmp(str, "操作系统") == 0)
        a = OS;
    else if(strcmp(str, "线代") == 0)
        a = XIAN_DAI;
    else if(strcmp(str, "概统") == 0)
        a = GAI_TONG;
    else if(strcmp(str, "近世") == 0)
        a = JIN_SHI;
    else if(strcmp(str, "信号") == 0)
        a = XIN_HAO;
    else if(strcmp(str, "网络") == 0)
        a = NET;
    else 
        return -1;
    return a;
}

void init()
{
    student* pnew;
    pnew = new student{"NULL", "NULL", MALE, JI_RUAN, -1};
    stu_ls.head = pnew;
    stu_ls.end = pnew;
    stu_ls.num = 0;
    fstream OpenFile;
    OpenFile.open("link_list.txt", ios::in);
    for(;;)
    {
        char id[15];
        char name[20];
        int sex, school, class_num, score;
        if(OpenFile >> id >> name >> sex >> school >> class_num){}
        else 
            break;
        pnew = new student{id, name, sex, school, class_num};
        for(int i = 0; i <= 19; i++)
        {
            OpenFile >> score;
            pnew->modify_score(i, score);
        }
        stu_ls.end->next = pnew;
        stu_ls.end = pnew;
        ++stu_ls.num;
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
    for(int i = 0; i < strlen(id); i++)
        if(id[i] < '0' || id[i] > '9')
        {
            student* perr;
            perr = new student{"NULL", "NULL", 0, 0, 0};
            perr->modify_check(2);
            return perr;
        }
    if(sizeof(id) > 14 || sizeof(name) > 19)
    {
        student* perr;
        perr = new student{"NULL", "NULL", 0, 0, 0};
        perr->modify_check(1);
        return perr;
    }
    if(!sex_correctness(sex))
    {
        student* perr;
        perr = new student{"NULL", "NULL", 0, 0, 0};
        perr->modify_check(3);
        return perr;
    }
    if(!school_correctness(school))
    {
        student* perr;
        perr = new student{"NULL", "NULL", 0, 0, 0};
        perr->modify_check(4);
        return perr;
    }
    if(class_num < 0)
    {
        student* perr;
        perr = new student{"NULL", "NULL", 0, 0, 0};
        perr->modify_check(6);
        return perr;
    }
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
        {
            if(strcmp(ptr->next->get_id(), id) > 0)
            {
                pnew->next = ptr->next;
                ptr->next = pnew;
                break;
            }
            else if(strcmp(ptr->next->get_id(), id) == 0)
            {
                if(stu_ls.end == ptr->next)
                    stu_ls.end = pnew;
                for(int i = 0; i < 20; i++)
                    pnew->modify_score(i, ptr->next->get_score(i));
                pnew->modify_check(5);
                pnew->next = ptr->next->next;
                delete(ptr->next);
                ptr->next = pnew;
                --stu_ls.num;
                break;
            }
            else 
                continue;
        }
        if(strcmp(ptr->get_id(), id) < 0 && strcmp(ptr->next->get_id(), id) > 0)
        {
            pnew->next = ptr->next;
            ptr->next = pnew;
            break;
        }
        if(strcmp(ptr->next->get_id(), id) == 0)
        {
            if(stu_ls.end == ptr->next)
                    stu_ls.end = pnew;
            for(int i = 0; i < 20; i++)
                pnew->modify_score(i, ptr->next->get_score(i));
            pnew->modify_check(5);
            pnew->next = ptr->next->next;
            delete(ptr->next);
            ptr->next = pnew;
            --stu_ls.num;
            break;
        }
    }
    ++stu_ls.num;
    return pnew;
}

student* add(const char* id, const char* name, const char* sex, const char* school, int class_num)
{
    return add(id, name, modify_to_int(sex), modify_to_int(school), class_num);
}


bool del(student* pdel)
{
    if(pdel == NULL)
        return false;
    student* ptr{stu_ls.head};
    for(int i = 0; i < seek_num; i++)
        if(seek_res[i] == pdel)
        {
            seek_res[i] = NULL;
            break;
        }
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
    if(!school_correctness(school))
        return;
    seek_num = 0;
    student* ptr{stu_ls.head->next};
    for(; NULL != ptr; ptr = ptr->next)
        if(ptr->get_school() == school)
            seek_res[seek_num++] = ptr;
    if(seek_num == 0)
        return;
    sort(seek_res, seek_res + seek_num, cmp_by_total);
}

void sort_by_total_score(const char* school)
{
    sort_by_total_score(modify_to_int(school));
}

void sort_by_total_score(int school, int class_num)
{
    if(!school_correctness(school))
        return;
    seek_num = 0;
    student* ptr{stu_ls.head->next};
    for(; NULL != ptr; ptr = ptr->next)
        if(ptr->get_school() == school && ptr->get_class_num() == class_num)
            seek_res[seek_num++] = ptr;
    if(seek_num == 0)
        return;
    sort(seek_res, seek_res + seek_num, cmp_by_total);
}

void sort_by_total_score(const char* school, int class_num)
{
    sort_by_total_score(modify_to_int(school), class_num);
}

void sort_by_subject_score(int school, int subject)
{
    if(!school_correctness(school) || !subject_correctness(subject))
        return;
    seek_num = 0;
    student* ptr{stu_ls.head->next};
    for(; NULL != ptr; ptr = ptr->next)
        if(ptr->get_school() == school)
            seek_res[seek_num++] = ptr;
    if(seek_num == 0)
        return;
    seek_num = seek_num;
    back_end_data::subject = subject;
    sort(seek_res, seek_res + seek_num, cmp_by_score);
}

void sort_by_subject_score(const char* school, const char* subject)
{
    sort_by_subject_score(modify_to_int(school), modify_to_int(subject));
}

void sort_by_subject_score(int school, int class_num, int subject)
{
    if(!school_correctness(school) || !subject_correctness(subject))
        return;
    seek_num = 0;
    student* ptr{stu_ls.head->next};
    for(; NULL != ptr; ptr = ptr->next)
        if(ptr->get_school() == school && ptr->get_class_num() == class_num)
            seek_res[seek_num++] = ptr;
    if(seek_num == 0)
        return;
    back_end_data::subject = subject;
    sort(seek_res, seek_res + seek_num, cmp_by_score);
}

void sort_by_subject_score(const char* school, int class_num, const char* subject)
{
    sort_by_subject_score(modify_to_int(school), class_num, modify_to_int(subject));
}

void sort_by_id()
{
    seek_num = 0;
    student* ptr{stu_ls.head->next};
    for(; NULL != ptr; ptr = ptr->next)
        seek_res[seek_num++] = ptr;
}

void sort_by_id(int school)
{
    if(!school_correctness(school))
        return;
    seek_num = 0;
    student* ptr{stu_ls.head->next};
    for(; NULL != ptr; ptr = ptr->next)
        if(ptr->get_school() == school)
            seek_res[seek_num++] = ptr;
}

void sort_by_id(const char* school)
{
    sort_by_id(modify_to_int(school));
}

void sort_by_id(int school, int class_num)
{
    if(!school_correctness(school))
        return;
    seek_num = 0;
    student* ptr = stu_ls.head->next;
    for(; NULL != ptr; ptr = ptr->next)
        if(ptr->get_school() == school && ptr->get_class_num() == class_num)
            seek_res[seek_num++] = ptr;
}

void sort_by_id(const char* school, int class_num)
{
    sort_by_id(modify_to_int(school), class_num);
}

double subject_pass_rate(int subject)
{
    if(!subject_correctness(subject))
        return -1.0;
    int total{0}, acc{0};
    student* ptr{stu_ls.head->next};
    for(; NULL != ptr; ptr = ptr->next)
        if(ptr->get_score(subject) >= 0)
        {
            ++total;
            if(ptr->get_score(subject) >= 60)
                ++acc;
        }
    if(total == 0)
        return -1.0;
    return double(acc) / double(total);
}

double subject_pass_rate(const char* subject)
{
    return subject_pass_rate(modify_to_int(subject));
}

double subject_pass_rate(int school, int subject)
{
    if(!school_correctness(school) || !subject_correctness(subject))
        return -1.0;
    int total{0}, acc{0};
    student* ptr{stu_ls.head->next};
    for(; NULL != ptr; ptr = ptr->next)
        if(ptr->get_school() == school && ptr->get_score(subject) >= 0)
        {
            ++total;
            if(ptr->get_score(subject) >= 60)
                ++acc;
        }
    if(total == 0)
        return -1.0;
    return double(acc) / double(total);
}

double subject_pass_rate(const char* school, const char* subject)
{
    return subject_pass_rate(modify_to_int(school), modify_to_int(subject));
}

double subject_pass_rate(int school, int class_num, int subject)
{
    if(!school_correctness(school) || !subject_correctness(subject))
        return -1.0;
    int total{0}, acc{0};
    student* ptr{stu_ls.head->next};
    for(; NULL != ptr; ptr = ptr->next)
        if(ptr->get_school() == school && ptr->get_class_num() == class_num && ptr->get_score(subject) >= 0)
        {
            ++total;
            if(ptr->get_score(subject) >= 60)
                ++acc;
        }
    if(total == 0)
        return -1.0;
    return double(acc) / double(total);
}

double subject_pass_rate(const char* school, int class_num, const char* subject)
{
    return subject_pass_rate(modify_to_int(school), class_num, modify_to_int(subject));
}

double subject_average(int subject)
{
    if(!subject_correctness(subject))
        return -1.0;
    int total_score{0}, total{0};
    student* ptr{stu_ls.head->next};
    for(; NULL != ptr; ptr = ptr->next)
        if(ptr->get_score(subject) >= 0)
        {
            ++total;
            total_score += ptr->get_score(subject);
        }
    if(total == 0)
        return -1.0;
    return double(total_score) / double(total);
}

double subject_average(const char* subject)
{
    return subject_average(modify_to_int(subject));
}

double subject_average(int school, int subject)
{
    if(!school_correctness(school) || !subject_correctness(subject))
        return -1.0;
    int total_score{0}, total{0};
    student* ptr{stu_ls.head->next};
    for(; NULL != ptr; ptr = ptr->next)
        if(ptr->get_school() == school && ptr->get_score(subject) >= 0)
        {
            ++total;
            total_score += ptr->get_score(subject);
        }
    if(total == 0)
        return -1.0;
    return double(total_score) / double(total);
}

double subject_average(const char* school, const char* subject)
{
    return subject_average(modify_to_int(school), modify_to_int(subject));
}

double subject_average(int school, int class_num, int subject)
{
    if(!school_correctness(school) || !subject_correctness(subject))
        return -1.0;
    int total_score{0}, total{0};
    student* ptr{stu_ls.head->next};
    for(; NULL != ptr; ptr = ptr->next)
        if(ptr->get_school() == school && ptr->get_class_num() == class_num && ptr->get_score(subject) >= 0)
        {
            ++total;
            total_score += ptr->get_score(subject);
        }
    if(total == 0)
        return -1.0;
    return double(total_score) / double(total);
}

double subject_average(const char* school, int class_num, const char* subject)
{
    return subject_average(modify_to_int(school), class_num, modify_to_int(subject));
}