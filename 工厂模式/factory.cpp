#include <iostream>
#include "IFactory.h"
using namespace std;
int main()
{
    IFactory * Factsquare = new FactorySquare();
    operation * opr = Factsquare->CreateOperation();
    opr->numA = 2;
    opr->numB = 3;
    cout<<opr->getResult()<<endl;
    return 0;
}