#include <iostream>
#include <string>
using namespace std;
template <class T>
class Test
{
public:
	Test(T t)
	{
		cout<<"t="<<t<<endl;
	}
};
template <class T>
void func(T a[], int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<a[i]<<endl;
	}
}
/************************************************/
int a=0;
class Test_1
{
public:
	static const int TS=1;
};
class Test_2 
{
public:
	struct TS 
	{
		int value;
	};
};
template <class T>
void test_class()
{   //如何理解下面的代码？
	typename T::TS *a  ;   
	// T::TS *a  ;   //1.通过泛指类型 T内部的数据类型TS定义指针变量 a'.(推荐的解读)
}                          //2.使用泛指类型 T内部的静态成员变量TS与全局变量a进行乘法操作
int main(int argc, const char *argv[])
{
	//Test<int>
	//a[5]={1,2,3,4,5};//分析：使用class定义模板参数和typename是一样的，并没有说将模板限定为类，class定义模板参数是历史原因	
	//test_class<Test_1>();
	test_class<Test_2>();//必须使用typename 修饰才能编译通过，否则编译器按照第二种解释进行编译 
	                     // typename 的作用：1.在模板定义中声明泛指类型
						 // 				 2.明确告诉编译器其后的标识符为类型
	
	return 0;
}
