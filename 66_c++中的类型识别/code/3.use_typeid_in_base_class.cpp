#include <iostream>
#include <typeinfo>

/***************
 *  filename:
 *  date    :2020/11/4
 *  author  :Q_uan
 *  function:测试在基类中使用typeid，打印动态类型信息
 ****************/
using namespace std;
class Animal
{
public:
	void print()
	{
		const type_info& info = typeid(*this);
		cout<<info.name()<<endl;
	}
	virtual ~Animal()
	{
	}
};

class Cat : public Animal
{

};

class Dog : public Animal
{
};

int main (int argc, const char * argv[])
{
	Cat cat;
	Dog dog;
	cat.print();
	dog.print();

	
}
