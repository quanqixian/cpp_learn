/*
 * 问题：如何初始化类中的成员变量？
 * 尝试：直接在构造函数中进行初始化
 * 结果：报错为修改只读变量和未初始化的成员变量 
 * 		 尝试失败
 */
#include <stdio.h>
class Test 
{
private:
	const int ci;
public:
	Test()
	{
		ci=10;
	}
	int getCI()
	{
		return ci;
	}
};
int  main(int argc, const char *argv[])
{
	Test t;
	printf("t.ci=%d\n",t.getCI());
	return 0;
}
