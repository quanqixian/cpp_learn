#include <iostream>
#include <string>

using namespace std;
class Parent
{
public:
	virtual void print()
	{
		cout<< "I'm Parent."<<endl;
	}
};
class Child :public Parent 
{
public:
	void print()
	{
		cout<<"I'm Child."<<endl;
	}
};
void say_hi(Parent *p)
{
	p->print(); //展现多态的行为
}
int main(int argc, const char *argv[])
{
	Parent p;
	Child c;

	say_hi(&p);
	say_hi(&c);
	return 0;
}
