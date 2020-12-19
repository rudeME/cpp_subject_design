#include<iostream>
#include<cstdio>
#include"test1.h"
using namespace std;

namespace one
{
    int a = 1;
    int b = 2;
}

using namespace one;

void show()
{
    cout << a << endl;
    cout << b << endl;
}