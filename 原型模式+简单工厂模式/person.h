#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include "notificationer.h"
using namespace std;
/*人物接口*/
typedef enum{
    MAN = 0,
    WOMAN
}GENDER;

class person : public Notification
{
    protected:
        char *name;  //姓名
        char gender;  //性别：0->男 1->女
        char *dressd; //衣着
        int attack;  //攻击力
        char *pretendName; //伪装后身份
    public:
        ~person()
        {
            if(name != nullptr)
                delete name;
            if(dressd != nullptr)
                delete dressd;
            if(pretendName != nullptr)
                delete pretendName;
            name = dressd = pretendName =nullptr;
        }
        person() = delete;
        person(const char *name):Notification()
        {
            setPretendName("没有伪装");
            int nameLen = strlen(name);
            this->name = new char[nameLen+1];
            strncpy(this->name,name,nameLen);
        }
        void setName(const char *name)
        {
            if(this->name != nullptr)
            {
                delete this->name;
            }
            int nameLen = strlen(name);
            this->name = new char[nameLen+1];
            strncpy(this->name,name,nameLen);
        }
        const char* getName() const
        {
            return name;
        }
        bool setGender(int gender)
        {
            if(gender <  0 || gender > 1)
            {
                return false;
            }
            this->gender = gender;
            return true;
        }
        const char *getGender() const
        {
            switch (gender)
            {
            case 0:
                return "男";
            case 1:
                return "女";
            default:
                return "未知性别";
            };
        }
        bool setDressd(const char *dress)
        {
            if(this->dressd != nullptr)
            {
                delete this->dressd;
            }
            int dressLen = strlen(dress);
            this->dressd = new char[dressLen + 1];
            strncpy(this->dressd , dress , dressLen);
            return true;
        }
        const char* getDress() const
        {
            return dressd;
        }
        void setAttack(int attack)
        {
            this->attack = attack;
        }
        int getAttack()
        {
            return attack;
        }
        bool setPretendName(const char* name)
        {
            if(this->pretendName != nullptr)
            {
                delete this->pretendName;
            }
            int nameLen = strlen(name);
            this->pretendName = new char[nameLen + 1];
            strncpy(this->pretendName , name , nameLen);
            *(this->pretendName+nameLen) = '\0';
            return true;
        }
        const char *getPretendName() const
        {
            return pretendName;
        }
};
ostream& operator << (ostream& outp , person& c)
{
    outp<<"姓名："<<c.getName()<<endl;
    outp<<"性别："<<c.getGender()<<endl;
    outp<<"衣着："<<c.getDress()<<endl;
    outp<<"攻击力:" <<c.getAttack()<<endl;
    outp<<"伪装："<<c.getPretendName()<<endl;
    cout<<"***************************"<<endl<<endl;;
    return outp;
}