#pragma once
#include "person.h"
class shashidi: public person
{
    public:
        shashidi():person("沙师弟")
        {
            setGender(MAN);
            setAttack(19);
            setDressd("一头红焰发蓬松,两只圆睛亮似灯。不黑不清蓝靛脸,如雷如鼓老龙声。");
        }
        void callPerson(const char* message)
        {
            cout<<name<<"听到"<<message<<","<<"赶紧去叫大师兄"<<endl;
        }
};