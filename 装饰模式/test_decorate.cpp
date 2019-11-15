#include <iostream>
#include<string>

//person 类
class Person
{
public:
    Person(){};
    Person(std::string name);
    virtual void Show();
    //当你用一个基类指针或引用指向一个继承类对象的时候，
    //调用一个虚函数时, 实际调用的是继承类的版本。


private:
    std::string name;
};

Person::Person(std::string name)
{
    this->name = name;
}

void Person::Show(){
    //父类的函数
    std::cout << "装饰的"<< name << std::endl;
}

//装饰类
//负责穿戴不同的服装 有一个参数是服装对象
class Finery :public Person{
protected:
    Person* component;
public:
    Finery(){};
    void Decorator(Person* component);//穿衣服函数
    void Show();
};

void Finery::Decorator(Person* component){
    this->component = component;
}
void Finery::Show(){
//子类的函数
    if (component != NULL)
        component->Show();
}


//具体服装
class Tshirts :public Finery{
public:
    Tshirts(){};
    void Show(){
        std::cout << "T shirts";
        Finery::Show();
    }
};

class Sneakers :public Finery{
public:
    Sneakers(){};
    void Show(){
        std::cout << " Sneakers";
        Finery::Show();
    }
};



int main(){
    
    Person* xc = new Person("小菜");
    std::cout << "first style:" << std::endl;
    Tshirts* ts = new Tshirts();
    Sneakers* sn = new Sneakers();

    ts->Decorator(xc);//小菜穿第一件衣服
    sn->Decorator(ts);//小菜穿第二件衣服
    sn->Show();
    
    
    system("pause");
}