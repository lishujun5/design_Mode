#include "employee.h"
int employee::startNum = 1000;

string manager::getType()
{
    return "manager";
}
void manager::getPay()
{
    _salary = _salary;
}
void manager::init()
{
    cout<<"input manager employee name"<<endl;
    cin>>_name;
    _salary = originSalaryManager;
    _grade = 4;
}

void manager::promote(int increment)
{
    _grade += increment;
}
string technicist::getType()
{
    return "technicist";
}
void technicist::init()
{
    cout<<"input technicist employee name"<<endl;
    cin>>_name;
    cout<<"input "<<_name<<" employee "<<"work hour"<<endl;
    cin>>workHour;
    _salary = 0;
    _grade = 3;
}
void technicist::getPay()
{
    _salary = workHour*100;
}
void technicist::promote(int increment)
{
    _grade += increment;
}
string salesman::getType()
{
    return "salesman";
}
void salesman::getPay()
{
    _salary = _saleroom*0.04;
}
void salesman::promote(int increment)
{
    _grade += increment;
}
void salesman::init()
{
    cout<<"input salesman employee name"<<endl;
    cin>>_name;
    cout<<"input "<<_name<<" employee "<<"saleroom"<<endl;
    cin>>_saleroom;
    _salary =0;
    _grade = 1;
}
string salesManger::getType()
{
    return "salesManger";
}

void salesManger::getPay()
{
    _salary = _salary + _saleroom*0.05;
}
void salesManger::promote(int increment)
{
    _grade += increment;
}
void salesManger::init()
{
    cout<<"input salesManger employee name"<<endl;
    cin>>_name;
    cout<<"input "<<_name<<" employee "<<"saleroom"<<endl;
    cin>>_saleroom;
    _salary = originSalarySaleManger;
    _grade = 3;
}

