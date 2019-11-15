#include "context.h"
double context::ContextInterface(double amount)
{
    if(com == NULL)
    {
        cerr<<"com is null"<<endl;
        exit(-1);
    }
    amount = strategy->AlgorithmInterrace(amount);
    cout<<"amount is "<<amount<<endl;
    return com->ContextInterface(amount);
}