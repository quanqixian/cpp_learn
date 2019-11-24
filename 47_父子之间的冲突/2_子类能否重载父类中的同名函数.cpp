/**
 * data  :2019.11.24
 * author:qqx
 * about :子类中定义的函数能否重载父类中的同名函数？
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
	void add(int a,int b)
	{
		mi += (a+b);
	}
};
class Child: public Parent 
{
public:
	int mi;
	void add(int x,int y,int z)
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
	cout<<"c.Parent::mi = "<<c.Parent::mi<<endl;
	c.Parent::add(1);//c.add(1);
	c.Parent::add(2,3);      //c.add(2,3);
	c.add(4,5,6);
	cout<<"c.mi="<<c.mi<<endl;
	cout<<"c.Parent::mi = "<<c.Parent::mi<<endl;
	return 0;
}
/**
 * result:
 * 重载必须发生在同一个作用域中
 * 子类中的同名函数，将子类从父类中继承的两个add函数隐藏了，必须加上作用域
 */
