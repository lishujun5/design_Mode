#pragma once
#include "person.h"
class Prototype // Prototype（抽象原型角色）：是抽象类或者接口，用来声明clone方法。该方法是用来克隆自身的接口。
{
public:
	virtual ~Prototype() = default;
	virtual Prototype* Clone(person *soucePerson)  = 0;
};