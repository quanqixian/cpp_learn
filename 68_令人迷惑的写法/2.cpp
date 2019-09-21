/********************
 try ...catch 用于分隔正常功能代码和异常处理代码 
 try ...catch 可以直接将函数实现分隔成2部分
 函数声明和定义可以直接指定可能抛出的异常类型 
 异常声明成为函数的一部分可以提高代码可读性 
 *******************/
#include <iostream>
#include <string>
using namespace std;
//int func(int i,int j)throw(int)//若指定抛出的异常为int型，而在函数中抛出其他类型，会导致程序异常终止。
int func(int i,int j)throw(int ,char )
{
	if( (0<j)&&(j<10) )
	{
		return (i+j);
	}
	else 
	{
		throw '0';    
		//throw 0 ;    
	}
}
void test(int i) try 
{
	cout<<"func(i,i)="<<func(i,i)<<endl;
}
catch(int )
{
	cout<<"Exception:"<<i<<endl;
}
catch(...)
{
	cout<<"Exception..."<<endl;
}
int main(int argc, const char *argv[])
{
	test(5);
	test(10);
	return 0;
}
