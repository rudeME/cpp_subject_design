#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include"class_student.h"
#include"functions.h"
using namespace std;
using namespace data;

int main()
{
    init();
    del_all();
    add("201983290999", "马保国", 0, 0, 11);
    add("201983290998", "张三", 0, 0, 11);
    add("201983290997", "李四", 0, 0, 11);
    save();
    return 0;
}