#pragma once
#include <iostream>
using namespace std;
class componet  //接口
{
    public:
        virtual double ContextInterface(double amount) = 0;       //获取打折之后的值
};
class calculator:public componet   //最后调用的对象  实例化被装饰者
{
    public:
        componet *arithmetic;
        double ContextInterface(double amount)
        {
            cout<<"calculator end!"<<endl;
            return amount;
        }
};