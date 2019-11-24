/**
 * data  :2019.11.24
 * author:qqx
 * about :子类中定义与父类同名的函数
 **/
#include <iostream>
#include <string>
using namespace std;
class Parent
{
public:
	int mi;
	void add(int v)
	{
		mi += v;
	}
	void add(int a, int b)
	{
		mi += (a+b);
	}
};
class Child:public Parent 
{
public:
	int mi;
	void add(int v)
	{
		mi += v;
	}
	void add(int a, int b)
	{
		mi += (a+b);
	}
	void add(int x,int y, int z)
	{
		mi += (x+y+z);
	}
};
int main(int argc, const char *argv[])
{
	Child c;
	c.mi = 100;
	 c.Parent::mi = 1000;
	 cout<<"c.mi = "<<c.mi<<endl;
	 cout<<"c.Parent::mi = <<"<<c.Parent::mi<<endl;
	 c.add(1);
	 c.add(2,3);
	 c.add(4,5,6);
	 cout<<"c.mi = "<<c.mi<<endl;
	 cout<<"c.Parent::mi =  "<<c.Parent::mi<<endl;

	
	return 0;
}
/**
 * 子类中定义与父类中完全相同的函数可行
 * 子类调用时，是调用子类的成员函数，除非加上父类的作用域分辨符 
 */
