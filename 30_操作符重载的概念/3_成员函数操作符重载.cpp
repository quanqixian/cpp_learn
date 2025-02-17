/**
 * 可以将操作符重载函数定义为类的成员函数
 *  -臂全局操作符重载函数少一个参数（左操作数）
 *  -编译器优先在成员函数中寻找操作符重载函数 
 */
#include <stdio.h>
class Complex
{
	int a;
	int b;
public:
	Complex(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	int getA()
	{
		return a;
	}
	int getB()
	{
		return b;
	}
	Complex operator +(const Complex &p)
	{
		Complex ret;
		ret.a = this->a + p.a;
		ret.b = this->b + p.b; 
		return ret;
	}
	friend Complex operator +(const Complex&p1, const Complex& p2);
};
Complex operator +(const Complex&p1, const Complex& p2)
{
	Complex ret;
	ret.a = p1.a + p2.a;
	ret.b = p1.b + p2.b;
	return ret;
}
int  main(int argc, const char *argv[])
{
	Complex c1(1,2);
	Complex c2(3,4);
	Complex c3= c1 +c2;
	printf("c3.a =%d,c3.b =%d\n",c3.getA(),c3.getB());
	return 0;
}
