#include "employee.h"
#include <typeinfo>
int main()
{
    employee * p[] = {new manager,new technicist,new salesman,new salesManger};
    #if 1
    for(int i=0; i<sizeof(p)/sizeof(p[0]); i++)
    {
        p[i]->init();
        p[i]->getPay();
        cout<<"-----------------"<<endl;
        p[i]->disInfor();
        cout<<"-----------------"<<endl;
    }
    for(int i=0; i<sizeof(p)/sizeof(p[0]); i++)
    {
        if(typeid(*p[i]) == typeid(manager))
        {
            p[i]->promote(1);
            p[i]->disInfor();
            break;
        }
    }

    #endif
    return 0;
}