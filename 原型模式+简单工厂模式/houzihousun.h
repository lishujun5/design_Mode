#pragma once
#include "person.h"
class houzihousun: public person
{
    public:
        houzihousun():person("猴子猴孙")
        {
            setGender(MAN);
            setAttack(18);
            setDressd("一张桃子形的面孔上,嵌着两颗闪着金光的眼睛,整天骨碌骨碌地直转,好像在打着什么主意.那小小的鼻子又塌又扁,而鼻孔却很大.鼻子下面有一张尖尖的大嘴巴,可爱极了!");
        }
};