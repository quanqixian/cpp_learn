/*测试子类是否可以访问父类私有成员变量*/
/*结果：不能通过编译*/
/*protected 成员变量不能被外界访问，能被子类访问*/
#include <iostream>
#include <string>
using namespace std;
class Parent
{
protected:
	int mv;
public:
	Parent()
	{
		mv=100;
	}
	int value()
	{
		return mv;
	}
};
class Child:public Parent 
{
public:
	int addValue(int v)
	{
		mv=mv+v; //can this be ok?
	}
};
int main()
{
	Parent p;
	cout<<"p.mv="<<p.value()<<endl;
	//p.mv=1000; //error 
	Child c;
	cout<<"c.mv="<<c.value()<<endl;
	c.addValue(50);
	cout<<"c.mv="<<c.value()<<endl;
	//c.mv=10000;//error
	return 0;
}
