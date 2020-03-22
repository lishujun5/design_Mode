//#include "Iterator.hpp"
#include "Ilist.hpp"
#include "node.h"
template<class T>
class ListIterator
{
public:
    ListIterator(Ilist<T> *list)
    {
        m_list = list;
        cur = list->getStart();
    }
    ListIterator(const ListIterator<T>& other)
    {
        m_list = other.m_list;
        cur = other.cur;
    }
    bool operator==(const ListIterator<T>& other)
    {
        return other.cur == this->cur;
    }
    bool operator!=(const ListIterator<T>& other)
    {
        return other.cur != this->cur;
    }
    T& operator*()
    {
        return cur->value;
    }
    ListIterator<T>& operator++()//前++
    {
        this->cur = this->cur->next;
        return *this;
    }
    ListIterator<T> operator++(int) //后++
    {
        ListIterator<T> tmp(*this);
        ++(*this);
        return tmp;
    }
  void SetCur(node<T>* other)
    {
        cur = other;
    }
private:
    Ilist<T> *m_list;
    node<T> *cur;
};

