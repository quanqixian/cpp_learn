/**
 *父类构造函数在子类中的调用方式 
 * -默认调用
 *  适用于无参构造函数和使用默认参数的构造函数 
 * -显示调用
 *  适用于初始化列表调用
 *  适用于所有父类构造函数 
 */
#include <iostream>
#include <string>
using namespace std;
class Parent
{
public:
	Parent()
	{
		cout<<"Parent()"<<endl;
	}
	Parent(string s)
	{
		cout<<"Parent(string s):"<<s<<endl;
	}
};
class Child:public Parent 
{
public:
	Child()
	{
		cout<<"Child()"<<endl;
	}
	Child(string s):Parent(s)
	{
		cout<<"child(string s):"<<s<<endl;
	}
};
int main()
{
	Child c;
	Child cc("cc");
	return 0;
}




