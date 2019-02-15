/*测试子类是否可以访问父类私有成员变量*/
/*结果：不能通过编译*/
#include <iostream>
#include <string>
using namespace std;
class Parent
{
private:
	int mv;
public:
	Parent()
	{
		mv=100;
	}
	int value()
	{
		return mv;
	}
};
class Child:public Parent 
{
public:
	int addValue(int v)
	{
		mv=mv+v; //can this be ok?
	}
};
int main()
{
	return 0;
}
