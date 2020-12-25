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
    for(int i = 0; i <= 9; i++)
        sort_by_subject_score(1, 1);
    cout << "Done!" << endl;
    return 0;
}