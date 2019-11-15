#include <iostream>
#include "strategy.h"
#include "context.h"
using namespace std;
int main()
{
    double amount = 10000;
    Strategy *strategy;
    strategy = new Discount(0.8);
    strategy->AlgorithmInterrace(10000);
    context con(strategy);
    cout<<"打折前： "<<amount<<"***********"<<"打折后："<<con.ContextInterface(amount)<<endl;
}