#pragma once
#include "person.h"
class sundaniang: public person
{
    public:
        sundaniang():person("孙大娘")
        {
            setGender(WOMAN);
            setAttack(23);
            setDressd("露出绿纱衫儿来，头上黄烘烘的插着一头钗环，鬓边插着些野花");
        }
};