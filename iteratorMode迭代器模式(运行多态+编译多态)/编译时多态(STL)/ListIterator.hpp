#pragma once
#include "type_traist.hpp"
#include "node.hpp"
template<class T>
class ListIterator
{       
public:
    typedef typename type_traist<T>::value_type value_type;
    typedef typename type_traist<T>::point point;
    typedef typename type_traist<T>::reference reference;
    typedef ListIterator<T> self;
    typedef Node<T> list_node;
    ListIterator(list_node *node)
    {
        this->node = node; 
    }
    ListIterator(const self& other)
    {
        this->node = other.node;
    }
    self& operator++()
    {
        node = node->next;
        return *this;
    }
    self operator++(int)
    {
        self tmp = *this;
        ++(*this);
        return tmp; 
    }
    bool operator==(const self& other)
    {
        return this->node == other.node;
    }
    bool operator!=(const self& other)
    {
        return this->node != other.node;
    }
    reference operator*() const
    {
        return this->node->val;
    }
    point operator->() const
    {
        return &(this->node->val);
    }
    private:
        list_node *node;
};