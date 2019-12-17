/**
 *new关键字与mallo函数的区别
 	new 关键字是c++的一部分
	malloc 是由c库提供的函数
	new 以具体类型为单位进行内存分配
	malloc 以字节为单位进行内存分配
	new 在申请内存空间时进行初始化
	malloc 仅根据需要申请定量内存空间
 *delete和free的区别
  	delete 在所有c++编译器中被支持
	free在某些系统开发中不能调用
	delete能够触发析构函数的调用
	free仅归还之前分配的内存空间 
	对象的销毁只能使用delete
	free不适合面向对象开发
 */

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Test 
{
	int * mp;
public:
	Test()
	{
		cout<<"Test::Test()"<<endl;
		mp = new int(100);
		cout<<*mp<<endl;
	}
	~Test()
	{
		delete mp;
		cout<<"~Test::Test()"<<endl;
	}
};
int main(int argc, const char *argv[])
{
	Test *pn = new Test;
	Test *pm = (Test*)malloc(sizeof(Test));

	delete pn;
	free(pm);
	return 0;
}
