#include <iostream>
#include <string>
using namespace std;
class Parent
{
	int mv;
public:
	Parent()
	{
		cout<<"Paret()"<<endl;
		mv=100;
	}
	void method()
	{
		cout<<"mv="<<mv<<endl;
	}
};
class Child:public Parent 
{
public:
	void hello()
	{
		cout<<"Child"<<endl;
	}
};
int main()
{
	Child c;
	c.hello();
	c.method();
	return 0;
}
