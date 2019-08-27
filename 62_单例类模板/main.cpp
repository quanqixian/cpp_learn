#include <iostream>
#include <string>
#include "Singleton.h"
using namespace std;
class Test 
{
	friend class Singleton<Test>;//当前类需要使用单例模式 
	Test(const Test&);
	Test& operator=(const Test&);
	Test(){}//构造函数被定义为private,所以在外部不能直接调用，但是友缘类可以调用。
public:
	void print()
	{
		cout<<"this="<<this<<endl;
	}
};
int main(int argc, const char *argv[])
{
	Test *s=Singleton<Test>::GetInstance();
	Test *s1=Singleton<Test>::GetInstance();
	Test *s2=Singleton<Test>::GetInstance();

	s->print();
	s1->print();
	s2->print();
	return 0;
}
