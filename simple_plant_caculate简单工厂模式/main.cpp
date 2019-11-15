#include <iostream>
#include "operation.h"
#include "operationCreator.h"
using namespace std;
int main()
{
    string strOpt;
    operationCreator plant;
    cout<<"input operator"<<endl;
    cin>>strOpt;
    operation *opt = plant.operationCreat(strOpt);
    if(!opt)
        return -1;
    cout<<"input num one"<<endl;
    cin>>opt->numA;
    cout<<"input num two"<<endl;
    cin>>opt->numB;
    cout<<"result = "<<opt->getResult()<<endl;
    return 0;
}