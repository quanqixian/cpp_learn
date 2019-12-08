/**
 * 析构函数的调用顺序与构造函数相反
 * 1.执行自身的析构函数
 * 2.执行成员变量的析构函数
 * 3.执行父类的析构函数 
 *
 */
#include <iostream>
#include <string>
using namespace std;

class Object 
{
public:
	Object(string s)
	{
		cout<<"Object(string s):"<<s<<endl;
	}
	~Object()
	{
		cout<<__func__<<endl;
	}
};
class Parent: public Object
{
public:
	Parent():Object("Default")
	{
		cout<<"Parent"<<endl;
	}
	Parent(string s):Object(s)
	{
		cout<<"Parent(string s):"<<s<<endl;
	}
	~Parent()
	{
		cout<<__func__<<endl;
	}
};
class Child :public Parent 
{
	Object mO1;
	Object mO2;
public:
	Child():mO1("Default 1"),mO2("Default 2")
	{
		cout<<"Child()"<<endl;
	}
	Child(string s):Parent(s),mO1(s+"1"),mO2(s+"2")
	{
		cout<<"Child(string s):"<<s<<endl;
	}
	~Child()
	{
		cout<<__func__<<endl;
	}
};
int main(int argc, const char *argv[])
{
	Child cc("cc");

	cout<<endl;
	return 0;
}
