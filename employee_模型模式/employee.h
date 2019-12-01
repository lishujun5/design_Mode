#ifndef __EMPLOYEE__
#define __EMPLOYEE__
#include <iostream>
using namespace std;
const int originSalaryManager = 8000;
const int originSalarySaleManger = 5000;
class employee
{
    protected:
        string _name;   //雇员姓名
        int _id;       //雇员ID
        float _salary;   //工资
        int _grade;   //级别
        static int startNum;//雇员ID开始编号
    public:
        employee():_id(startNum++),_grade(1){}
        virtual void getPay() = 0;
        virtual string getType() = 0;
        virtual void promote(int increment = 1) = 0;
        virtual void init() = 0;
        void disInfor()
        {
            cout<<_name<<":"<<_id<<endl;
            cout<<"work type:"<<getType()<<endl;
            cout<<"salary:"<<_salary<<endl;
            cout<<"grade:"<<_grade<<endl;
        }
};
//经理
class manager:virtual public employee
{
    public:
        manager():employee()
        {

        }
        virtual void getPay();
        void init();
        string getType();
        void promote(int increment = 0);
};
//销售人员
class salesman:virtual public employee
{
    protected:
        int _saleroom;   //销售额
    public:
        salesman():employee()
        {

        }
        virtual void getPay();
        string getType();
        void init();
        void promote(int increment = 0);
};
//技术人员
class technicist:public employee
{
    protected:
        int workHour;   //工作时长
    public:
        technicist():employee()
        {

        }
        void getPay();
        string getType();
        void init();
        void promote(int increment = 0);
};
//销售经理
class salesManger:public salesman,public manager
{
    public:
        salesManger()
        {

        }
        virtual void getPay();
        string getType();
        void init();
        void promote(int increment = 0);
};
#endif