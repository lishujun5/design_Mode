//成员函数指针进一步抽象接口
#pragma once
class IDelegateHandler{
public:
    virtual ~IDelegateHandler() {}
    virtual void Invoke(const char *message) = 0;
};