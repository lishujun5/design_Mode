#ifndef __STRATEGY__
#define __STRATEGY__
#include <iostream>
#include "decorate.h"
using namespace std;
class Strategy
{
    public:
        virtual double AlgorithmInterrace(double amount) = 0;
};
/*返现金*/
class ReturnCash:public Strategy
{
    public:
        ReturnCash(double condition , double preReturnCash)
        {
            this->condition = condition;
            this->PreReturnCash = preReturnCash;
        }
        double AlgorithmInterrace(double amount);
    private:
        double condition;
        double PreReturnCash;
};
/*打折*/
class Discount:public Strategy
{
    public: 
        Discount(float discount)
        {
            this->discount = discount;
        }
        double AlgorithmInterrace(double amount);
    private:
        float discount;
};
/*正常*/
class NomalCash:public Strategy
{
    public:
        double AlgorithmInterrace(double amount);
};
#endif