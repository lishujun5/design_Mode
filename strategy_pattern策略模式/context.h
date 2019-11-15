#ifndef __CONTEXT__
#define __CONTEXT__
#include "strategy.h"
class context
{
    private:
        Strategy *strategy;
    public:
        context(Strategy *Strategy)
        {
            this->strategy = Strategy;
        }
        double ContextInterface(double amount);
};
#endif