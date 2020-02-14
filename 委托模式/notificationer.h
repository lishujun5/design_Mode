#pragma once
#include <list>
#include "IDelegateHandler.h"
#include <string.h>
using namespace std;
/*通知者抽象接口*/
class Notification
{
    private:
        list<IDelegateHandler *> entruster;
        char *message;
    public:
        Notification(){}
        Notification(const char* message)
        {
            setMessage(message);
        }
        void setMessage(const char *message)
        {
            if(this->message != nullptr)
            {
                delete this->message;
            }
            this->message = new char[strlen(message)+1];
            memcpy(this->message , message , strlen(message));
            *(this->message + strlen(message)) = '\0';
        }
        void notificate()
        {
            for(auto e: entruster)
            {
                e->Invoke(message);
            }
        }
        void addHandler(IDelegateHandler * entt)
        {
            entruster.push_back(entt);
        }
        void deleteHandler(IDelegateHandler * entt)
        {
            entruster.remove(entt);
        }
};