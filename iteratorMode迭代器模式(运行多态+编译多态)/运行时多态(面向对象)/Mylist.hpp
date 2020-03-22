#pragma once
#include <iostream>
#include "Ilist.hpp"
#include "Myiterator.hpp"
using std::cout;
using std::cin;
using std::endl;
template <class T>
class MyList : public Ilist<T>
{
    private:
        node<T>* header;
        int size;
        node<T>* _end;   //指向尾结点
    public:
    typedef ListIterator<T> iter;
        MyList():size(0)
        {
            header = new node<T>;
            _end = new node<T>();
            header->pre = header;
            header->next = _end;
            _end->pre = header;
            _end->next = nullptr;
        }
        ~MyList()
        { 
            auto i = header;
            while(i != _end)
            {
                auto tmp = i->next;
                delete i;
                i = tmp;
            }
            delete _end;
        }
        void push_back(T value) override
        {
            node<T>* tmp = new node<T>;
            tmp->pre = _end->pre;
            tmp->next = _end;
            tmp->value = value;
            _end->pre->next = tmp;
            _end->pre = tmp;
            ++size;
        }
        void push_front(T value) override
        {
            node<T>* tmp = new node<T>;
            tmp->next = header->next;
            tmp->pre = header;
            tmp->value = value;
            header->next = tmp;
            tmp->next->pre = tmp;
            ++size;
        }
        void pop_back() override
        {
            if(size != 0)
            {
                node<T> *tmp = _end->pre;
                _end->pre->pre->next = _end;
                _end->pre = _end->pre->pre;
                delete tmp;
                --size;
            }
        }
        void pop_front() override
        {
            if(size != 0)
            {  
                node<T>* tmp = header->next;
                header->next->next->pre = header;
                header->next = header->next->next;
                delete tmp;
                --size;
            }
        }
        int getSize() override
        {
            return size;
        }
        bool isEmpty() override
        {
            return size==0;
        }
        node<T>* getStart() override
        {
            return header->next;
        }
        node<T>* getEnd() override
        {
            return _end;
        }
 
        T front() override
        {
            return header->next->value;
        }
        T back() override
        {
            return _end->pre->value;
        }
        ListIterator<T> begin()
        {   
            ListIterator<T> tmp(this);
            tmp.SetCur(header->next);
            return tmp;
        }
        ListIterator<T> end()
        {
            ListIterator<T> tmp(this);
            tmp.SetCur(_end);
            return tmp;
        }
};