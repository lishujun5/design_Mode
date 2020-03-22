#pragma once
template<class T>
struct Node
{
    Node* pre;
    Node* next;
    T val;
};
