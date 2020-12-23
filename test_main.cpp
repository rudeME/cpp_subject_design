#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include"class_student.h"
#include"functions.h"
using namespace std;
using namespace back_end_data;

int main()
{
    init();
    student* a{add("201983290396", "Like", JI_RUAN, 1, 1)};
    a->modify_score("高数", 100);
    add("201983290396", "Me", JI_RUAN, 0, 1);
    save();
    return 0;
}