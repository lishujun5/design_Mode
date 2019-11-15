#ifndef __CONTEXT__
#define __CONTEXT__
#include "strategy.h"
class context
{
    private:
        Strategy *strategy;
    public:
        context(int index)
        {
            switch (index)
            {
                /*满300减100*/
            case 1:
            strategy = new ReturnCash(300,100);
            break;
            /*打八折*/
            case 2:
            strategy = new Discount(0.8);
            break;
            /*正常付费*/
            default:
            strategy = new NomalCash();
            break;
            }
        }
        double ContextInterface(double amount);
};
#endif