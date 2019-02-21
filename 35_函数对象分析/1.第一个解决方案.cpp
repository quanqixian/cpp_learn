#include <iostream>
#include <string>
/*斐波那契数列1,1,2,3,5,8,13,21,34,55,89,144,233*/
/*
 * func:可以获取斐波那契数列每一项的值 
 *      每调用一次返回一个值
 *      函数可以根据需要重复使用
 * 一开始尝试如下：
 */

/*
 * 我们貌似实现了斐波那契数列的值 的输出。但是这个函数，是存在问题的： 
 * *函数一旦调用就无法重来 
 * *静态函数变量处于函数内部，外部无法改变 
 * *函数为全局函数，是唯一的，无法多次独立使用。 
 * *无法指定某个初始的数列项作为初始值打印输出
 * */
using namespace std;
int fib()
{
	static int a0=0;
	static int a1=1;
	int ret=a1;//先将a1保存起来给ret 
	a1=a0+a1;
	a0=ret;//再将a1的值给a0
	return ret;//此时ret为a1，即要输出的每一项 
}
int main()
{
	for(int i=0;i<10;i++)
	{
		cout<<fib()<<endl;
	}
	cout<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<fib()<<endl;
	}
	return 0;
}
