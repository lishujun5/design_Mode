#include "notificationer.h"
#include "sundaniang.h"
#include "sunwukong.h"
#include "zhubajie.h"
#include "sasidi.h"
#include <iostream>
#include "DelegateHandler.h"
using namespace std;
int main()
{
    person *notificator = new sundaniang();
    sunwukong *listen_1 = new sunwukong();
    zhubajie *listen_2 = new zhubajie();
    shashidi *listen_3 = new shashidi();
    notificator->setMessage("师傅被妖怪抓走了");
    IDelegateHandler *sunwukongAction = new DelegateHandler<sunwukong>(listen_1, &sunwukong::fuckMonster);
    IDelegateHandler *zhubajieAction = new DelegateHandler<zhubajie>(listen_2 , &zhubajie::hidingMyself);
    IDelegateHandler *shashidiAction = new DelegateHandler<shashidi>(listen_3 , &shashidi::callPerson);
    notificator->addHandler(sunwukongAction);
    notificator->addHandler(zhubajieAction);
    notificator->addHandler(shashidiAction);
    notificator->notificate();
    delete notificator;
    delete listen_1;
    delete listen_2;
    delete listen_3;
    delete sunwukongAction;
    delete zhubajieAction;
    delete shashidiAction;
    return 0;
}
