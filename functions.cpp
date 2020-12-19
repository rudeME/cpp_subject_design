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
    int num;
};

namespace data
{
    link_list stu_ls;
}

using namespace data;

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