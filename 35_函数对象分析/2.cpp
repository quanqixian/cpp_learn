#include <iostream>
#include <string>
using namespace std;
class Fib
{
	int a0;
	int a1;
public:
	Fib()
	{
		a0=0;
		a1=1;
	}
	Fib(int n)
	{
		a0=0;
		a1=1;
		for(int i=2;i<=n;i++)
		{
			int t=a1;
			a1=a0+a1;
			a0=t;
		}
	}
	int operator() ()//函数调用操作符重载 
	{
		int ret=a1;
		a1=a0+a1;
		a0=ret;
		return ret;
	}
};
int main()
{
	Fib fib;
	for(int i=0;i<10;i++)
	{
		cout<<fib()<<endl;
	}
	cout<<endl;
	for(int i=0;i<5;i++)
	{
		cout <<fib()<<endl;
	}
	cout<<endl;
	Fib fib2(10);
	for(int i=0;i<5;i++)
	{
		cout<<fib2()<<endl;
	}
	return 0;

}
/*我的理解：
 * 	函数对象还是对象，通过重载函数操作符(),使得对象能通过函数的方式访问，
 * 	对象可以创建多个，每一个对象的私有成员是相互独立的，利用这个性质弥补函数的不足*/
