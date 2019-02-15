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
