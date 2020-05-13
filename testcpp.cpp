//testcpp
#include<iostream>
#include<string>
#include<stdio.h>
#include"TemplateTest.h"
using namespace std;
int main()
{
    cout<<"hello world"<<endl;
    string str("123");
    cout << str <<endl;
    printf("ok了，不知道好用不");
    MySwap<int> mys(3,6);
    int res=mys.maxVal();
    cout<<res<<endl;
    system("pause");
}