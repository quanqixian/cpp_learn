/**
 * 对象构造时构造函数的调用顺序 
 * 1.调用父类的构造函数
 * 2.调用成员变量的构造函数
 * 3.调用类自身的构造函数 
 * 		口诀心法：
 * 			先父母，后客人，再自己 
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
};
int main(int argc, const char *argv[])
{
	Child cc("cc");

	return 0;
}
