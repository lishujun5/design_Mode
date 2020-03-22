#pragma once
#include "ListIterator.hpp"
#include "node.hpp"
#include "type_traist.hpp"
template<class T>
class Mylist
{
    public:
        typedef ListIterator<T> iterator;
        typedef Node<T> list_node;
        typedef typename type_traist<T>::value_type value_type;
        typedef typename type_traist<T>::point point;
        typedef typename type_traist<T>::reference reference;
    Mylist():size(0)
    {
            header = new list_node;
            _end = new list_node;
            header->pre = header;
            header->next = _end;
            _end->pre = header;
            _end->next = nullptr;
    }
    ~Mylist()
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
    void push_back(T value)
        {
            list_node* tmp = new list_node;
            tmp->pre = _end->pre;
            tmp->next = _end;
            tmp->val = value;
            _end->pre->next = tmp;
            _end->pre = tmp;
            ++size;
        }
        void push_front(T value)
        {
            list_node* tmp = new list_node;
            tmp->next = header->next;
            tmp->pre = header;
            tmp->val = value;
            header->next = tmp;
            tmp->next->pre = tmp;
            ++size;
        }
        void pop_back()
        {
            if(size != 0)
            {
                list_node *tmp = _end->pre;
                _end->pre->pre->next = _end;
                _end->pre = _end->pre->pre;
                delete tmp;
                --size;
            }
        }
        void pop_front()
        {
            if(size != 0)
            {  
                list_node* tmp = header->next;
                header->next->next->pre = header;
                header->next = header->next->next;
                delete tmp;
                --size;
            }
        }
        int getSize()
        {
            return size;
        }
        bool isEmpty()
        {
            return size==0;
        }
        value_type front()
        {
            return header->next->val;
        }
        value_type back()
        {
            return _end->pre->val;
        }
        iterator begin()
        {
            iterator tmp(header->next);
            return tmp;
        }
        iterator end()
        {
            iterator tmp(_end->pre);
            return tmp;
        }
    private:
        list_node* header; 
        list_node* _end;
        int size;
};