#pragma once
template<typename T>
struct node
{
    node* next;
    node* pre;
    T value;
};