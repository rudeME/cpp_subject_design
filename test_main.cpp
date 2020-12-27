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
    student* ptr{add("111", "name", 0, 0, 0)};
    ptr->modify_score(0, 100);
    ptr->modify_score(1, 30);
    ptr->modify_score(1, 40);
    ptr->modify_score(3, -2);
    cout << ptr->get_total_score();
    return 0;
}