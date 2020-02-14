#pragma once
#include "IDelegateHandler.h"
template <typename T>
class DelegateHandler:public IDelegateHandler
{
public:
    DelegateHandler(T *pT, void (T::*pFunc)(const char *message)) : m_pT(pT),
                m_pFunc(pFunc){}            //初始化对象和函数指针
 
    void Invoke(const char *message) override
    {
        (m_pT->*m_pFunc)(message);        //执行对象：：函数
    }
private:
    T *m_pT;
    void (T::*m_pFunc)(const char*);
};

/*偏特化搞定非成员函数*/
template <>
class DelegateHandler<void>:public IDelegateHandler
{
    public:
        DelegateHandler(void (*pFunc)(const char *message)) :m_pFunc(pFunc){};
        void Invoke(const char* message) override
        {
            (*m_pFunc)(message);
        }
        ~DelegateHandler()
        {
        }
    private:
        void (*m_pFunc)(const char *name);
};