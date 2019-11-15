#include <iostream>
#include<string>

//person ��
class Person
{
public:
    Person(){};
    Person(std::string name);
    virtual void Show();
    //������һ������ָ�������ָ��һ���̳�������ʱ��
    //����һ���麯��ʱ, ʵ�ʵ��õ��Ǽ̳���İ汾��


private:
    std::string name;
};

Person::Person(std::string name)
{
    this->name = name;
}

void Person::Show(){
    //����ĺ���
    std::cout << "װ�ε�"<< name << std::endl;
}

//װ����
//���𴩴���ͬ�ķ�װ ��һ�������Ƿ�װ����
class Finery :public Person{
protected:
    Person* component;
public:
    Finery(){};
    void Decorator(Person* component);//���·�����
    void Show();
};

void Finery::Decorator(Person* component){
    this->component = component;
}
void Finery::Show(){
//����ĺ���
    if (component != NULL)
        component->Show();
}


//�����װ
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
    
    Person* xc = new Person("С��");
    std::cout << "first style:" << std::endl;
    Tshirts* ts = new Tshirts();
    Sneakers* sn = new Sneakers();

    ts->Decorator(xc);//С�˴���һ���·�
    sn->Decorator(ts);//С�˴��ڶ����·�
    sn->Show();
    
    
    system("pause");
}