#pragma once
//#include "Iterator.hpp"
#include "node.h"
template <class T>
class Ilist
{
public:
    virtual void push_back(T value) = 0;
    virtual void push_front(T value) = 0;
    virtual void pop_back() = 0;
    virtual void pop_front() = 0;
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual node<T>* getStart() = 0;
    virtual node<T>* getEnd() = 0;
    virtual T front() = 0;
    virtual T back() = 0 ;
};