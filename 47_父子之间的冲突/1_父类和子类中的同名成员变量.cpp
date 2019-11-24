/**
 *data  :2019.11.24
 *author:qqx
 *about :子类中是否可以定义父类中的同名成员，如果可以，如何区分?
 */
#include <iostream>
#include <string>

using namespace std;
class Parent 
{
public:
	int mi;
	Parent()
	{
		cout<<"Parent():"<<"&mi = "<<&mi<<endl;
	}
};
class Child: public Parent 
{
public:
	int mi;
	Child()
	{
		cout<<"Child:"<<"&mi = "<<&mi<<endl;
	}
};
int main(int argc, const char *argv[])
{
	Child c;
	c.mi=100;
	c.Parent::mi=1000;
	
	cout<<"&c.mi="<<&c.mi<<endl;
	cout<<"c.mi="<<c.mi<<endl;

	cout<<"&c.Parent::mi="<<&c.Parent::mi<<endl;
	cout<<"c.Parent::mi="<<c.Parent::mi<<endl;

	return 0;
}

/**
 * result:
 * 子类可以定义父类的同名成员
 * 子类中的成员函数隐藏父类中的同名成员函数
 * 父类中的同名成员依然存在于子类中
 * 通过作用域分辨符（::）访问父类中的同名成员 
 */
