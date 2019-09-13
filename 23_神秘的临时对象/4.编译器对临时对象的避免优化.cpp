#include <stdio.h>
class Test
{
	int mi;
public:
	Test(int i)
	{
		printf("Test(int i):%d\n",i);
		mi=i;
	}
	Test(const Test&t)
	{
		printf("Test(const Test&t):%d\n",t.mi);
		mi=t.mi;
	}
	Test()
	{
		printf("Test()\n");
		mi=0;
	}
	int print()
	{
		printf("mi=%d\n",mi);
	}
	~Test()
	{
		printf("~Test()\n");
	}
};
Test func()
{
	return  Test(20);
}
int main()
{
	Test t= Test(10);//推理：先生成一个临时对象，在调用拷贝构造函数， 将临时对象赋值给t
					//结果：看打印并没有调用拷贝构造函数
					//原理：编译器做了优化，避免临时对象的产生 ==>Test t=10;
	Test tt=func();//推理：func()中先生成一个临时对象，在调用拷贝构造函数， 将临时对象赋值给tt 
					//结果：看打印并没有调用拷贝构造函数
					//原理：编译器做了优化，避免临时对象的产生 ==>Test tt=Test(20);==>Test tt=20;
	return 0;
}
