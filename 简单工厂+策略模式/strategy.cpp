#include "strategy.h"

double ReturnCash::AlgorithmInterrace(double amount)
{
    cout<<"ReturnCash"<<endl;
    if(amount>=condition && condition != 0 )
    {
        return amount - static_cast<float>(amount)/condition*PreReturnCash;
    }
}

double Discount::AlgorithmInterrace(double amount)
{
    cout<<"Discount"<<endl;
    return amount*discount;
}

double NomalCash::AlgorithmInterrace(double amount)
{
    cout<<"NomalCash"<<endl;
    return amount;
}