#include <iostream>
#include "prototype.h"
#include "sundaniang.h"
#include "zhubajie.h"
#include "houzihousun.h"
#include "fakeSunwukong.h"


int main(void)
{
    sunwukong *p = new sunwukong();
    sunwukong *p_sundaniang = (sunwukong *)(p->Clone(new sundaniang()));
    sunwukong *p_houzihousun = (sunwukong *)(p->Clone(new houzihousun()));
    sunwukong *p_zhubajie = (sunwukong *)(p->Clone(new zhubajie()));
    sunwukong *p_sunwukong = (sunwukong *)(p->Clone(p));
    cout<<*p_sundaniang<<endl;
    cout<<*p_houzihousun<<endl;
    cout<<*p<<endl;
    cout<<*p_zhubajie<<endl;
    cout<<*p_sunwukong<<endl;
    delete p;
    delete p_houzihousun;
    delete p_sundaniang;
    delete p_zhubajie;
    delete p_sunwukong;
    p=p_sunwukong=p_zhubajie=p_houzihousun=p_sundaniang = nullptr;
    return 0;
}