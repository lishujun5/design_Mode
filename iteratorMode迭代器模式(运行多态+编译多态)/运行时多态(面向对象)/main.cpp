#include "Mylist.hpp"
#include "iterator"
#include <iostream>
using namespace std;
int main()
{
    MyList<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_front(5);
    a.push_front(6);
    a.push_front(7);
    a.pop_front();
    a.pop_back();
    for (auto i = a.begin() ; i != a.end() ; i++)
    {
        cout<<*i<<endl;
    }
    return 0;
}