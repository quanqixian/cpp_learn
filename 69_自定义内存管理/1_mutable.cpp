/*统计对象中某个成员变量的访问次数*/
#include <iostream>
#include <string>
using namespace std;
class Test 
{
	int m_value;
	mutable int m_count;
public:
	Test(int value=0)
	{
		m_value=value;
		m_count=0;
	}
	int getValue()const  
	{
		m_count++;
		return m_value;
	}
	int setValue(int value)
	{
		m_count++;
		m_value=value;
	}
	int getCount() const 
	{
		return m_count;
	}
	~Test()
	{
		
	}
};

int main(int argc, const char *argv[])
{
	Test t;
	t.setValue(100);

	cout<<"t.m_value="<<t.getValue()<<endl;
	cout<<"t.m_value="<<t.getCount()<<endl;

	const Test ct(200);
	cout<<"ct.m_value="<<ct.getValue()<<endl;
	cout<<"ct.m_count="<<ct.getCount()<<endl;
	
	return 0;
}
