#include "strategy.h"

double ReturnCash::AlgorithmInterrace(double amount)
{
    if(amount>=condition && condition != 0 )
    {
        cout<<"ReturnCash"<<endl;
        return amount - amount/condition*PreReturnCash;
    }
}

double Discount::AlgorithmInterrace(double amount)
{
    cout<<"Discount :"<<discount<<endl;
    return amount*discount;
}

double NomalCash::AlgorithmInterrace(double amount)
{
    cout<<"NomalCash"<<endl;
    return amount;
}