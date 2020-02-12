#include<iostream>
#include<string>
using namespace std;
/*思考 原型模式与直接new的好处在哪里*/
/*可进行定制化复制参考 而不是需要整个类new  不需要修改部分可直接使用浅拷贝 指向相同内存区域进行引用  而需要修改部分就自身进行进行深拷贝 从而减少内存开销 如果使用拷贝函数 则需要重新分配内存 比较麻烦*/
class Prototype // Prototype（抽象原型角色）：是抽象类或者接口，用来声明clone方法。该方法是用来克隆自身的接口。
{
public:
	virtual ~Prototype() = default;
	virtual Prototype* Clone() = 0;

};
class WorkExperience final :public Prototype
{// ConcretePrototype（具体的原型类）：是客户端角色使用的对象，即被复制的对象。需要实现克隆自身的具体操作。
private:
	std::string m_workDate;
	std::string m_company;
public:
	string getWorkDate(){ return m_workDate; }
	string getCompany() { return m_company; }
	void setWorkDate(string workDate) { m_workDate = workDate; }
	void setCompany(string company) {m_company = company;}

	Prototype* Clone()override
	{
		WorkExperience *p = new WorkExperience();    //先申请内存 后进行自我赋值操作
		*p = *this;
		return p;
	}
};

class Resume final :public Prototype
{//ConcretePrototype（具体的原型类）：是客户端角色使用的对象，即被复制的对象。需要实现克隆自身的具体操作。
private:
	std::string m_name;
	std::string m_sex;
	std::string m_age;
    WorkExperience *m_work;
public:
    explicit Resume()
    {
        m_work = new WorkExperience();
    }
	explicit Resume(WorkExperience *work) :m_work((WorkExperience*)work->Clone()) {}
    ~Resume()
    {
        if(m_work != nullptr)
        {
            cout<<"~Resume()"<<endl;   //解决源代码中的内存泄露问题
            delete m_work;
        }
    }
public:
	void SetPersonalInfo(string name, string sex, string age)
	{
		m_name = name;
		m_sex = sex;
		m_age = age;
	}
	void SetWorkExperience(std::string workDate, std::string company)
	{
		m_work->setWorkDate(workDate);
		m_work->setCompany(company);
	}
	void Display()
	{
		cout << "姓名：" << m_name << " "
			<< " 性别：" << m_sex << " "
			<< " 年龄：" << m_age << endl;

		cout << "工作经历为：" << m_work->getWorkDate() << " " << m_work->getCompany() << endl << endl;

        cout<<"m_work = "<<m_work<<endl;
		
	}
	Prototype *Clone()override
	{
		Resume *cloneResume = new Resume(m_work);   //工作经历采用自我clone 深拷贝方式进行
		cloneResume->m_name = this->m_name;
		cloneResume->m_sex = this->m_sex;
		cloneResume->m_age = this->m_age;
		return cloneResume;
	}
};
int main()
{
	Resume *a = new Resume;
	a->SetPersonalInfo("大鸟", "男", "29");
	a->SetWorkExperience("1998-2000", "XX公司");
	a->Display();


	Resume *b = (Resume*)a->Clone();
	b->SetPersonalInfo("黄成涛", "男", "22");
	b->SetWorkExperience("1997-2006", "YY公司");
	b->Display();

	Resume *c = (Resume*)a->Clone();
	c->SetPersonalInfo("小菜", "男", "20");
	c->SetWorkExperience("2000-2006", "ZZ公司");
	c->Display();

	delete a;
	delete b;
	delete c;
	a = b = c = nullptr;
	system("pause");
	return 0;
}