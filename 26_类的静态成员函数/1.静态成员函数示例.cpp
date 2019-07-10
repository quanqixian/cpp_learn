/*静态成员函数具有以下特性：
 * 	静态成员函数是类中特殊的成员函数 
 * 	静态成员函数属于整个类所有 
 * 	可以通过类名（作用域访问）直接访问共有静态成员函数 
 * 	可以通过对象名 访问共有静态成员函数
 * */
#include <stdio.h>
class Demo 
{
private:
	int i;
public:
	int getI();
	static void StaticFunc(const char *s);
	static void StaticSetI(Demo&d,int v);
};
int Demo::getI()
{
	return i;
}
void Demo::StaticFunc(const char*s)
{
	printf("StaticFunc:%s\n",s);
}
/*
静态成员函数，没有直接调用变量i，而是通过对象来间接调用变量i，这说明什么呢？
说明：静态成员函数不能访问普通成员变量（函数），需通过对象间接访问成员变量（函数）
*/
void Demo::StaticSetI(Demo&d,int v)
{
	d.i=v;
}
int main()
{
	Demo::StaticFunc("main begin...");
	Demo d;
	Demo::StaticSetI(d,10);
	printf("d.i=%d\n",d.getI());
	Demo::StaticFunc("main end...");
	return 0;
}
