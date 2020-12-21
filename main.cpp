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
    sort_by_subject_score(JI_RUAN, 2);
    for(int i = 0; i < seek_num; i++)
    {
        cout << seek_res[i]->get_id() << " " << seek_res[i]->get_name() << " ";
        cout << seek_res[i]->get_score(2) << endl;
    }
    //save();
    return 0;
}