#include <iostream>
#include "strategy.h"
#include "context.h"
using namespace std;
int main()
{
    double amount;
    int index;
    cout<<"input the money amount"<<endl;
    cin>>amount;
    cout<<"choose the way :"<<endl;
    cout<<"1.returnCash"<<endl;
    cout<<"2.discount"<<endl;
    cout<<"3.nomal pay"<<endl;
    cin>>index;
    context con(index);
    cout<<"打折前： "<<amount<<"***********"<<"打折后："<<con.ContextInterface(amount)<<endl;
}