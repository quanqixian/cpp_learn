/*统计程序运行期间某各类的个数
 * 使用全局变量实现:
 *
 * */
#include <iostream>
using namespace std;
int gCount=0;
class Test
{
private:
	int mCount;
public:
	Test():mCount(0)
	{
		gCount++;
	}
	~Test()
	{
		--gCount;
	}
	int getCount()
	{
		return gCount;
	}
};
Test gTest;
int main()
{
	Test t1;
	Test t2;
	cout<<"count="<<gTest.getCount()<<endl;
	cout<<"count="<<t1.getCount()<<endl;
	cout<<"count="<<t2.getCount()<<endl;
	return  0;

}
