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
    student* a{add("201983290395", "Li", JI_RUAN, 1, 1)};
    cout << a->get_check() << endl;
    del_all();
    save();
    return 0;
}