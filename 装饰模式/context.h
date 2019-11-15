#ifndef __CONTEXT__
#define __CONTEXT__
#include "strategy.h"
class  context:public componet
{
    private:
        Strategy *strategy;
        componet *com;
    public:
        context(Strategy *Strategy)
        {
            cout<<"init context"<<endl;
            this->strategy = Strategy;
        }
        void setArith(componet *arithmetic)
        {
            com = arithmetic;
        }
        double ContextInterface(double amount);
};
#endif