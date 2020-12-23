#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include"class_student.h"
#include"functions.h"
using namespace std;
using namespace back_end_data;

void save_txt()
{
    fstream OpenFile;
    OpenFile.open("C:/CPP_subject_design/link_list.txt", ios::out);
    OpenFile << "test" << endl;
    OpenFile.close();
}

int main()
{
    save_txt();
    return 0;
}