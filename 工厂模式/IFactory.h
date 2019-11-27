#ifndef __IFACTORY__
#define __IFACTORY__
#include <operation.h>

class IFactory
{
    public:
        virtual operation* CreateOperation(){}
};

class FactoryAdd:public IFactory
{
    public:
        operation* CreateOperation()
        {
            return new addtion();
        }
};

class FactorySubtraction:public IFactory
{
    public:
        operation* CreateOperation()
        {
            return new subtraction();
        }
};

class FactoryMultiplication:public IFactory
{
    public:
        operation* CreateOperation()
        {
            return new multiplication();
        }
};

class FactoryDivision:public IFactory
{
    public:
        operation* CreateOperation()
        {
            return new division();
        }
};

class FactorySquare:public IFactory
{
    public:
        operation* CreateOperation()
        {
            return new square();
        }
};
#endif