#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Operator
{
public:
	T add(T a,T b)
	{
		return a+b;
	}
	T sub(T a,T b)
	{
		return a-b;
	}
	T mul(T a,T b)
	{
		return a*b;
	}
	T div(T a,T b)
	{
		return a/b;
	}
};
/*编译器对类模板的处理方式和函数模版相同
 * 在类模板声明的地方对模板进行一次编译 
 * 在使用的地方对参数替换之后对代码进行一次编译
 * */
string operator -(string &l,string &r)
{
	return "sub";
}
int main()
{
	Operator<int > a;
	cout<<a.add(1,2)<<endl;
	Operator<string> b;
	cout<<b.add("hello","world")<<endl;
	cout<<b.sub("hello","world")<<endl;
	return 0;
}
