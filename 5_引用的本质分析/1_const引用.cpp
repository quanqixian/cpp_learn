#include <stdio.h>
/**
 * c++ 中可以声明const 引用 
 * const T & name = var;
 * const 引用让变量拥有只读属性
 */
void Example()
{
	printf("Example\n");
	int a = 4;
	const int& b = a;
	int * p = (int *)&b;
	//b = 5;
	*p = 5;
	printf("a =%d\n",a);
	printf("b =%d\n",b);
}
/**
 * 当使用常量对const引用进行初始化时，c++编译器会为常量值分配空间，
 * 并将引用名作为指端空间的别名
 */
void Demo()
{
	printf("Demo\n");
	const int& c = 1;
	int *p = (int *)&c;
	//c = 5;
	*p = 5;
	printf("c =%d\n",c);
}
int main(int argc, const char *argv[])
{
	Example();
	printf("\n");
	Demo();
	return 0;
}
