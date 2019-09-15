#include <iostream>
using namespace std;
template <typename T1,typename T2>
class Test
{
public:
	void add(T1 a,T2 b)
	{
		cout<<"void add(T1 a ,T2 b)"<<endl;
		cout<<a+b<<endl;
	}
};
template <typename T1,typename T2>
class Test <T1 *,T2*>//关于指针的特化实现
{
public:
	void add(T1*a,T2*b)
	{
		cout<<__func__<<endl;
		cout<<*a+*b<<endl;
	}
};
template <typename T>
class Test<T,T>
{
public:
	void add(T a,T b)
	{
		cout<<__func__<<endl;
		cout<<a+b<<endl;
	}
	void print()
	{
		cout<<__func__<<endl;
	}
};
int main()
{
	return 0;
}
