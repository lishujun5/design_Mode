#pragma once
#include <typeinfo>
#include "prototype.h"
#include "person.h"
class sunwukong : public Prototype , public person
{
    public:
        sunwukong():person("孙悟空")
        {
            setGender(MAN);
            setAttack(100000);
            setDressd("锁子黄金甲，凤翅紫金冠，藕丝步云履，如意金箍棒");
        }
        Prototype* Clone(person *soucePerson)
        {
            cout<<typeid(*soucePerson).name()<<endl;                //本来准备使用typeid区分不同的子类 但是这里区分全部都是父类 不明原因。。。
            return personCreate(soucePerson);                        //欢迎指导
        }
        sunwukong *personCreate(person *sourcePerson)
        {
            sunwukong * backPerson = nullptr;
            if(0 != strcmp(sourcePerson->getName() , "孙悟空"))     //孙大娘 猪八戒 猴子猴孙   因为其他都需要改变所以全部采用深拷贝方式进行
            {
                backPerson = new sunwukong(sourcePerson);
                backPerson->name= this->name;
                backPerson->setAttack(sourcePerson->getAttack());
                backPerson->setDressd(sourcePerson->getDress());
                if(0 == strcmp(sourcePerson->getGender(),"男"))
                    backPerson->setGender(MAN);
                else
                     backPerson->setGender(WOMAN);
                backPerson->setPretendName(sourcePerson->getName());
            }
            else if(0 == strcmp(sourcePerson->getName() , "孙悟空"))            //真假悟空穿着姓名都引用悟空的
            {
                backPerson = new sunwukong(sourcePerson);
                backPerson->setPretendName("假悟空");
                backPerson->setAttack(0);
                backPerson->name = const_cast<char *>(sourcePerson->getName());
                backPerson->dressd = const_cast<char *>(sourcePerson->getDress());
                backPerson->setGender(MAN);
            }
            else
            {
                return nullptr;
            }
            return backPerson;
        }
        void fuckMonster(const char *message)
        {
            cout<<name<<"听到"<<message<<"，"<<"打妖怪"<<endl;
        }
        private:
            sunwukong(person *sourceType):person("孙悟空"){};
};