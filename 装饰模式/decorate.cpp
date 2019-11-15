#include "decorate.h"
#include "context.h"
#include "strategy.h"
#include <iostream>
using namespace std;
int main()
{
    double amount = 10000;
    context *discount = new context(new Discount(0.8));    //打折0.8
    context *returncash = new context(new ReturnCash(300,100)); // 满300减100
    context *second_discount = new context(new Discount(0.98));  //折上折

    calculator *calcul = new calculator();   //先打0.8折
    discount->setArith(calcul);
    second_discount->setArith(discount);
    returncash->setArith(second_discount);

    cout<<returncash->ContextInterface(amount)<<endl;


    delete discount;
    delete returncash;
    delete second_discount;

}