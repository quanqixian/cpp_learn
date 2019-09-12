/**
 * 统计程序运行过程中某个类的个数 
 * 使用静态成员变量
 */
#include <iostream>
using namespace std;
class Test
{
private:
	static int cCount;
public:
	Test()
	{
		cCount++;
	}
	~Test()
	{
		--cCount;
	}
	int getCount()
	{
		return cCount;
	}
};
int Test::cCount=0;
Test gTest;
int main()
{
	Test t1;
	Test t2;
	cout<<"cout="<<gTest.getCount()<<endl;
	cout<<"cout="<<t1.getCount()<<endl;
	cout<<"cout="<<t2.getCount()<<endl;

	Test *pt=new Test();
	cout<<"cout="<<pt->getCount()<<endl;
	delete pt;
	cout<<"cout="<<pt->getCount()<<endl;
	return 0;


}
/*
 静态成员变量属于整个类所有
 静态成员的生命周期不依赖于任何对象（程序包运行的整个周期）
 可以通过类名直接访问共有静态成员变量
 所有对象共享类的静态成员变量
 可以通过对象名访问公有静态成员变量
由以上分析得出静态成员变量的几条特性：

在定义时直接通过static关键字修饰
静态成员变量需要在类外单独分配空间
静态成员变量在程序内部位于全局数据区（但是文件间无法共享）
 */
