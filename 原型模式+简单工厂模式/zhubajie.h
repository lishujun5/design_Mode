#pragma once
#include "person.h"
class zhubajie: public person
{
    public:
        zhubajie():person("猪八戒")
        {
            setGender(MAN);
            setAttack(60);
            setDressd("黑脸短毛，长喙大耳，穿一身青不青，蓝不蓝的梭布直裰，系一条花布手巾");
        }
        void hidingMyself(const char* message)
        {
            cout<<name<<"听到"<<message<<","<<"赶紧躲起来"<<endl;
        }
};