#include <iostream>
#include <string>
/*产生内存泄漏的原因：指针无法控制所有堆空间的生命周期,析构函数得不到调用,c++没有垃圾回收机制,在堆上申请的空间需要程序员自己归还*/
using namespace std;
class Test
{
	int i;
public:
	Test(int i)
	{
		this->i=i;
		cout<<"Test(int i)"<<endl;
	}
	int value()
	{
		return i;
	}
	~Test()
	{
		cout<<"~Test()"<<endl;
	}
};
int main()
{
	for(int i=0;i<5;i++)
	{
		Test*p=new Test(i);
		cout<<p->value()<<endl;
	}
	return 0;
}
