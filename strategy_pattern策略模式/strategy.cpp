#include "strategy.h"

double ReturnCash::AlgorithmInterrace(double amount)
{
    if(amount>=condition && condition != 0 )
    {
        return amount - amount/condition*PreReturnCash;
    }
}

double Discount::AlgorithmInterrace(double amount)
{
    return amount*discount;
}

double NomalCash::AlgorithmInterrace(double amount)
{
    return amount;
}