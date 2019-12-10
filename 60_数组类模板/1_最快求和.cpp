/*
 * 1.模板参数可以是数值型参数（非类型参数）
 * 	template <typename T, int N>
 * 	void func()
 * 	{
 * 		T a[N];使用模板餐厨定义局部数组 
 * 	}
 * 2.数值型模板参数的限制
 * -变量不能作为模板参数
 * -浮点数不能作为模板参数
 * -类对象不能作为模板参数 
 */
#include <iostream>
#include <string>
using namespace std;
template <typename T, int N>
void func()
{
	T a[N] = {0};
	for(int i = 0; i<N;i++)
	{
		a[i] = i;
	}
	for(int i=0;i<N;i++)
	{
		cout<<a[i]<<endl;
	}
}
template<int N>
class Sum
{
public:
	static const int VALUE=Sum<N-1>::VALUE+N;
};
template <>
class Sum <1>
{
public:
	static const int VALUE = 1;
};
int main(int argc, const char *argv[])
{
	cout <<"1+2+3+...+ 10="<<Sum<10>::VALUE<<endl;
	cout <<"1+2+3+...+100="<<Sum<100>::VALUE<<endl;
	return 0;
}
