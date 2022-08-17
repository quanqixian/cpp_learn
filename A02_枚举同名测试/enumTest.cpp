#include <iostream>
class A
{
public:
	enum Types
	{
		TYPE_A = 1,
		TYPE_B,
	};
};

class B
{
public:
	enum Types
	{
		TYPE_A = 10,
		TYPE_B,
	};
};

enum Types
{
	TYPE_A = 100,
	TYPE_B,
};

int main(int argc, const char *argv[])
{
	
	int a1 = A::TYPE_A;
	int a2 = B::TYPE_A;
	int a3 = TYPE_A;

	std::cout<<"a1="<<a1<<std::endl;
	std::cout<<"a2="<<a2<<std::endl;
	std::cout<<"a3="<<a3<<std::endl;

	return 0;
}
