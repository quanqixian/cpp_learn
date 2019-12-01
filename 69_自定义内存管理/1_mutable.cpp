/*统计对象中某个成员变量的访问次数*/
#include <iostream>
#include <string>
using namespace std;
class Test 
{
	int m_value;
	/**
	 * mutable是为了突破const函数的限制而设计的
	 * mutable成员变量永远处于可改变的状态
	 * mutable在实际的项目开发中被严禁滥用 
	 */
	mutable  int m_count;
public:
	Test(int value=0)
	{
		m_value=value;
		m_count=0;
	}
	//int getValue() 
	int getValue() const 
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
	/* 定义非const对象 */
	Test t;
	t.setValue(100);
	cout<<"t.m_value="<<t.getValue()<<endl;
	cout<<"t.m_count="<<t.getCount()<<endl;

	/* 定义只读对象 */
	const Test ct(200);
	cout<<"ct.m_value="<<ct.getValue()<<endl;
	cout<<"ct.m_count="<<ct.getCount()<<endl;
	
	return 0;
}
/**
 * mutable 成员变量破坏了只读对象的内部状态
 */
